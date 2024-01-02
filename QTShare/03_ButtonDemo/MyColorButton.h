#pragma once

#include <QPushButton>
#include <QColor>

class MyColorButton : public QPushButton
{
	Q_OBJECT

public:
	MyColorButton(QWidget *parent);
	~MyColorButton();

	//获取颜色
	QColor GetColor();

	//设置颜色
	void SetColor(const QColor& clr);
signals:
	void Si_ColorChanged(const QColor& clr);
public slots:
	void click(bool checked /* = false */);
	void S_Refresh();
private:
	//根据背景色获取字体颜色 透明度不变其他通道反色（255-x）
	const QColor& MakeTextColor();
	//根据颜色获取样式表
	QString CreateStyleSheet();
private:
	QString m_styleSheetFormat;
	QColor m_bgColor;
	QColor m_textColor;
};
