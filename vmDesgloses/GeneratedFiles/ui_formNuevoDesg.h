/********************************************************************************
** Form generated from reading UI file 'formNuevoDesg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNUEVODESG_H
#define UI_FORMNUEVODESG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNuevoDesg
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QLabel *label_14;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QPushButton *botonNuevo;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelFecha;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxDesglose;
    QPushButton *botonNuevoDesglose;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelDivisa;
    QLineEdit *lineEdit_DollarEuro;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelAlbaran;
    QLineEdit *lineEdit_Albaran;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_01;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_RefDesglose;
    QLineEdit *lineEdit_MMdesglose;
    QLineEdit *lineEdit_RefNota;
    QWidget *layoutWidget_02;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_CtsDesglose;
    QLineEdit *lineEdit_CostoDollar;
    QLineEdit *lineEdit_ventaEuro;
    QWidget *layoutWidget_03;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_16;

    void setupUi(QWidget *FormNuevoDesg)
    {
        if (FormNuevoDesg->objectName().isEmpty())
            FormNuevoDesg->setObjectName(QStringLiteral("FormNuevoDesg"));
        FormNuevoDesg->resize(623, 353);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormNuevoDesg->sizePolicy().hasHeightForWidth());
        FormNuevoDesg->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(FormNuevoDesg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 281, 141));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 20, 261, 53));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_8->addWidget(label_4);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_8->addWidget(label_14);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(comboBox);

        botonNuevo = new QPushButton(layoutWidget);
        botonNuevo->setObjectName(QStringLiteral("botonNuevo"));
        botonNuevo->setEnabled(true);
        botonNuevo->setFocusPolicy(Qt::NoFocus);
        botonNuevo->setAutoDefault(false);
        botonNuevo->setDefault(false);

        verticalLayout->addWidget(botonNuevo);


        horizontalLayout->addLayout(verticalLayout);

        groupBox_2 = new QGroupBox(FormNuevoDesg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 20, 281, 142));
        verticalLayout_10 = new QVBoxLayout(groupBox_2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_9->addWidget(label);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_9->addWidget(label_15);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelFecha = new QLabel(groupBox_2);
        labelFecha->setObjectName(QStringLiteral("labelFecha"));

        horizontalLayout_6->addWidget(labelFecha);

        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_6->addWidget(dateEdit);


        verticalLayout_9->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBoxDesglose = new QComboBox(groupBox_2);
        comboBoxDesglose->setObjectName(QStringLiteral("comboBoxDesglose"));
        sizePolicy1.setHeightForWidth(comboBoxDesglose->sizePolicy().hasHeightForWidth());
        comboBoxDesglose->setSizePolicy(sizePolicy1);
        comboBoxDesglose->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(comboBoxDesglose);

        botonNuevoDesglose = new QPushButton(groupBox_2);
        botonNuevoDesglose->setObjectName(QStringLiteral("botonNuevoDesglose"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(botonNuevoDesglose->sizePolicy().hasHeightForWidth());
        botonNuevoDesglose->setSizePolicy(sizePolicy2);
        botonNuevoDesglose->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(botonNuevoDesglose);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelDivisa = new QLabel(groupBox_2);
        labelDivisa->setObjectName(QStringLiteral("labelDivisa"));

        horizontalLayout_5->addWidget(labelDivisa);

        lineEdit_DollarEuro = new QLineEdit(groupBox_2);
        lineEdit_DollarEuro->setObjectName(QStringLiteral("lineEdit_DollarEuro"));
        lineEdit_DollarEuro->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_5->addWidget(lineEdit_DollarEuro);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_10->addLayout(horizontalLayout_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        labelAlbaran = new QLabel(groupBox_2);
        labelAlbaran->setObjectName(QStringLiteral("labelAlbaran"));

        horizontalLayout_14->addWidget(labelAlbaran);

        lineEdit_Albaran = new QLineEdit(groupBox_2);
        lineEdit_Albaran->setObjectName(QStringLiteral("lineEdit_Albaran"));
        lineEdit_Albaran->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_14->addWidget(lineEdit_Albaran);


        verticalLayout_10->addLayout(horizontalLayout_14);

        groupBox_3 = new QGroupBox(FormNuevoDesg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 190, 601, 111));
        groupBox_3->setFlat(false);
        layoutWidget_01 = new QWidget(groupBox_3);
        layoutWidget_01->setObjectName(QStringLiteral("layoutWidget_01"));
        layoutWidget_01->setGeometry(QRect(11, 21, 261, 81));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_01);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(layoutWidget_01);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::RichText);

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_01);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setTextFormat(Qt::RichText);

        verticalLayout_4->addWidget(label_3);

        label_10 = new QLabel(layoutWidget_01);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setTextFormat(Qt::RichText);

        verticalLayout_4->addWidget(label_10);


        horizontalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_RefDesglose = new QLineEdit(layoutWidget_01);
        lineEdit_RefDesglose->setObjectName(QStringLiteral("lineEdit_RefDesglose"));

        verticalLayout_3->addWidget(lineEdit_RefDesglose);

        lineEdit_MMdesglose = new QLineEdit(layoutWidget_01);
        lineEdit_MMdesglose->setObjectName(QStringLiteral("lineEdit_MMdesglose"));

        verticalLayout_3->addWidget(lineEdit_MMdesglose);

        lineEdit_RefNota = new QLineEdit(layoutWidget_01);
        lineEdit_RefNota->setObjectName(QStringLiteral("lineEdit_RefNota"));

        verticalLayout_3->addWidget(lineEdit_RefNota);


        horizontalLayout_8->addLayout(verticalLayout_3);

        layoutWidget_02 = new QWidget(groupBox_3);
        layoutWidget_02->setObjectName(QStringLiteral("layoutWidget_02"));
        layoutWidget_02->setGeometry(QRect(332, 22, 261, 81));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_02);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_5 = new QLabel(layoutWidget_02);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::RichText);

        verticalLayout_6->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_02);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setTextFormat(Qt::RichText);

        verticalLayout_6->addWidget(label_6);

        label_9 = new QLabel(layoutWidget_02);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setTextFormat(Qt::RichText);

        verticalLayout_6->addWidget(label_9);


        horizontalLayout_9->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_CtsDesglose = new QLineEdit(layoutWidget_02);
        lineEdit_CtsDesglose->setObjectName(QStringLiteral("lineEdit_CtsDesglose"));

        verticalLayout_5->addWidget(lineEdit_CtsDesglose);

        lineEdit_CostoDollar = new QLineEdit(layoutWidget_02);
        lineEdit_CostoDollar->setObjectName(QStringLiteral("lineEdit_CostoDollar"));
        sizePolicy1.setHeightForWidth(lineEdit_CostoDollar->sizePolicy().hasHeightForWidth());
        lineEdit_CostoDollar->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(lineEdit_CostoDollar);

        lineEdit_ventaEuro = new QLineEdit(layoutWidget_02);
        lineEdit_ventaEuro->setObjectName(QStringLiteral("lineEdit_ventaEuro"));

        verticalLayout_5->addWidget(lineEdit_ventaEuro);


        horizontalLayout_9->addLayout(verticalLayout_5);

        layoutWidget_03 = new QWidget(FormNuevoDesg);
        layoutWidget_03->setObjectName(QStringLiteral("layoutWidget_03"));
        layoutWidget_03->setGeometry(QRect(20, 320, 581, 20));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_03);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_03);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(label_12);

        label_13 = new QLabel(layoutWidget_03);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_16 = new QLabel(layoutWidget_03);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_3->addWidget(label_16);

        QWidget::setTabOrder(lineEdit_DollarEuro, lineEdit_Albaran);
        QWidget::setTabOrder(lineEdit_Albaran, lineEdit_RefDesglose);
        QWidget::setTabOrder(lineEdit_RefDesglose, lineEdit_MMdesglose);
        QWidget::setTabOrder(lineEdit_MMdesglose, lineEdit_RefNota);
        QWidget::setTabOrder(lineEdit_RefNota, lineEdit_CtsDesglose);
        QWidget::setTabOrder(lineEdit_CtsDesglose, lineEdit_CostoDollar);
        QWidget::setTabOrder(lineEdit_CostoDollar, lineEdit_ventaEuro);

        retranslateUi(FormNuevoDesg);

        QMetaObject::connectSlotsByName(FormNuevoDesg);
    } // setupUi

    void retranslateUi(QWidget *FormNuevoDesg)
    {
        FormNuevoDesg->setWindowTitle(QApplication::translate("FormNuevoDesg", "Nuevo Desglose", 0));
        groupBox->setTitle(QApplication::translate("FormNuevoDesg", "CLIENTES", 0));
        label_4->setText(QApplication::translate("FormNuevoDesg", "Clientes Disponibles", 0));
        label_14->setText(QString());
        botonNuevo->setText(QApplication::translate("FormNuevoDesg", "A\303\261adir", 0));
        groupBox_2->setTitle(QApplication::translate("FormNuevoDesg", "DESGLOSES", 0));
        label->setText(QApplication::translate("FormNuevoDesg", "Desgloses Disponibles", 0));
        label_15->setText(QString());
        labelFecha->setText(QApplication::translate("FormNuevoDesg", "Fecha", 0));
        botonNuevoDesglose->setText(QApplication::translate("FormNuevoDesg", "A\303\261adir", 0));
        labelDivisa->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> Divisa</p></body></html>", 0));
        labelAlbaran->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#e80000;\">[T-N]</span> Albaran</p></body></html>", 0));
        groupBox_3->setTitle(QApplication::translate("FormNuevoDesg", "DESGLOSE", 0));
        label_2->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#da0909;\">[T-N*] </span>Ref. Desglose</p></body></html>", 0));
        label_3->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#e60000;\">[T-N*]</span> MM Desglose </p></body></html>", 0));
        label_10->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#e20000;\">[T-N*]</span> Ref. Nota </p></body></html>", 0));
        label_5->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> Cts. Desglose</p></body></html>", 0));
        label_6->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> P. Costo $</p></body></html>", 0));
        label_9->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#0000ff;\">[N*]</span> P. Venta \342\202\254 </p></body></html>", 0));
        label_12->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p><span style=\" color:#ec0000;\">[T-N] Texto y n\303\272meros</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p align=\"center\"><span style=\" color:#0000ff;\">[N] Solo n\303\272meros</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("FormNuevoDesg", "<html><head/><body><p align=\"right\">[*] Campo obligatorio</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class FormNuevoDesg: public Ui_FormNuevoDesg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNUEVODESG_H
