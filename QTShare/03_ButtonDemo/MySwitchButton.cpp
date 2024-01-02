#include "MySwitchButton.h"
#include <QTimer>

MySwitchButton::MySwitchButton(QWidget *parent)
	: QWidget(parent)
{
	setMouseTracking(true);
	m_pAnimeTimer = new QTimer(this);
	m_pAnimeTimer->setInterval(10);
	connect(m_pAnimeTimer, &QTimer::timeout, this, &MySwitchButton::S_Tick);

	m_cClr = Qt::white;
	m_cHClr = Qt::white;
	m_cDClr = Qt::black;
	m_cDHClr = Qt::black;

	m_bClr = QColor(77, 205, 213);
	m_bHClr = QColor(87, 215, 223);
	m_bDClr = Qt::white;
	m_bDHClr = Qt::lightGray;
}

MySwitchButton::~MySwitchButton()
{

}

void MySwitchButton::SetToogleState(bool bToogle)
{
	m_bToogle = bToogle;
	if (!m_pAnimeTimer->isActive())
	{
		m_pAnimeTimer->start();
	}
}

bool MySwitchButton::GetToogleState()
{
	return false;
}

void MySwitchButton::S_Tick()
{
	//如果勾选了就向右，如果没有勾选就向左
	//如果到达了边界，就停止
	if (m_bToogle)
	{
		m_cCenter.setX(m_cCenter.x() + m_iGap);
		if (m_cCenter.x() >= m_cCenterRect.right())
		{
			m_cCenter.setX(m_cCenterRect.right());
			m_pAnimeTimer->stop();
		}
	}
	else
	{
		m_cCenter.setX(m_cCenter.x() - m_iGap);
		if (m_cCenter.x() <= m_cCenterRect.left())
		{
			m_cCenter.setX(m_cCenterRect.left());
			m_pAnimeTimer->stop();
		}
	}

	update();
	//redraw();
}

void MySwitchButton::enterEvent(QEvent* event)
{
	m_bHover = true;
	update();
}

void MySwitchButton::leaveEvent(QEvent* event)
{
	m_bHover = false;
	update();
}

#include <QPainter>
void MySwitchButton::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	QPen pen;
	pen.setColor(Qt::green);
	pen.setWidth(1);
	painter.setPen(pen);
	painter.setBrush(Qt::NoBrush);

	//绘制边框
	if(0)
	{
		QRect outline(0, 0, width() - 1, height() - 1);
		painter.drawRect(outline);
	}

	//绘制底色
	{
		if (m_bToogle)
		{
			painter.setPen(Qt::NoPen);
			painter.setBrush(m_bHover ? m_bHClr : m_bClr);
		}
		else
		{
			pen.setWidth(3);
			pen.setColor(Qt::black);
			painter.setPen(pen);
			painter.setBrush(m_bHover ? m_bDHClr : m_bDClr);
		}
		
		painter.drawRoundedRect(m_bgRect, m_bgRect.height() / 2.0, m_bgRect.height() / 2.0);
	}

	//绘制中心圆
	{
		if (m_bToogle)
		{
			painter.setPen(Qt::NoPen);
			painter.setBrush(m_cClr);
		}
		else
		{
			painter.setPen(Qt::NoPen);
			painter.setBrush(m_cDClr);
		}
		
		painter.drawEllipse(m_cCenter, (int)m_cRadius, (int)m_cRadius);
	}
}

void MySwitchButton::mousePressEvent(QMouseEvent* event)
{
	m_bToogle = !m_bToogle;
	if (!m_pAnimeTimer->isActive())
	{
		m_pAnimeTimer->start();
	}
	emit Si_ToogleStateChanged(m_bToogle);
}

void MySwitchButton::resizeEvent(QResizeEvent* event)
{
	m_bgRect = QRect(3, 3, width() - 6, height() - 6);
	m_cRadius = m_bgRect.height() / 4;
	//勾选的时候在右侧
	if (m_bToogle)
	{
		m_cCenter = QPoint(m_bgRect.right() - m_cRadius * 2, height() / 2.0);
	}
	else
	{
		m_cCenter = QPoint(m_bgRect.x() + m_cRadius * 2, height() / 2.0);
	}
	
	m_cCenterRect = QRect(m_bgRect.x() + m_cRadius * 2, 3, m_bgRect.width() - m_cRadius * 4, height() - 6);
}