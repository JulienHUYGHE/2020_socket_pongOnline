/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QOpenGLWidget *openGLWidget;
    QFrame *barreJoueur1;
    QGraphicsView *balle;
    QFrame *barreJoueur2;
    QPushButton *pushButton;
    QLabel *Ecran;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1241, 1229);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(100, 20, 1001, 641));
        barreJoueur1 = new QFrame(centralwidget);
        barreJoueur1->setObjectName(QString::fromUtf8("barreJoueur1"));
        barreJoueur1->setGeometry(QRect(120, 260, 31, 131));
        barreJoueur1->setFrameShape(QFrame::VLine);
        barreJoueur1->setFrameShadow(QFrame::Sunken);
        balle = new QGraphicsView(centralwidget);
        balle->setObjectName(QString::fromUtf8("balle"));
        balle->setGeometry(QRect(590, 290, 20, 20));
        barreJoueur2 = new QFrame(centralwidget);
        barreJoueur2->setObjectName(QString::fromUtf8("barreJoueur2"));
        barreJoueur2->setGeometry(QRect(1050, 260, 31, 131));
        barreJoueur2->setFrameShape(QFrame::VLine);
        barreJoueur2->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 90, 75, 23));
        Ecran = new QLabel(centralwidget);
        Ecran->setObjectName(QString::fromUtf8("Ecran"));
        Ecran->setGeometry(QRect(100, 50, 1001, 31));
        Ecran->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1241, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Jouer", nullptr));
        Ecran->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Appuyez sur le bouton pour commencer</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
