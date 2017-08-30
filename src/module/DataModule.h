#ifndef DATAMODULE_H
#define DATAMODULE_H

#include "common.h"
#include "Module.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class DataModule : public Module {
private:
	QMap<QString, QHttpConnection *> clients;

public:
	DataModule(QObject *parent = nullptr);
	virtual ~DataModule();

	virtual bool dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response);
	virtual void receiveData(DataPacket *dataPacket);
	bool attach(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error);
};

#endif