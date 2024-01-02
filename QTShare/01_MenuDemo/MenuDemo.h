#pragma once

#include <QtWidgets/QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MenuDemoClass; };
QT_END_NAMESPACE

class QPoint;
class MenuDemo : public QMainWindow
{
    Q_OBJECT

public:
    MenuDemo(QWidget *parent = nullptr);
    ~MenuDemo();
public slots:
    void S_ShowMenu();
    void S_ShowMenuForTreeWidget(const QPoint& pos);
private:
    Ui::MenuDemoClass *ui;
};
