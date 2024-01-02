#pragma once

#include <QPushButton>
#include <QColor>

class MyColorButton : public QPushButton
{
	Q_OBJECT

public:
	MyColorButton(QWidget *parent);
	~MyColorButton();

	//��ȡ��ɫ
	QColor GetColor();

	//������ɫ
	void SetColor(const QColor& clr);
signals:
	void Si_ColorChanged(const QColor& clr);
public slots:
	void click(bool checked /* = false */);
	void S_Refresh();
private:
	//���ݱ���ɫ��ȡ������ɫ ͸���Ȳ�������ͨ����ɫ��255-x��
	const QColor& MakeTextColor();
	//������ɫ��ȡ��ʽ��
	QString CreateStyleSheet();
private:
	QString m_styleSheetFormat;
	QColor m_bgColor;
	QColor m_textColor;
};
