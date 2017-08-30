#include "CommandHandler.h"
#include "Packet.h"
#include "UpdateHandler.h"
#include "ArduinoHandler.h"

CommandHandler::CommandHandler(UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent) : QObject(parent) {
    this->arduinoHandler = arduinoHandler;

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &CommandHandler::prepareForUpdate, Qt::DirectConnection);
}

CommandHandler::~CommandHandler() {
    
}

void CommandHandler::prepareForUpdate() {
	qDebug() << "CommandHandler::prepareForUpdate";
}

bool CommandHandler::issueCommand(RequestPacket *packet) {
	uint8_t buffer[128];
	uint8_t size = packet->toByteArray(buffer);
	QByteArray data((const char *) buffer, size);

	return arduinoHandler->writeData(DEVICE_ARDUINO_CONTROLLER, &data);
}