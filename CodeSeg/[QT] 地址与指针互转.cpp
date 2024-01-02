//设置名字，方便测试
this->setObjectName("123");

//转字符串，方便传出
QString cur_address=QString::number((int)this,16);
cur_address.insert(0,"0x");

//转为地址，并给一个指针初始化
bool res;
int hexNum=cur_address.toInt(cur_address,16);
QDialog* dlg=(QDialog*)hexNum;

//获取名字，进行验证
QString objName=dlg->objName();//123

/* zss 2020年10月13日
备注：在同一个exe中这样写是没有问题的，但是通过QProcess::start(app,arguments)的方式启动另一个exe，并且将这个地址传出去，在另一个exe中虽然能够成功转化，且地址一致，但是调用函数的过程中会出错
*/
