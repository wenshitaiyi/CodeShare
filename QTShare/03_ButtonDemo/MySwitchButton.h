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
	//���û�����ť��״̬
	void SetToogleState(bool bToogle);
	//��ȡ������ť��״̬
	bool GetToogleState();
signals:
	//��ѡ״̬�ı���ź�
	void Si_ToogleStateChanged(bool bToogle);
public slots:
	//��ʱ����
	void S_Tick();
public://�¼���д
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

	//����Ч��
	QTimer* m_pAnimeTimer{ nullptr };
	int m_iGap{ 2 };//�ƶ��ļ�� [����]
	int m_iDuration{ 1500 };//������ʱ�� [ms]

	//��ʱ��
	QPoint m_cCenter;//Բ������
	QRect m_cCenterRect;//Բ�ĵĻ����
	float m_cRadius;//Բ�İ뾶
	QRect m_bgRect;//��������
};
