#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMoveEvent>
#include <QKeyEvent>
#include "iostream"
#include <QTimer>
#include "define.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_allerADroite(true)
    ,m_player(NULL)
{
    ui->setupUi(this);
    ui->barreJoueur1->setFocus();
}

MainWindow::~MainWindow()
#include <QTimer>
{
    delete ui;
}
int MainWindow::monterBarreJ1()
{
    setCoordoneesBarreJ1(getCoordoneesBarreJ1()-10);
    ui->barreJoueur1->move(120,getCoordoneesBarreJ1());
    return getCoordoneesBarreJ1();

}
int MainWindow::descendreBarreJ1()
{
    setCoordoneesBarreJ1(getCoordoneesBarreJ1()+10);
    ui->barreJoueur1->move(120,getCoordoneesBarreJ1());

    return getCoordoneesBarreJ1();

}
int MainWindow::monterBarreJ2()
{
    setCoordoneesBarreJ2(getCoordoneesBarreJ2()-10);
    ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
    return getCoordoneesBarreJ2();

}


int MainWindow::descendreBarreJ2()
{
    setCoordoneesBarreJ2(getCoordoneesBarreJ2()+10);
    ui->barreJoueur2->move(1050,getCoordoneesBarreJ2());
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

    if(e->key() == Qt::Key_S)
    {
        if(coordoneesBarreJ2 < 525)
            descendreBarreJ2();
    }
    if(e->key() == Qt::Key_Z)
    {
        if(coordoneesBarreJ2 >25)
            monterBarreJ2();
    }

}


void MainWindow:: deplacerBalle()
{



    std::cout<<"avant"<<std::endl;
    std::cout<<"XBalle=" <<XBalle <<std::endl;
    std::cout<<"coordoneesBarreJ1=" <<coordoneesBarreJ1 <<std::endl;
    std::cout<<"coordoneesBarreJ2=" << coordoneesBarreJ2<<std::endl;



    if(getXBalle() <= 1050 && getXBalle() >= 120)
    {
            if(m_allerADroite)
                setXBalle(getXBalle() + 10);
            else
                setXBalle(getXBalle() - 10);

            ui->balle->move(getXBalle() , 300);

    }
    else
    {
        m_allerADroite = !m_allerADroite;
        if(m_allerADroite)

            setXBalle(getXBalle() + 10);


        else


            setXBalle(getXBalle() - 10);



        if (getXBalle() == coordoneesBarreJ1 || getXBalle() == coordoneesBarreJ2)
        {
            jouerMusique("PEW.wav");
        }


        ui->balle->move(getXBalle() , 300);
        if(getYBalle()> coordoneesBarreJ1 || getYBalle() > coordoneesBarreJ2)
        {
                ui->balle->move(600 , 300);
            m_timer->stop();

            if( getYBalle() != coordoneesBarreJ2)
            {
                ui->Ecran->setText("\t\t\t\t\t\t\tLe gagnant est joueur 2 !");
            }
            if(getYBalle() != coordoneesBarreJ1)
            {
                ui->Ecran->setText("\t\t\t\t\t\t\tLe gagnant est joueur 1 !");
            }
        }
    }




}


void MainWindow::timer()
{
    std::cout << "Création du timer" << std::endl;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(deplacerBalle()));
    m_timer->start(50);
    ui->barreJoueur1->setFocus();

}




void MainWindow::on_pushButton_clicked()
{
    setXBalle(300);
    deplacerBalle();
    timer();
jouerMusique("tetris.mp3");
}





bool MainWindow::match()
{
    return true;
}

void MainWindow::jouerMusique(QString s)
{
    m_player = new QMediaPlayer;

    // mettre le chemin de votre dossier musique
    // s.prepend("/Users/bapti/Desktop/Musique/");
    s.prepend(CHEMIN_MUSIQUE);

    std::cout << QUrl::fromLocalFile(s).toString().toStdString() << std::endl;

    m_player->setMedia(QUrl::fromLocalFile( s));
    m_player->setVolume(50);
    m_player->play();
}

