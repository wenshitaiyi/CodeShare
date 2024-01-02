#pragma once

#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class LabelDemoClass; };
QT_END_NAMESPACE

class TabCtrl : public QObject
{
	Q_OBJECT
public:
	TabCtrl(QObject* parent);
	~TabCtrl();
	void SetUIPtr(Ui::LabelDemoClass* ui);
	virtual void Config() = 0;
protected:
	Ui::LabelDemoClass* ui{ nullptr };
};


class TabCtrlNormal  : public TabCtrl
{
	Q_OBJECT

public:
	TabCtrlNormal(QObject *parent) : TabCtrl(parent) {}
	~TabCtrlNormal() {}
	virtual void Config();
};


class TabCtrlImg : public TabCtrl
{
	Q_OBJECT

public:
	TabCtrlImg(QObject* parent) : TabCtrl(parent) {}
	~TabCtrlImg() {}
	virtual void Config();
};


class TabCtrlStyle : public TabCtrl
{
	Q_OBJECT

public:
	TabCtrlStyle(QObject* parent) : TabCtrl(parent) {}
	~TabCtrlStyle() {}
	virtual void Config();
	bool eventFilter(QObject* watched, QEvent* event);
};