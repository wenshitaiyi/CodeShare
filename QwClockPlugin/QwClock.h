#pragma once

#include <QtWidgets/QWidget>
#include <QTime>
#include <QTimer>

class QwClock : public QWidget
{
    Q_OBJECT

public:
    QwClock(QWidget *parent = Q_NULLPTR);
protected:
    void paintEvent(QPaintEvent* event);
private:
    QTime m_curTime;
    QTimer m_timer;
    void CreatePlate(QPainter& painter);
    void CreateTimeScale(QPainter& painter);//两种刻度
    void CreateTimeText(QPainter& painter);
    void CreateArrow(QPainter& painter);//三种指针

    int m_iHSLen, m_iMSLen;
    int m_iSOMargin, m_iTOMargin;
    int m_iHALen, m_iMALen, m_iSALen;
    QColor m_HSColor, m_MSColor, m_HAColor, m_MAColor, m_SAColor;
};
