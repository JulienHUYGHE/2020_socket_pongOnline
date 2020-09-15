#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMoveEvent>
#include <QKeyEvent>
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barreJoueur1->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::monterBarreJ1()
{
    setCoordoneesBarreJ1(getCoordoneesBarreJ1()-10);
    ui->barreJoueur1->move(100,getCoordoneesBarreJ1());
return getCoordoneesBarreJ1();

}
int MainWindow::descendreBarreJ1()
{
    setCoordoneesBarreJ1(getCoordoneesBarreJ1()+10);
    ui->barreJoueur1->move(100,getCoordoneesBarreJ1());
return getCoordoneesBarreJ1();

}
int MainWindow::monterBarreJ2()
{
    setCoordoneesBarreJ2(getCoordoneesBarreJ2()+10);
    ui->barreJoueur2->move(1000,getCoordoneesBarreJ2());
return getCoordoneesBarreJ2();

}


int MainWindow::descendreBarreJ2()
{
    setCoordoneesBarreJ2(getCoordoneesBarreJ2()+10);
    ui->barreJoueur2->move(1000,getCoordoneesBarreJ2());
return getCoordoneesBarreJ2();

}


int MainWindow::getCoordoneesBarreJ1()
{
    return coordoneesBarreJ1;
}

void MainWindow::setCoordoneesBarreJ1(int value)
{
    coordoneesBarreJ1 = value;
}

int MainWindow::getCoordoneesBarreJ2()
{
    return coordoneesBarreJ2;
}

void MainWindow::setCoordoneesBarreJ2(int value)
{
    coordoneesBarreJ2 = value;
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    std::cout<<" test" <<std::endl;
if(e->key() == Qt::Key_Down)
{
       descendreBarreJ1();
}
if(e->key() == Qt::Key_Up)
{
       monterBarreJ1();
}

 if(e->key() == Qt::Key_S)
{
     descendreBarreJ2();
}
if(e->key() == Qt::Key_Z)
{
     monterBarreJ2();
}

}

