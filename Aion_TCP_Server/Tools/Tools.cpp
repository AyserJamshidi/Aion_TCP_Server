#include "Tools/Tools.h"

QDebug cDebug::test() {
	dbg = qDebug();
	dbg.noquote();
	dbg.nospace();
}

static QDebug test() {
	//if (dbg.)
	//dbg = qDebug();
	return dbg;
}