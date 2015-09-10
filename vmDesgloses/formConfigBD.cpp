/*----------------------------------------------------------------------------------------------------
	created:	2013/08/10
	created:	15:9:2013   13:39
	file base:	formConfigBD
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para introducir la contraseña y usuario de la bbdd
----------------------------------------------------------------------------------------------------*/

#include "StdAfx.h"
#include "formconfigbd.h"
#include "simpleCrypt.h"
#include "funcionesExtras.h"

/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
FormConfigBD::FormConfigBD(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(322, 266);

	// Carga la configuracion
	cargarConfig();

	// Connects
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(guardarConfig()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancelarForm()));
	connect(ui.bttnTest, SIGNAL(clicked()), this, SLOT(comprobarConexion()));
	connect(ui.btnnCrearBBDD, SIGNAL(clicked()), this, SLOT(crearBBDD()));
}
/*--------------------------------------------------------------------------------------------------*/
FormConfigBD::~FormConfigBD()
{
	
}





/*----------------------------------------------------------------------------------------------------
  CARGAR CONFIGURACION
	Carga la configuracion por defecto. En este caso, el usuario y la contraseña de la base de datos.
----------------------------------------------------------------------------------------------------*/
void FormConfigBD::cargarConfig( void )
{
	extras::InfoBBDD* infoBBDD=extras::cargarConfigBBDD();
	if(infoBBDD!=NULL)
	{
		ui.lineEditUser->setText(infoBBDD->user);
		ui.lineEditPassword->setText(infoBBDD->password);
		ui.lineEditPuerto->setText(QString::number(infoBBDD->port));
		ui.lineEditHost->setText(infoBBDD->host);
		delete infoBBDD;
	}
}
/*----------------------------------------------------------------------------------------------------
  GUARDAR CONFIGURACION
	Si el usuario acepta el formulario, guarda el usuario y contraseña introducidos. 
----------------------------------------------------------------------------------------------------*/
void FormConfigBD::guardarConfig( void )
{
	extras::InfoBBDD* infoBBDD=NULL;
	infoBBDD=new extras::InfoBBDD;

	if(infoBBDD!=NULL)
	{
		infoBBDD->user=ui.lineEditUser->text();
		infoBBDD->password=ui.lineEditPassword->text();
		infoBBDD->port=ui.lineEditPuerto->text().toInt();
		infoBBDD->host=ui.lineEditHost->text();
		extras::guardarConfigBBDD(infoBBDD);

		delete infoBBDD;
	}
}




void FormConfigBD::cancelarForm()
{

}




/*----------------------------------------------------------------------------------------------------
  COMPROBAR CONEXION
	Comprueba la conexion a la base de datos con el usuario y password proporcionados.
----------------------------------------------------------------------------------------------------*/
void FormConfigBD::comprobarConexion( void )
{
	guardarConfig();

	// Mensaje para ver que el programa sigue ejecutandose...
	QMessageBox* msgEspera=extras::crearMensajeEspera(this, tr("Wait"), tr("Connecting to the database, wait ..."));
	
	if(extras::conectarBBDD(this) && crearPGPass())
	{
		msgEspera->close();
		QMessageBox::information(this, "Test Base de Datos", "Conexion con la base de datos correcta.\n"
			"Reinicia la aplicacion para aplicar los cambios.");
	}
	msgEspera->close();
	if(msgEspera) delete msgEspera;
}





/*----------------------------------------------------------------------------------------------------
  CREAR ARCHIVO PGPASS.CONF
	El archivo pgpass.conf es el encargado de almacenar la informacion para poder realizar
	operaciones sobre la base de datos sin introducir la contraseña. Todos los procesos se
	hacen de forma automatica ya que se obtiene la informacion directamente del archivo. 

	Necesario para el pg_dump y el pg_restore. Para evitar que solicite la contraseña.

	El archivo se crea en la carpeta del usuario. En Windows seria asi:
	...C:/Users/%APPDATA%\postgresql\pgpass.conf    --> Windows 7 en adelante
	...C:/Documents and Settings\Application Data\postgresql\pgpass.conf   -->   Windows XP
	
	El formato del arhivo es el siguiente: hostname:port:database:username:password
	Se puede usar el '*' para coincidir con todo. 
	Ejemplo de fichero: 192.168.1.130:5432:*:postgres:meham12
----------------------------------------------------------------------------------------------------*/
bool FormConfigBD::crearPGPass()
{
	// Si no encuentra ninguna ruta valida, cancelamos
	QString dirDocu(QDir::homePath());
	if(dirDocu=="c:/")
	{
		QMessageBox::critical(this, "Error pgpass.conf", "No se encuentra la ruta \"Mis documentos\".");
		return false;
	}

	// Obtener direccion del usuario, diferente WinXP del 7
	if(dirDocu.contains("C:/Users")) dirDocu+="/AppData/Roaming";
	else if(dirDocu.contains("C:/Documents and Settings")) dirDocu+="/Application Data";
	else
	{
		QMessageBox::critical(this, "Error pgpass.conf", "No se encuentra la ruta \"Mis documentos\".");
		return false;
	}

	// Si no existe la carpeta la crea
	if(!QDir(dirDocu+"/postgresql").exists())
		if(!QDir().mkdir(dirDocu+"/postgresql"))
		{
			QMessageBox::critical(this, "Error pgpass.conf", 
				"No se puede crear la carpeta postgres en mis documentos.");
			return false;
		}

	// Crea el fichero, si existe lo borra para crearlo de nuevo
	QFile ficheroPGPass(dirDocu+"/postgresql/pgpass.conf");
	if(ficheroPGPass.exists())
		ficheroPGPass.remove();

	// Abre el fichero
	if(!ficheroPGPass.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, "Error pgpass.conf", "No se puede abrir el fichero pgpass.conf para editarlo.");
		return false;
	}

	// Escribe en el fichero
	extras::InfoBBDD* infoBBDD=extras::cargarConfigBBDD();
	if(infoBBDD!=NULL)
	{
		QTextStream out(&ficheroPGPass);
		out <<infoBBDD->host <<":" <<infoBBDD->port <<":*:" <<infoBBDD->user <<":" <<infoBBDD->password<<"\n";

		delete infoBBDD;
	}
	else
	{
		QMessageBox::critical(this, "Cargar Config", "Error al cargar la informacion de la BBDD");
		return false;
	}

	// Todo ha ido bien
	ficheroPGPass.close();
	return true;
}





/*----------------------------------------------------------------------------------------------------
  CREAR BASE DE DATOS
	Funcion encargada de crear la base de datos de vanessmark desgloses. 
	Si la base de datos esta creada, la elimina, con su informacion, y vuelve a crearla.
	Crea la base de datos, las tablas, y el fichero pgpass.conf para el pg_dump/restore.exe
----------------------------------------------------------------------------------------------------*/
void FormConfigBD::crearBBDD()
{
	QMessageBox::StandardButton reply; 
	reply=QMessageBox::question(this, "Crear BBDD", tr("This create the database"), 
		QMessageBox::Yes | QMessageBox::No); 

	if(reply==QMessageBox::Yes) 
	{
		QMessageBox* msgEspera=extras::crearMensajeEspera(this, "Espere", "Ejecutando accion, por favor espere ...");
		if(extras::crearDBvmdesglose(this))
		{
			if(extras::conectarBBDD(this) && extras::crearDBTablas(this))
			{
				msgEspera->close();
				QMessageBox::information(this, "BBDD", "Base de datos creada correctamente.");
			}
		}
		msgEspera->close();
		if(msgEspera) delete msgEspera;
	}
}



