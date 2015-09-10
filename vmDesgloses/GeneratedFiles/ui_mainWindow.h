/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionNuevo;
    QAction *actionBuscar;
    QAction *actionBarNuevo;
    QAction *actionAcerca;
    QAction *actionBarBuscar;
    QAction *actionSalir;
    QAction *actionBarEditar;
    QAction *actionBarImprimir;
    QAction *actionConfigBD;
    QAction *actionEditar;
    QAction *actionCopiarRestaurar;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAyuda;
    QMenu *menuConfiguracion;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(655, 505);
        MainWindowClass->setMinimumSize(QSize(600, 450));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/resources/icono_Vanessmark.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        actionNuevo = new QAction(MainWindowClass);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/Resources/icono_Nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuevo->setIcon(icon1);
        actionBuscar = new QAction(MainWindowClass);
        actionBuscar->setObjectName(QStringLiteral("actionBuscar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/icono_Buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuscar->setIcon(icon2);
        actionBarNuevo = new QAction(MainWindowClass);
        actionBarNuevo->setObjectName(QStringLiteral("actionBarNuevo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/resources/icono_Nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarNuevo->setIcon(icon3);
        actionAcerca = new QAction(MainWindowClass);
        actionAcerca->setObjectName(QStringLiteral("actionAcerca"));
        actionBarBuscar = new QAction(MainWindowClass);
        actionBarBuscar->setObjectName(QStringLiteral("actionBarBuscar"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainWindow/resources/icono_Buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarBuscar->setIcon(icon4);
        actionSalir = new QAction(MainWindowClass);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionBarEditar = new QAction(MainWindowClass);
        actionBarEditar->setObjectName(QStringLiteral("actionBarEditar"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainWindow/resources/icono_Cliente.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarEditar->setIcon(icon5);
        actionBarImprimir = new QAction(MainWindowClass);
        actionBarImprimir->setObjectName(QStringLiteral("actionBarImprimir"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MainWindow/resources/icono_Impresora.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarImprimir->setIcon(icon6);
        actionConfigBD = new QAction(MainWindowClass);
        actionConfigBD->setObjectName(QStringLiteral("actionConfigBD"));
        actionEditar = new QAction(MainWindowClass);
        actionEditar->setObjectName(QStringLiteral("actionEditar"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/MainWindow/Resources/icono_Cliente.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditar->setIcon(icon7);
        actionCopiarRestaurar = new QAction(MainWindowClass);
        actionCopiarRestaurar->setObjectName(QStringLiteral("actionCopiarRestaurar"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);

        horizontalLayout->addWidget(tabWidget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuConfiguracion = new QMenu(menuBar);
        menuConfiguracion->setObjectName(QStringLiteral("menuConfiguracion"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(18, 18));
        mainToolBar->setFloatable(false);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConfiguracion->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuFile->addAction(actionNuevo);
        menuFile->addAction(actionBuscar);
        menuFile->addAction(actionEditar);
        menuFile->addSeparator();
        menuFile->addAction(actionSalir);
        menuAyuda->addAction(actionAcerca);
        menuConfiguracion->addAction(actionConfigBD);
        menuConfiguracion->addAction(actionCopiarRestaurar);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBarNuevo);
        mainToolBar->addAction(actionBarBuscar);
        mainToolBar->addAction(actionBarEditar);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBarImprimir);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Vanessmark Desgloses 1.0.2", 0));
        actionNuevo->setText(QApplication::translate("MainWindowClass", "Nuevo", 0));
#ifndef QT_NO_TOOLTIP
        actionNuevo->setToolTip(QApplication::translate("MainWindowClass", "Inserta nuevos clientes y desgloses", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNuevo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionBuscar->setText(QApplication::translate("MainWindowClass", "Buscar", 0));
        actionBarNuevo->setText(QApplication::translate("MainWindowClass", "BarNuevo", 0));
#ifndef QT_NO_TOOLTIP
        actionBarNuevo->setToolTip(QApplication::translate("MainWindowClass", "Inserta nuevos clientes y desgloses", 0));
#endif // QT_NO_TOOLTIP
        actionAcerca->setText(QApplication::translate("MainWindowClass", "Acerca", 0));
        actionBarBuscar->setText(QApplication::translate("MainWindowClass", "BarBuscar", 0));
#ifndef QT_NO_TOOLTIP
        actionBarBuscar->setToolTip(QApplication::translate("MainWindowClass", "Busca desgloses de los clientes", 0));
#endif // QT_NO_TOOLTIP
        actionSalir->setText(QApplication::translate("MainWindowClass", "Salir", 0));
        actionBarEditar->setText(QApplication::translate("MainWindowClass", "Editar", 0));
#ifndef QT_NO_TOOLTIP
        actionBarEditar->setToolTip(QApplication::translate("MainWindowClass", "Edita los desgloses", 0));
#endif // QT_NO_TOOLTIP
        actionBarImprimir->setText(QApplication::translate("MainWindowClass", "Impresora", 0));
#ifndef QT_NO_TOOLTIP
        actionBarImprimir->setToolTip(QApplication::translate("MainWindowClass", "Imprime los desgloses", 0));
#endif // QT_NO_TOOLTIP
        actionConfigBD->setText(QApplication::translate("MainWindowClass", "Datos conexion", 0));
        actionEditar->setText(QApplication::translate("MainWindowClass", "Editar", 0));
        actionCopiarRestaurar->setText(QApplication::translate("MainWindowClass", "Copiar y restaurar", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "Desgloses", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindowClass", "Ayuda", 0));
        menuConfiguracion->setTitle(QApplication::translate("MainWindowClass", "Base de datos", 0));
#ifndef QT_NO_TOOLTIP
        mainToolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
