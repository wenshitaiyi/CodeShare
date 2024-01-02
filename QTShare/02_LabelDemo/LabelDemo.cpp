#include "LabelDemo.h"
#include "TabCtrl.h"

LabelDemo::LabelDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    {
		TabCtrlNormal* pTab = new TabCtrlNormal(this);
		pTab->SetUIPtr(&ui);
    }

    {
		TabCtrlImg* pTab = new TabCtrlImg(this);
		pTab->SetUIPtr(&ui);
    }

	{
		TabCtrlStyle* pTab = new TabCtrlStyle(this);
		pTab->SetUIPtr(&ui);
	}
}

LabelDemo::~LabelDemo()
{}
