/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formNuevoDesg
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para editar los desgloses
----------------------------------------------------------------------------------------------------*/


#ifndef __FORMEDITARDESG_H_
#define __FORMEDITARDESG_H_

#include <QtWidgets/QDialog>
#include "ui_formEditarDesg.h"

class formEditarDesg : public QDialog
{
	Q_OBJECT

public:
	formEditarDesg(QWidget *parent=0);
	~formEditarDesg();

protected:
	virtual void keyPressEvent(QKeyEvent *event);

private slots:
	void cambiarCliente(void);
	void cambiarDesglose(void);
	void DvdSiguiente(void);
	void DvdAnterior(void);
	void DvdModificar(void);
	void DvdBorrar(void);
	void DesgloseBorrar(void);
	void ClienteBorrar(void);

private:
	void mostrarClientes(void);
	void mostrarDesglose(void);
	void actualizarQueryActual(void);
	void comprobarUsuario( int idCliente );

	Ui::FormEditarDesg ui;
	QSqlQuery queryDvdActual;
};


#endif // FORMEDITARDESGLOSE_H
