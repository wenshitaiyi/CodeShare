#include "MenuDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuDemo w;
    w.show();
    return a.exec();
}
