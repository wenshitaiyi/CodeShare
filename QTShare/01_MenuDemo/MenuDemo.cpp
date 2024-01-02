#include "MenuDemo.h"
#include "ui_MenuDemo.h"
#include "MenuDialog.h"
#include <QDebug>
#include <QString>

MenuDemo::MenuDemo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuDemoClass())
{
    ui->setupUi(this);

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    //customContextMenuRequested pos 
    connect(this, &QWidget::customContextMenuRequested, this, [this](const QPoint& pos)
        {
            qDebug() << QString::fromLocal8Bit("点击了位置(%1,%2)").arg(pos.x()).arg(pos.y());
        });

    connect(this, &QWidget::customContextMenuRequested, this, &MenuDemo::S_ShowMenu);

    //给TreeWidget添加菜单
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, &QWidget::customContextMenuRequested, this, &MenuDemo::S_ShowMenuForTreeWidget);

    //给按钮添加菜单
    ui->pushButton->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->pushButton, &QWidget::customContextMenuRequested, this, [this](const QPoint& pos)
        {
            MenuDialog* dlg = new MenuDialog(this);
            //dlg->MoveCenter(QCursor::pos());
            QPoint centerPnt(ui->pushButton->width() / 2, ui->pushButton->height() / 2);
            dlg->MoveCenter(ui->pushButton->mapToGlobal(centerPnt));
            dlg->show();
        });
}

MenuDemo::~MenuDemo()
{
    delete ui;
}


#include <QMenu>
void MenuDemo::S_ShowMenu()
{
    qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
    QMenu menu;

    //way 1
    {
        menu.addAction(QString::fromLocal8Bit("功能1"));
        menu.addAction(QString::fromLocal8Bit("功能2"));
        auto pAction = menu.addAction(QString::fromLocal8Bit("功能3"));
        connect(pAction, &QAction::triggered, [this,pAction]() {
            qDebug() << "action name" << pAction->text() << sender()->metaObject()->className();
            });
    }

    menu.addSeparator();

    //way 2
    {
        menu.addAction(QString("fun 1"), this, [this]()
            {
                qDebug() << "triggered fun 1"<< sender()->metaObject()->className();
            });
    }

    menu.addSeparator();

    //sub menu
    {
        auto pSubMenu = menu.addMenu(QString("sub menu"));
        pSubMenu->addAction(QString("sub menu fun1"));
        pSubMenu->addAction(QString("sub menu fun2"));
        pSubMenu->addAction(QString("sub menu fun3"));
    }

    menu.addSeparator();

    //icon shortcut
    {
		menu.addAction(QString::fromLocal8Bit("功能1"));
		auto pAction = menu.addAction(QString::fromLocal8Bit("功能2"));
        pAction->setIcon(QIcon(QPixmap(":/MenuDemo/Rescource/image_57.png")));
        pAction->setShortcut(QKeySequence("Ctrl+R"));
    }
    menu.exec(QCursor::pos());
}


#include <QTreeWidget>
void MenuDemo::S_ShowMenuForTreeWidget(const QPoint& pos)
{
    QTreeWidget* pTW = ui->treeWidget;

    QMenu menu;

    QTreeWidgetItem* pItem = pTW->itemAt(pos);
    if (pItem)
    {
        if (!pItem->parent())
        {
            menu.addAction(QStringLiteral("顶级节点菜单"));
        }

        if (pItem->childCount() > 0)
        {
            if (pItem->isExpanded())
            {
                menu.addAction(QStringLiteral("折叠节点"), this, [this, pTW, pItem] 
                    {
                        pTW->collapseItem(pItem);
                    });
            }
            else
            {
				menu.addAction(QStringLiteral("展开节点"), this, [this, pTW, pItem]
					{
						pTW->expandItem(pItem);
					});
            }
        }
        else
        {
            menu.addAction(QStringLiteral("叶节点"));
        }
    }
    else
    {
        menu.addAction(QStringLiteral("空白处右键菜单"));
    }

    menu.exec(QCursor::pos());
}
