/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:42
	file base:	funcionesExtras
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Funciones auxiliares
----------------------------------------------------------------------------------------------------*/


#ifndef __FUNCIONESEXTRAS_H_
#define __FUNCIONESEXTRAS_H_

namespace extras
{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		// CONEXION BASE DE DATOS (QMYSQL)
		bool crearDBvmdesglose( QWidget* parent );
		bool conectarBBDD( QWidget* parent, bool mostrarError=true );

		struct InfoBBDD { QString user; QString password; unsigned int port; QString host; };
		InfoBBDD* cargarConfigBBDD();
		void guardarConfigBBDD(InfoBBDD* infoBBDD);

		/////////////////////////////////////////////////////////////////////////////////////////////////
		// CREAR TABLAS BASE DE DATOS
		bool crearDBTablas( QWidget* parent );	
		bool crearDesgloseTablaCliente(QWidget* parent );
		bool crearDesgloseTablaDesgloses(QWidget* parent);


		/////////////////////////////////////////////////////////////////////////////////////////////////
		// FUNCIONES BASE DE DATOS
		int getIdCliente( const QString& nombreCliente, QWidget* parent );
		void insertarCliente( const QString& nombreCliente, QWidget* parent );
		QDate getFecha( int idCliente, const QString& idDesglose, QWidget* parent);
		QString getCotizacion( int idCliente, const QString& idDesglose, QWidget* parent );
		QString getAlbaran( int idCliente, const QString& idDesglose, QWidget* parent );
		QString getRefNota( int idCliente, const QString& idDesglose, QWidget* parent );
		int getNumeroDesgloses( int idCliente, QWidget* parent);
		bool borrarDVD( int idAuxDesglose );
		void borrarCliente( int idCliente, QWidget* parent );
		bool borrarDesglose( int idCliente, const QString& idDesglose, QWidget* parent );
		void borrarClientesVacio( QWidget* parent );
		QStringList getNombreClientes( QWidget* parent );
		QStringList getDesgloses( int idCliente, QWidget* parent );
		QStringList getDVD( int idcliente, const QString& iddesglose, QWidget* parent );



		/////////////////////////////////////////////////////////////////////////////////////////////////
		// OPERACION CON SUMATORIOS
		double getSumaColumna( unsigned int idCliente, const QStringList listaDesglose, 
			const QString& nomColumna, QWidget* parent );
		double getSumaBeneficioPor(unsigned int idCliente, const QStringList listaDesglose, QWidget* parent);




		/////////////////////////////////////////////////////////////////////////////////////////////////
		// FUNCIONES DE IMPRESION
		int impDesgloseContarPag( QList<QTableWidget* > tablas, unsigned int maxFilas );

		void impDesgloseCabecera( 
			QPrinter& printer, QPainter& painter, int& alturaActual, 
			const QString& textoCabecera, const QString& textoAlbaran, int pagActual, int numPaginaTotal, 
			const QString& rotuloTabla, QTableWidget* tabla );

		void impDesgloseTabla( 
			QPrinter& printer, QPainter& painter, int& alturaActual, int filasMax,
			const QString& textoCabecera, const QString& textoAlbaran, int& pagActual, int numPaginaTotal, 
			const QString& rotuloTabla, QTableWidget* tabla );




		/////////////////////////////////////////////////////////////////////////////////////////////////
		// FUNCIONES CON NUMEROS
		bool esNumero( const QString& cad );
		void numeroEuropeo(QString& cadena);
		inline QString formatearNumero(double num, unsigned int numDecimales=2)
			{return QString("%L1").arg(num, 0, 'f', numDecimales, '0');}


		/////////////////////////////////////////////////////////////////////////////////////////////////
		// FUNCIONES CON CADENAS DE TEXTO
		void convertirCMD(QString& cadena);


		/////////////////////////////////////////////////////////////////////////////////////////////////
		// FUNCIONES
		QMessageBox* crearMensajeEspera(QWidget* parent, const QString& titulo, const QString& mensaje);
};

#endif



