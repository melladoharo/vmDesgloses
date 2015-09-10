/********************************************************************************
** Form generated from reading UI file 'formConfigBD.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCONFIGBD_H
#define UI_FORMCONFIGBD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formConfigBD
{
public:
    QFrame *line;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditUser;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditPuerto;
    QLineEdit *lineEditHost;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *bttnTest;
    QPushButton *btnnCrearBBDD;

    void setupUi(QDialog *formConfigBD)
    {
        if (formConfigBD->objectName().isEmpty())
            formConfigBD->setObjectName(QStringLiteral("formConfigBD"));
        formConfigBD->resize(322, 266);
        line = new QFrame(formConfigBD);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 210, 321, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(formConfigBD);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 281, 132));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditUser = new QLineEdit(layoutWidget);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));

        verticalLayout_2->addWidget(lineEditUser);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEditPassword);

        lineEditPuerto = new QLineEdit(layoutWidget);
        lineEditPuerto->setObjectName(QStringLiteral("lineEditPuerto"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPuerto->sizePolicy().hasHeightForWidth());
        lineEditPuerto->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lineEditPuerto);

        lineEditHost = new QLineEdit(layoutWidget);
        lineEditHost->setObjectName(QStringLiteral("lineEditHost"));

        verticalLayout_2->addWidget(lineEditHost);


        horizontalLayout->addLayout(verticalLayout_2);

        okButton = new QPushButton(formConfigBD);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(149, 230, 75, 23));
        cancelButton = new QPushButton(formConfigBD);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(230, 230, 75, 23));
        bttnTest = new QPushButton(formConfigBD);
        bttnTest->setObjectName(QStringLiteral("bttnTest"));
        bttnTest->setGeometry(QRect(80, 160, 75, 23));
        btnnCrearBBDD = new QPushButton(formConfigBD);
        btnnCrearBBDD->setObjectName(QStringLiteral("btnnCrearBBDD"));
        btnnCrearBBDD->setGeometry(QRect(160, 160, 75, 23));
        QWidget::setTabOrder(lineEditUser, lineEditPassword);
        QWidget::setTabOrder(lineEditPassword, lineEditPuerto);
        QWidget::setTabOrder(lineEditPuerto, lineEditHost);
        QWidget::setTabOrder(lineEditHost, bttnTest);
        QWidget::setTabOrder(bttnTest, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(formConfigBD);
        QObject::connect(okButton, SIGNAL(clicked()), formConfigBD, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), formConfigBD, SLOT(reject()));

        QMetaObject::connectSlotsByName(formConfigBD);
    } // setupUi

    void retranslateUi(QDialog *formConfigBD)
    {
        formConfigBD->setWindowTitle(QApplication::translate("formConfigBD", "Configurar acceso a BBDD", 0));
        label->setText(QApplication::translate("formConfigBD", "Usuario", 0));
        label_2->setText(QApplication::translate("formConfigBD", "Contrase\303\261a", 0));
        label_3->setText(QApplication::translate("formConfigBD", "Puerto", 0));
        label_5->setText(QApplication::translate("formConfigBD", "Host", 0));
        okButton->setText(QApplication::translate("formConfigBD", "OK", 0));
        cancelButton->setText(QApplication::translate("formConfigBD", "Cancel", 0));
        bttnTest->setText(QApplication::translate("formConfigBD", "Test", 0));
        btnnCrearBBDD->setText(QApplication::translate("formConfigBD", "Crear BBDD", 0));
    } // retranslateUi

};

namespace Ui {
    class formConfigBD: public Ui_formConfigBD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCONFIGBD_H
