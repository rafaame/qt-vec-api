#include "ArduinoHandler.h"
#include "IoControllerInterface.h"
#include "UpdateHandler.h"

ArduinoHandler::ArduinoHandler(IoControllerInterface *ioController, UpdateHandler *updateHandler, QObject *parent) : QObject(parent) {
    this->ioController = ioController;

    bcm2835_gpio_fsel(DEVICE_ARDUINO_DATA_RESET_PIN, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(DEVICE_ARDUINO_CONTROLLER_RESET_PIN, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(DEVICE_ARDUINO_DATA_RESET_PIN, BCM2835_GPIO_PUD_UP);
    bcm2835_gpio_set_pud(DEVICE_ARDUINO_CONTROLLER_RESET_PIN, BCM2835_GPIO_PUD_UP);

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &ArduinoHandler::prepareForUpdate, Qt::DirectConnection);
}

ArduinoHandler::~ArduinoHandler() {
    
}

void ArduinoHandler::prepareForUpdate() {
	qDebug() << "ArduinoHandler::prepareForUpdate";

	bcm2835_gpio_set_pud(DEVICE_ARDUINO_DATA_RESET_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DEVICE_ARDUINO_CONTROLLER_RESET_PIN, BCM2835_GPIO_PUD_UP);
}

void ArduinoHandler::resetDevice(ArduinoDevices_t device) {
	RPiGPIOPin resetPin;
	switch (device) {
		case DEVICE_ARDUINO_DATA:
			resetPin = DEVICE_ARDUINO_DATA_RESET_PIN;
			break;

		case DEVICE_ARDUINO_CONTROLLER:
			resetPin = DEVICE_ARDUINO_CONTROLLER_RESET_PIN;
			break;

		default:
			return;
	}

	bcm2835_gpio_set_pud(resetPin, BCM2835_GPIO_PUD_DOWN);
	bcm2835_delay(1);
	bcm2835_gpio_set_pud(resetPin, BCM2835_GPIO_PUD_UP);
}

QByteArray *ArduinoHandler::readData(ArduinoDevices_t device, quint32 size) {
	QByteArray *data = ioController->readFrom(device, size);

	return data;
}

bool ArduinoHandler::writeData(ArduinoDevices_t device, QByteArray *data) {
	return ioController->writeTo(device, data);
}