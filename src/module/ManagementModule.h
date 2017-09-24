#ifndef MANAGEMENTMODULE_H
#define MANAGEMENTMODULE_H

#include "common.h"
#include "Module.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class ArduinoHandler;

class ManagementModule : public Module {
protected:
	ArduinoHandler *arduinoHandler;

public:
	ManagementModule(ArduinoHandler *arduinoHandler, QObject *parent = nullptr);
	virtual ~ManagementModule();

	bool reset(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
};

#endif