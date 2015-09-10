#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	private slots:
		// Slots y nuevos forms (nf)
		void nfAbout(void);
		void nfNuevoDesglose(void);
		void nfBuscarDesglose(void);
		void nfEditarDesglose(void);
		void nfConfigurarBBDD(void);
		void nfCopiarRestaurarBBDD(void);
		void slotBorrarTab(int pos);
		void imprimirDesgloses(void);

private:
	// Funciones varias
	void cargarConfig(void);
	void guardarConfig(void);

	// Creacion de las tablas del cliente seleccionado en la ventana principal
	void actualizarCliente( unsigned int idCliente, const QString& nomCliente, const QStringList listaDesglose );
	QLabel* crearTablaEncabezado(const QString& texto);
	QTableWidget* crearTablaDesglose(int idCliente, const QString& idDesglose);
	QTableWidget* crearTablaResumen( unsigned int idCliente, const QStringList listaDesglose,
		QList<QTableWidget*> listaTablaDesglose );

	Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H
