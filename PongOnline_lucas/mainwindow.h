#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Serveur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

int monterBarreJ1();
int descendreBarreJ1();

int PositionnerBarreJoueurAdv(int pos_Y);


int getCoordoneesBarreJ1() ;
void setCoordoneesBarreJ1(int value);

int getCoordoneesBarreJ2() ;
void setCoordoneesBarreJ2(int value);

int getYBalle() ;
void setYBalle(int value);

int getXBalle() ;
void setXBalle(int value);

void deplacerBalle(bool commence);

bool match();

private:
Ui::MainWindow *ui;
int coordoneesBarreJ1 = 255;
int coordoneesBarreJ2 = 255;

int YBalle = 500;
int XBalle = 500;

Serveur serv;

protected:

   void keyReleaseEvent(QKeyEvent * e);

};
#endif // MAINWINDOW_H
