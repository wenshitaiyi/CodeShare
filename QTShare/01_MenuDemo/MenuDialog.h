#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuDialogClass; };
QT_END_NAMESPACE

class QPoint;
class QEvent;
class QMouseEvent;
class MenuDialog : public QDialog
{
	Q_OBJECT

public:
	MenuDialog(QWidget *parent = nullptr);
	~MenuDialog();

	void MoveCenter(const QPoint& pos);

public:
	bool event(QEvent* event);
	void mousePressEvent(QMouseEvent* event);

private:
	Ui::MenuDialogClass *ui;
};
