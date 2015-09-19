#ifndef DATACOLLECTTHREAD_H
#define DATACOLLECTTHREAD_H

#include <QThread>
#include "win_qextserialport.h"

#define SERIALPORT_OPEN			1
#define SERIALPORT_CLOSE		2
#define SERIALPORT_OPEN_FAILED	3

#define SYNC	0xAA
#define EXCODE	0x55

/* Data CODE definitions */
#define PARSER_POOR_SIGNAL_CODE 0x02
#define PARSER_HEARTRATE_CODE	0x03
#define PARSER_CONFIG_CODE		0x08
#define PARSER_RAW_CODE			0x80
#define PARSER_DEBUG1_CODE		0x84
#define PARSER_DEBUG2_CODE		0x85

/**
 * @brief The DataCollectThread class
 */
class DataCollectThread : public QThread
{
	Q_OBJECT
public:
	DataCollectThread();
	~DataCollectThread();

	void run();
	void SerialPortInit();
	void SerialPortOpen();
	void SerialPortClose();

	void ParsePayload(unsigned char *payload, unsigned char pLength);
	int getRawWaveValue(unsigned char highOrderByte, unsigned char lowOrderByte);

public:
	/*´®¿Ú*/
	Win_QextSerialPort *SerialPort;
	struct PortSettings portSettings;
	QString PortName;
	bool SerialPortState;
	short RawWaveValue;
	void ChangeThreadState(bool state);
private:
	bool ThreadState;

signals:
	void SerialPortFlagSignal(int flag);
	void SerialPortRawWaveValueSignal(int value);
	void SerialPortHeartRateValueSignal(int value);
	void SerialPortPoorSignalQualitySignal(int value);
};


#endif
