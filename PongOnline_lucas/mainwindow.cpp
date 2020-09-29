#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMoveEvent>
#include <QKeyEvent>
#include "iostream"
#include "Serveur.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serv (this)
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
    ui->barreJoueur1->move(120,getCoordoneesBarreJ1());// fois (-1) pour differencier la barre j1 de la barre J2
    serv.EnvoyerInfoBarreJ1(getCoordoneesBarreJ1()*(-1));
    return getCoordoneesBarreJ1();

}
int MainWindow::descendreBarreJ1()
{
    std::cout << "MainWindow::descendreBarreJ1()" << std::endl;
    setCoordoneesBarreJ1(getCoordoneesBarreJ1()+10);
    ui->barreJoueur1->move(120,getCoordoneesBarreJ1());
    serv.EnvoyerInfoBarreJ1(getCoordoneesBarreJ1()*(-1));
    return getCoordoneesBarreJ1();

}

int MainWindow::PositionnerBarreJoueurAdv(int pos_Y)
{
    std::cout << "MainWindow::PositionnerBarreJoueurAdv  posY=" << pos_Y << std::endl;
    if(pos_Y == 1){ //descendre
        setCoordoneesBarreJ2(getCoordoneesBarreJ2()+10);
        ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
        serv.EnvoyerInfoBarreJ1(getCoordoneesBarreJ2());
        return getCoordoneesBarreJ2();
    }
    else {//monter
        setCoordoneesBarreJ2(getCoordoneesBarreJ2()-10);
        ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
        serv.EnvoyerInfoBarreJ1(getCoordoneesBarreJ2());
        return getCoordoneesBarreJ2();
    }

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

int MainWindow::getYBalle()
{
    return YBalle;
}

void MainWindow::setYBalle(int value)
{
    YBalle = value;
}

int MainWindow::getXBalle()
{
    return XBalle;
}

void MainWindow::setXBalle(int value)
{
    XBalle = value;
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{

    if(e->key() == Qt::Key_Down)
    {
        if(coordoneesBarreJ1 < 525)
            descendreBarreJ1();
    }
    if(e->key() == Qt::Key_Up)
    {
        if(coordoneesBarreJ1 >25)
            monterBarreJ1();
    }
}

/*
void MainWindow:: deplacerBalle(bool commence)
{
    if (commence)
    {
        std::cout<<"test"<<std::endl;
      while (XBalle != coordoneesBarreJ1 ||  coordoneesBarreJ2 || YBalle != coordoneesBarreJ1 || coordoneesBarreJ1)
        {

             std::cout<<"test"<<std::endl;
            setXBalle(getXBalle() + 10);
            ui->balle->move(getXBalle() , 300);



        }
    }
    else
    {
        while (XBalle != coordoneesBarreJ1 ||  coordoneesBarreJ2 || YBalle != coordoneesBarreJ1 || coordoneesBarreJ1)
        {
            std::cout<<"Essai"<<std::endl;
            setXBalle(getXBalle() - 10);
            ui->balle->move(getXBalle() , 300);

        }
    }

}
*/

