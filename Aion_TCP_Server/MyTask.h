#pragma once

#include <qdebug.h>
#include <qobject.h>
#include <qrunnable.h>

class MyTask : public QObject, public QRunnable {
	Q_OBJECT

public:
	MyTask();
	~MyTask();
	void setMessage(QString msg);

signals:
	void Result(QString result);

protected:
	void run();

private:
	QString receivedMsg;
};

class Response : public QObject {
	Q_OBJECT
	Q_ENUMS(Responses)

public:
	enum Responses {
		SEND_LOGIN_REQUEST,
		SEND_WELCOME_MSG, 
		SEND_DISCONNECT
	};
};