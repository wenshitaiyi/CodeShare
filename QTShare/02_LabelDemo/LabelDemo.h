#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LabelDemo.h"

class LabelDemo : public QMainWindow
{
    Q_OBJECT

public:
    LabelDemo(QWidget *parent = nullptr);
    ~LabelDemo();
private:
    Ui::LabelDemoClass ui;
};
