#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("军棋");
    w.setWindowIcon(QIcon(":/new/prefix1/abc.ico"));
    w.show();
    return a.exec();
}
