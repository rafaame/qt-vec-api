#ifndef MODULE_H
#define MODULE_H

#include "common.h"
#include "Packet.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class ModuleHandler;

class Module : public QObject {
protected:
	ModuleHandler *moduleHandler;
	QMap<QString, function<bool(QHttpRequest *, RequestPacket *, QHttpResponse *, QString *)>> actions;

public:
	Module(QObject *parent = nullptr);
	virtual ~Module();

	void setModuleHandler(ModuleHandler *moduleHandler);
	QJsonObject buildResponse(bool success, QString error);

	void registerAction(QString name, function<bool(QHttpRequest *, RequestPacket *, QHttpResponse *, QString *)> action);
	virtual bool dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response);
	virtual void receiveData(DataPacket *dataPacket);
	virtual void sendCommand(RequestPacket *requestPacket);
};

#endif