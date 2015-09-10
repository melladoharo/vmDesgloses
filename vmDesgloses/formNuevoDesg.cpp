/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formNuevoDesg
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para introducir un nuevo desglose
----------------------------------------------------------------------------------------------------*/


#include "StdAfx.h"
#include "formNuevoDesg.h"
#include "funcionesExtras.h"

/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
FormNuevoDesg::FormNuevoDesg(QWidget *parent)
	:	QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	insertarNuevoCliente=false;
	insertarNuevoDesglose=false;

	// Cargar datos en widgets antes de cargar la configuracion
	mostrarClientes();
	mostrarDesglose();

	// Carga la configuracion por defecto
	cargarConfig();
	this->setFixedSize(625, 355);

	// Conects
	connect(ui.botonNuevo, SIGNAL(clicked()), this, SLOT(agregarCliente()));
	connect(ui.botonNuevoDesglose, SIGNAL(clicked()), this, SLOT(agregarDesglose()));
	connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(cambiarCliente()));
	connect(ui.comboBoxDesglose, SIGNAL(activated(int)), this, SLOT(cambiarDesglose()));

	// Connects para enter key (numeros)
	QSignalMapper* mSignalMapper=new QSignalMapper(this);
	mSignalMapper->setMapping(ui.lineEdit_DollarEuro, ui.lineEdit_DollarEuro);
	mSignalMapper->setMapping(ui.lineEdit_CtsDesglose, ui.lineEdit_CtsDesglose);
	mSignalMapper->setMapping(ui.lineEdit_CostoDollar, ui.lineEdit_CostoDollar);
	mSignalMapper->setMapping(ui.lineEdit_ventaEuro, ui.lineEdit_ventaEuro);
	connect(ui.lineEdit_DollarEuro, SIGNAL(returnPressed()), mSignalMapper, SLOT(map()));
	connect(ui.lineEdit_CtsDesglose, SIGNAL(returnPressed()), mSignalMapper, SLOT(map()));
	connect(ui.lineEdit_CostoDollar, SIGNAL(returnPressed()), mSignalMapper, SLOT(map()));
	connect(ui.lineEdit_ventaEuro, SIGNAL(returnPressed()), mSignalMapper, SLOT(map()));
	connect(mSignalMapper, SIGNAL(mapped(QWidget *)), this, SLOT(comprobarNumero(QWidget *)));

	// Connects para enter key (texto)
	QSignalMapper *mMap2=new QSignalMapper(this);
	mMap2->setMapping(ui.lineEdit_RefDesglose, ui.lineEdit_RefDesglose);
	mMap2->setMapping(ui.lineEdit_MMdesglose, ui.lineEdit_MMdesglose);
	mMap2->setMapping(ui.lineEdit_RefNota, ui.lineEdit_RefNota);
	mMap2->setMapping(ui.lineEdit_Albaran, ui.lineEdit_Albaran);
	connect(ui.lineEdit_RefDesglose, SIGNAL(returnPressed()), mMap2, SLOT(map()));
	connect(ui.lineEdit_MMdesglose, SIGNAL(returnPressed()), mMap2, SLOT(map()));
	connect(ui.lineEdit_RefNota, SIGNAL(returnPressed()), mMap2, SLOT(map()));
	connect(ui.lineEdit_Albaran, SIGNAL(returnPressed()), mMap2, SLOT(map()));
	connect(mMap2, SIGNAL(mapped(QWidget *)), this, SLOT(comprobarCadena(QWidget *)));
}
/*--------------------------------------------------------------------------------------------------*/
FormNuevoDesg::~FormNuevoDesg(void)
{
	guardarConfig();
}




/*----------------------------------------------------------------------------------------------------
  KEY PRESS EVENT
  Eventos pulsar determinadas teclas
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::keyPressEvent( QKeyEvent *event )
{
	if(event->key()==Qt::Key_Up) this->focusPreviousChild();
	else if(event->key()==Qt::Key_Down)	this->focusNextChild();
}




/*----------------------------------------------------------------------------------------------------
  CARGAR CONFIGURACION
  Cargar datos por defecto, tamaño de la ventana y otra informacion que el usuario modifique
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::cargarConfig( void )
{
	ui.dateEdit->setDate(QDate::currentDate());

	QSettings settings("VanessMark", "vmDesglose");
	resize(settings.value("nuevoDesglose/size", QSize(400, 400)).toSize());
	move(settings.value("nuevoDesglose/pos", QPoint(200, 200)).toPoint());
	ui.lineEdit_DollarEuro->setText(settings.value("nuevoDesglose/dollarEuro").toString());
	ui.dateEdit->setDate(settings.value("nuevoDesglose/tiempo").toDate());

	int index = ui.comboBox->findText(settings.value("nuevoDesglose/ultimoCliente").toString());
	if(index!=-1) ui.comboBox->setCurrentIndex(index);

	cambiarCliente();

	index=ui.comboBoxDesglose->findText(settings.value("nuevoDesglose/ultimoDesglose").toString());
	if(index!=-1) ui.comboBoxDesglose->setCurrentIndex(index);

	cambiarDesglose();
}
/*----------------------------------------------------------------------------------------------------
  GUARDAR CONFIGURACION
  Guarda los datos por defecto, tamaño de la ventana y otra informacion que el usuario modifique
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::guardarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	settings.setValue("nuevoDesglose/size", size());
	settings.setValue("nuevoDesglose/pos", pos());
	settings.setValue("nuevoDesglose/dollarEuro", ui.lineEdit_DollarEuro->text());
	settings.setValue("nuevoDesglose/tiempo", (ui.comboBoxDesglose->count()>0) ? ui.dateEdit->date() : QDate::currentDate());
	settings.setValue("nuevoDesglose/ultimoCliente", ui.comboBox->itemText(ui.comboBox->currentIndex()));
	settings.setValue("nuevoDesglose/ultimoDesglose", ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex()));
}




/*----------------------------------------------------------------------------------------------------
  MOSTRAR CLIENTES
  Rellena el combobox con los nombres de los clientes disponibles.
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::mostrarClientes( void )
{
	QSqlQuery query;
	if(!query.exec("SELECT nombre_cliente FROM cliente"))
	{
		QMessageBox::critical(this, "ERROR MOSTRAR CLIENTES", query.lastError().text());
	}
	else
	{
		while(query.next()) 
		{
			ui.comboBox->addItem(query.value(0).toString());
		}
	}
}
/*----------------------------------------------------------------------------------------------------
  MOSTRAR DESGLOSES
  Rellena el combobox (desgloses) con los desgloses disponibles del cliente seleccionado
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::mostrarDesglose( void )
{
	if(ui.comboBox->count()>0)
	{
		int idCliente=extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);

		QSqlQuery query;
		query.prepare("SELECT DISTINCT(id_desglose) FROM desglose WHERE id_cliente=:id");
		query.bindValue(":id", idCliente);
		if(!query.exec())
			QMessageBox::critical(this, "ERROR MOSTRAR DESGLOSE", query.lastError().text());

		while(query.next()) 
		{
			ui.comboBoxDesglose->addItem(query.value(0).toString());
		}
	}
	else
	{
		//QMessageBox::critical(this, "Lista vacia.", "La lista de clientes esta vacia.");
	}
}




/*----------------------------------------------------------------------------------------------------
  PRIVATE SLOTS - COMPROBAR NUMERO
  Se asegura de que se ha introducido un valor numerico, antes de pasar al siguiente campo.
  Necesario para garantizar que no se introducen valores erroneos en la entrada.
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::comprobarNumero( QWidget *widget )
{
	if(ui.comboBox->count()>0 && ui.comboBoxDesglose->count()>0)
	{
		QLineEdit *lineEdit=dynamic_cast<QLineEdit*>(widget);	
		if(extras::esNumero(lineEdit->text()) && lineEdit->text().toDouble()>0) // es un numero valido
		{
			this->focusNextChild();
			if(lineEdit==ui.lineEdit_ventaEuro)
				terminarDesglose();
		}
		else // no es un numero valido
		{
			QMessageBox::critical(this, "Error", "Formato no valido. Debes introducir un numero mayor de cero.\t\n");
			lineEdit->setText("");
		}
	}
	else
	{
		QMessageBox::information(this, "Aviso", "No has seleccionado un cliente y/o un desglose validos.");
	}
}


void FormNuevoDesg::comprobarCadena( QWidget *widget )
{
	if(ui.comboBox->count()>0 && ui.comboBoxDesglose->count()>0)
	{
		QLineEdit *lineEdit=dynamic_cast<QLineEdit*>(widget);

		if(!lineEdit->text().isEmpty() || lineEdit==ui.lineEdit_Albaran)
		{
			this->focusNextChild();

		}
		else // no ha introducido un texo
		{
			QMessageBox::critical(this, "Error", "Texto vacio. Introduce algun texto para continuar.\t\n");
			lineEdit->setText("");
		}
	}
	else
	{
		QMessageBox::information(this, "Aviso", "No has seleccionado un cliente y/o un desglose validos.");
	}
}


void FormNuevoDesg::cambiarCliente( void )
{
	ui.comboBoxDesglose->clear();
	mostrarDesglose();
	cambiarDesglose();
}


void FormNuevoDesg::cambiarDesglose( void )
{
	if(ui.comboBox->count()>0)
	{
		// Si estabamos insertando un nuevo desglose, se cancela la operacion
		if(insertarNuevoDesglose)
		{
			ui.comboBoxDesglose->removeItem(indexActualDesglose);
			indexActualDesglose=1;
			insertarNuevoDesglose=false;
		}

		int idcliente=extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);
		QString idDesglose=ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex());
		ui.dateEdit->setDate(extras::getFecha(idcliente, idDesglose, this));
		ui.lineEdit_DollarEuro->setText(extras::getCotizacion(idcliente, idDesglose, this));
		ui.lineEdit_RefNota->setText(extras::getRefNota(idcliente, idDesglose, this));
		ui.lineEdit_Albaran->setText(extras::getAlbaran(idcliente, idDesglose, this));
		ui.lineEdit_RefDesglose->setFocus();

		ui.lineEdit_RefDesglose->clear();
		ui.lineEdit_MMdesglose->clear();
		ui.lineEdit_CostoDollar->clear();
		ui.lineEdit_CtsDesglose->clear();
		ui.lineEdit_ventaEuro->clear();
		ui.lineEdit_RefDesglose->setFocus();

		ui.labelFecha->setEnabled(false);
		ui.dateEdit->setEnabled(false);
		ui.labelAlbaran->setEnabled(false);
		ui.lineEdit_Albaran->setEnabled(false);
		ui.labelDivisa->setEnabled(false);
		ui.lineEdit_DollarEuro->setEnabled(false);
	}
}


/*----------------------------------------------------------------------------------------------------
  PRIVATE SLOTS - NUEVO CLIENTE
  Introduce un nuevo cliente en la base de datos.
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::agregarCliente( void )
{
	if(!insertarNuevoCliente) // Evita que se inserte 2 clientes seguidos
	{
		bool ok=false, repetir=false;
		QString nuevoNombre;

		do 
		{
			ok=repetir=false;
			nuevoNombre.clear();

			nuevoNombre=QInputDialog::getText(this, "Introducir nuevo cliente", 
				"Nuevo cliente:", QLineEdit::Normal, "Nombre", &ok); 

			if(ok) // Aceptar nuevo cliente
			{
				if(!nuevoNombre.isEmpty() && nuevoNombre!="Nombre")
				{
					// Comprueba que el cliente no existe
					for(unsigned int i=0; i<ui.comboBox->count(); ++i)
					{
						if(ui.comboBox->itemText(i)==nuevoNombre)
						{
							QMessageBox::critical(this, "Nombre cliente duplicado", 
								"Ya existe un cliente con ese nombre. Por favor, inserte otro distinto.");
							repetir=true;
							break;
						}
					}

					if(!repetir) // Nombre correcto, se inserta definitivamente
					{
						ui.comboBox->addItem(nuevoNombre);
						int index = ui.comboBox->findText(nuevoNombre);
						if(index!=-1)	ui.comboBox->setCurrentIndex(index);
						ui.comboBoxDesglose->clear();
						insertarNuevoCliente=true;
					}
				}
				else // Nombre mal escrito
				{
					QMessageBox::critical(this, "Nombre cliente incorrecto", 
						"El nombre de cliente que has introducido es incorrecto. Por favor, intentelo de nuevo.");
					repetir=true;
				}
			}
			else // Cancelar nuevo cliente
			{
				return;
			}
		} 
		while (repetir);
	}
	else
	{
		QMessageBox::information(this, "Aviso", "Inserta al menos un desglose completo antes de añadir otro.  ");
	}
}
/*----------------------------------------------------------------------------------------------------
  PRIVATE SLOTS - AGREGAR DESGLOSE
  Añade un nuevo desglose al cliente actual seleccionado
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::agregarDesglose( void )
{
	if(ui.comboBox->count()>0 && !insertarNuevoDesglose) // Si hay cliente y ha finalizado con el desglose anterior...
	{
		bool ok=false, repetir=false;
		QString nuevoDesglose;

		do 
		{
			ok=repetir=false;
			nuevoDesglose.clear();

			nuevoDesglose=QInputDialog::getText(this, "Nuevo desglose", 
				"Nuevo desglose:", QLineEdit::Normal, "Desglose", &ok); 

			if(ok) // Aceptar nuevo cliente
			{
				if(!nuevoDesglose.isEmpty() && nuevoDesglose!="Desglose")
				{
					// Comprueba que el desglose no este creado ya
					for(unsigned int i=0; i<ui.comboBoxDesglose->count(); ++i)
					{
						if(ui.comboBoxDesglose->itemText(i)==nuevoDesglose)
						{
							QMessageBox::critical(this, "Desglose duplicado", 
								"Ya existe un desglose con ese nombre para este cliente. Por favor, inserte otro distinto.");
							repetir=true;
							break;
						}
					}

					if(!repetir) // Inserta el nuevo desglose y termina
					{
						ui.comboBoxDesglose->addItem(nuevoDesglose);
						int index = ui.comboBoxDesglose->findText(nuevoDesglose);
						if(index!=-1)	ui.comboBoxDesglose->setCurrentIndex(index);
						indexActualDesglose=index; // para cancelar el nuevo desglose si se selecciona otro
						ui.dateEdit->setDate(QDate::currentDate());
						ui.lineEdit_DollarEuro->clear();
						ui.lineEdit_Albaran->clear();
						ui.lineEdit_RefNota->clear();
						ui.dateEdit->setEnabled(true);
						ui.labelFecha->setEnabled(true);
						ui.lineEdit_Albaran->setEnabled(true);
						ui.labelAlbaran->setEnabled(true);
						ui.lineEdit_DollarEuro->setEnabled(true);
						ui.labelDivisa->setEnabled(true);
						ui.dateEdit->setFocus();
						insertarNuevoDesglose=true;
					}
				}
				else // Nombre mal escrito
				{
					QMessageBox::critical(this, "Desglose incorrecto", 
						"El desglose que has introducido es incorrecto. Por favor, intentelo de nuevo.");
					repetir=true;
				}
			}
		}
		while(repetir);
	}
	else
	{
		if(insertarNuevoDesglose)
			QMessageBox::information(this, "Aviso", "Inserta al menos un desglose completo antes de añadir otro.  ");
		else
			QMessageBox::information(this, "Aviso", "Lista de clientes esta vacia. Agrega un cliente primero.  ");
	}
}




/*----------------------------------------------------------------------------------------------------
  PRIVATE SLOTS - TERMINAR DESGLOSE
  Termina este formulario introduciendo los valores en la bbdd
----------------------------------------------------------------------------------------------------*/
void FormNuevoDesg::terminarDesglose( void )
{
	if(!ui.lineEdit_DollarEuro->text().isEmpty() &&
	   !ui.lineEdit_RefDesglose->text().isEmpty() &&
	   !ui.lineEdit_MMdesglose->text().isEmpty() &&
	   !ui.lineEdit_RefNota->text().isEmpty() &&
	   !ui.lineEdit_CtsDesglose->text().isEmpty() && extras::esNumero(ui.lineEdit_CtsDesglose->text()) &&
	   !ui.lineEdit_CostoDollar->text().isEmpty() && extras::esNumero(ui.lineEdit_CostoDollar->text()) &&
	   !ui.lineEdit_ventaEuro->text().isEmpty() && extras::esNumero(ui.lineEdit_ventaEuro->text()))
	{
		QMessageBox::StandardButton reply; 
		reply=QMessageBox::question(this, "Confirmar", tr("Do you want to embed this breakdown?"), 
			QMessageBox::Yes | QMessageBox::No); 

		if(reply==QMessageBox::Yes) 
		{
			// Inserta el nuevo cliente si es necesario
			if(insertarNuevoCliente)
				extras::insertarCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);
			insertarNuevoCliente=false;
			insertarNuevoDesglose=false;

			// Redondear numero QString::number(value, 'f', 2);
			double ctsDesg=ui.lineEdit_CtsDesglose->text().toDouble();
			double pcostoDollar=ui.lineEdit_CostoDollar->text().toDouble();
			double cotizacionDE=ui.lineEdit_DollarEuro->text().toDouble();
			double ventaEuro=ui.lineEdit_ventaEuro->text().toDouble();

			QSqlQuery query;
			query.prepare("INSERT INTO desglose "
				"(id_cliente, id_desglose, id_dvd, mm_desglose, fecha_desglose, ref_nota, alb_nota, "
				"cts_desglose, pcosto_dollar, cotizacion, pventa_euro) "
				"VALUES (:idcliente, :idDesglose, :idDVD, :mmDesg, :fecha, :refNota, :albNota, :ctsDesg, :pcostoDollar, "
				":cotizacionDE, :pCteEuro)");

			query.bindValue(":idcliente", extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this));
			query.bindValue(":idDesglose", ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex()));
			query.bindValue(":idDVD", ui.lineEdit_RefDesglose->text());
			query.bindValue(":mmDesg", ui.lineEdit_MMdesglose->text());
			query.bindValue(":fecha", ui.dateEdit->date().toString("yyyy-MM-dd"));
			query.bindValue(":refNota", ui.lineEdit_RefNota->text());
			query.bindValue(":albNota", ui.lineEdit_Albaran->text());
			query.bindValue(":ctsDesg", ctsDesg);
			query.bindValue(":pcostoDollar", pcostoDollar);
			query.bindValue(":cotizacionDE", cotizacionDE);
			query.bindValue(":pCteEuro", ventaEuro);

			if(!query.exec())
				QMessageBox::critical(this, "ERROR TERMINAR DESGLOSE", query.lastError().text());

			QMessageBox::StandardButton continuarReply;
			reply=QMessageBox::question(this, "Continuar", tr("Do you want to add more breakouts?"), 
				QMessageBox::Yes | QMessageBox::No); 

			if(reply==QMessageBox::Yes) 
			{
				ui.lineEdit_RefDesglose->clear();
				ui.lineEdit_MMdesglose->clear();
				ui.lineEdit_CostoDollar->clear();
				ui.lineEdit_CtsDesglose->clear();
				ui.lineEdit_ventaEuro->clear();
				ui.lineEdit_RefDesglose->setFocus();

				ui.labelFecha->setEnabled(false);
				ui.dateEdit->setEnabled(false);
				ui.labelAlbaran->setEnabled(false);
				ui.lineEdit_Albaran->setEnabled(false);
				ui.labelDivisa->setEnabled(false);
				ui.lineEdit_DollarEuro->setEnabled(false);
			}
			else
			{
				accept();
			}
		}
	}
	else
	{
		QMessageBox::information(this, "Aviso", "No se puede insertar este desglose. "
			"Asegurese de que los campos obligatorios no estan vacios, y el formato sea el correcto.");
	}
}



