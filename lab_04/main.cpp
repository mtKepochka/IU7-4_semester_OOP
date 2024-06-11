#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumHeight(w.height());
    w.setMaximumWidth(w.width());
    w.setMinimumHeight(w.height());
    w.setMinimumWidth(w.width());
    w.setWindowTitle("ЛР №4");
    w.show();
    return a.exec();
}
