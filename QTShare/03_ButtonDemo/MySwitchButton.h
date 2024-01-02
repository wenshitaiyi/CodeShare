#pragma once

#include <QWidget>
#include <QColor>
#include <QPoint>

class QTimer;
class MySwitchButton  : public QWidget
{
	Q_OBJECT

public:
	MySwitchButton(QWidget *parent);
	~MySwitchButton();
public:
	//设置滑动按钮的状态
	void SetToogleState(bool bToogle);
	//获取滑动按钮的状态
	bool GetToogleState();
signals:
	//勾选状态改变的信号
	void Si_ToogleStateChanged(bool bToogle);
public slots:
	//超时绘制
	void S_Tick();
public://事件重写
	virtual void enterEvent(QEvent* event);
	virtual void leaveEvent(QEvent* event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void resizeEvent(QResizeEvent* event);
private:
	QColor m_cClr, m_cHClr, m_cDClr, m_cDHClr;
	QColor m_bClr, m_bHClr, m_bDClr, m_bDHClr;
	QString m_text;
	bool m_bToogle{ false };
	bool m_bHover{ false };

	//动画效果
	QTimer* m_pAnimeTimer{ nullptr };
	int m_iGap{ 2 };//移动的间隔 [像素]
	int m_iDuration{ 1500 };//动画的时常 [ms]

	//临时量
	QPoint m_cCenter;//圆的中心
	QRect m_cCenterRect;//圆心的活动区域
	float m_cRadius;//圆的半径
	QRect m_bgRect;//背景矩形
};
