#include "GUI/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowFlags(Qt::FramelessWindowHint);
    window.show();
    return a.exec();
}
