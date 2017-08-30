#include "UpdateModule.h"
#include "UpdateHandler.h"

using namespace std::placeholders;

UpdateModule::UpdateModule(UpdateHandler *updateHandler, QObject *parent) : Module(parent) {
	this->updateHandler = updateHandler;

	registerAction("check", bind(&UpdateModule::check, this, _1, _2, _3, _4));
	registerAction("start", bind(&UpdateModule::start, this, _1, _2, _3, _4));
}

UpdateModule::~UpdateModule() {

}

bool UpdateModule::check(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_STRING) {
		*error = "The data must be an string.";
		return false;
	}

	if (requestPacket->data != "qt-vec-api" &&
		requestPacket->data != "arduino-vec-data" &&
		requestPacket->data != "arduino-vec-controller") {
		*error = "Invalid data. Must be one of 'arduino-vec-data', 'arduino-vec-controller', 'qt-vec-api'.";
		return false;
	}

	// @FIXME: put this bool in the response (not in success)
	return updateHandler->needsUpdate(QString(requestPacket->data.c_str()));
}

bool UpdateModule::start(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_STRING) {
		*error = "The data must be an string.";
		return false;
	}

	if (requestPacket->data != "qt-vec-api" &&
		requestPacket->data != "arduino-vec-data" &&
		requestPacket->data != "arduino-vec-controller") {
		*error = "Invalid data. Must be one of 'arduino-vec-data', 'arduino-vec-controller', 'qt-vec-api'.";
		return false;
	}

	QString component(requestPacket->data.c_str());
	if (! updateHandler->needsUpdate(component)) {
		*error = "Component already up-to-date.";
		return false;
	}

	return updateHandler->startUpdate(component);
}