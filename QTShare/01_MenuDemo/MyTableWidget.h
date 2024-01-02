#pragma once

#include <QTableWidget>
#include <QObject>

class MyTableWidget;

class MyMenu;
class MyTableWidget  : public QTableWidget
{
	Q_OBJECT
public:
	MyTableWidget(QWidget *parent);
	~MyTableWidget();
private:
	MyMenu* m_pMenu{ nullptr };
};
