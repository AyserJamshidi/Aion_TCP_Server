#pragma once
#include <qobject.h>
#include <qtcpsocket.h>
//#include <qdebug.h>
//#include <qthreadpool.h>

#include <list>

#include "MyTask.h"

class TCPClient : public QObject {
	Q_OBJECT

public:
	TCPClient(QObject *parent = 0);
	~TCPClient();
	void SetSocket(int Descriptor);

signals:

public slots:
	//void onConnected();
	void onDisconnected();
	void readSocketData();
	void TaskResult(QString result);

private:
	QTcpSocket *socket;
};

