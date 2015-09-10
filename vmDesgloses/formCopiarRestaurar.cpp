/*----------------------------------------------------------------------------------------------------
	created:	2013/15/10
	created:	15:10:2013   09:39
	file base:	formCopiarRestaurar.cpp
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para crear copias de seguridad de la bbdd y restaurar dichas copias
----------------------------------------------------------------------------------------------------*/

#include "StdAfx.h"
#include "formCopiarRestaurar.h"
#include "funcionesExtras.h"

/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
FormCopiarRestaurar::FormCopiarRestaurar(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(260, 170);

	cargarConfig();

	// Connects
	//connect(ui.bttnAceptarForm, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.bttnCopiarBBDD, SIGNAL(clicked()), this, SLOT(copiarBBDD()));
	connect(ui.bttnRestaurarBBDD, SIGNAL(clicked()), this, SLOT(restaurarBBDD()));
}
/*--------------------------------------------------------------------------------------------------*/
FormCopiarRestaurar::~FormCopiarRestaurar()
{
	guardarConfig();
}





/*----------------------------------------------------------------------------------------------------
  CARGAR CONFIGURACION
  Carga la configuracion por defecto
----------------------------------------------------------------------------------------------------*/
void FormCopiarRestaurar::cargarConfig( void )
{
	// Cargar informacion de la bbdd
	extras::InfoBBDD* infoBBDD=extras::cargarConfigBBDD();
	if(infoBBDD!=NULL)
	{
		userBBDD=infoBBDD->user;
		passBBDD=infoBBDD->password;
		hostBBDD=infoBBDD->host;
		delete infoBBDD;
	}
	QSettings settings("VanessMark", "vmDesglose");
	ultimaRutaUsada.setPath(settings.value("BBDD/rutaUltimaCopia").toString());

	// Concatena a la ultima ubicacion utulizada con el nombre por defecto.
	// El nombre por defecto lleva concatenado a su vez la fecha actual
	QString nomDefecto=QString("/backup_desgloses_%1.backup").arg(QDate::currentDate().toString("dd_MMM_yyyy"));
	if(ultimaRutaUsada.exists())
	{
		ultimaRutaUsada.setPath(ultimaRutaUsada.path()+nomDefecto);
	}
	else // ruta por defecto
	{
		QString ruta(".");
		if(QDir("./backups").exists())
			ruta="./backups";
		ultimaRutaUsada.setPath(ruta + nomDefecto);
	}
}
/*----------------------------------------------------------------------------------------------------
  GUARDAR CONFIGURACION
  Guarda la configuracion por defecto
----------------------------------------------------------------------------------------------------*/
void FormCopiarRestaurar::guardarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	settings.setValue("BBDD/rutaUltimaCopia", ultimaRutaUsada.path());
}






/*----------------------------------------------------------------------------------------------------
  CREAR COPIA DE SEGURIDAD DE LA BBDD
  Crea un fichero que contiene la copia de la base de datos. Se le pide al usuario que lo almacene
  en la ruta que el quiera. Tiene que elegir una.
----------------------------------------------------------------------------------------------------*/
void FormCopiarRestaurar::copiarBBDD( void )
{
	//QFile file_pg_dump("C:/Program Files (x86)/PostgreSQL/9.3/bin/pg_dump.exe");
	QDir dirActual(".");
	QFile file_pg_dump(dirActual.absolutePath()+"./pg_dump.exe");
	if(file_pg_dump.exists())
	{
		QString fileName=QFileDialog::getSaveFileName(this, "Guardar copia desgloses", 
			ultimaRutaUsada.path(),  "Backup SQL (*.backup)");

		if(!fileName.isEmpty())
		{
			ui.labelEstado->setText("Copiando. Por favor espere.");

			QMessageBox* msgEspera=extras::crearMensajeEspera(this, "Espere", "Creando copia de seguridad ...");

			// Ruta del pg_dump
			QString pathCMD(file_pg_dump.fileName());
			extras::convertirCMD(pathCMD);

			// Ruta donde se guardara el .backup
			QString pathSQL(fileName);
			extras::convertirCMD(pathSQL);

			// ...pg_dump.exe -U user -Fc databasename > fileout.backup
			QProcess *miProceso=new QProcess(this);
			QStringList params;
			params	<< "/C"
				<< pathCMD + " -U " + userBBDD + " -h " + hostBBDD + " -Fc db_vmdesglose > " + pathSQL;

			miProceso->start("cmd.exe", params);
			miProceso->waitForFinished();

			// Guarda la ultima ruta usada para usarla mas tarde
			QDir aux(fileName);
			aux.cdUp();
			ultimaRutaUsada=aux.path();

			msgEspera->close();
			if(msgEspera) delete msgEspera;
			ui.labelEstado->setText("Copia creada correctamente");
		}
	}
	else
	{
		QMessageBox::critical(this, "Error pg_dump.exe", "No se encuentra o no esta disponible pg_dump.exe");
	}
}


void FormCopiarRestaurar::restaurarBBDD( void )
{
	//QFile file_psql("C:/Program Files (x86)/PostgreSQL/9.3/bin/pg_restore.exe");
	QDir dirActual(".");
	QFile file_psql(dirActual.absolutePath()+"/pg_restore.exe");
	
	if(file_psql.exists())
	{
		// Ultima ruta usada, donde se guardo la copia, para ahora restaurarla
		QDir ultimaRuta(ultimaRutaUsada);
		ultimaRuta.cdUp();

		QString fileName=QFileDialog::getOpenFileName(this, "Restaurar copia desgloses", 
			ultimaRuta.path(), "Backup SQL (*.backup)"); 

		if(!fileName.isEmpty())
		{
			// Mensaje de espera
			QMessageBox* msgEspera=extras::crearMensajeEspera(this, "Espere", "Restaurando copia de seguridad ...");

			// Ruta del ejecutable
			QString pathCMD(file_psql.fileName());
			extras::convertirCMD(pathCMD);

			// Ruta donde se encuentra el .backup
			QString pathSQL(fileName);
			extras::convertirCMD(pathSQL);

			// Ejecuta el terminal cmd con el comando:
			// ...pg_restore.exe -U postgres -n public -c -1 -d db_vmdesglose bc1.backup
			QProcess *miProceso=new QProcess(this);
			QStringList params;
			params	<< "/C" << pathCMD + " -U " + userBBDD + " -h " + hostBBDD + " -n public -c -1 -d db_vmdesglose < " + pathSQL;
			miProceso->start("cmd.exe", params);
			miProceso->waitForFinished();
			
			// Guarda la ultima ruta usada para usarla mas tarde
			QDir aux(fileName);
			aux.cdUp();
			ultimaRutaUsada=aux.path();

			msgEspera->close();
			if(msgEspera) delete msgEspera;
			ui.labelEstado->setText("Copia restaurada correctamente");
		}
	}
	else
	{
		QMessageBox::critical(this, "Error plsql", "No se encuentra o no esta disponible pg_restore.exe");
	}
}



