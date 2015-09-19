#include "DataCollectThread.h"

/**
 * @brief DataCollectThread::DataCollectThread
 */
DataCollectThread::DataCollectThread()
{
	/*串口初始化*/
	SerialPortState = false;
	/*串口设置*/
	PortName = "COM8";
	portSettings = { BAUD57600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 2 };
	SerialPortInit();
	ThreadState = true;
	RawWaveValue = 0;

}

/**
 * @brief DataCollectThread::~DataCollectThread
 */
DataCollectThread::~DataCollectThread()
{
	SerialPortClose();
	delete SerialPort;
}


/**
 * @brief DataCollectThread::run
 */
void DataCollectThread::run()
{
	unsigned char _SYNC = 0;
	unsigned char _PLength = 0;
	unsigned char _PayLoad[256] = {0};
	unsigned char _Check = 0;
	int _CheckSum = 0;
	int i = 0;

	while (ThreadState)
	{
		/*处理SYNC*/
		SerialPort->getChar((char *)&_SYNC);
		if (_SYNC != SYNC) continue;
		_SYNC = 0x00;

		SerialPort->getChar((char *)&_SYNC);
		if (_SYNC != SYNC) continue;
		_SYNC = 0x00;
		/*读取PLength*/
		SerialPort->getChar((char *)&_PLength);
	
		if (_PLength > 169) continue;

		/*读取payload*/
		memset(_PayLoad, 0, sizeof(_PayLoad));
		for (i = 0; i < _PLength; i++)
		{
			SerialPort->getChar((char *)&_PayLoad[i]);
		}

		/*计算校验码*/
		_CheckSum = 0;
		for (i = 0; i < _PLength; i++)
		{
			_CheckSum += _PayLoad[i];
		}
		_CheckSum &= 0xFF;
		_CheckSum = ~_CheckSum & 0xFF;
		SerialPort->getChar((char *)&_Check);

		/*判断校验码*/
		if (_Check != _CheckSum)
		{
			qDebug("CheckSum failed");
			continue;
		}

		/*处理PayLoad数据*/
		ParsePayload(_PayLoad, _PLength);
	}
//	exit(0);
}

/**
 * @brief DataCollectThread::ParsePayload
 * @param payload
 * @param pLength
 * @return
 */
void DataCollectThread::ParsePayload(unsigned char *payload, unsigned char pLength)
{
	unsigned char bytesParsed = 0;
	unsigned char code;
	unsigned char length;
	unsigned char extendedCodeLevel;
	
	int i;
	/*解析Payload*/
	while (bytesParsed < pLength)
	{
		/* 记录EXCODE的个数，代表Extended Code Level */
		extendedCodeLevel = 0;
		while (payload[bytesParsed] == EXCODE)
		{
			extendedCodeLevel++;
			bytesParsed++;
		}
		code = payload[bytesParsed++];/*记录CODE值*/

		if (code & 0x80)/*code>0x7F,为多字节数据*/
		{
			length = payload[bytesParsed++];
		}
		else/*code<0x7F,为单字节数据*/
		{
			length = 1;
		}

		switch (code)
		{
			case PARSER_HEARTRATE_CODE:	emit SerialPortHeartRateValueSignal(payload[bytesParsed]); 
				break;
			case PARSER_POOR_SIGNAL_CODE: emit SerialPortPoorSignalQualitySignal(payload[bytesParsed]); 
				break;
			case PARSER_RAW_CODE: RawWaveValue = (payload[bytesParsed] << 8) | payload[bytesParsed + 1];
//				emit SerialPortRawWaveValueSignal(RawWaveValue);
				break;
			case PARSER_CONFIG_CODE:
				break;
			case PARSER_DEBUG1_CODE:
				break;
			case PARSER_DEBUG2_CODE:
				break;
			default:break;
		}
		/* Increment the bytesParsed by the length of the Data Value */
		bytesParsed += length;
	}
}

int DataCollectThread::getRawWaveValue(unsigned char highOrderByte, unsigned char lowOrderByte)
{
	/* Sign-extend the signed high byte to the width of a signed int */
	int hi = (int)highOrderByte;
	/* Extend low to the width of an int, but keep exact bits instead of sign-extending */
	int lo = ((int)lowOrderByte) & 0xFF;
	/* Calculate raw value by appending the exact low bits to the sign-extended high bits */
	int value = (hi << 8) | lo;
	return(value);
}


/**
* @brief BMD101::SerialPortInit
* 串口初始化
*/
void DataCollectThread::SerialPortInit()
{
	QString _SerialPortName = "\\\\.\\";
	_SerialPortName.append(PortName);
	SerialPort = new Win_QextSerialPort(_SerialPortName, QextSerialBase::Polling);
	//	connect(SerialPort, SIGNAL(readyRead()), this, SLOT(SerialPortRead()));
}

/**
* @brief BMD101::SerialPortOpen
* 打开串口
*/
void DataCollectThread::SerialPortOpen()
{
	if (SerialPortState == false)
	{

		if (SerialPort->open(QIODevice::ReadWrite))
		{
			SerialPortState = true;
			emit SerialPortFlagSignal(SERIALPORT_OPEN);
			SerialPort->setBaudRate(portSettings.BaudRate);
			SerialPort->setParity(portSettings.Parity);
			SerialPort->setStopBits(portSettings.StopBits);
			SerialPort->setDataBits(portSettings.DataBits);
			//		SerialPort->setTimeout(5);
		}
		else
		{
			emit SerialPortFlagSignal(SERIALPORT_OPEN_FAILED);
		}
	}
}

/**
* @brief BMD101::SerialPortClose
* 关闭串口
*/
void DataCollectThread::SerialPortClose()
{
	if (SerialPortState == true)
	{
		SerialPort->close();
		SerialPortState = false;
		emit SerialPortFlagSignal(SERIALPORT_CLOSE);
	}
}

void DataCollectThread::ChangeThreadState(bool state)
{
	ThreadState = state;
}




