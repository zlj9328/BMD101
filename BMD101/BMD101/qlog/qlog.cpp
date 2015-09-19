#include "qlog.h"
#include "qdatetime.h"

/**
 * @brief LogOutput
 * @param type
 * @param Context
 * @param msg
 * 日志输出到文件函数
 */
void LogOutput(QtMsgType type, const QMessageLogContext& Context, const QString  &msg)
{
	QString txt;
        QString str;

	QDateTime time = QDateTime::currentDateTime();
	str = time.toString();

	switch (type) 
	{
	case QtDebugMsg:
		txt = QString("Debug: %1").arg(msg);
		break;

	case QtWarningMsg:
		txt = QString("Warning: %1").arg(msg);
		break;
	case QtCriticalMsg:
		txt = QString("Critical: %1").arg(msg);
		break;
	case QtFatalMsg:
		txt = QString("Fatal: %1").arg(msg);
		abort();
	}

	str.append("\t----");
	str.append(txt);
	str.append("----");

	QFile outFile("BMD101_Log.log");
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	ts << str << endl;
}
