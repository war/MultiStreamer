
#include "mainwindow.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QIcon icon = QIcon("./icon-alt.png");
    //a.setWindowIcon(icon);

    MainWindow w;
    w.show();

    return a.exec();
}
