#include "TCPClient.h"

#include <qhostaddress.h>
#include <QtWidgets>

QDataStream in;

TCPClient::TCPClient(QObject *parent) : QObject(parent) {
	QThreadPool::globalInstance()->setMaxThreadCount(4);
}


TCPClient::~TCPClient() {
}

void TCPClient::SetSocket(int Descriptor) {

	socket = new QTcpSocket(this);

	//connect(socket, SIGNAL(connected()), this, SLOT(onConnected()), Qt::UniqueConnection);
	connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::UniqueConnection);
	connect(socket, SIGNAL(readyRead()), this, SLOT(readSocketData()), Qt::UniqueConnection);

	socket->setSocketDescriptor(Descriptor);
	in.setDevice(socket);
	in.setVersion(QDataStream::Qt_5_11);
	
	qDebug() << socket->peerAddress().toString() << "connected.";
}

/*void TCPClient::onConnected() {
	qDebug() << "Client connected event.";
}*/

void TCPClient::onDisconnected() {
	qDebug() << socket->peerAddress().toString() << "disconnected.";
}


void TCPClient::readSocketData() {
	in.startTransaction();

	QString test;
	in >> test;

	if (!in.commitTransaction())
		return;

	MyTask *mytask = new MyTask();
	mytask->setAutoDelete(true);
	mytask->setMessage(test);

	connect(mytask, SIGNAL(Result(QString)), this, SLOT(TaskResult(QString)), Qt::QueuedConnection);
	QThreadPool::globalInstance()->start(mytask);
}

void TCPClient::TaskResult(QString result) {
	// QueuedConnection from readSocketData will come back HERE.
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_11);
	/*QString returnMessage;

	returnMessage.append(result);*/

	out << tr(result.toLatin1());

	socket->write(block);

	qDebug() << socket->peerAddress().toString() << "Sent:" << result;
}