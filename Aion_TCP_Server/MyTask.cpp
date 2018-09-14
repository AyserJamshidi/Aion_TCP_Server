#include "MyTask.h"

#include <QtWidgets>

MyTask::MyTask() {
	// Constructor
}


MyTask::~MyTask() {
	// Deconstructor
}

void MyTask::run() {

	Response responses;

	QMetaObject MetaObject = responses.staticMetaObject;
	QMetaEnum MetaEnum = MetaObject.enumerator(MetaObject.indexOfEnumerator("Responses"));
	QString returnVal;

	switch (MetaEnum.keyToValue(receivedMsg.toLatin1())) {
	case responses.SEND_LOGIN_REQUEST:
		returnVal = "login";
		break;
	case responses.SEND_WELCOME_MSG:
		returnVal = "Connected to Lmfaoown TCP Server.";
		break;
	case responses.SEND_DISCONNECT:
		returnVal = "Your computer is not authorized for this program.";
		break;
	default:
		returnVal = "Undefined...:" + receivedMsg.toLatin1();
		break;
	}

	emit Result(returnVal);

}

void MyTask::setMessage(QString msg) {
	MyTask::receivedMsg = msg;
}