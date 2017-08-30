#include "ComfortModule.h"

using namespace std::placeholders;

ComfortModule::ComfortModule(QObject *parent) : Module(parent) {
	registerAction("set-ventilator-speed", bind(&ComfortModule::setVentilatorSpeed, this, _1, _2, _3, _4));
}

ComfortModule::~ComfortModule() {

}

bool ComfortModule::setVentilatorSpeed(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (requestPacket->dataType != PACKET_DATA_TYPE_INTEGER) {
		*error = "The data must be an integer.";
		return false;
	}

	quint8 speed = (quint8) atoi(requestPacket->data.c_str());
	if (speed > 4) {
		*error = "Speed must be between 0 and 4.";
		return false;
	}

	sendCommand(requestPacket);
	return true;
}