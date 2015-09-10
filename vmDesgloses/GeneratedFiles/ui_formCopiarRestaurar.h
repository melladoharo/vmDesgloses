/********************************************************************************
** Form generated from reading UI file 'formCopiarRestaurar.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOPIARRESTAURAR_H
#define UI_FORMCOPIARRESTAURAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formCopiarRestaurar
{
public:
    QFrame *line;
    QLabel *labelEstado;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *bttnCopiarBBDD;
    QLabel *label_2;
    QPushButton *bttnRestaurarBBDD;

    void setupUi(QDialog *formCopiarRestaurar)
    {
        if (formCopiarRestaurar->objectName().isEmpty())
            formCopiarRestaurar->setObjectName(QStringLiteral("formCopiarRestaurar"));
        formCopiarRestaurar->resize(262, 171);
        line = new QFrame(formCopiarRestaurar);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 120, 261, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelEstado = new QLabel(formCopiarRestaurar);
        labelEstado->setObjectName(QStringLiteral("labelEstado"));
        labelEstado->setGeometry(QRect(20, 140, 201, 20));
        layoutWidget = new QWidget(formCopiarRestaurar);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 221, 54));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        bttnCopiarBBDD = new QPushButton(layoutWidget);
        bttnCopiarBBDD->setObjectName(QStringLiteral("bttnCopiarBBDD"));

        gridLayout->addWidget(bttnCopiarBBDD, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        bttnRestaurarBBDD = new QPushButton(layoutWidget);
        bttnRestaurarBBDD->setObjectName(QStringLiteral("bttnRestaurarBBDD"));

        gridLayout->addWidget(bttnRestaurarBBDD, 1, 1, 1, 1);


        retranslateUi(formCopiarRestaurar);

        QMetaObject::connectSlotsByName(formCopiarRestaurar);
    } // setupUi

    void retranslateUi(QDialog *formCopiarRestaurar)
    {
        formCopiarRestaurar->setWindowTitle(QApplication::translate("formCopiarRestaurar", "Copias de seguridad", 0));
        labelEstado->setText(QApplication::translate("formCopiarRestaurar", "Elige una opcion", 0));
        label->setText(QApplication::translate("formCopiarRestaurar", "Copia de seguridad", 0));
        bttnCopiarBBDD->setText(QApplication::translate("formCopiarRestaurar", "Copiar", 0));
        label_2->setText(QApplication::translate("formCopiarRestaurar", "Restaurar copia", 0));
        bttnRestaurarBBDD->setText(QApplication::translate("formCopiarRestaurar", "Restaurar", 0));
    } // retranslateUi

};

namespace Ui {
    class formCopiarRestaurar: public Ui_formCopiarRestaurar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOPIARRESTAURAR_H
