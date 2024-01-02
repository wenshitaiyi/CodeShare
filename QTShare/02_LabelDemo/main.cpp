#include "LabelDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LabelDemo w;
    w.show();
    return a.exec();
}
