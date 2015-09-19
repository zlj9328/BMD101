#ifndef QLOG_H
#define QLOG_H

#include <QtDebug>
#include <QFile>
#include <QTextStream>

void LogOutput(QtMsgType type, const QMessageLogContext& Context, const QString  &msg);

#endif