#include "stdafx.h"
#include "MainWindow.h"
#include "funcionesExtras.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	// Idioma español por defecto
	QTranslator tsQtESP, tsAppESP;
	tsQtESP.load("qt_es.qm", app.applicationDirPath());
	tsAppESP.load("vmdesgloses_es.qm", app.applicationDirPath());
	app.installTranslator(&tsQtESP);
	app.installTranslator(&tsAppESP);

	// Pantalla de bienvenida
	QSplashScreen *splash=new QSplashScreen(QPixmap("./Resources/splashScreen.png"));
	splash->show();
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	QColor colorSplash(240, 240, 240);

	// Tiempo desde que se mostro el ultimo mensaje. Sirve pare retrasar el splah screen, 
	// para que se pueda leer el mensaje, si no desparece muy rapido y no se puede leer.
	time_t tUltimoMensaje(time(NULL));
	splash->showMessage("Creando la ventana principal...", topRight, colorSplash);
	while(difftime(time(NULL), tUltimoMensaje)<1.0) { }

	// Conectar a base de datos
	tUltimoMensaje=time(NULL);
	splash->showMessage("Conectando con la base de datos...", topRight, colorSplash);
	extras::conectarBBDD(NULL, false);
	while(difftime(time(NULL), tUltimoMensaje)<0.6) { }

	// Ventana principal programa desgloses
	MainWindow desglosesApp;
	desglosesApp.show();
	splash->finish(&desglosesApp);
	delete splash;

	desglosesApp.show();
	return app.exec();
}
