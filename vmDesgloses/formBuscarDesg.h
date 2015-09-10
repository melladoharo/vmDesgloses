/*----------------------------------------------------------------------------------------------------
	created:	2013/09/15
	created:	15:9:2013   13:39
	file base:	formNuevoDesg
	file ext:	h
	author:		Manuel Mellado Haro
	Copyright(C) 2013 Manuel Mellado Haro. Todos los derechos reservados.
	
	purpose:	Formulario para buscar un nuevo desglose
----------------------------------------------------------------------------------------------------*/

#ifndef __FORMBUSCARDESG_H_
#define __FORMBUSCARDESG_H_

#include <QtWidgets/QDialog>
#include "ui_formBuscarDesg.h"

class FormBuscarDesg : public QDialog
{
	Q_OBJECT

public:
	FormBuscarDesg(QWidget *parent=0);
	~FormBuscarDesg();

	QString getNombreCliente(void);
	QStringList getListaDesglose(void);


private slots:
	void crearDesgloses(void);
	void marcarTodos(void);


private:
	void cargarConfig(void);
	void guardarConfig(void);
	void buscarClientes(void);

	Ui::FormBuscarDesg ui;
	QVBoxLayout *layoutScroll;
	QWidget *widgetScroll;
	QList<QCheckBox*> listCBox;
	QStringList listNombreDesglose;
};

#endif // FORMBUSCARDESG_H



