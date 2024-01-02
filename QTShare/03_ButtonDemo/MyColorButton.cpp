#include "MyColorButton.h"

MyColorButton::MyColorButton(QWidget *parent)
	: QPushButton(parent)
{
	m_styleSheetFormat = "background-color:rgba(%1, %2, %3,%4);border:none;color:rgba(%5, %6, %7,%8);";
	connect(this, &MyColorButton::Si_ColorChanged, this, &MyColorButton::S_Refresh);
	connect(this, &MyColorButton::clicked, this, &MyColorButton::click);
	SetColor(Qt::white);
}

MyColorButton::~MyColorButton()
{}

QColor MyColorButton::GetColor()
{
	return m_bgColor;
}

void MyColorButton::SetColor(const QColor& clr)
{
	m_bgColor = clr;
	MakeTextColor();
	emit Si_ColorChanged(m_bgColor);
}

#include <QColorDialog>
void MyColorButton::click(bool checked /* = false */)
{
	auto clr = QColorDialog::getColor(m_bgColor, nullptr, QStringLiteral("Ñ¡ÔñÑÕÉ«"), QColorDialog::ShowAlphaChannel);
	if (clr != m_bgColor)
	{
		m_bgColor = clr;
		MakeTextColor();
		emit Si_ColorChanged(m_bgColor);
	}
}

void MyColorButton::S_Refresh()
{
	this->setText(QString("0x%1%2%3%4")
		.arg(m_bgColor.red(),2,16,QChar('0'))
		.arg(m_bgColor.green() , 2, 16, QChar('0'))
		.arg(m_bgColor.blue(),  2, 16, QChar('0'))
		.arg(m_bgColor.alpha(), 2, 16, QChar('0'))
	);
	this->setStyleSheet(CreateStyleSheet());
}

const QColor& MyColorButton::MakeTextColor()
{
	m_textColor.setAlpha(m_bgColor.alpha());
	m_textColor.setRed(255 - m_bgColor.red());
	m_textColor.setGreen(255 - m_bgColor.green());
	m_textColor.setBlue(255 - m_bgColor.blue());
	return m_textColor;
}

QString MyColorButton::CreateStyleSheet()
{
	return m_styleSheetFormat
		.arg(m_bgColor.red()).arg(m_bgColor.green()).arg(m_bgColor.blue()).arg(m_bgColor.alpha())
		.arg(m_textColor.red()).arg(m_textColor.green()).arg(m_textColor.blue()).arg(m_textColor.alpha());
}
