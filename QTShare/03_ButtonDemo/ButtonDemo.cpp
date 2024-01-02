#include "ButtonDemo.h"

ButtonDemo::ButtonDemo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ButtonDemoClass())
{
    ui->setupUi(this);
}

ButtonDemo::~ButtonDemo()
{
    delete ui;
}
