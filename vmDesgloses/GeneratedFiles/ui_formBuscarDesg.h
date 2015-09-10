/********************************************************************************
** Form generated from reading UI file 'formBuscarDesg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMBUSCARDESG_H
#define UI_FORMBUSCARDESG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormBuscarDesg
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBoxCliente;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxTodos;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSalir;

    void setupUi(QDialog *FormBuscarDesg)
    {
        if (FormBuscarDesg->objectName().isEmpty())
            FormBuscarDesg->setObjectName(QStringLiteral("FormBuscarDesg"));
        FormBuscarDesg->resize(345, 540);
        gridLayout = new QGridLayout(FormBuscarDesg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(FormBuscarDesg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        comboBoxCliente = new QComboBox(groupBox);
        comboBoxCliente->setObjectName(QStringLiteral("comboBoxCliente"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxCliente->sizePolicy().hasHeightForWidth());
        comboBoxCliente->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBoxCliente);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 305, 428));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxTodos = new QCheckBox(groupBox);
        checkBoxTodos->setObjectName(QStringLiteral("checkBoxTodos"));
        checkBoxTodos->setChecked(true);

        horizontalLayout_2->addWidget(checkBoxTodos);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonSalir = new QPushButton(groupBox);
        buttonSalir->setObjectName(QStringLiteral("buttonSalir"));

        horizontalLayout_2->addWidget(buttonSalir);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(FormBuscarDesg);

        QMetaObject::connectSlotsByName(FormBuscarDesg);
    } // setupUi

    void retranslateUi(QDialog *FormBuscarDesg)
    {
        FormBuscarDesg->setWindowTitle(QApplication::translate("FormBuscarDesg", "Buscar Cliente", 0));
        groupBox->setTitle(QApplication::translate("FormBuscarDesg", "BUSQUEDA CLIENTES", 0));
        label->setText(QApplication::translate("FormBuscarDesg", "Clientes", 0));
        checkBoxTodos->setText(QApplication::translate("FormBuscarDesg", "Seleccionar Todos", 0));
        buttonSalir->setText(QApplication::translate("FormBuscarDesg", "Aceptar", 0));
    } // retranslateUi

};

namespace Ui {
    class FormBuscarDesg: public Ui_FormBuscarDesg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMBUSCARDESG_H
