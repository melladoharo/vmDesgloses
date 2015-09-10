/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:42
	file base:	funcionesExtras
	file ext:	cpp
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Funciones auxiliares
----------------------------------------------------------------------------------------------------*/

#include "stdafx.h"
#include "simpleCrypt.h"
#include "funcionesExtras.h"

namespace extras
{
	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
						        C O N E X T I O N   B A S E   D E    D A T O S
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------------------------
	// Method:		cargarConfigBBDD
	//				Carga la informacion de los parametros para realizar la conexion con la BBDD,
	//				usuario, contraseña, puerto, y dominio.
	//				La contraseña esta encriptada para evitar guardarla en el registro directamente.
	//				
	// Returns:		mInfoBBDD* || Estructura almacenmiento de informacion de la BBDD
	----------------------------------------------------------------------------------------------------*/
	InfoBBDD* cargarConfigBBDD()
	{
		InfoBBDD* infoBBDD=NULL;
		infoBBDD=new InfoBBDD;

		if(infoBBDD!=NULL)
		{
			SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
			QSettings settings("VanessMark", "vmDesglose");
			infoBBDD->user=settings.value("BBDD/user").toString();
			infoBBDD->password=crypto.decryptToString(settings.value("BBDD/password").toString());
			infoBBDD->port=settings.value("BBDD/puerto").toInt();
			infoBBDD->host=settings.value("BBDD/host").toString();

			if(infoBBDD->user.isEmpty())			infoBBDD->user="postgres";
			if(infoBBDD->password.isEmpty())		infoBBDD->password="1234";
			if(infoBBDD->port==0)				infoBBDD->port=5432;
			if(infoBBDD->host.isEmpty())			infoBBDD->host="localhost";
		}

		return infoBBDD;
	}

	/*----------------------------------------------------------------------------------------------------
	// Method:		guardarConfigBBDD
	//				Guarda la informacion de los parametros para realizar la conexion con la BBDD,
	//				usuario, contraseña, puerto, y dominio.
	//				La contraseña esta encriptada para evitar guardarla en el registro directamente.
	// Returns:		void
	----------------------------------------------------------------------------------------------------*/
	void guardarConfigBBDD(InfoBBDD* infoBBDD)
	{
		if(infoBBDD!=NULL)
		{
			SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
			QSettings settings("VanessMark", "vmDesglose");
			settings.setValue("BBDD/user", infoBBDD->user);
			settings.setValue("BBDD/password", crypto.encryptToString(infoBBDD->password));
			settings.setValue("BBDD/puerto", infoBBDD->port);
			settings.setValue("BBDD/host", infoBBDD->host);
		}
	}
	




	/*----------------------------------------------------------------------------------------------------
	// Method:		conectarBBDD
	//				Conecta con la base de datos. Si no conecta, el objeto QSqlDatabase estara cerrado 
	//				(db.close), y el resto de acciones del programa no funcionan.
	// Parameter:	QWidget * parent	-- Ventana padre que llama a la funcion.
	// Parameter:	bool mostrarError	-- Muestra o no el mensaje de error [si lo hay]
	// Returns:		bool				-- True si la conexion es satisfactoria. False en cualquier otro caso.
	----------------------------------------------------------------------------------------------------*/
	bool conectarBBDD( QWidget* parent, bool mostrarError )
	{
		QSqlDatabase db=QSqlDatabase::database();
		if(db.isOpen())
		{
			db.removeDatabase(db.connectionName());
			db.close();
		}

		InfoBBDD* infoBBDD=cargarConfigBBDD();
		if(infoBBDD!=NULL)
		{
			db=QSqlDatabase::addDatabase("QPSQL");
			db.setHostName(infoBBDD->host);
			db.setUserName(infoBBDD->user);
			db.setPassword(infoBBDD->password);
			db.setPort(infoBBDD->port);
			db.setDatabaseName("db_vmdesglose");
			delete infoBBDD;
			if (!db.open()) 
			{ 
				if(mostrarError)
					QMessageBox::critical(parent, "Abrir bbdd. Error al abrir la base de datos", db.lastError().text());
				db.removeDatabase(db.connectionName());
				db.close();
				return false;
			} 
			return true;
		}
		
		QMessageBox::critical(parent, "Cargar Config", "Error al cargar la informacion de la BBDD");
		return false;
	}




	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
						  C R E A R   T A B L A S    D E   B A S E   D E   D A T O S
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------------------------
	  CREAR BASE DE DATOS VM_DESGLOSES
	  Crea la base de datos db_vmdesglose. Previamente borra cualquier base de datos que coincida 
	  con ese nombre. Usar con responsabilidad, una vez se borre la base de datos, toda la informacion
	  guardada en la misma tambien sera borrada.
	----------------------------------------------------------------------------------------------------*/
	bool crearDBvmdesglose( QWidget* parent )
	{
		QSqlDatabase db=QSqlDatabase::database();
		if(db.isOpen())
		{
			db.removeDatabase(db.connectionName());
			db.close();
		}


		InfoBBDD* infoBBDD=cargarConfigBBDD();
		if(infoBBDD!=NULL)
		{
			db=QSqlDatabase::addDatabase("QPSQL");
			db.setHostName(infoBBDD->host);
			db.setUserName(infoBBDD->user);
			db.setPassword(infoBBDD->password);
			db.setPort(infoBBDD->port);
			delete infoBBDD;
			if(db.open())
			{
				QSqlQuery query;
				if(!query.exec("DROP DATABASE IF EXISTS db_vmdesglose"))
				{
					QMessageBox::critical(parent, "Destruir base", "Error DROP DATABASE "+query.lastError().text());
					db.removeDatabase(db.connectionName());
					db.close();
					return false;
				}
				query.finish();
				if(!query.exec("CREATE DATABASE db_vmdesglose"))
				{
					QMessageBox::critical(parent, "Destruir base", "Error CREATE DATABASE "+query.lastError().text());
					db.removeDatabase(db.connectionName());
					db.close();
					return false;
				}
				db.removeDatabase(db.connectionName());
				db.close();
				return true;
			}
			QMessageBox::critical(parent, "Crear base. Error al abrir la base de datos", db.lastError().text());
			return false;
		}

		QMessageBox::critical(parent, "Cargar Config", "Error al cargar la informacion de la BBDD");
		return false;
	}


	/*----------------------------------------------------------------------------------------------------
	  COMPROBAR TABLAS BBDD
	  Comprueba que las tablas necesarias para el correcto funcionamiento del programa estan creadas.
	  Si no estan creadas, las crea.
	----------------------------------------------------------------------------------------------------*/
	bool crearDBTablas(QWidget* parent)
	{
		if(!extras::crearDesgloseTablaCliente(parent) ||
		   !extras::crearDesgloseTablaDesgloses(parent))
				return false;

		return true;
	}

	/*----------------------------------------------------------------------------------------------------
	  TABLA DE LOS CLIENTES
	  Tabla que guarda la informacion de los clientes.
	----------------------------------------------------------------------------------------------------*/
	bool crearDesgloseTablaCliente(QWidget* parent)
	{
		QSqlQuery query;
		if(query.exec("CREATE TABLE cliente"
			"("
			"id_cliente serial NOT NULL,"
			"nombre_cliente character varying(64) NOT NULL,"
			"CONSTRAINT pk_tabla_cliente PRIMARY KEY (id_cliente)"
			");"))
		return true;

		QMessageBox::critical(parent, "Crear tabla cliente", query.lastError().text());
		return false;
	}

	/*----------------------------------------------------------------------------------------------------
	  TABLA DE LOS DESGLOSES
	  Aqui se guarda la informacion de los desgloses. Para calcular los campos restantes con la maxima
	  precision (NUMERIC), las operaciones se hacen con un disparador en la base de datos. Cada vez
	  que se inserta una nueva fila, el disparador completa el resto de campos automaticamente.
	----------------------------------------------------------------------------------------------------*/
	bool crearDesgloseTablaDesgloses(QWidget* parent)
	{
		// Funcion-Disparador
		QSqlQuery query;
		if(!query.exec("CREATE OR REPLACE FUNCTION tf_completar_desglose() RETURNS trigger AS $BODY$\n"
			"DECLARE\n"
				"aux_costo_euro NUMERIC(25, 15) := NEW.pcosto_dollar / NEW.cotizacion;\n"
				"aux_total_costo NUMERIC(25, 15) := aux_costo_euro * NEW.cts_desglose;\n"
				"aux_total_venta NUMERIC(25, 15) := NEW.pventa_euro * NEW.cts_desglose;\n"
				"aux_beneficio NUMERIC(25, 15) := aux_total_venta - aux_total_costo;\n"
				"aux_beneficio_por NUMERIC(25, 15) := (aux_beneficio / aux_total_venta) * 100;\n"

			"BEGIN\n"
				"NEW.pcosto_euro=aux_costo_euro;\n"
				"NEW.total_costo=aux_total_costo;\n"
				"NEW.total_venta=aux_total_venta;\n"
				"NEW.beneficio=aux_beneficio;\n"
				"NEW.beneficio_porcentaje=aux_beneficio_por;\n"
				"RETURN NEW;\n"

			"END;\n"
			"$BODY$\n"
			"LANGUAGE plpgsql VOLATILE\n"
			"COST 100;"))
		{
			QMessageBox::critical(parent, "Crear tf_completar_desglose", query.lastError().text());
			return false;
		}


		// Tabla-desglose
		query.finish();
		if(!query.exec("CREATE TABLE desglose"
			"("
			"id_aux_desglose serial NOT NULL,"
			"id_cliente integer NOT NULL,"
			"id_desglose character varying(32) NOT NULL,"
			"id_dvd character varying(32) NOT NULL,"
			"mm_desglose character varying(32) NOT NULL,"
			"fecha_desglose date NOT NULL,"
			"ref_nota character varying(50),"
			"alb_nota character varying(130),"
			"cts_desglose numeric(6,4) NOT NULL,"
			"pcosto_dollar numeric(10,2) NOT NULL,"
			"pcosto_euro numeric(25,15),"
			"cotizacion numeric(3,2) NOT NULL,"
			"total_costo numeric(25,15),"
			"pventa_euro numeric(10,2) NOT NULL,"
			"total_venta numeric(25,15),"
			"beneficio numeric(25,15),"
			"beneficio_porcentaje numeric(25,15),"
			"CONSTRAINT pk_tabla_desglose PRIMARY KEY (id_aux_desglose)"
			")"))
		{
			QMessageBox::critical(parent, "Crear tabla desglose", query.lastError().text());
			return false;
		}

		// Disparador-tabla-desglose
		query.finish();
		if(!query.exec("CREATE TRIGGER nt_insert_desglose\n"
			"BEFORE INSERT\n"
			"ON desglose\n"
			"FOR EACH ROW\n"
			"EXECUTE PROCEDURE tf_completar_desglose();"
			))
		{
			QMessageBox::critical(parent, "TRIGGER nt_insert_desglose", query.lastError().text());
			return false;
		}

		// Disparador-tabla-desglose
		query.finish();
		if(!query.exec("CREATE TRIGGER nt_update_desglose\n"
			"BEFORE UPDATE\n"
			"ON desglose\n"
			"FOR EACH ROW\n"
			"EXECUTE PROCEDURE tf_completar_desglose();"
			))
		{
			QMessageBox::critical(parent, "TRIGGER nt_update_desglose", query.lastError().text());
			return false;
		}

		return true;
	}






	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
						C O N S U L T A S   P A R A   L A   B A S E   D E   D A T O S
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/
	
	int getIdCliente( const QString& nombreCliente, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT id_cliente FROM cliente WHERE nombre_cliente=:nombre");
		query.bindValue(":nombre", nombreCliente);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR", query.lastError().text());
		query.next();

		return query.value(0).toInt();
	}

	void insertarCliente( const QString& nombreCliente, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("INSERT INTO cliente (nombre_cliente) VALUES (:nombre)");
		query.bindValue(":nombre", nombreCliente);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR", query.lastError().text());
	}


	QString getCotizacion( int idCliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT cotizacion FROM desglose "
			"WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		query.bindValue(":idcliente", idCliente);
		query.bindValue(":idDesglose", idDesglose);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR", query.lastError().text());

		query.next();
		return query.value(0).toString();
	}


	QDate getFecha( int idCliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT fecha_desglose FROM desglose "
			"WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		query.bindValue(":idcliente", idCliente);
		query.bindValue(":idDesglose", idDesglose);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR", query.lastError().text());
		query.next();

		QDate fecha=QDate::fromString(query.value(0).toString(), "yyyy-MM-dd");
		return fecha;
	}



	QString getAlbaran( int idCliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT alb_Nota FROM desglose WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		query.bindValue(":idcliente", idCliente);
		query.bindValue(":idDesglose", idDesglose);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR GET ALBARAN", query.lastError().text());

		QString albaran;
		while(query.next())
		{
			if(query.value(0).toString().size()>0)
				albaran=query.value(0).toString();
		}
		return albaran;
	}


	/*----------------------------------------------------------------------------------------------------
	  GET REFERENCIA NOTA
	  Devuelve la ultima nota introducida.
	----------------------------------------------------------------------------------------------------*/
	QString getRefNota( int idCliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT ref_nota FROM desglose WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		query.bindValue(":idcliente", idCliente);
		query.bindValue(":idDesglose", idDesglose);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR GET REF_NOTA", query.lastError().text());
		
		query.last();

		return query.value(0).toString();
	}


	QStringList getNombreClientes( QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaNombre;

		query.prepare("SELECT nombre_cliente FROM cliente");
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR", query.lastError().text());
		
		while(query.next())
		{
			listaNombre<<query.value(0).toString();
		}

		return listaNombre;
	}



	QStringList getDesgloses( int idCliente, QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaDesglose;
		query.prepare("SELECT DISTINCT(id_desglose) FROM desglose "
			"WHERE id_cliente=:idcliente ORDER BY fecha_desglose");
		query.bindValue(":idcliente", idCliente);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR GET DESGLOSES", query.lastError().text());

		while(query.next())
			listaDesglose<<query.value(0).toString();

		return listaDesglose;
	}

	QStringList getDVD( int idcliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaDVD;
		query.prepare("SELECT id_dvd FROM desglose "
			"WHERE id_cliente=:idcliente AND id_desglose=:idDesglose");
		query.bindValue(":idcliente", idcliente);
		query.bindValue(":idDesglose", idDesglose);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR GET DESGLOSES", query.lastError().text());

		while(query.next())
			listaDVD<<query.value(0).toString();

		return listaDVD;
	}


	int getNumeroDesgloses( int idCliente, QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaDVD;
		query.prepare("SELECT COUNT(DISTINCT(id_desglose)) FROM desglose WHERE id_cliente=:idcliente");
		query.bindValue(":idcliente", idCliente);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR GET NUMERO DESGLOSES", query.lastError().text());

		query.next();
		return query.value(0).toInt();
	}


	void borrarCliente( int idCliente, QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaDVD;
		query.prepare("DELETE FROM cliente WHERE id_cliente=:idcliente");
		query.bindValue(":idcliente", idCliente);
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR BORRAR CLIENTE", query.lastError().text());
	}


	bool borrarDVD( int idAuxDesglose )
	{
		QSqlQuery query;
		query.prepare("DELETE FROM desglose WHERE id_aux_desglose=:id");
		query.bindValue(":id", idAuxDesglose);

		return query.exec();
	}


	bool borrarDesglose( int idCliente, const QString& idDesglose, QWidget* parent )
	{
		QSqlQuery query;
		QStringList listaDVD;
		query.prepare("DELETE FROM desglose WHERE id_cliente=:idcliente AND id_desglose=:iddesglose");
		query.bindValue(":idcliente", idCliente);
		query.bindValue(":iddesglose", idDesglose);
		return query.exec();
	}


	void borrarClientesVacio( QWidget* parent )
	{
		QSqlQuery query;
		query.prepare("SELECT id_cliente FROM cliente");
		if(!query.exec())
			QMessageBox::critical(parent, "ERROR BORRAR CLIENTES VACIO", query.lastError().text());
		
		while(query.next())
		{
			if(getNumeroDesgloses(query.value(0).toInt(), parent)==0)
			{
				borrarCliente(query.value(0).toInt(), parent);
			}
		}
	}


	/*----------------------------------------------------------------------------------------------------
	  GET SUMATORIO COLUMNA
	  Obtiene el sumatorio de una columna de la BBDD. El nombre de la columna la proporciona el usuario.
	  El sumatorio corresponde a los desgloses seleccionados del cliente seleccionado.
	----------------------------------------------------------------------------------------------------*/
	double getSumaColumna( unsigned int idCliente, const QStringList listaDesglose, const QString& nomColumna, QWidget* parent )
	{
		// Prepara la clausula where con los desgloses que se desean sumar
		QString whereStr=" AND id_desglose IN (";
		for(unsigned int i=0; i<listaDesglose.size(); ++i)
		{
			whereStr+="'"+listaDesglose[i]+"'";
			if(i!=listaDesglose.size()-1)
				whereStr+=", ";
		}
		whereStr+=")";

		QSqlQuery query;
		query.prepare("SELECT ROUND(SUM("+nomColumna+"), 2) "
			"FROM desglose "
			"WHERE id_cliente=:idcliente "+whereStr );
		query.bindValue(":idcliente", idCliente);
		
		if(!query.exec())	QMessageBox::critical(parent, "ERROR GET SUMA "+nomColumna, query.lastError().text());
		if(query.next())	return query.value(0).toDouble();

		return 0;
	}



	double getSumaBeneficioPor( unsigned int idCliente, const QStringList listaDesglose, QWidget* parent )
	{		
		QString whereStr=" AND id_desglose IN (";
		for(unsigned int i=0; i<listaDesglose.size(); ++i)
		{
			whereStr+="'"+listaDesglose[i]+"'";
			if(i!=listaDesglose.size()-1)
				whereStr+=", ";
		}
		whereStr+=")";

		QSqlQuery query;
		query.prepare("SELECT ROUND((SUM(beneficio) / SUM(total_venta)) * 100 , 2) "
			"FROM desglose "
			"WHERE id_cliente=:idcliente "+whereStr );
		query.bindValue(":idcliente", idCliente);

		if(!query.exec())	QMessageBox::critical(parent, "ERROR GET SUMA BENEFICIO", query.lastError().text());
		if(query.next())	return query.value(0).toDouble();

		return 0;
	}









	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
								F U N C I O N E S   D E   I M P R E S I O N
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------------------------
	  IMPRIMIR DESGLOSE CABECERA
	  Imprime la cabecera del desglose (nombre del cliente, logotipo y cabecera de la tabla).
	----------------------------------------------------------------------------------------------------*/
	void impDesgloseCabecera( QPrinter& printer, QPainter& painter, int& alturaActual, 
		const QString& textoCabecera,  const QString& textoAlbaran, int pagActual, int numPaginaTotal, 
		const QString& rotuloTabla, QTableWidget* tabla )
	{
		QFont fontNormal("Arial", 10);
		QFont fontNegrita("Arial", 11, QFont::Bold);
		QFont fontCebecera("Arial", 9, QFont::Bold);
		QFont fontAlbaran("Arial", 8, -1, true);

		// Reinicia-Establece la altura actual
		alturaActual=30;

		// Encabezado - "Desglose - Cliente" + Imagen VM
		// Texto
		int anchoPagina=printer.width();
		int altoPagina=printer.height();
		painter.setFont(fontNormal);
		painter.drawText(QRectF(5, 7, anchoPagina/2, 20), textoCabecera);
		// Imagen
		QImage image("./Resources/imagen_VM.png");
		painter.drawImage(QRectF(anchoPagina-102, 0, 102, 23), image, QRectF(0, 0, 512, 116));
		alturaActual+=80;

		// Rotulo informativo nombre del desglose "DESGLOSE 1982/51   -   Feb 12 1230"
		painter.setFont(fontNegrita);
		painter.drawText(QRectF(0, alturaActual, anchoPagina, 20), Qt::AlignCenter, rotuloTabla);
		
		// Ref Albara si existe
		if(!textoAlbaran.isEmpty())
		{
			alturaActual+=35;
			painter.setFont(fontAlbaran);
			painter.drawText(QRectF(0, alturaActual, anchoPagina, 10), Qt::AlignCenter, textoAlbaran);
		}
		alturaActual+=60;

		// Encabezado (headers horizontal) de la tabla
		int sizeColActual=0; // A partir de donde se escribe, de izquierda a derecha
		int sizeColum=printer.width()/tabla->columnCount(); // Tamaño de las columnas
		int heightRow=20; // Tamaño de las filas
		painter.setFont(fontCebecera);
		for(unsigned int i=0; i<tabla->columnCount(); ++i)
		{
			// 3 primeras lineas tipo texto, alineacion a izquierda, el resto numeros a derecha
			int alin=(i<3) ? Qt::AlignLeft : Qt::AlignRight;
			painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow*2), alin,
				tabla->horizontalHeaderItem(i)->text());

			// Ajuste de la columna, la ultima se lleva al final del ancho de la pagina
			if(i==tabla->columnCount()-2)
				sizeColActual=printer.width()-sizeColum;
			else
				sizeColActual+=sizeColum;
		}
		// Linea de separacion del encabezado con el contenido de la tabla
		QPen pen(painter.pen()); // Se cambia el grosor de la linua, un poco mas grueso
		pen.setWidth(1);
		painter.setPen(pen);
		alturaActual+=32;
		sizeColActual=0;
		painter.setFont(fontNegrita);
		painter.drawLine(QLine(0, alturaActual, printer.width(), alturaActual));
		alturaActual+=20;

		// Informacion de las paginas
		painter.setFont(fontNormal);
		int alturaNumPag=printer.height()-30;
		painter.drawText(QRectF(0, alturaNumPag, printer.width(), 20), Qt::AlignCenter, 
			"Pagina  "+QString::number(pagActual)+"  de  "+QString::number(numPaginaTotal));
	}

	/*----------------------------------------------------------------------------------------------------
	  IMPRIMIR DESGLOSE TABLA
	  Imprime el contenido de la tabla. Calcula el ancho de la impresion y lo divide por el numero
	  de columnas de la tabla.
	----------------------------------------------------------------------------------------------------*/
	void impDesgloseTabla( QPrinter& printer, QPainter& painter, int& alturaActual, int filasMax,
		const QString& textoCabecera, const QString& textoAlbaran, int& pagActual, int numPaginaTotal, 
		const QString& rotuloTabla, QTableWidget* tabla )
	{
		QFont fontNegrita("Arial", 11, QFont::Bold);
		QFont fontNormal("Arial", 10);
		QFont fontMenor("Arial", 9);

		int sizeColActual=0; // A partir de donde se escribe, de izquierda a derecha
		int sizeColum=printer.width()/tabla->columnCount(); // Tamaño de las columnas
		int heightRow=20; // Tamaño de las filas
		int filaActual=0;

		// Color rojo cantidades negativas
		QPen penActual(QColor(0, 0, 0), 0, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
		QPen penRojo(QColor(255, 0, 0), 0, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);

		// Contenido de la tabla ("tabla->rowCount()-1" ultima fila con el resumen no nos interesa)
		for(unsigned int i=0; i<tabla->rowCount()-1; ++i)
		{
			for(unsigned int j=0; j<tabla->columnCount(); ++j)
			{
				if(tabla->item(i,j)->text().toDouble()<0)
					painter.setPen(penRojo);

				// Ajusta el tamaño del texto, por si es muy largo. Solo de las 2 primeras columnas, la 3 no hace falta
				painter.setFont(fontNormal);
				if(j<2 && tabla->item(i, j)->text().size()>=10)
					painter.setFont(fontMenor);

				if(j<3)
					painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), 
					Qt::AlignLeft, tabla->item(i, j)->text());
				else	
					painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), 
					Qt::AlignRight, tabla->item(i, j)->text());

				// Ajuste de la columna, la ultima se lleva al final del ancho de la pagina
				if(j==tabla->columnCount()-2)
					sizeColActual=printer.width()-sizeColum;
				else
					sizeColActual+=sizeColum;
			}

			painter.setPen(penActual);
			sizeColActual=0;
			alturaActual+=25;
			filaActual++;
			if(filaActual>=filasMax-1)
			{
				pagActual++;
				filaActual=0;
				printer.newPage();
				impDesgloseCabecera(printer, painter, alturaActual, textoCabecera, textoAlbaran,
					pagActual, numPaginaTotal, rotuloTabla, tabla);
			}
		}

		painter.setPen(penActual);
		// Ultima a fila, a mano
		int ultFila=tabla->rowCount()-1;
		alturaActual+=5;

		painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum*3, heightRow), Qt::AlignCenter,
			tabla->item(ultFila, 0)->text());
		sizeColActual+=sizeColum*3;

		painter.setFont(fontNegrita);
		painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), Qt::AlignRight,
			tabla->item(ultFila, 3)->text());
		sizeColActual+=sizeColum*5;

		if(tabla->item(ultFila, 8)->text().toDouble()<0)
			painter.setPen(penRojo);
		painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), Qt::AlignRight,
			tabla->item(ultFila, 8)->text());
		sizeColActual+=sizeColum;
		painter.setPen(penActual);

		if(tabla->item(ultFila, 9)->text().toDouble()<0)
			painter.setPen(penRojo);
		painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), Qt::AlignRight,
			tabla->item(ultFila, 9)->text());
		sizeColActual=printer.width()-sizeColum;
		painter.setPen(penActual);

		if(tabla->item(ultFila, 10)->text().toDouble()<0)
			painter.setPen(penRojo);
		painter.drawText(QRectF(sizeColActual, alturaActual, sizeColum, heightRow), Qt::AlignRight,
			tabla->item(ultFila, 10)->text());
		painter.setPen(penActual);
	}

	/*----------------------------------------------------------------------------------------------------
	  IMPRIMIR DESGLOSE CONTADOR DE PAGINAS
	  Calcula cuantas paginas va a necesitar para imprimir todas las tablas. maxFilas equivale 
	  al numero maximo de filas que puede imprimir en cada hoja. Cuando supera ese limite se la 
	  tabla se corta y se sigue imprimiendo en la siguiente hoja
	----------------------------------------------------------------------------------------------------*/
	int impDesgloseContarPag( QList<QTableWidget* > tablas, unsigned int maxFilas )
	{
		int contPag=0;
		int contFilas=0;

		for(unsigned int i=0; i<tablas.size(); ++i)
		{
			contPag++; // Pagina por tabla
			contFilas=0;
			// Se le quita la ultima fila, que es la del resumen "tablas[i]->rowCount()-1"
			for(unsigned int j=0; j<tablas[i]->rowCount()-1; ++j)
			{
				contFilas++;
				if(contFilas>=maxFilas-1) // Tabla cortadas en varias paginas
				{
					contFilas=0;
					contPag++;
				}
			}
		}

		return contPag;
	}





	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
								F U N C I O N E S   C O N   N U M E R O S
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	bool esNumero( const QString& cad )
	{
		bool ok;
		float value = cad.toFloat(&ok);
		if(ok)	return true;
		return false;
	}

	void numeroEuropeo( QString& cadena )
	{
		for(unsigned int i=0; i<cadena.size(); ++i)
		{
			if(cadena[i]==',') cadena[i]='.';
			else if(cadena[i]=='.') cadena[i]=',';
		}
	}





	/*----------------------------------------------------------------------------------------------------
	  --------------------------------------------------------------------------------------------------
							F U N C I O N E S   C O N   C A D E N A S   D E   T E X T O
	  --------------------------------------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	/* Prepara una cadena para que sea compatible con el terminal CMD. Este terminal no admite 
	 * espacios en blanco para las rutas de los archivos. Se deben usar comillas dobles para evitar
	 * este error. Ejemplo: 
	 * C:/Program Files (x86)/MySQL/MySQL Server 5.5/bin/mysqldump.exe 
	 * C:/"Program Files (x86)"/MySQL/"MySQL Server 5.5"/bin/mysqldump.exe */
	void convertirCMD( QString& cadena )
	{
		// Se separa la cadena en subcadenas, y se inserta las comillas segun sea necesario
		QStringList subCadena=cadena.split("/");
		for(unsigned int i=0; i<subCadena.size(); ++i)
		{
			for(unsigned int j=0; j<subCadena[i].size(); ++j)
			{
				if(subCadena[i][j]==' ')
				{
					subCadena[i].insert(0, "\"");
					subCadena[i].insert(subCadena[i].size(), "\"");
					break;
				}
			}
		}
		
		// Se vuelve a unir las subcadenas para formar la cadena final
		cadena.clear();
		for(unsigned int i=0; i<subCadena.size(); ++i)
		{
			cadena+=subCadena[i];
			if(i!=subCadena.size()-1) cadena+="/";
		}
	}


	QMessageBox* crearMensajeEspera( QWidget* parent, const QString& titulo, const QString& mensaje )
	{
		QMessageBox* msgEspera=new QMessageBox(parent);
		msgEspera->setAttribute(Qt::WA_DeleteOnClose); //makes sure the msgbox is deleted automatically when closed
		msgEspera->setStandardButtons(0);
		msgEspera->setIcon(QMessageBox::Information);
		msgEspera->setWindowTitle(titulo);
		msgEspera->setText(mensaje);
		msgEspera->setModal(false);
		msgEspera->open();
		QCoreApplication::processEvents(); // Para que se dibuje la ventana correctamente [chetazo]

		return msgEspera;
	}
};



