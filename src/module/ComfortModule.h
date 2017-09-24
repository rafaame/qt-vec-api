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

	bool setVentilatorPosition(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool setVentilatorSpeed(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool setAirConditioning(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool setAirRecirculation(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool setHazardLights(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool toggleDoorLocks(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool toggleDefrost(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool openTrunk(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
};

#endif