#ifndef MODULEHANDLER_H
#define MODULEHANDLER_H

#include "common.h"
#include "Packet.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

class UpdateHandler;
class DataWorker;
class CommandWorker;
class Module;

class ModuleHandler : public QObject {
	Q_OBJECT

private:
	DataWorker *dataWorker;
	CommandWorker *commandWorker;
	QMap<QString, Module *> modules;
	bool updateInProgress;

public:
	ModuleHandler(UpdateHandler *updateHandler, DataWorker *dataWorker, CommandWorker *commandWorker, QObject *parent = nullptr);
	~ModuleHandler();

	void registerModule(QString name, Module *module);
	bool dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response);
	void sendCommand(RequestPacket *requestPacket);

public slots:
	void prepareForUpdate();
	void receiveData(DataPacket dataPacket);

signals:
	void commandReceived(RequestPacket *requestPacket);
};

#endif