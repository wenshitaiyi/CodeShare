// 用md5码判断两个文件是否一致
QByteArray byteArray = fileMd5(filePath);
QString md5 = byteArray.toHex();
if (sameText(md5, "5b7db1e8c9d3382c85a06a849f06b42a"))
{
// 两个文件内容一致
}

QByteArray fileMd5(QString filePath)
{
	QFile localFile(filePath);
	if (!localFile.open(QFile::ReadOnly))
	{
		qDebug() << "file open error.";
		return 0;
	}
	// QCryptographicHash类提供了一种方法来生成密码散列
	QCryptographicHash ch(QCryptographicHash::Md5);
	quint64 totalBytes = 0;
	quint64 bytesWritten = 0;
	quint64 bytesToWrite = 0;
	quint64 loadSize = 1024 * 4;
	QByteArray buf;
	totalBytes = localFile.size();
	bytesToWrite = totalBytes;
	while (1)
	{
		if(bytesToWrite > 0)
		{
			buf = localFile.read(qMin(bytesToWrite, loadSize));
			ch.addData(buf);
			bytesWritten += buf.length();
			bytesToWrite -= buf.length();
			buf.resize(0);
		}else
		{
			break;
		}

		if (bytesWritten == totalBytes)
		{
			break;
		}
	}
	localFile.close();
	// 生成密码散列
	QByteArray md5 = ch.result();
	return md5;
}​
 
// 解析与打开CHM文件（用于帮助文档）
QString strPath = exePath() + TRANS_STRING("Template\\help.CHM");
QDesktopServices bs;
bs.openUrl(QUrl::fromLocalFile(strPath));