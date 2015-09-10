/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formNuevoDesg
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para buscar un nuevo desglose
----------------------------------------------------------------------------------------------------*/


#include "StdAfx.h"
#include "formbuscardesg.h"
#include "funcionesExtras.h"


/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
FormBuscarDesg::FormBuscarDesg(QWidget *parent)
	:	QDialog(parent)
{
	ui.setupUi(this);

	//this->setFixedSize(302, 215);
	widgetScroll=new QWidget(ui.scrollArea);
	layoutScroll=new QVBoxLayout(widgetScroll);
	layoutScroll->setSpacing(0);
	widgetScroll->setLayout(layoutScroll);
	ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	ui.scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.scrollArea->setWidgetResizable(true);
	ui.scrollArea->setWidget(widgetScroll);

	// Init config
	buscarClientes();
	crearDesgloses();
	marcarTodos();

	// Cargar configuracion
	cargarConfig();

	// Connects
	//connect(ui.comboBoxCliente, SIGNAL(activated(int)), this, SLOT(terminarForm()));
	connect(ui.comboBoxCliente, SIGNAL(activated(int)), this, SLOT(crearDesgloses()));
	connect(ui.checkBoxTodos, SIGNAL(clicked()), this, SLOT(marcarTodos()));
	connect(ui.buttonSalir, SIGNAL(clicked()), this, SLOT(accept()));
}
/*--------------------------------------------------------------------------------------------------*/
FormBuscarDesg::~FormBuscarDesg()
{
	guardarConfig();
}



/*----------------------------------------------------------------------------------------------------
  CARGAR CONFIGURACION
  Cargar datos por defecto, tamaño de la ventana y otra informacion que el usuario modifique
----------------------------------------------------------------------------------------------------*/
void FormBuscarDesg::cargarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	resize(settings.value("buscarDesglose/size", QSize(400, 400)).toSize());
	move(settings.value("buscarDesglose/pos", QPoint(200, 200)).toPoint());
}
/*----------------------------------------------------------------------------------------------------
  GUARDAR CONFIGURACION
  Guarda los datos por defecto, tamaño de la ventana y otra informacion que el usuario modifique
----------------------------------------------------------------------------------------------------*/
void FormBuscarDesg::guardarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	settings.setValue("buscarDesglose/size", size());
	settings.setValue("buscarDesglose/pos", pos());
}




/*----------------------------------------------------------------------------------------------------
  MARCAR TODOS
  Activa o desactiva todos los ChecBox de los desglose del cliente
----------------------------------------------------------------------------------------------------*/
void FormBuscarDesg::marcarTodos( void )
{
	bool marcar=ui.checkBoxTodos->isChecked();
	for(unsigned int i=0; i<listCBox.size(); ++i)
		listCBox[i]->setChecked(marcar);
}




/*----------------------------------------------------------------------------------------------------
  GET NOMBRE CLIENTE
  Devuelve el actual cliente seleccionado del combobx 
  Devolverlo para saber que cliente se ha seleccionado
----------------------------------------------------------------------------------------------------*/
QString FormBuscarDesg::getNombreCliente( void )
{
	QString nombreCliente;
	if(ui.comboBoxCliente->count()>0) 
		nombreCliente=ui.comboBoxCliente->itemText(ui.comboBoxCliente->currentIndex());
	return nombreCliente;
}




/*----------------------------------------------------------------------------------------------------
  GET LISTA DESGLOSES
  Devuelve una lista de nombres con los desgloses seleccionados
----------------------------------------------------------------------------------------------------*/
QStringList FormBuscarDesg::getListaDesglose( void )
{
	QStringList lista;
	for(unsigned int i=0; i<listNombreDesglose.size(); ++i)
	{
		if(listCBox[i]->isChecked())
		{
			lista<<listNombreDesglose[i];
		}
	}

	return lista;
}




/*----------------------------------------------------------------------------------------------------
  BUSCAR CLIENTES
  Rellena el combobox principal con los nombres de los clientes disponibles
----------------------------------------------------------------------------------------------------*/
void FormBuscarDesg::buscarClientes( void )
{
	QSqlQuery query;
	if(!query.exec("SELECT nombre_cliente FROM cliente"))
	{
		QMessageBox::critical(this, "ERROR BUSCAR CLIENTES", query.lastError().text());
	}
	else
	{
		while(query.next()) 
		{
			ui.comboBoxCliente->addItem(query.value(0).toString());
		}
	}
}




/*----------------------------------------------------------------------------------------------------
  CREAR DESGLOSES
  Crea una lista de checkbox con los desgloses del cliente elegido
  Asi el usuario puede elegir que desgloser ver
----------------------------------------------------------------------------------------------------*/
void FormBuscarDesg::crearDesgloses( void )
{
	// Elimina los anteriores para crear los nuevos
	QLayoutItem *child;
	while ((child = layoutScroll->takeAt(0)) != 0){
		delete child->widget(); // delete Layout Item's underlying widget
	}
	listCBox.clear();
	listNombreDesglose.clear();
	
	// Realiza la consulta, muestra los desgloses distintos de un cliente
	int idCliente=extras::getIdCliente(ui.comboBoxCliente->itemText(ui.comboBoxCliente->currentIndex()), this);
	QSqlQuery query;
	query.prepare("SELECT DISTINCT(id_desglose), fecha_desglose FROM desglose "
		"WHERE id_cliente=:idcliente ORDER BY fecha_desglose DESC");
	query.bindValue(":idcliente", idCliente);
	if(!query.exec())
		QMessageBox::critical(this, "ERROR", query.lastError().text());


	while(query.next())
	{
		QDate fecha=QDate::fromString(query.value(1).toString(), "yyyy-MM-dd");

		QCheckBox *cBox=new QCheckBox();
		cBox->setText("Desglose: "+query.value(0).toString()+"     ["+fecha.toString("dd MMM yyyy")+"]");
		cBox->setFixedHeight(25);
		cBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
		cBox->setMinimumSize(200,30);
		layoutScroll->addWidget(cBox);
		listCBox<<cBox;
		listNombreDesglose<<query.value(0).toString();
	}

	QSpacerItem* vertialSpace=new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
	layoutScroll->addSpacerItem(vertialSpace);

	marcarTodos();
}



