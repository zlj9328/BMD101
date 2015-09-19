#include "bmd101.h"
#include "DataCollectThread.h"

#define XAXIS_STEP 1
#define XAXIS_NUM  200

/**
 * @brief BMD101::BMD101
 * @param parent
 */
BMD101::BMD101(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/*按键初始化*/
	ui.BaseDataButton->setStatusTip(tr("显示基本数据"));
	ui.ChartButton->setStatusTip(tr("显示心跳波形"));
	ui.SettingButton->setStatusTip(tr("设置"));

//	ui.BaseDataButton->setStyleSheet("background-color: blue;");

	connect(ui.BaseDataButton, SIGNAL(clicked()), this, SLOT(BaseDataButton_Clicked()));
	connect(ui.ChartButton, SIGNAL(clicked()), this, SLOT(ChartButton_Clicked()));
	connect(ui.SettingButton, SIGNAL(clicked()), this, SLOT(SettingButton_Clicked()));

	/*Widget隐藏*/
	ui.SettingWidget->hide();
	ui.QCustomPlotWidget->hide();

	/*setting widget初始化*/
	SettingWidgetInit();

	/*图标初始化*/
	HeartChartInit();

	/*线程初始化*/
	dataCollectThread = new DataCollectThread();
	connect(dataCollectThread, SIGNAL(SerialPortFlagSignal(int)), this, SLOT(SerialPortFlagSlot(int)));
	connect(dataCollectThread, SIGNAL(SerialPortRawWaveValueSignal(int)), this, SLOT(SerialPortRawWaveValueSlot(int)));
	connect(dataCollectThread, SIGNAL(SerialPortHeartRateValueSignal(int)), this, SLOT(SerialPortHeartRateValueSlot(int)));
	connect(dataCollectThread, SIGNAL(SerialPortPoorSignalQualitySignal(int)), this, SLOT(SerialPortPoorSignalQualitySlot(int)));
	dataCollectThread->SerialPortOpen();
	if (dataCollectThread->SerialPortState)
	{
		dataCollectThread->start();
	}
	xAxis_num = 0.0;
	
}

/**
 * @brief BMD101::~BMD101
 */
BMD101::~BMD101()
{
	qDebug("APP Stop");
	if (dataCollectThread->isRunning())
	{
		dataCollectThread->ChangeThreadState(false);
		qDebug("APP Stop:dataCollectThread terminate");
	}
	delete dataCollectThread;
}

/**
 * @brief BMD101::SettingWidgetInit
 */
void BMD101::SettingWidgetInit()
{
	int i = 0;
	QString str;

	/*端口选择初始化*/
	for (i = 0; i < 16; i++)
	{
		str.clear();
		str.append("COM");
		str.append(QString::number(i));
		ui.PortComboBox->addItem(str);	
	}

	/*波特率选择初始化*/
	ui.BaudComboBox->addItem(QString::number(4800));
	ui.BaudComboBox->addItem(QString::number(9600));
	ui.BaudComboBox->addItem(QString::number(19200));
	ui.BaudComboBox->addItem(QString::number(38400));
	ui.BaudComboBox->addItem(QString::number(57600));
	ui.BaudComboBox->addItem(QString::number(115200));

	/*数据位初始化*/
	ui.DataNumComboBox->addItem(QString::number(8));
	ui.DataNumComboBox->addItem(QString::number(7));
	ui.DataNumComboBox->addItem(QString::number(6));
	ui.DataNumComboBox->addItem(QString::number(5));

	/*停止位初始化*/
	ui.StopComboBox->addItem(QString::number(1));
	ui.StopComboBox->addItem(QString::number(1.5));
	ui.StopComboBox->addItem(QString::number(2));

	/*校验位初始化*/
	ui.CheckComboBox->addItem("None");
	ui.CheckComboBox->addItem("奇");
	ui.CheckComboBox->addItem("偶");

	connect(ui.PortComboBox, SIGNAL(activated(int)), this, SLOT(SelectPort(int)));
	connect(ui.BaudComboBox, SIGNAL(activated(int)), this, SLOT(SelectBaud(int)));
	connect(ui.StopComboBox, SIGNAL(activated(int)), this, SLOT(SelectStop(int)));
	connect(ui.DataNumComboBox, SIGNAL(activated(int)), this, SLOT(SelectData(int)));
	connect(ui.CheckComboBox, SIGNAL(activated(int)), this, SLOT(SelectCheck(int)));

	ui.BaudComboBox->setCurrentIndex(4);
	ui.PortComboBox->setCurrentIndex(8);
}

/**
 * @brief BMD101::SelectPort
 * @param num
 * 选择端口信号槽
 */
void BMD101::SelectPort(int num)
{
	dataCollectThread->PortName.clear();
	switch (num)
	{
		case 0:  dataCollectThread->PortName.append("COM0"); break;
		case 1:  dataCollectThread->PortName.append("COM1"); break;
		case 2:  dataCollectThread->PortName.append("COM2"); break;
		case 3:  dataCollectThread->PortName.append("COM3"); break;
		case 4:  dataCollectThread->PortName.append("COM4"); break;
		case 5:  dataCollectThread->PortName.append("COM5"); break;
		case 6:  dataCollectThread->PortName.append("COM6"); break;
		case 7:  dataCollectThread->PortName.append("COM7"); break;
		case 8:  dataCollectThread->PortName.append("COM8"); break;
		case 9:  dataCollectThread->PortName.append("COM9"); break;
		case 10: dataCollectThread->PortName.append("COM10"); break;
		case 11: dataCollectThread->PortName.append("COM11"); break;
		case 12: dataCollectThread->PortName.append("COM12"); break;
		case 13: dataCollectThread->PortName.append("COM13"); break;
		case 14: dataCollectThread->PortName.append("COM14"); break;
		case 15: dataCollectThread->PortName.append("COM15"); break;
		default: dataCollectThread->PortName.append("COM0"); break;
	}

	QString _SerialPortName = "\\\\.\\";
	_SerialPortName.append(dataCollectThread->PortName);
	dataCollectThread->SerialPort->setPortName(_SerialPortName);
	ui.statusBar->showMessage("设置成功",2000);
	qDebug("Setting Port:COM%d", dataCollectThread->PortName.split("M").last().toInt());
}

/**
 * @brief BMD101::SelectBaud
 * @param num
 * 选择波特率信号槽
 */
void BMD101::SelectBaud(int num)
{
	switch (num)
	{
		case 0: dataCollectThread->portSettings.BaudRate = BAUD4800; break;
		case 1: dataCollectThread->portSettings.BaudRate = BAUD9600; break;
		case 2: dataCollectThread->portSettings.BaudRate = BAUD19200; break;
		case 3: dataCollectThread->portSettings.BaudRate = BAUD38400; break;
		case 4: dataCollectThread->portSettings.BaudRate = BAUD57600; break;
		case 5: dataCollectThread->portSettings.BaudRate = BAUD115200; break;
		default:dataCollectThread->portSettings.BaudRate = BAUD57600; break;
	}

	ui.statusBar->showMessage("设置成功", 2000);
	qDebug("Setting Baud:%d", dataCollectThread->portSettings.BaudRate);
}

/**
 * @brief BMD101::SelectCheck
 * @param num
 * 选择校验位信号槽
 */
void BMD101::SelectCheck(int num)
{
	switch (num)
	{
		case 0: dataCollectThread->portSettings.Parity = PAR_NONE; break;
		case 1: dataCollectThread->portSettings.Parity = PAR_ODD;  break;
		case 2: dataCollectThread->portSettings.Parity = PAR_EVEN;  break;
		default: dataCollectThread->portSettings.Parity = PAR_NONE; break;
	}
	
	ui.statusBar->showMessage("设置成功", 2000);
	qDebug("Setting Parity:%d", dataCollectThread->portSettings.Parity);
}

/**
 * @brief BMD101::SelectStop
 * @param num
 * 选择停止位信号槽
 */
void BMD101::SelectStop(int num)
{
	switch (num)
	{
		case 0: dataCollectThread->portSettings.StopBits = STOP_1;  break;
		case 1: dataCollectThread->portSettings.StopBits = STOP_1_5; break;
		case 2: dataCollectThread->portSettings.StopBits = STOP_2;  break;
		default: dataCollectThread->portSettings.StopBits = STOP_1; break;
	}
	
	ui.statusBar->showMessage("设置成功", 2000);
	qDebug("Setting StopBits:%d", dataCollectThread->portSettings.StopBits);
}

/**
 * @brief BMD101::SelectData
 * @param num
 * 选择数据位信号槽
 */
void BMD101::SelectData(int num)
{
	switch (num)
	{
		case 0: dataCollectThread->portSettings.DataBits = DATA_8;  break;
		case 1: dataCollectThread->portSettings.DataBits = DATA_7;  break;
		case 2: dataCollectThread->portSettings.DataBits = DATA_6;  break;
		case 3: dataCollectThread->portSettings.DataBits = DATA_5;  break;
		default: dataCollectThread->portSettings.DataBits = DATA_8; break;
	}	
	ui.statusBar->showMessage("设置成功", 2000);
	qDebug("Setting DataBits:%d", dataCollectThread->portSettings.DataBits);
}

/**
 * @brief BMD101::SerialPortFlagSlot
 * @param flag
 */
void BMD101::SerialPortFlagSlot(int flag)
{
	switch (flag)
	{
		case SERIALPORT_OPEN:ui.statusBar->showMessage(tr("串口打开成功"), 5000); 
			qDebug("串口打开成功");
			break;
		case SERIALPORT_CLOSE:ui.statusBar->showMessage("串口已关闭", 5000); 
			qDebug("串口已关闭");
			break;
		case SERIALPORT_OPEN_FAILED:ui.statusBar->showMessage(tr("串口打开失败，请重新设置串口"), 5000);
			qDebug("串口打开失败，请重新设置串口");
			break;
		default:break;
	}
}

/**
 * @brief BMD101::SerialPortRawWaveValueSlot
 * @param value
 */
void BMD101::SerialPortRawWaveValueSlot(int value)
{
//	ui.RawWaveVaueLabel->setText(QString::number(value));
	if (ui.QCustomPlotWidget->isVisible())
	{
		HeartChartRawWaveValueAdd(value);
	}
	
}

/**
 * @brief BMD101::SerialPortHeartRateValueSlot
 * @param value
 */
void BMD101::SerialPortHeartRateValueSlot(int value)
{
	if (ui.BaseDataWidget->isVisible())
	{
		ui.HeartRateLabel->setText(QString::number(value));
	}
}

/**
 * @brief BMD101::SerialPortPoorSignalQualitySlot
 * @param value
 */
void BMD101::SerialPortPoorSignalQualitySlot(int value)
{
	if (ui.BaseDataWidget->isVisible())
	{
		ui.PoorSignalQualityLabel->setText(QString::number(value));
	}
}

/**
 * @brief BMD101::BaseDataButton_Clicked
 */
void BMD101::BaseDataButton_Clicked()
{
	qDebug("BaseDataButton_Clicked");
	if (!(ui.BaseDataWidget->isVisible()))
	{
		ui.SettingWidget->hide();
		ui.QCustomPlotWidget->hide();
		ui.BaseDataWidget->show();
	}
	dataCollectThread->SerialPortOpen();
	if (dataCollectThread->SerialPortState)
	{
		if (!(dataCollectThread->isRunning()))
		{
			dataCollectThread->ChangeThreadState(true);
			dataCollectThread->start();
			qDebug("dataCollectThread start");
		}
	}
}

/**
 * @brief BMD101::ChartButton_Clicked
 */
void BMD101::ChartButton_Clicked()
{
	qDebug("ChartButton_Clicked");
	if (!(ui.QCustomPlotWidget->isVisible()))
	{
		ui.BaseDataWidget->hide();
		ui.SettingWidget->hide();
		ui.QCustomPlotWidget->show();
	}
	dataCollectThread->SerialPortOpen();
	if (dataCollectThread->SerialPortState)
	{
		if (!(dataCollectThread->isRunning()))
		{
			dataCollectThread->ChangeThreadState(true);
			dataCollectThread->start();
			qDebug("dataCollectThread start");
		}
	}
}

/**
 * @brief BMD101::SettingButton_Clicked
 */
void BMD101::SettingButton_Clicked()
{
	qDebug("SettingButton_Clicked");
	if (!(ui.SettingWidget->isVisible()))
	{
		ui.BaseDataWidget->hide();
		ui.QCustomPlotWidget->hide();
		ui.SettingWidget->show();
	}	
	dataCollectThread->SerialPortClose();
	if (dataCollectThread->isRunning())
	{
//		dataCollectThread->terminate();
		dataCollectThread->ChangeThreadState(false);
		qDebug("dataCollectThread terminate");
	}
	
}

/**
 * @brief BMD101::HeartChartInit
 * 心率图初始化
 */
void BMD101::HeartChartInit()
{
	connect(ui.QCustomPlotWidget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));//连接鼠标点击信号和槽
	connect(ui.QCustomPlotWidget, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));//连接鼠标滚轮信号和槽
	connect(ui.QCustomPlotWidget, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));//连接曲线选择信号和槽

	//设置交互方式
	ui.QCustomPlotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);

	QBrush qBrush(QColor(240, 240, 240));//设置背景色
	ui.QCustomPlotWidget->setBackground(qBrush);

	ui.QCustomPlotWidget->legend->setVisible(true);
	ui.QCustomPlotWidget->xAxis->setLabel("时间 (t/s)");//设置ｘ轴
	ui.QCustomPlotWidget->xAxis->setRange(0, XAXIS_NUM);
//	ui.QCustomPlotWidget->xAxis->setTicks(false);

	ui.QCustomPlotWidget->yAxis->setLabel("电压值");//设置ｙ轴
	ui.QCustomPlotWidget->yAxis->setAutoTicks(true);
	ui.QCustomPlotWidget->yAxis->setAutoTickStep(true);
	ui.QCustomPlotWidget->yAxis->setAutoSubTicks(true);

	Heart_Graph_Channel = ui.QCustomPlotWidget->addGraph();
	QPen qPen1(QColor(0, 255, 0));
	Heart_Graph_Channel->setPen(qPen1);//设置画笔颜色
	Heart_Graph_Channel->setName(QString("电压值"));
}

void BMD101::HeartChartRawWaveValueAdd(int value)
{
	QVector<int> x(1), y(1);

	xAxis_num += XAXIS_STEP;
	if (xAxis_num > XAXIS_NUM)
	{
		xAxis_num = 0;
		Heart_Graph_Channel->clearData();
	}
	y[0] = value;
	x[0] = xAxis_num;

	Heart_Graph_Channel->addData(x[0], y[0]);
//	ui.QCustomPlotWidget->rescaleAxes(true);//从新适应坐标
	ui.QCustomPlotWidget->yAxis->rescale(true);
	ui.QCustomPlotWidget->replot();
}

/**
* @brief MainWindow::mousePress
*　鼠标点击
*/
void BMD101::mousePress()
{
	// if an axis is selected, only allow the direction of that axis to be dragged
	// if no axis is selected, both directions may be dragged
	if (ui.QCustomPlotWidget->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.QCustomPlotWidget->axisRect()->setRangeDrag(ui.QCustomPlotWidget->xAxis->orientation());
	}
	else if (ui.QCustomPlotWidget->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.QCustomPlotWidget->axisRect()->setRangeDrag(ui.QCustomPlotWidget->yAxis->orientation());
	}
	else
	{
		ui.QCustomPlotWidget->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
	}
}

/**
* @brief MainWindow::mouseWheel
*　鼠标滚轮
*/
void BMD101::mouseWheel()
{
	// if an axis is selected, only allow the direction of that axis to be zoomed
	// if no axis is selected, both directions may be zoomed
	if (ui.QCustomPlotWidget->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.QCustomPlotWidget->axisRect()->setRangeZoom(ui.QCustomPlotWidget->xAxis->orientation());
	}
	else if (ui.QCustomPlotWidget->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.QCustomPlotWidget->axisRect()->setRangeZoom(ui.QCustomPlotWidget->yAxis->orientation());
	}
	else
	{
		ui.QCustomPlotWidget->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
	}
}

/**
* @brief MainWindow::selectionChanged
* 曲线选择
*/
void BMD101::selectionChanged()
{
	/*
	normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
	the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
	and the axis base line together. However, the axis label shall be selectable individually.

	The selection state of the left and right axes shall be synchronized as well as the state of the
	bottom and top axes.

	Further, we want to synchronize the selection of the graphs with the selection state of the respective
	legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
	or on its legend item.
	*/

	// make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
	if (ui.QCustomPlotWidget->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui.QCustomPlotWidget->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
		ui.QCustomPlotWidget->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui.QCustomPlotWidget->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
	{
		ui.QCustomPlotWidget->xAxis2->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
		ui.QCustomPlotWidget->xAxis->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
	}
	// make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
	if (ui.QCustomPlotWidget->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui.QCustomPlotWidget->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
		ui.QCustomPlotWidget->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui.QCustomPlotWidget->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
	{
		ui.QCustomPlotWidget->yAxis2->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
		ui.QCustomPlotWidget->yAxis->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
	}

	// synchronize selection of graphs with selection of corresponding legend items:
	for (int i = 0; i<ui.QCustomPlotWidget->graphCount(); ++i)
	{
		QCPGraph *graph = ui.QCustomPlotWidget->graph(i);
		QCPPlottableLegendItem *item = ui.QCustomPlotWidget->legend->itemWithPlottable(graph);
		if (item->selected() || graph->selected())
		{
			item->setSelected(true);
			graph->setSelected(true);
		}
	}
}
