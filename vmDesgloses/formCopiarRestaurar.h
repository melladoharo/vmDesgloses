/*----------------------------------------------------------------------------------------------------
	created:	2013/15/10
	created:	15:10:2013   09:39
	file base:	formCopiarRestaurar.h
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para crear copias de seguridad de la bbdd y restaurar dichas copias
----------------------------------------------------------------------------------------------------*/

#ifndef FORMCOPIARRESTAURAR_H
#define FORMCOPIARRESTAURAR_H

#include <QtWidgets/QDialog>
#include "ui_formCopiarRestaurar.h"

class FormCopiarRestaurar : public QDialog
{
	Q_OBJECT

public:
	FormCopiarRestaurar(QWidget *parent=0);
	~FormCopiarRestaurar();
	
private slots:
	void copiarBBDD(void);
	void restaurarBBDD(void);

private:
	void cargarConfig(void);
	void guardarConfig(void);

	Ui::formCopiarRestaurar ui;	
	QDir ultimaRutaUsada;
	QString userBBDD;
	QString passBBDD;
	QString hostBBDD;
};

#endif // FORMCOPIARRESTAURAR_H



