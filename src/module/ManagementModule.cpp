#include "ManagementModule.h"
#include "ArduinoHandler.h"

using namespace std::placeholders;

ManagementModule::ManagementModule(ArduinoHandler *arduinoHandler, QObject *parent) : Module(parent) {
	this->arduinoHandler = arduinoHandler;

	registerAction("reset", bind(&ManagementModule::reset, this, _1, _2, _3, _4));
}

ManagementModule::~ManagementModule() {

}

bool ManagementModule::reset(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
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

	if (requestPacket->data == "arduino-vec-data") {
		qDebug() << "Resetting arduino-vec-data...";
		arduinoHandler->resetDevice(DEVICE_ARDUINO_DATA);
	} else if (requestPacket->data == "arduino-vec-controller") {
		qDebug() << "Resetting arduino-vec-controller";
		arduinoHandler->resetDevice(DEVICE_ARDUINO_CONTROLLER);
	}

	return true;
}