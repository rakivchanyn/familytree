#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FamilyTreeW w;
    w.show();

    return a.exec();
}
