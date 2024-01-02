#include "MyTableWidget.h"

class MyMenu :public QObject
{
	Q_OBJECT
public:
	MyMenu(MyTableWidget* parent = nullptr);
public slots:
	void S_ShowMenu(const QPoint& pos);
	void S_RemoveColumn(int iC);
private:
	friend class MyTableWidget;
	MyTableWidget* m_pTW{ nullptr };
};

MyTableWidget::MyTableWidget(QWidget *parent)
	: QTableWidget(parent)
{
	m_pMenu = new MyMenu(this);
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, &MyTableWidget::customContextMenuRequested, m_pMenu, &MyMenu::S_ShowMenu);
}

MyTableWidget::~MyTableWidget()
{}

MyMenu::MyMenu(MyTableWidget* parent /*= nullptr*/)
	:QObject(parent)
{
	m_pTW = parent;
	Q_ASSERT(m_pTW);
}

#include <QMenu>
void MyMenu::S_ShowMenu(const QPoint& pos)
{
	QMenu menu;

	if (auto pItem = m_pTW->itemAt(pos))
	{
		menu.addAction(QStringLiteral("重命名"));
		menu.addAction(QStringLiteral("删除行"));
		menu.addAction(QStringLiteral("删除列"), this, [this, pItem] 
			{
				S_RemoveColumn(pItem->column());
			});

	}
	else
	{
		menu.addAction(QStringLiteral("导入"));
		menu.addAction(QStringLiteral("导出"));
		menu.addAction(QStringLiteral("清空"));
	}
	menu.exec(QCursor::pos());
}

void MyMenu::S_RemoveColumn(int iC)
{
	//TODO 
}

#include "x64/Debug/moc/MyTableWidget.moc"