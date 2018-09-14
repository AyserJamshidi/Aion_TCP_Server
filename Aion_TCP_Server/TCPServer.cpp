#include "TCPServer.h"
#include "Tools/Tools.h"

#include <qthread.h>


TCPServer::TCPServer(QObject *parent) : QTcpServer(parent) {
	while (!StartServer())
		QThread::sleep(1);
	//StartServer();
}

bool TCPServer::StartServer() {
	QDebug debug = qDebug();
	debug.noquote();
	debug.nospace();
	
	QHostAddress listenAddr = QHostAddress::AnyIPv4;
	int listenPort = 1234;
	if (QTcpServer::listen(listenAddr, listenPort)) {
		debug << "Server started on " << listenAddr.toString() << ":" << listenPort;
		return true;
	}
	debug << "Server could not start!";
	return false;
}

void TCPServer::incomingConnection(qintptr handle) {
	TCPClient *client = new TCPClient(this);
	qDebug() << "Handle1 ==" << handle;
	client->SetSocket(handle);
	qDebug() << "Handle2 ==" << handle;
}