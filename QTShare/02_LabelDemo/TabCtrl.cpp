#include "TabCtrl.h"
#include "ui_LabelDemo.h"
#include <QPixmap>
#include <QMovie>

TabCtrl::TabCtrl(QObject* parent)
	: QObject(parent)
{

}

TabCtrl::~TabCtrl()
{
}

void TabCtrl::SetUIPtr(Ui::LabelDemoClass* ui)
{
	this->ui = ui;
	Config();
}

void TabCtrlNormal::Config()
{
	ui->label1->setText(QStringLiteral("千山鸟飞绝，万径人踪灭。孤舟蓑笠翁，独钓寒江雪。"));
	ui->label1->setWordWrap(true);

	ui->label1_link->setText(QStringLiteral("<h1><a href=\"https://baike.baidu.com/item/%E6%B1%9F%E9%9B%AA/2059572?fr=ge_ala\">江雪：百度百科</a></h1>"));
	ui->label1_link->setOpenExternalLinks(true);
}

void TabCtrlStyle::Config()
{
	ui->label2->installEventFilter(this);
}

#include <QPainter>
bool TabCtrlStyle::eventFilter(QObject* watched, QEvent* event)
{
	if (watched != ui->label2) return QObject::eventFilter(watched, event);

	QLabel* pL = ui->label2;

	static bool g_bState = 0;//0 离开  1 进入

	switch (event->type())
	{
	case QEvent::Paint:
	{
		QPainter painter(pL);
		painter.setBrush(g_bState ? Qt::red : Qt::black);
		painter.setPen(Qt::NoPen);
		painter.drawRect(0, 0, pL->width(), pL->height());
		return false;
	}
	case QEvent::Enter:
	{
		g_bState = 1;
		pL->update();
	}
	break;
	case QEvent::Leave:
	{
		g_bState = 0;
		pL->update();
	}
	break;
	default:
		break;
	}

	return QObject::eventFilter(watched, event);
}

void TabCtrlImg::Config()
{
	//设置图像
	ui->label_img->setPixmap(QPixmap(":/_LabelDemo/Resource/city.jpeg"));
	ui->label_img->setToolTip(QStringLiteral("江南烟雨"));

	//设置gif
	QMovie* movie = new QMovie(":/_LabelDemo/Resource/huihui.gif");
	ui->label_gif->setToolTip(QStringLiteral("为美好世界献上祝福-惠惠"));
	ui->label_gif->setMovie(movie);
	movie->start();
}
