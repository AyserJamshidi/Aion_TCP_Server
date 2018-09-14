#include <QtCore/QCoreApplication>
#include "TCPServer.h"

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	TCPServer server;
	//server.StartServer();
	return a.exec();
}