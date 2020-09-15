#include "mainwindow.h"
#include <QKeyEvent>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    w.match();
    return a.exec();

}
