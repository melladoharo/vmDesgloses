#include "stdafx.h"
#include "MainWindow.h"

#include "stdafx.h"
#include "mainwindow.h"
#include "formNuevoDesg.h"
#include "formBuscarDesg.h"
#include "formEditarDesglose.h"
#include "formConfigBD.h"
#include "formCopiarRestaurar.h"
#include "funcionesExtras.h"

/*----------------------------------------------------------------------------------------------------
  CONSTRUCTOR & DESTRUCTOR
----------------------------------------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent)
	:	QMainWindow(parent)
{
	ui.setupUi(this);

	// Cargar configuracion
	cargarConfig();
	
	// Connects
	connect(ui.actionBarNuevo, SIGNAL(triggered()), this, SLOT(nfNuevoDesglose()));
	connect(ui.actionBarBuscar, SIGNAL(triggered()), this, SLOT(nfBuscarDesglose()));
	connect(ui.actionBarEditar, SIGNAL(triggered()), this, SLOT(nfEditarDesglose()));
	connect(ui.actionBarImprimir, SIGNAL(triggered()), this, SLOT(imprimirDesgloses()));
	connect(ui.actionConfigBD, SIGNAL(triggered()), this, SLOT(nfConfigurarBBDD()));
	connect(ui.actionCopiarRestaurar, SIGNAL(triggered()), this, SLOT(nfCopiarRestaurarBBDD()));
	connect(ui.actionNuevo, SIGNAL(triggered()), this, SLOT(nfNuevoDesglose()));
	connect(ui.actionBuscar, SIGNAL(triggered()), this, SLOT(nfBuscarDesglose()));
	connect(ui.actionEditar, SIGNAL(triggered()), this, SLOT(nfEditarDesglose()));
	connect(ui.actionAcerca, SIGNAL(triggered()), this, SLOT(nfAbout()));
	connect(ui.actionSalir, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(slotBorrarTab(int)));
}
/*--------------------------------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
	// Borra la info de la tabla aux, la de operaciones
	QSqlQuery query("DELETE FROM db_vmDesglose.desglose_aux");
	guardarConfig();
}




/*----------------------------------------------------------------------------------------------------
  CARGAR CONFIGURACION
	Carga la configuracion por defecto. Propiedades de ventana, tamaño posicion, maximizada...
----------------------------------------------------------------------------------------------------*/
void MainWindow::cargarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	resize(settings.value("ventanaPrincipal/size", QSize(400, 400)).toSize());
	move(settings.value("ventanaPrincipal/pos", QPoint(200, 200)).toPoint());
	if(settings.value("ventanaPrincipal/maximizada").toBool())
		this->showMaximized();

	ui.statusBar->showMessage("Configuracion cargada correctamente");
}
/*----------------------------------------------------------------------------------------------------
  GUARDAR CONFIGURACION
	Guarda la configuracion por defecto. Propiedades de ventana, tamaño posicion, maximizada...
----------------------------------------------------------------------------------------------------*/
void MainWindow::guardarConfig( void )
{
	QSettings settings("VanessMark", "vmDesglose");
	settings.setValue("ventanaPrincipal/maximizada", this->isMaximized());
	if(this->isMaximized()) this->showNormal();
	settings.setValue("ventanaPrincipal/size", size());
	settings.setValue("ventanaPrincipal/pos", pos());
}




/*----------------------------------------------------------------------------------------------------
  ACTUALIZAR CLIENTE
	Funcion que muestra las tablas con los desgloses del cliente seleccionado. 
	Recibe el cliente, y la lista de desgloses que se desean imprimir.
	Al final crea tambien una tabla resumen con el sumatorio de los desgloses.
----------------------------------------------------------------------------------------------------*/
void MainWindow::actualizarCliente( unsigned int idCliente, const QString& nomCliente, const QStringList listaDesglose )
{
	// Si el mismo cliente esta abierto(en el tabWidget), lo borra para crearlo de nuevo
	for(unsigned int i=0; i<ui.tabWidget->count(); ++i)
	{
		if(ui.tabWidget->tabText(i)==nomCliente)
			ui.tabWidget->removeTab(i);
	}

	// Nueva pestaña en la pagina principal con el nombre del cliente
	// La nueva pestaña esta formada por un scroll area que muestra todos los desgloses, y un resumen al final
	QWidget *widgetPage=new QWidget();
	QVBoxLayout *layoutPage = new QVBoxLayout(widgetPage);
	QScrollArea* scrollArea = new QScrollArea();

	layoutPage->setSpacing(0); // Sin espacios entre widges, encabezado+tabla
	scrollArea->setWidgetResizable(true); // Necesario para escalar los widgets
	scrollArea->setWidget(widgetPage);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // Barra horizontal siempre presente
	scrollArea->setFrameShape(QFrame::NoFrame); // Sin bordes

	ui.tabWidget->addTab(scrollArea, nomCliente);
	ui.tabWidget->setCurrentIndex(ui.tabWidget->count()-1);
	

	// Lista con las tablas de desglose, necesario para hacer mas tarde los sumatorios
	QList<QTableWidget*> listaTablaDesglose; 

	// Por cada desglose seleccionado, se crea una tabla (tabla=encabezado+tabla+espacio)
	for(unsigned int i=0; i<listaDesglose.size(); ++i)
	{
		// La fecha se completa abajo, cuando tenga el dato de la tabla
		QLabel *lblDesglose=crearTablaEncabezado(" DESGLOSE  "+listaDesglose[i]+ "    -    ");
		layoutPage->addWidget(lblDesglose);

		// Tabla de desglose
		QTableWidget *nuevaTabla=crearTablaDesglose(idCliente, listaDesglose[i]);
		layoutPage->addWidget(nuevaTabla);

		QDate fecha(extras::getFecha(idCliente, listaDesglose[i], this));
		lblDesglose->setText(lblDesglose->text()+ fecha.toString("dd  MMM  yyyy").toUpper());
		
		// Espacio entre tablas
		layoutPage->addSpacing(75);
		QSpacerItem* vertialSpace=new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
		layoutPage->addSpacerItem(vertialSpace);
		
		listaTablaDesglose<<nuevaTabla;
	}

	// Crea la tabla resumen con los sumatorios de los sumatorios, si hay desgloses
	if(listaTablaDesglose.size()>0)
	{
		QLabel *lblDesglose=crearTablaEncabezado(" TOTAL  "+QString(nomCliente).toUpper());
		layoutPage->addWidget(lblDesglose);

		QTableWidget* tablaResumen=crearTablaResumen(idCliente, listaDesglose, listaTablaDesglose);
		layoutPage->addWidget(tablaResumen);

		QSpacerItem* vertialSpace=new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
		layoutPage->addSpacerItem(vertialSpace);
	}
}
/*----------------------------------------------------------------------------------------------------
  CREAR ENCABEZADO TABLA
	Muestra un encabezado encima de las tablas. Por diseño y funcionalidad.
----------------------------------------------------------------------------------------------------*/
QLabel* MainWindow::crearTablaEncabezado( const QString& texto )
{
	// Label-Encabezado de la tabla
	QLabel *lblEncabezado=new QLabel(texto);
	lblEncabezado->setFixedHeight(40);
	lblEncabezado->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

	// Estilo del encabezado, con fondo y con bordes
	QColor colorEncabezado=QColor(220, 220, 235);
	QString estiloEncabezado="background-color: rgb(%1, %2, %3);";
	estiloEncabezado=estiloEncabezado.arg(colorEncabezado.red()).arg(colorEncabezado.green()).arg(colorEncabezado.blue());
	estiloEncabezado+="color: black;";
	estiloEncabezado+="border: 1px solid gray;";
	lblEncabezado->setStyleSheet(estiloEncabezado);

	// Fuente del encabezado, bold
	QFont fontEncabezado("Arial", 12, QFont::Bold);
	lblEncabezado->setFont(fontEncabezado);

	return lblEncabezado;
}
/*----------------------------------------------------------------------------------------------------
  CREAR TABLA DESGLOSE
	Crea una tabla con el desglose seleccionado. Los campos son los de la consulta, y la ultima
	fila contiene el sumatorio de las cifras relevantes.
----------------------------------------------------------------------------------------------------*/
QTableWidget* MainWindow::crearTablaDesglose( int idCliente, const QString& idDesglose )
{
	// Ejecutar consulta, selecciona todos los campos
	QSqlQuery query;
	query.prepare("SELECT id_dvd, ref_nota, mm_desglose, cts_desglose, pcosto_dollar, "
		"pcosto_euro, total_costo, pventa_euro, total_venta, beneficio, beneficio_porcentaje "
		"FROM desglose "
		"WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
	query.bindValue(":idcliente", idCliente);
	query.bindValue(":idDesglose", idDesglose);
	query.exec();

	// Nombre de los encabezados de la tabla
	// Columnas tipo texto 0, 1, 2   ||    TOTAL: 11 Columnas
	QStringList headersLabel;
	headersLabel<<"Referencia\nDesglose" <<"Referencia\nNota" <<"MM\nDesglose" <<"CTS\nDesglose" 
		<<"Valor\nCosto $" <<QString("Valor\nCosto %1").arg(QChar(8364)) 
		<<QString("Total\nCosto $ / %1").arg(QChar(8364)) <<QString("PC. CTE  %1").arg(QChar(8364))
		<<QString("Importe %1").arg(QChar(8364)) <<QString("Beneficio") <<QString("% Beneficio");

	int row=query.size(), column=headersLabel.size();
	QTableWidget *tableWidget=new QTableWidget(row+1, column, this); // row + 1 = fila con los sumatorios
	tableWidget->setFixedHeight(38+(30*(row+1))); // 24=tamaño header | 30=tamaño de las filas
	tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum); // 24*2=38, header en dos filas
	tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableWidget->verticalHeader()->hide();
	tableWidget->setAlternatingRowColors(true);
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	tableWidget->setSortingEnabled(false);
	tableWidget->setHorizontalHeaderLabels(headersLabel);

	// Cambio de letra para la cabecera
	QFont fHeader("Arial", 8);
	tableWidget->horizontalHeader()->setFont(fHeader);

	// Se rellena la tabla con los datos
	int rowActual=0;
	while(query.next()) // filas
	{
		for(unsigned int columAct=0; columAct<column; ++columAct) // columnas
		{
			QTableWidgetItem *newItem = new QTableWidgetItem(); 
			if(columAct<3) // Datos tipo texto (por temas de ordenar)
			{
				newItem->setText(QString(query.value(columAct).toString()));
				newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			}
			else // Datos tipo float (por temas de ordenar)
			{
				// Ajusta bien los decimales, por defecto 2 decimales (xxx.00)
				// Necesario para los CTS que pueden tener 3 o mas decimales (xxx.000)
				int numDecimal=2;
				if(columAct==3) // Columna de los CTS
				{
					QString strDecimal=query.value(columAct).toString();
					if(strDecimal.indexOf(".")!=-1 && strDecimal.right(strDecimal.size()-strDecimal.indexOf(".")).size()==4)
					{
						numDecimal=3;
					}
				}
				newItem->setData(Qt::DisplayRole, extras::formatearNumero(query.value(columAct).toDouble(), numDecimal));
				newItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
			}
			tableWidget->setItem(rowActual, columAct, newItem);

			// Fila entera de color rojo si el beneficio es un numero negativo
			if(columAct==column-1 && query.value(columAct).toDouble()<0)
			{
				for(unsigned int j=0; j<=columAct; ++j)
					tableWidget->item(rowActual, j)->setBackgroundColor(QColor(255, 230, 230));
			}
		}
		rowActual++;
	}
	
	// Crea la ultima fila final con los sumatorios
	QFont ftabla("Arial", 12, QFont::Bold);
	for(unsigned int i=0; i<column; ++i)
	{
		QTableWidgetItem *newItem = new QTableWidgetItem();
		tableWidget->setItem(rowActual, i, newItem);
		newItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		newItem->setBackground(QColor(230,230,230));
		newItem->setFont(ftabla);
	}

	// Rellena los datos de la ultima fila, los sumatorios
	double sumCt=extras::getSumaColumna(idCliente, QStringList(idDesglose), "cts_desglose", this);
	double sumImporte=extras::getSumaColumna(idCliente, QStringList(idDesglose), "total_venta", this);
	double sumBenefio=extras::getSumaColumna(idCliente, QStringList(idDesglose), "beneficio", this);
	double sumBenefioPor=extras::getSumaBeneficioPor(idCliente, QStringList(idDesglose), this);
	QString divisa=extras::getCotizacion(idCliente, idDesglose, this);
	QString notaAlbaran=extras::getAlbaran(idCliente, idDesglose, this);
	QFont fResumen("Arial", 9);
	tableWidget->setSpan(rowActual, 0, 1, 2); // Une las celdas que no se usan
	tableWidget->item(rowActual,0)->setFont(fResumen);
	tableWidget->item(rowActual,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	tableWidget->item(rowActual,0)->setText("DIVISA   "+divisa);
	tableWidget->item(rowActual,3)->setData(Qt::DisplayRole, extras::formatearNumero(sumCt));
	tableWidget->setSpan(rowActual, 4, 1, 4); // Une las celdas que no se usan
	fResumen.setPointSize(8);
	tableWidget->item(rowActual,4)->setFont(fResumen);
	tableWidget->item(rowActual,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	tableWidget->item(rowActual,4)->setText(notaAlbaran);
	tableWidget->item(rowActual,8)->setData(Qt::DisplayRole,  extras::formatearNumero(sumImporte));
	tableWidget->item(rowActual,9)->setData(Qt::DisplayRole, extras::formatearNumero(sumBenefio));
	tableWidget->item(rowActual,10)->setData(Qt::DisplayRole, extras::formatearNumero(sumBenefioPor));
	
	
	//tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	//tableWidget->setFixedWidth(1200);
	//tableWidget->horizontalHeader()->setStretchLastSection(true);
	return tableWidget;
}
/*----------------------------------------------------------------------------------------------------
  CREAR TABLA RESUMEN
	Al final de todas las tablas de desgloses, se crea una tabla con el total de los sumatorios.
	El total corresponde a la suma de los desgloses seleccionados, no a la de todos los desgloses.
----------------------------------------------------------------------------------------------------*/
QTableWidget* MainWindow::crearTablaResumen( unsigned int idCliente, const QStringList listaDesglose, 
	QList<QTableWidget*> listaTablaDesglose )
{
	QTableWidget *tableWidget=new QTableWidget();

	if(listaTablaDesglose.size()>0)
	{
		// Row + 1, el tamaño de la tabla es +1, por la fila resumen
		int row=1;
		int column=listaTablaDesglose[0]->columnCount();

		tableWidget->setRowCount(row);
		tableWidget->setColumnCount(column);
		tableWidget->setFixedHeight(38+(30*(row))); // 24=tamaño header | 30=tamaño de las filas
		tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum); // 24*2=38, header en dos filas
		tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		tableWidget->verticalHeader()->hide();
		tableWidget->setAlternatingRowColors(true);
		tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
		tableWidget->setSortingEnabled(false);

		// Nombre de los encabezados de la tabla
		QStringList headersLabel;
		headersLabel<<"" <<"" <<"" <<"Total CTS\nDesglose" <<"" <<"" <<"" <<""
			<<QObject::tr("Total\nImporte %1").arg(QChar(8364)) 
			<<QObject::tr("Total\nBefencio") 
			<<QObject::tr("Total\n% Beneficio");
		tableWidget->setHorizontalHeaderLabels(headersLabel);

		// Cambio de letra para la cabecera
		QFont fHeader("Arial", 8);
		tableWidget->horizontalHeader()->setFont(fHeader);

		// Unica fila con el sumatorio total del cliente
		QFont ftabla("Arial", 12, QFont::Bold);
		for(unsigned int i=0; i<column; ++i)
		{
			QTableWidgetItem *newItem = new QTableWidgetItem();
			tableWidget->setItem(0, i, newItem);
			newItem->setFont(ftabla);
			newItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
			newItem->setBackground(QColor(230,230,230));
		}

		double sumCtsTotal=extras::getSumaColumna(idCliente, listaDesglose, "cts_desglose", this);
		double sumImporteTotal=extras::getSumaColumna(idCliente, listaDesglose, "total_venta", this);
		double sumBenefioTotal=extras::getSumaColumna(idCliente, listaDesglose, "beneficio", this);
		double sumBenefioPorTotal=extras::getSumaBeneficioPor(idCliente, listaDesglose, this);

		tableWidget->setSpan(0, 0, 1, 2); // Une las celdas que no se usan
		tableWidget->item(0, 3)->setData(Qt::DisplayRole, extras::formatearNumero(sumCtsTotal));
		tableWidget->setSpan(0, 4, 1, 4); // Une las celdas que no se usan
		tableWidget->item(0, 8)->setData(Qt::DisplayRole, extras::formatearNumero(sumImporteTotal));
		tableWidget->item(0, 9)->setData(Qt::DisplayRole, extras::formatearNumero(sumBenefioTotal));
		tableWidget->item(0, 10)->setData(Qt::DisplayRole, extras::formatearNumero(sumBenefioPorTotal));
	}

	return tableWidget;
}





/*----------------------------------------------------------------------------------------------------
  FORM ABOUT
	Muestra un nuevo form con informacion acerca de la aplicacion, el autor etc.
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfAbout( void )
{
	//QMessageBox::about(this, tr("About of Vanessmark Desgloses"), tr("AboutInfo")); 
	
	QMessageBox::about(this, "Acerca de Vanessmark Desgloses", 
		tr("<h2>VanessMark Desgloses 1.0.2</h2>"
		   "<p>Copyright &copy; 2013 Manuel Mellado Haro.<br>"
		   "Todos los derechos reservados."
		   "<p>Vanessmark Desgloses es un programa dedicado a la gestion de los desgloses "
		   "de Vanessmark SL. Permite insertar, buscar, editar e imprimir los desgloses de cada cliente."
		   "<p>Informacion de contacto:<br>" 
		   "Correo: melladoharo@gmail.com"
		   "<p> Este software usa las librerias Qt v5.2.0<br>"
		   "Este software usa PostgreSQL v9.3.1-1"
			));
}
/*----------------------------------------------------------------------------------------------------
  FORM NUEVO DESGLOSE
	Muestra un nuevo form para introducir un nuevo desglose. Tambien se usa para insertan un 
	nuevo cliente. No se pueden editar desde aqui. 
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfNuevoDesglose( void )
{
	QSqlDatabase db=QSqlDatabase::database();
	if(db.isOpen())
	{
		FormNuevoDesg form;
		form.exec();
		ui.statusBar->showMessage("Nuevo desglose finalizado");
	}
	else
	{
		QMessageBox::critical(this, "Error al abrir la base de datos", db.lastError().text());
	}
}
/*----------------------------------------------------------------------------------------------------
  FORM BUSCAR DESGLOSE
	Nuevo form encargado de mostrar los clientes con sus respectivos desgloses. 
	Cada cliente se abrira posteriormente en una pestaña.
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfBuscarDesglose( void )
{
	QSqlDatabase db=QSqlDatabase::database();
	if(db.isOpen())
	{
		FormBuscarDesg form;
		if(form.exec()==QDialog::Accepted)
		{
			ui.statusBar->showMessage("Busqueda completada con exito");
			QString nombreCliente=form.getNombreCliente();
			QStringList listDesglose=form.getListaDesglose();
			if(!listDesglose.empty())
			{
				int idCliente=extras::getIdCliente(nombreCliente, this);
				actualizarCliente(idCliente, nombreCliente, listDesglose);
			}
		}
		else
		{
			ui.statusBar->showMessage("Busqueda de clientes cancelada");
		}
	}
	else
	{
		QMessageBox::critical(this, "Error al abrir la base de datos", db.lastError().text());
	}
}
/*----------------------------------------------------------------------------------------------------
  FORM BUSCAR DESGLOSE
	Form encargado de editar los desgloses. 
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfEditarDesglose( void )
{
	QSqlDatabase db=QSqlDatabase::database();
	if(db.isOpen())
	{
		formEditarDesg form;
		form.exec();
		ui.statusBar->showMessage("Edicion finalizada");
	}
	else
	{
		QMessageBox::critical(this, "Error al abrir la base de datos", db.lastError().text());
	}
}
/*----------------------------------------------------------------------------------------------------
  FORM CONFIGURAR LA BBDD
	Nuevo form donde se pide informacion acerca de la conexion de la base de datos, 
	como usuario, contraseña, puerto y un test para comprobar dichos datos.
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfConfigurarBBDD( void )
{
	FormConfigBD form(this);
	if(form.exec()==QDialog::Accepted)
		ui.statusBar->showMessage("Configuracion base de datos terminada");
	else
		ui.statusBar->showMessage("Configuracion base de datos cancelada");
}
/*----------------------------------------------------------------------------------------------------
  FORM COPIAS DE SEGURIDAD Y RESTAURACION DE LA BBDD
	Nuevo form para crear copias de seguridad de la base de datos, y poder restuarar mas tarde
	dichas copias. 
----------------------------------------------------------------------------------------------------*/
void MainWindow::nfCopiarRestaurarBBDD( void )
{
	QSqlDatabase db=QSqlDatabase::database();
	if(db.isOpen())
	{
		FormCopiarRestaurar form;
		form.exec();
		ui.statusBar->showMessage("Copias y restauracion terminada");
	}
	else
	{
		QMessageBox::critical(this, "Error al abrir la base de datos", db.lastError().text());
	}
}
/*----------------------------------------------------------------------------------------------------
  SLOT BORRAR TAB
	Elimina la pestaña seleccionada del tabwidget
----------------------------------------------------------------------------------------------------*/
void MainWindow::slotBorrarTab( int pos )
{
	ui.tabWidget->removeTab(pos);
}
/*----------------------------------------------------------------------------------------------------
  SLOT IMPRIMIR DESGLOSES
	Imprime los desgloses que se muestran actualmente en la ventana principal. Si hay varias
	pestañas, imprime los desglose de la pestaña que se esta viendo. Ejecuta un dialogo de
	impresion para seleccionar la impresora.
----------------------------------------------------------------------------------------------------*/
void MainWindow::imprimirDesgloses( void )
{
	// Tablas para imprimir, son las que esten en la tab actual
	QWidget *widgetPage=ui.tabWidget->widget(ui.tabWidget->currentIndex());
	QList<QLabel *> allLabel=widgetPage->findChildren<QLabel *>();
	QList<QTableWidget*> allTablas=widgetPage->findChildren<QTableWidget *>();

	if(allTablas.size()>0 && allLabel.size()>0)
	{
		QPrinter printer;

		//printer.setOutputFormat(QPrinter::PdfFormat);
		//printer.setOutputFileName("Salida_PDF.pdf");
		//printer.setPageMargins(15, 10, 15, 10, QPrinter::Millimeter); // Margenes de la impresion
		//printer.setPaperSize(QPrinter::A4);
		//printer.setOrientation(QPrinter::Landscape); // Se imprime en horizontal para una lectura mas comoda

		// Inicia el dialogo de la impresora
		QPrintDialog *dialog = new QPrintDialog(&printer, this); 
		dialog->setWindowTitle("Imprimir desgloses");
		if(dialog->exec() == QDialog::Accepted)
		{
			// Independientemente de la configuracion elegida, aqui se establece la config final
			printer.setPageMargins(15, 10, 15, 10, QPrinter::Millimeter); // Margenes de la impresion
			printer.setPaperSize(QPrinter::A4);
			printer.setOrientation(QPrinter::Landscape);

			QPainter painter;
			painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
			painter.begin(&printer);

			int tamAlturaActual=30; // posicion actual donde esta imprimiendo el texto
			int numMaxFilas=16; // Maximo filas en las tablas por hoja
			int numPaginas=extras::impDesgloseContarPag(allTablas, numMaxFilas); // numero de hojas totales
			int numPagActual=1; // pag actual [Pagina 1 de x]
			QString etiquetaCabecera("Desgloses  -  " + ui.tabWidget->tabText(ui.tabWidget->currentIndex()).toUpper());

			// Solo se ha seleccionado un desglose, entonces no se imprime el total
			if(allTablas.size()<=2)
			{
				numPaginas--;

				QString etiquetaAlbaran(allTablas[0]->item(allTablas[0]->rowCount()-1, 4)->text());

				extras::impDesgloseCabecera(printer, painter, tamAlturaActual, etiquetaCabecera, 
					etiquetaAlbaran, numPagActual, numPaginas, allLabel[0]->text(), allTablas[0]);
				extras::impDesgloseTabla(printer, painter, tamAlturaActual, numMaxFilas, etiquetaCabecera, 
					etiquetaAlbaran, numPagActual, numPaginas, allLabel[0]->text(), allTablas[0]);
			}
			// Mas de un desglose seleccionado, se incluye los totales
			else
			{
				// Por cada tabla, se crea una pagina independiente
				for(unsigned int i=0; i<allTablas.size(); ++i)
				{

					QString etiquetaAlbaran(allTablas[i]->item(allTablas[i]->rowCount()-1, 4)->text());

					extras::impDesgloseCabecera(printer, painter, tamAlturaActual, etiquetaCabecera, 
						etiquetaAlbaran, numPagActual, numPaginas, allLabel[i]->text(), allTablas[i]);
					extras::impDesgloseTabla(printer, painter, tamAlturaActual, numMaxFilas, etiquetaCabecera, 
						etiquetaAlbaran, numPagActual, numPaginas, allLabel[i]->text(), allTablas[i]);

					numPagActual++;

					if(i!=allTablas.size()-1) // No imprimir ultima pagina en blanco
						printer.newPage();
				}
			}

			painter.end();
		}
	}
	else
	{
		QMessageBox::critical(this, "Error impresion", 
			"Debes seleccionar al menos un desglose para poder imprimir. ");
	}
}
