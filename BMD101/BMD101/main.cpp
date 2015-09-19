#include "bmd101.h"
#include <QtWidgets/QApplication>
#include "qlog.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BMD101 w;
//	w.setFixedSize(600, 357);
	qInstallMessageHandler(LogOutput);
	qDebug("APP Start");
	w.show();
	return a.exec();
}
