#include "DataHandler.h"
#include "UpdateHandler.h"
#include "ArduinoHandler.h"
#include "Packet.h"

DataHandler::DataHandler(UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent) : QObject(parent) {
    this->arduinoHandler = arduinoHandler;

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &DataHandler::prepareForUpdate, Qt::DirectConnection);
}

DataHandler::~DataHandler() {
    
}

void DataHandler::prepareForUpdate() {
	qDebug() << "DataHandler::prepareForUpdate";
}

DataPacket *DataHandler::readData() {
	QByteArray *data = arduinoHandler->readData(DEVICE_ARDUINO_DATA, DataPacket::getByteArraySize());
	if (! data) {
		return nullptr;
	}

	DataPacket *dataPacket = DataPacket::fromByteArray((uint8_t *) data->data());
	return dataPacket;
}