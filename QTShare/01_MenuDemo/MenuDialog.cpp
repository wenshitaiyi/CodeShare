#include "MenuDialog.h"
#include "ui_MenuDialog.h"

MenuDialog::MenuDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::MenuDialogClass())
{
	ui->setupUi(this);
	this->setMouseTracking(true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setAttribute(Qt::WA_StyledBackground);

	connect(ui->pb_openFile, &QPushButton::clicked, this, [this]()
		{
			this->close();
		});
	connect(ui->pb_website, &QPushButton::clicked, this, [this]()
		{
			this->close();
		});
	connect(ui->pb_dataprocess, &QPushButton::clicked, this, [this]()
		{
			this->close();
		});
	connect(ui->pb_download, &QPushButton::clicked, this, [this]()
		{
			this->close();
		});
}

MenuDialog::~MenuDialog()
{
	delete ui;
}

void MenuDialog::MoveCenter(const QPoint& pos)
{
	QPoint center(width() / 2, height() / 2);
	move(pos - center);
}

bool MenuDialog::event(QEvent* event)
{
	if (event->type() == QEvent::ActivationChange)
	{
		if (QApplication::activeWindow() != this)
		{
			this->close();
		}
	}

	return	QDialog::event(event);
}

void MenuDialog::mousePressEvent(QMouseEvent* event)
{
	this->setAttribute(Qt::WA_NoMouseReplay);
	return QDialog::mousePressEvent(event);
}
