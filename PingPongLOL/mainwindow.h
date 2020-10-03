#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMediaPlayer>

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
int monterBarreJ2();
int descendreBarreJ2();
void timer();


int getCoordoneesBarreJ1() ;
void setCoordoneesBarreJ1(int value);

int getCoordoneesBarreJ2() ;
void setCoordoneesBarreJ2(int value);

int getYBalle() ;
void setYBalle(int value);

int getXBalle() ;
void setXBalle(int value);

void deplacerBarreDroite();
void deplacerBarreGauche();

bool match();

void jouerMusique(QString s);

private slots :
void  deplacerBalle();

private:
Ui::MainWindow *ui;
int coordoneesBarreJ1 = 300;
int coordoneesBarreJ2 = 300;

int YBalle = 300;
int XBalle = 500;
QTimer *m_timer;
bool m_allerADroite;
QMediaPlayer* m_player;

protected:

   void keyReleaseEvent(QKeyEvent * e);

private slots:
   void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
