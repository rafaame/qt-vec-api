#include "ComfortModule.h"

using namespace std::placeholders;

ComfortModule::ComfortModule(QObject *parent) : Module(parent) {
	registerAction("set-ventilator-position", bind(&ComfortModule::setVentilatorPosition, this, _1, _2, _3, _4));
	registerAction("set-ventilator-speed", bind(&ComfortModule::setVentilatorSpeed, this, _1, _2, _3, _4));
	registerAction("set-air-conditioning", bind(&ComfortModule::setAirConditioning, this, _1, _2, _3, _4));
	registerAction("set-air-recirculation", bind(&ComfortModule::setAirRecirculation, this, _1, _2, _3, _4));
	registerAction("set-hazard-lights", bind(&ComfortModule::setHazardLights, this, _1, _2, _3, _4));
	registerAction("toggle-door-locks", bind(&ComfortModule::toggleDoorLocks, this, _1, _2, _3, _4));
	registerAction("toggle-defrost", bind(&ComfortModule::toggleDefrost, this, _1, _2, _3, _4));
	registerAction("open-trunk", bind(&ComfortModule::openTrunk, this, _1, _2, _3, _4));
}

ComfortModule::~ComfortModule() {

}

bool ComfortModule::setVentilatorPosition(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_INTEGER) {
		*error = "The data must be an integer.";
	}

	quint8 position = (quint8) atoi(requestPacket->data.c_str());
	if (position > 5) {
		*error = "Position must be between 0 and 5.";
	}
 
	sendCommand(requestPacket);
	return true;
}

bool ComfortModule::setVentilatorSpeed(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_INTEGER) {
		*error = "The data must be an integer.";
	}

	quint8 speed = (quint8) atoi(requestPacket->data.c_str());
	if (speed > 4) {
		*error = "Speed must be between 0 and 4.";
	}
 
	sendCommand(requestPacket);
	return true;
}

bool ComfortModule::setAirConditioning(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_BOOL) {
		*error = "The data must be a boolean.";
	}

	sendCommand(requestPacket);
	return true;
}

bool ComfortModule::setAirRecirculation(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_BOOL) {
		*error = "The data must be a boolean.";
	}

	//sendCommand(requestPacket);
	return true;
}

bool ComfortModule::setHazardLights(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_BOOL) {
		*error = "The data must be a boolean.";
	}

	sendCommand(requestPacket);
	return true;
}

bool ComfortModule::toggleDoorLocks(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	sendCommand(requestPacket);
	return true;
}

bool ComfortModule::toggleDefrost(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	//sendCommand(requestPacket);
	return true;
}

bool ComfortModule::openTrunk(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	sendCommand(requestPacket);
	return true;
}