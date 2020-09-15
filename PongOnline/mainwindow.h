#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


int getCoordoneesBarreJ1() ;
void setCoordoneesBarreJ1(int value);

int getCoordoneesBarreJ2() ;
void setCoordoneesBarreJ2(int value);

private:
Ui::MainWindow *ui;
int coordoneesBarreJ1 = 500;
int coordoneesBarreJ2 = 500;

protected:

   void keyReleaseEvent(QKeyEvent * e);

};
#endif // MAINWINDOW_H
