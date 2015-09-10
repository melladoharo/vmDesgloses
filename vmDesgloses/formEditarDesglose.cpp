/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formEditarDesg
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para editar desgloses
----------------------------------------------------------------------------------------------------*/

#include "StdAfx.h"
#include "formEditarDesglose.h"
#include "funcionesExtras.h"

/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
formEditarDesg::formEditarDesg(QWidget *parent)
	:	QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(625, 370);

	// Borrar Clientes Vacios
	extras::borrarClientesVacio(this);

	// Cargar datos en widgets antes de cargar la configuracion
	mostrarClientes();
	mostrarDesglose();
	cambiarCliente();
	cambiarDesglose();

	connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(cambiarCliente()));
	connect(ui.comboBoxDesglose, SIGNAL(activated(int)), this, SLOT(cambiarDesglose()));
	connect(ui.botonModificarDvd, SIGNAL(clicked()), this, SLOT(DvdModificar()));
	connect(ui.botonBorrarDvd, SIGNAL(clicked()), this, SLOT(DvdBorrar()));
	connect(ui.botonBorrarDesglose, SIGNAL(clicked()), this, SLOT(DesgloseBorrar()));
	connect(ui.botonBorrarCliente, SIGNAL(clicked()), this, SLOT(ClienteBorrar()));
	connect(ui.bttnSiguiente, SIGNAL(clicked()), this, SLOT(DvdSiguiente()));
	connect(ui.bttnAnterior, SIGNAL(clicked()), this, SLOT(DvdAnterior()));
}
/*--------------------------------------------------------------------------------------------------*/
formEditarDesg::~formEditarDesg()
{
	
}




void formEditarDesg::keyPressEvent( QKeyEvent *event )
{
	if(event->key()==Qt::Key_Up) this->focusPreviousChild();
	else if(event->key()==Qt::Key_Down)	this->focusNextChild();
}


/*----------------------------------------------------------------------------------------------------
  COMPROBAR USUARIO
  Comprueba que el usuario tiene algun desglose disponible
  Si no tiene ningun desglose, el usuario se borra autamticamente de la lista de clientes
----------------------------------------------------------------------------------------------------*/
void formEditarDesg::comprobarUsuario( int idCliente )
{
	if(extras::getNumeroDesgloses(idCliente, this)==0)
	{
		extras::borrarCliente(idCliente, this);
	}
}




void formEditarDesg::mostrarClientes( void )
{
	ui.comboBox->clear();

	QSqlQuery query;
	if(!query.exec("SELECT nombre_cliente FROM cliente ORDER BY nombre_cliente"))
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

void formEditarDesg::mostrarDesglose( void )
{
	ui.comboBoxDesglose->clear();

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
}

void formEditarDesg::cambiarCliente( void )
{
	ui.comboBoxDesglose->clear();
	mostrarDesglose();
	cambiarDesglose();
}

void formEditarDesg::cambiarDesglose( void )
{
	if(ui.comboBox->count()>0)
	{
		int idcliente=extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);
		QString idDesglose=ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex());
		ui.dateEdit->setDate(extras::getFecha(idcliente, idDesglose, this));
		ui.lineEdit_DollarEuro->setText(extras::getCotizacion(idcliente, idDesglose, this));
		ui.lineEdit_RefNota->setText(extras::getRefNota(idcliente, idDesglose, this));
		ui.lineEdit_Albaran->setText(extras::getAlbaran(idcliente, idDesglose, this));
		ui.lineEdit_RefDesglose->setFocus();

		actualizarQueryActual();
		DvdSiguiente();
	}
}





void formEditarDesg::actualizarQueryActual( void )
{
	// QueryDvdActual
	queryDvdActual.clear();
	ui.lineEdit_RefDesglose->clear();
	ui.lineEdit_MMdesglose->clear();
	ui.lineEdit_CostoDollar->clear();
	ui.lineEdit_CtsDesglose->clear();
	ui.lineEdit_ventaEuro->clear();
	ui.lineEdit_RefDesglose->setFocus();

	if(ui.comboBox->count()>0 && ui.comboBoxDesglose->count()>0)
	{
		int idCliente=extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);
		QString idDesglose=ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex());

		queryDvdActual.prepare("SELECT id_dvd, mm_desglose, ref_nota, cts_desglose, pcosto_dollar, pventa_euro, id_aux_desglose "
			"FROM desglose WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		queryDvdActual.bindValue(":idcliente", idCliente);
		queryDvdActual.bindValue(":idDesglose", idDesglose);
		if(!queryDvdActual.exec())
			QMessageBox::critical(this, "ERROR ACTUALIZAR DVD ACTUAL", queryDvdActual.lastError().text());
	}
}






void formEditarDesg::DvdAnterior( void )
{
	if(queryDvdActual.isActive())
	{
		if(!queryDvdActual.previous())
		{
			queryDvdActual.last();
		}

		//idDVD, mmDesg, refNota, ctsDesg, pCostoDollar, pCteEuro
		ui.lineEdit_RefDesglose->setText(queryDvdActual.value(0).toString());
		ui.lineEdit_MMdesglose->setText(queryDvdActual.value(1).toString());
		ui.lineEdit_RefNota->setText(queryDvdActual.value(2).toString());
		ui.lineEdit_CtsDesglose->setText(QString::number(queryDvdActual.value(3).toDouble(), 'f', 2));
		ui.lineEdit_CostoDollar->setText(QString::number(queryDvdActual.value(4).toDouble(), 'f', 2));
		ui.lineEdit_ventaEuro->setText(QString::number(queryDvdActual.value(5).toDouble(), 'f', 2));
	}
}

void formEditarDesg::DvdSiguiente( void )
{
	if(queryDvdActual.isActive())
	{
		if(!queryDvdActual.next())
		{
			queryDvdActual.first();
		}

		//idDVD, mmDesg, refNota, ctsDesg, pCostoDollar, pCteEuro
		ui.lineEdit_RefDesglose->setText(queryDvdActual.value(0).toString());
		ui.lineEdit_MMdesglose->setText(queryDvdActual.value(1).toString());
		ui.lineEdit_RefNota->setText(queryDvdActual.value(2).toString());
		ui.lineEdit_CtsDesglose->setText(QString::number(queryDvdActual.value(3).toDouble(), 'f', 2));
		ui.lineEdit_CostoDollar->setText(QString::number(queryDvdActual.value(4).toDouble(), 'f', 2));
		ui.lineEdit_ventaEuro->setText(QString::number(queryDvdActual.value(5).toDouble(), 'f', 2));
	}
}


void formEditarDesg::DvdModificar( void )
{
	if(ui.comboBox->count()>0 && ui.comboBoxDesglose->count()>0)
	{
		QMessageBox::StandardButton reply; 
		reply=QMessageBox::question(this, "Modificar", tr("Are you sure you want to modify this item?"), 
			QMessageBox::Yes | QMessageBox::No); 

		if(reply==QMessageBox::Yes) 
		{
			QSqlQuery query;
			query.prepare("UPDATE desglose "
				"SET id_dvd=:idDVD, mm_desglose=:mmDesg, alb_nota=:albNota, "
				"cts_desglose=:ctsDesg, pcosto_dollar=:pcostoDollar, pventa_euro=:pCteEuro "
				"WHERE id_aux_desglose=:id ");

			query.bindValue(":id", queryDvdActual.value(6).toInt());
			query.bindValue(":idDVD", ui.lineEdit_RefDesglose->text());
			query.bindValue(":mmDesg", ui.lineEdit_MMdesglose->text());
			query.bindValue(":albNota", ui.lineEdit_Albaran->text());
			query.bindValue(":ctsDesg", ui.lineEdit_CtsDesglose->text().toDouble());
			query.bindValue(":pcostoDollar", ui.lineEdit_CostoDollar->text().toDouble());
			query.bindValue(":pCteEuro", ui.lineEdit_ventaEuro->text().toDouble());

			if(query.exec())
			{
				QMessageBox::information(this, "CORRECTO", "Informacion modificada correctamente.");
			}
			else
			{
				QMessageBox::critical(this, "ERROR MODIFICAR DESGLOSE", query.lastError().text());
			}
		}
	}
}




void formEditarDesg::DvdBorrar( void )
{
	if(ui.comboBox->count()>0 && ui.comboBoxDesglose->count()>0)
	{
		QMessageBox::StandardButton reply; 
		reply=QMessageBox::question(this, tr("Remove"), tr("Are you sure you want to delete this DVD?"), 
			QMessageBox::Yes | QMessageBox::No); 

		if(reply==QMessageBox::Yes) 
		{
			if(extras::borrarDVD(queryDvdActual.value(6).toInt()))
			{
				QMessageBox::information(this, "CORRECTO", "Elemento borrado correctamente.");
				actualizarQueryActual();
				DvdSiguiente();
				if(queryDvdActual.size()==0)
				{
					comprobarUsuario(extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this));
					mostrarClientes();
					mostrarDesglose();
					actualizarQueryActual();
					DvdSiguiente();
				}
			}
			else
			{
				QMessageBox::critical(this, "ERROR BORRAR DVD", "Error borrar dvd.");
			}	
		}
	}
}



void formEditarDesg::DesgloseBorrar( void )
{
	if(ui.comboBoxDesglose->count()>0)
	{
		QMessageBox::StandardButton reply; 
		reply=QMessageBox::question(this, "Borrar", tr("Are you sure you want to completely remove this breakdown? \n"
			"This action can not undo."), 
			QMessageBox::Yes | QMessageBox::No); 

		if(reply==QMessageBox::Yes) 
		{
			int id=extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this);
			QString desglose(ui.comboBoxDesglose->itemText(ui.comboBoxDesglose->currentIndex()));
			if(extras::borrarDesglose(id, desglose, this))
			{
				QMessageBox::information(this, "CORRECTO", "Desglose borrado correctamente.");
				comprobarUsuario(extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this));
				mostrarClientes();
				mostrarDesglose();
				actualizarQueryActual();
				DvdSiguiente();
			}
			else
			{
				QMessageBox::critical(this, "ERROR BORRAR DESGLOSE", "Error borrar ultimo desglose.");
			}	
		}
	}
}


void formEditarDesg::ClienteBorrar( void )
{
	if(ui.comboBox->count()>0)
	{
		QMessageBox::StandardButton reply; 
		reply=QMessageBox::question(this, "Borrar", tr("Are you sure you want to delete this customer? \n"
			"This action can not undo."), 
			QMessageBox::Yes | QMessageBox::No); 

		if(reply==QMessageBox::Yes) 
		{
			QSqlQuery query;
			query.prepare("DELETE FROM desglose "
				"WHERE id_cliente=:idcliente");
			query.bindValue(":idcliente", extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this));

			if(query.exec())
			{
				QMessageBox::information(this, "CORRECTO", "Cliente eliminado correctamente.");
				comprobarUsuario(extras::getIdCliente(ui.comboBox->itemText(ui.comboBox->currentIndex()), this));
				mostrarClientes();
				mostrarDesglose();
				actualizarQueryActual();
				DvdSiguiente();
			}
			else
			{
				QMessageBox::critical(this, "ERROR BORRAR CLIENTE", query.lastError().text());
			}	
		}
	}
}



