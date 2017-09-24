#include "Module.h"
#include "ModuleHandler.h"

Module::Module(QObject *parent) : QObject(parent) {
	
}

Module::~Module() {

}

void Module::setModuleHandler(ModuleHandler *moduleHandler) {
	this->moduleHandler = moduleHandler;
}

QJsonObject Module::buildResponse(bool success, QString error) {
	QJsonObject response;
    response["success"] = QJsonValue(success);
    if (error.length() > 0) {
    	response["error"] = QJsonValue(error);
    }

    return response;
}

void Module::registerAction(QString name, function<bool(QHttpRequest *, RequestPacket *, QHttpResponse *, QString *)> action) {
	actions.insert(name, action);
}

bool Module::dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response) {
	QString error;
	bool closeConnection;
	if (actions.contains(QString(requestPacket->action.c_str()))) {
		closeConnection = actions[QString(requestPacket->action.c_str())](request, requestPacket, response, &error);
	} else {
		closeConnection = true;
		error = QString("Invalid action '") + QString(requestPacket->action.c_str()) + "'";
	}

	bool success = ! error.length();
	QJsonObject responseBody = buildResponse(success, error);
	response->setStatusCode(success ? ESTATUS_OK : ESTATUS_INTERNAL_SERVER_ERROR);
	response->write(QJsonDocument(responseBody).toJson());

	return true;
}

void Module::receiveData(DataPacket *dataPacket) {
	
}

void Module::sendCommand(RequestPacket *requestPacket) {
	moduleHandler->sendCommand(requestPacket);
}