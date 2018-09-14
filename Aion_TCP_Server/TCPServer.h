#pragma once

#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <qabstractsocket.h>
#include "TCPClient.h"

class TCPServer : public QTcpServer {
	Q_OBJECT
public:
	explicit TCPServer(QObject *parent = 0);
	bool StartServer();

protected:
	void incomingConnection(qintptr handle);

signals:

public slots:

};