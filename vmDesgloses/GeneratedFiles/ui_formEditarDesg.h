/********************************************************************************
** Form generated from reading UI file 'formEditarDesg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEDITARDESG_H
#define UI_FORMEDITARDESG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEditarDesg
{
public:
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *bttnAnterior;
    QPushButton *botonModificarDvd;
    QPushButton *botonBorrarDvd;
    QPushButton *bttnSiguiente;
    QSpacerItem *horizontalSpacer_6;
    QWidget *layoutWidget_01;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_CtsDesglose;
    QLineEdit *lineEdit_CostoDollar;
    QLineEdit *lineEdit_ventaEuro;
    QWidget *layoutWidget_02;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_RefDesglose;
    QLineEdit *lineEdit_MMdesglose;
    QLineEdit *lineEdit_RefNota;
    QGroupBox *groupBox;
    QWidget *layoutWidget_03;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_12;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QPushButton *botonBorrarCliente;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_04;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QLineEdit *lineEdit_Albaran;
    QWidget *layoutWidget_05;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxDesglose;
    QPushButton *botonBorrarDesglose;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_DollarEuro;
    QWidget *layoutWidget_06;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;

    void setupUi(QDialog *FormEditarDesg)
    {
        if (FormEditarDesg->objectName().isEmpty())
            FormEditarDesg->setObjectName(QStringLiteral("FormEditarDesg"));
        FormEditarDesg->resize(626, 371);
        groupBox_3 = new QGroupBox(FormEditarDesg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 180, 601, 151));
        groupBox_3->setFlat(false);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 110, 414, 27));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        bttnAnterior = new QPushButton(layoutWidget);
        bttnAnterior->setObjectName(QStringLiteral("bttnAnterior"));
        bttnAnterior->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_18->addWidget(bttnAnterior);

        botonModificarDvd = new QPushButton(layoutWidget);
        botonModificarDvd->setObjectName(QStringLiteral("botonModificarDvd"));
        botonModificarDvd->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_18->addWidget(botonModificarDvd);

        botonBorrarDvd = new QPushButton(layoutWidget);
        botonBorrarDvd->setObjectName(QStringLiteral("botonBorrarDvd"));
        botonBorrarDvd->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(botonBorrarDvd->sizePolicy().hasHeightForWidth());
        botonBorrarDvd->setSizePolicy(sizePolicy);
        botonBorrarDvd->setFocusPolicy(Qt::NoFocus);
        botonBorrarDvd->setDefault(true);

        horizontalLayout_18->addWidget(botonBorrarDvd);

        bttnSiguiente = new QPushButton(layoutWidget);
        bttnSiguiente->setObjectName(QStringLiteral("bttnSiguiente"));
        bttnSiguiente->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_18->addWidget(bttnSiguiente);


        horizontalLayout_19->addLayout(horizontalLayout_18);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_6);

        layoutWidget_01 = new QWidget(groupBox_3);
        layoutWidget_01->setObjectName(QStringLiteral("layoutWidget_01"));
        layoutWidget_01->setGeometry(QRect(330, 20, 261, 76));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_01);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_5 = new QLabel(layoutWidget_01);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_7->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_01);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_7->addWidget(label_6);

        label_9 = new QLabel(layoutWidget_01);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_7->addWidget(label_9);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_CtsDesglose = new QLineEdit(layoutWidget_01);
        lineEdit_CtsDesglose->setObjectName(QStringLiteral("lineEdit_CtsDesglose"));

        verticalLayout_4->addWidget(lineEdit_CtsDesglose);

        lineEdit_CostoDollar = new QLineEdit(layoutWidget_01);
        lineEdit_CostoDollar->setObjectName(QStringLiteral("lineEdit_CostoDollar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_CostoDollar->sizePolicy().hasHeightForWidth());
        lineEdit_CostoDollar->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(lineEdit_CostoDollar);

        lineEdit_ventaEuro = new QLineEdit(layoutWidget_01);
        lineEdit_ventaEuro->setObjectName(QStringLiteral("lineEdit_ventaEuro"));

        verticalLayout_4->addWidget(lineEdit_ventaEuro);


        horizontalLayout_4->addLayout(verticalLayout_4);

        layoutWidget_02 = new QWidget(groupBox_3);
        layoutWidget_02->setObjectName(QStringLiteral("layoutWidget_02"));
        layoutWidget_02->setGeometry(QRect(10, 20, 261, 76));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_02);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_2 = new QLabel(layoutWidget_02);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_9->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_02);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_9->addWidget(label_3);

        label_10 = new QLabel(layoutWidget_02);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_9->addWidget(label_10);


        horizontalLayout_7->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lineEdit_RefDesglose = new QLineEdit(layoutWidget_02);
        lineEdit_RefDesglose->setObjectName(QStringLiteral("lineEdit_RefDesglose"));

        verticalLayout_8->addWidget(lineEdit_RefDesglose);

        lineEdit_MMdesglose = new QLineEdit(layoutWidget_02);
        lineEdit_MMdesglose->setObjectName(QStringLiteral("lineEdit_MMdesglose"));

        verticalLayout_8->addWidget(lineEdit_MMdesglose);

        lineEdit_RefNota = new QLineEdit(layoutWidget_02);
        lineEdit_RefNota->setObjectName(QStringLiteral("lineEdit_RefNota"));

        verticalLayout_8->addWidget(lineEdit_RefNota);


        horizontalLayout_7->addLayout(verticalLayout_8);

        groupBox = new QGroupBox(FormEditarDesg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 141));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        layoutWidget_03 = new QWidget(groupBox);
        layoutWidget_03->setObjectName(QStringLiteral("layoutWidget_03"));
        layoutWidget_03->setGeometry(QRect(11, 20, 261, 53));
        horizontalLayout = new QHBoxLayout(layoutWidget_03);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(layoutWidget_03);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_12 = new QLabel(layoutWidget_03);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(layoutWidget_03);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(comboBox);

        botonBorrarCliente = new QPushButton(layoutWidget_03);
        botonBorrarCliente->setObjectName(QStringLiteral("botonBorrarCliente"));
        botonBorrarCliente->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(botonBorrarCliente);


        horizontalLayout->addLayout(verticalLayout);

        groupBox_2 = new QGroupBox(FormEditarDesg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 10, 281, 141));
        layoutWidget_04 = new QWidget(groupBox_2);
        layoutWidget_04->setObjectName(QStringLiteral("layoutWidget_04"));
        layoutWidget_04->setGeometry(QRect(10, 109, 261, 22));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_04);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_04);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setEnabled(false);

        horizontalLayout_14->addWidget(label_11);

        lineEdit_Albaran = new QLineEdit(layoutWidget_04);
        lineEdit_Albaran->setObjectName(QStringLiteral("lineEdit_Albaran"));
        lineEdit_Albaran->setEnabled(false);
        lineEdit_Albaran->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_14->addWidget(lineEdit_Albaran);

        layoutWidget_05 = new QWidget(groupBox_2);
        layoutWidget_05->setObjectName(QStringLiteral("layoutWidget_05"));
        layoutWidget_05->setGeometry(QRect(11, 20, 261, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_05);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(layoutWidget_05);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        label_13 = new QLabel(layoutWidget_05);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_6->addWidget(label_13);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget_05);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(false);

        horizontalLayout_6->addWidget(label_8);

        dateEdit = new QDateEdit(layoutWidget_05);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setEnabled(false);
        dateEdit->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_6->addWidget(dateEdit);


        verticalLayout_6->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBoxDesglose = new QComboBox(layoutWidget_05);
        comboBoxDesglose->setObjectName(QStringLiteral("comboBoxDesglose"));
        sizePolicy1.setHeightForWidth(comboBoxDesglose->sizePolicy().hasHeightForWidth());
        comboBoxDesglose->setSizePolicy(sizePolicy1);
        comboBoxDesglose->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(comboBoxDesglose);

        botonBorrarDesglose = new QPushButton(layoutWidget_05);
        botonBorrarDesglose->setObjectName(QStringLiteral("botonBorrarDesglose"));
        botonBorrarDesglose->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(botonBorrarDesglose);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget_05);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(false);

        horizontalLayout_5->addWidget(label_7);

        lineEdit_DollarEuro = new QLineEdit(layoutWidget_05);
        lineEdit_DollarEuro->setObjectName(QStringLiteral("lineEdit_DollarEuro"));
        lineEdit_DollarEuro->setEnabled(false);
        lineEdit_DollarEuro->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_5->addWidget(lineEdit_DollarEuro);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_2);

        layoutWidget_06 = new QWidget(FormEditarDesg);
        layoutWidget_06->setObjectName(QStringLiteral("layoutWidget_06"));
        layoutWidget_06->setGeometry(QRect(20, 340, 581, 20));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_06);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_06);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(label_14);

        label_15 = new QLabel(layoutWidget_06);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        label_16 = new QLabel(layoutWidget_06);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_3->addWidget(label_16);

        QWidget::setTabOrder(lineEdit_RefDesglose, lineEdit_MMdesglose);
        QWidget::setTabOrder(lineEdit_MMdesglose, lineEdit_RefNota);
        QWidget::setTabOrder(lineEdit_RefNota, lineEdit_CtsDesglose);
        QWidget::setTabOrder(lineEdit_CtsDesglose, lineEdit_CostoDollar);
        QWidget::setTabOrder(lineEdit_CostoDollar, lineEdit_ventaEuro);
        QWidget::setTabOrder(lineEdit_ventaEuro, lineEdit_DollarEuro);
        QWidget::setTabOrder(lineEdit_DollarEuro, lineEdit_Albaran);

        retranslateUi(FormEditarDesg);

        QMetaObject::connectSlotsByName(FormEditarDesg);
    } // setupUi

    void retranslateUi(QDialog *FormEditarDesg)
    {
        FormEditarDesg->setWindowTitle(QApplication::translate("FormEditarDesg", "Editar Desg", 0));
        groupBox_3->setTitle(QApplication::translate("FormEditarDesg", "DESGLOSE", 0));
        bttnAnterior->setText(QApplication::translate("FormEditarDesg", "<<", 0));
        botonModificarDvd->setText(QApplication::translate("FormEditarDesg", "Modificar", 0));
        botonBorrarDvd->setText(QApplication::translate("FormEditarDesg", "Borrar", 0));
        bttnSiguiente->setText(QApplication::translate("FormEditarDesg", ">>", 0));
        label_5->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> Cts. Desglose</p></body></html>", 0));
        label_6->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> P. Costo $      </p></body></html>", 0));
        label_9->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> P. Venta \342\202\254      </p></body></html>", 0));
        label_2->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#da0909;\">[T-N*] </span>Ref. Desglose</p></body></html>", 0));
        label_3->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#da0909;\">[T-N*] </span>MM Desglose </p></body></html>", 0));
        label_10->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#da0909;\">[T-N*] </span>Ref. Nota</p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("FormEditarDesg", "CLIENTES", 0));
        label_4->setText(QApplication::translate("FormEditarDesg", "Clientes Disponibles", 0));
        label_12->setText(QString());
        botonBorrarCliente->setText(QApplication::translate("FormEditarDesg", "Borrar", 0));
        groupBox_2->setTitle(QApplication::translate("FormEditarDesg", "DESGLOSES", 0));
        label_11->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#e80000;\">[T-N]  </span>Albaran</p></body></html>", 0));
        label->setText(QApplication::translate("FormEditarDesg", "Desgloses Disponibles", 0));
        label_13->setText(QString());
        label_8->setText(QApplication::translate("FormEditarDesg", "Fecha", 0));
        botonBorrarDesglose->setText(QApplication::translate("FormEditarDesg", "Borrar", 0));
        label_7->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> Divisa</p></body></html>", 0));
        label_14->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p><span style=\" color:#ec0000;\">[T-N] Texto y n\303\272meros</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p align=\"center\"><span style=\" color:#0000ff;\">[N] Solo n\303\272meros</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("FormEditarDesg", "<html><head/><body><p align=\"right\">[*] Campo obligatorio</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class FormEditarDesg: public Ui_FormEditarDesg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEDITARDESG_H
