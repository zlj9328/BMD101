#ifndef BMD101_H
#define BMD101_H

#include <QtWidgets/QMainWindow>
#include "ui_bmd101.h"
#include <qapplication.h>
#include <tchar.h>
#include "DataCollectThread.h"

/*QT中文显示优化*/
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif  3

/**
 * @brief The BMD101 class
 */
class BMD101 : public QMainWindow
{
	Q_OBJECT

public:
	BMD101(QWidget *parent = 0);
	~BMD101();

private:
	Ui::BMD101Class ui;
	/*线程*/
	DataCollectThread *dataCollectThread;
	/*心率图*/
	QCPGraph *Heart_Graph_Channel;


	int xAxis_num;

	void SettingWidgetInit();
	void HeartChartInit();
	void HeartChartRawWaveValueAdd(int value);

private slots:

	/*鼠标操作*/
	void mousePress();
	void mouseWheel();
	void selectionChanged();

	/*按键信号槽*/
	void BaseDataButton_Clicked();
	void ChartButton_Clicked();
	void SettingButton_Clicked();

	/*ComboBox信号槽*/
	void SelectPort(int num);
	void SelectBaud(int num);
	void SelectData(int num);
	void SelectStop(int num);
	void SelectCheck(int num);

	/*串口状态信号*/
	void SerialPortFlagSlot(int flag);
	void SerialPortRawWaveValueSlot(int value);
	void SerialPortHeartRateValueSlot(int value);
	void SerialPortPoorSignalQualitySlot(int value);

};

#endif // BMD101_H
