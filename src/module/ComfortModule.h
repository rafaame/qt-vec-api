#ifndef COMFORTMODULE_H
#define COMFORTMODULE_H

#include "common.h"
#include "Module.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class ComfortModule : public Module {
protected:
	

public:
	ComfortModule(QObject *parent = nullptr);
	virtual ~ComfortModule();

	bool setVentilatorSpeed(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
};

#endif