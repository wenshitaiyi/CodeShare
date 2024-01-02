// Qt项目遇到的  将view中的数据导出为excel
// 总结一下经验：
QString fileName = QFileDialog::getSaveFileName(this, tr("Save excel"),
".", tr("Microsoft Office 2003 (*.xls)"));//获取保存路径
if (fileName.isEmpty()) {
QMessageBox::critical(0, tr("错误"), tr("要保存的文件名为空！"));
return;
}
//建立Excel对象
QAxObject *excel = new QAxObject("Excel.Application");

excel->dynamicCall("SetVisible(bool)", true); //如果为了看自己的程序到底怎样工作，可以设置为true
excel->setProperty("Visible", false);
QAxObject *workbooks = excel->querySubObject("WorkBooks");
workbooks->dynamicCall("Add");
QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
QAxObject *range = worksheet->querySubObject("Cells(int,int)", row,column);//row  column为要插入的行和列
range->setProperty("Value", String); //此处写要插入的内容

workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));
QMessageBox::information(this, tr("OK"), tr("保存成功！"));
workbook->dynamicCall("Close()");
worksheet->clear();//释放所有工作表
excel->dynamicCall("Quit()");
delete excel;//释放excel

至此 完成
转载于:https://blog.51cto.com/5449763/1128856