/*----------------------------------------------------------------------------------------------------
	created:	2013/08/10
	created:	15:9:2013   13:39
	file base:	formConfigBD
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para introducir la contraseña y usuario de la bbdd
----------------------------------------------------------------------------------------------------*/

#ifndef FORMCONFIGBD_H
#define FORMCONFIGBD_H

#include <QtWidgets/QDialog>
#include "ui_formConfigBD.h"

class FormConfigBD : public QDialog
{
	Q_OBJECT

public:
	FormConfigBD(QWidget *parent);
	~FormConfigBD();

	struct ConfDefecto
	{
		QString user;
		QString pass;
		QString port;
		QString host;
	};

private slots:
	void cargarConfig(void);
	void guardarConfig(void);
	void comprobarConexion(void);
	void cancelarForm();
	void crearBBDD();

private:
	bool crearPGPass(); 
	Ui::formConfigBD ui;
};

#endif // FORMCONFIGBD_H
