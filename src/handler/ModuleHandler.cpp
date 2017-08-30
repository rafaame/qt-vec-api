#include "ModuleHandler.h"
#include "UpdateHandler.h"
#include "DataWorker.h"
#include "CommandWorker.h"
#include "Module.h"

using namespace std;
using namespace qhttp;
using namespace qhttp::server;

ModuleHandler::ModuleHandler(UpdateHandler *updateHandler, DataWorker *dataWorker, CommandWorker *commandWorker, QObject *parent) : QObject(parent) {
	this->dataWorker = dataWorker;
	this->commandWorker = commandWorker;
	updateInProgress = false;

	QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &ModuleHandler::prepareForUpdate, Qt::DirectConnection);
	QObject::connect(dataWorker, &DataWorker::dataUpdated, this, &ModuleHandler::receiveData, Qt::QueuedConnection);
	QObject::connect(this, &ModuleHandler::commandReceived, commandWorker, &CommandWorker::executeCommand, Qt::QueuedConnection);
}

ModuleHandler::~ModuleHandler() {

}

void ModuleHandler::prepareForUpdate() {
	qDebug() << "ModuleHandler::prepareForUpdate";

	updateInProgress = true;
}

void ModuleHandler::registerModule(QString name, Module *module) {
	modules.insert(name, module);
	module->setModuleHandler(this);
}

bool ModuleHandler::dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response) {
	if (! modules.contains(QString(requestPacket->module.c_str()))) {
		return false;
	}

	if (updateInProgress && requestPacket->module != "update") {
		qDebug() << "Discarding command";
		return false;
	}

	return modules[QString(requestPacket->module.c_str())]->dispatch(request, requestPacket, response);
}

void ModuleHandler::sendCommand(RequestPacket *requestPacket) {
	emit commandReceived(requestPacket);
}

void ModuleHandler::receiveData(DataPacket dataPacket) {
	for (auto moduleName : modules.keys()) {
		modules[moduleName]->receiveData(&dataPacket);
	}
}