#include "mainwindow.h"
#include <QKeyEvent>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    while(w.deplacerBalle(true) != 1)
    {
        w.deplacerBalle(true);
    }

    return a.exec();

}
