#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ButtonDemo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ButtonDemoClass; };
QT_END_NAMESPACE

class ButtonDemo : public QMainWindow
{
    Q_OBJECT

public:
    ButtonDemo(QWidget *parent = nullptr);
    ~ButtonDemo();

private:
    Ui::ButtonDemoClass *ui;
};
