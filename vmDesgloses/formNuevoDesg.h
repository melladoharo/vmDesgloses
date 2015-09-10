/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formNuevoDesg
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para introducir un nuevo desglose
----------------------------------------------------------------------------------------------------*/


#ifndef _FORMNUEVODESG_H_
#define _FORMNUEVODESG_H_

#include <QtWidgets/QDialog>
#include "ui_formNuevoDesg.h"

class FormNuevoDesg : public QDialog
{
	Q_OBJECT

public:
	explicit FormNuevoDesg(QWidget *parent=0);
	~FormNuevoDesg(void);

protected:
	virtual void keyPressEvent(QKeyEvent *event);

private slots:
	void comprobarNumero(QWidget *widget);
	void comprobarCadena(QWidget *widget);
	void agregarCliente(void);
	void agregarDesglose(void);
	void terminarDesglose(void);
	void cambiarCliente(void);
	void cambiarDesglose(void);

private:
	void cargarConfig(void);
	void guardarConfig(void);
	void mostrarClientes(void);
	void mostrarDesglose(void);
	void actualizarDesglose(void);

	Ui::FormNuevoDesg ui;
	bool insertarNuevoCliente;
	bool insertarNuevoDesglose;
	int indexActualDesglose;
};

#endif