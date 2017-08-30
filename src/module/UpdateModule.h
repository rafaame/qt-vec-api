#ifndef UPDATEMODULE_H
#define UPDATEMODULE_H

#include "common.h"
#include "Module.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class UpdateHandler;

class UpdateModule : public Module {
protected:
	UpdateHandler *updateHandler;

public:
	UpdateModule(UpdateHandler *updateHandler, QObject *parent = nullptr);
	virtual ~UpdateModule();

	bool check(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
	bool start(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
};

#endif