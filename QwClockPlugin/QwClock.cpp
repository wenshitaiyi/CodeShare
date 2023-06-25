#include "QwClock.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

QwClock::QwClock(QWidget* parent)
	: QWidget(parent)
	, m_iHSLen(10), m_iMSLen(5)
	, m_iSOMargin(3), m_iTOMargin(5)
	, m_iHALen(60), m_iMALen(80), m_iSALen(90)
	, m_HSColor(Qt::white), m_MSColor(Qt::lightGray), m_HAColor(Qt::white), m_MAColor(Qt::white), m_SAColor(Qt::green)
{
	m_curTime.setHMS(3, 12, 4);
	m_timer.setInterval(50);
	m_timer.start();
	connect(&m_timer, &QTimer::timeout, this, [=]()
		{
			m_curTime = m_curTime.addSecs(1);
			this->update();
		});
}

void QwClock::paintEvent(QPaintEvent* event)
{
	//保证时钟绘制在窗体的中心位置
	QPainter painter(this);
	int minR = width();
	minR = minR < height() ? minR : height();
	QRect rect((width() - minR) / 2, (height() - minR) / 2, minR, minR);
	painter.setViewport(rect);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	//painter.rotate(-180 + 360.0 / 12.0);

	////test painter
	//painter.save();
	//painter.setWindow(-100, -100, 200, 200);
	//painter.drawRect(QRect(-90, -90, 180, 180));
	//painter.restore();

	CreatePlate(painter);
	CreateTimeScale(painter);
	CreateTimeText(painter);
	CreateArrow(painter);
}

void QwClock::CreatePlate(QPainter& painter)
{
	painter.save();

	painter.setWindow(-100, -100, 200, 200);

	QPen pen;
	pen.setColor(QColor(0, 0, 0, 0));
	pen.setWidth(2);
	pen.setStyle(Qt::SolidLine);
	painter.setPen(pen);

	QBrush brush;
	brush.setColor(Qt::black);
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);

	painter.drawEllipse(QPointF(0, 0), 100, 100);

	painter.restore();
}

void QwClock::CreateTimeScale(QPainter& painter)
{
	painter.save();
	painter.setWindow(-100, -100, 200, 200);

	QPen pen;
	pen.setColor(m_HSColor);
	pen.setWidth(2);
	pen.setStyle(Qt::SolidLine);
	painter.setPen(pen);

	int iScaleCnt = 12;
	double dGap = 360.0 / iScaleCnt;

	for (int i = 0; i < iScaleCnt; i++)
	{
		painter.drawLine(QPointF(0, -(100 - m_iSOMargin - m_iHSLen)), QPointF(0, -(100 - m_iSOMargin)));
		painter.rotate(dGap);
	}
	painter.restore();

	painter.save();
	painter.setWindow(-100, -100, 200, 200);
	pen.setColor(m_MSColor);
	pen.setWidth(1);
	painter.setPen(pen);

	iScaleCnt = 12 * 5;
	dGap = 360.0 / iScaleCnt;
	for (int i = 0; i < iScaleCnt; i++)
	{
		if (i % 5 == 0)
		{
			painter.rotate(dGap);
			continue;
		}
		painter.drawLine(QPointF(0, -(100 - m_iSOMargin - m_iMSLen)), QPointF(0, -(100 - m_iSOMargin)));
		painter.rotate(dGap);
	}
	painter.restore();
}

void QwClock::CreateTimeText(QPainter& painter)
{
	//需要矫正文字的偏转角度
	painter.save();
	painter.setWindow(-100, -100, 200, 200);

	QPen pen;
	pen.setColor(Qt::white);
	pen.setWidth(1);
	painter.setPen(pen);

	double dGap = 360.0 / 12;
	for (int i = 0; i < 12; i++)
	{
		painter.save();
		QFontMetrics textSize(this->font());
		QString timeStr = QString::number((i % 12 == 0) ? 12 : (i % 12));
		QRectF rect = textSize.boundingRect(timeStr);
		painter.setFont(this->font());
		double rx = 0, ry = 0;
		rx = -(rect.width() / 2);
		ry = 100 - m_iSOMargin - m_iHSLen - m_iTOMargin;
		//获取中心点
		painter.translate(QPointF(0, -ry + rect.height() / 2.0));
		painter.rotate(-i * dGap);
		//x,y,str
		painter.drawText(QPointF(rx, rect.height() / 2.0), timeStr);
		//painter.drawRect(QRectF(rx, -rect.height() / 2.0, rect.width(), rect.height()));
		painter.restore();
		painter.rotate(dGap);
	}
	painter.restore();
}

void QwClock::CreateArrow(QPainter& painter)
{
	QPen pen;
	pen.setColor(Qt::white);
	pen.setCapStyle(Qt::RoundCap);
	pen.setWidth(5);

	QPen penTile;
	penTile.setColor(Qt::black);
	penTile.setCapStyle(Qt::RoundCap);
	penTile.setWidth(2);

	int iHS = m_curTime.hour();
	int iMS = m_curTime.minute();
	int iSS = m_curTime.second();

	double dHS = (iHS * 60 * 60 + iMS * 60 + iSS) / (12.0 * 60.0 * 60.0) * 360;
	double dMS = (iMS * 60 + iSS) / (60.0 * 60.0) * 360.0;
	double dSS = iSS / 60.0 * 360.0;

	painter.save();
	painter.setWindow(-100, -100, 200, 200);
	//painter.rotate(180 - 360.0 / 12.0);

	//hour
	painter.save();
	pen.setColor(m_HAColor);
	pen.setWidth(5);
	painter.setPen(pen);
	painter.rotate(dHS);
	painter.drawLine(QPointF(0, 0), QPointF(0, -m_iHALen));
	painter.setPen(penTile);
	painter.drawLine(QPointF(0, -m_iHALen + 10), QPointF(0, -m_iHALen));
	painter.restore();

	//minute
	painter.save();
	pen.setColor(m_MAColor);
	pen.setWidth(5);
	painter.setPen(pen);
	painter.rotate(dMS);
	painter.drawLine(QPointF(0, 0), QPointF(0, -m_iMALen));
	painter.setPen(penTile);
	painter.drawLine(QPointF(0, -m_iMALen + 10), QPointF(0, -m_iMALen));
	painter.restore();

	//second
	painter.save();
	pen.setColor(m_SAColor);
	pen.setWidth(1);
	painter.setPen(pen);
	painter.rotate(dSS);

	QPainterPath path;
	path.moveTo(0, -3);
	path.lineTo(0, -m_iSALen);
	path.closeSubpath();
	path.moveTo(0, 3);
	path.lineTo(0, 8);
	path.addEllipse(QPointF(0, 0), 3, 3);
	painter.drawPath(path);
	painter.restore();

	painter.restore();
}
