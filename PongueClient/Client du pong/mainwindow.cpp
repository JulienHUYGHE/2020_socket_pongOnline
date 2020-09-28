#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMoveEvent>
#include <QKeyEvent>
#include "iostream"
#include "ClientTCP.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Client( this )
{
    ui->setupUi(this);
    ui->barreJoueur1->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::positionnerBarreJoueurAdv(int posY)
{
    ui->barreJoueur1->move(120,posY*(-1));
}

void MainWindow::positionnerBarreMaBarre(int posY)
{
    setCoordoneesBarreJ2(posY);
    ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
}

int MainWindow::monterBarreJ2()
{

    setCoordoneesBarreJ2(getCoordoneesBarreJ2() - 10);
    ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
    Client.EnvoyerInfoBarre(getCoordoneesBarreJ2());
    return getCoordoneesBarreJ2();

}


int MainWindow::descendreBarreJ2()
{

    setCoordoneesBarreJ2(getCoordoneesBarreJ2() + 10);
    ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
    Client.EnvoyerInfoBarre(getCoordoneesBarreJ2());
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
    int x = 0;

    if(e->key() == Qt::Key_S)
    {
        if(coordoneesBarreJ2 < 525){
            DemandeDescendreBarre = true;
            if(DemandeDescendreBarre){
                x = 1;
                Client.EnvoyerInfoBarre(x); //1 = descendre barre
                x = 0;
            }

//            descendreBarreJ2();
        }
    }
    if(e->key() == Qt::Key_Z)
    {
        if(coordoneesBarreJ2 > 25)
        {
            DemandeMonterBarre = true;
            if(DemandeMonterBarre){
                x = 2;
                Client.EnvoyerInfoBarre(x); // 2 = Monter barre
                x = 0;
            }
//            monterBarreJ2();
        }
    }


}

bool MainWindow::match()
{


   while(deplacerBalle(true) != 1)
   {

       return false;
   }
   return true;


}
int MainWindow:: deplacerBalle(bool commence)
{
    if (commence)
    {
        std::cout<<"test"<<std::endl;
      while (XBalle != coordoneesBarreJ1 ||  coordoneesBarreJ2 || YBalle != coordoneesBarreJ1 || coordoneesBarreJ1)
        {

             std::cout<<"test"<<std::endl;
            setXBalle(getXBalle() + 10);
            ui->balle->move(getXBalle() , 300);
             return getXBalle();



        }
    }
    else
    {
        while (XBalle != coordoneesBarreJ1 ||  coordoneesBarreJ2 || YBalle != coordoneesBarreJ1 || coordoneesBarreJ1)
        {
            setXBalle(getXBalle() - 10);
            ui->balle->move(getXBalle() , 300);
            return getXBalle();

        }
    }

    if( XBalle == coordoneesBarreJ1 || coordoneesBarreJ2 || YBalle == coordoneesBarreJ1 || coordoneesBarreJ2)
    {
        return 1;
    }
    else
        return 0;


}

