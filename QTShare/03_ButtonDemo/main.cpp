#include "ButtonDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ButtonDemo w;
    w.show();
    return a.exec();
}
