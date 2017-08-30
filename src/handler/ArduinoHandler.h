#ifndef ARDUINOHANDLER_H
#define ARDUINOHANDLER_H

#include "common.h"

class IoControllerInterface;
class UpdateHandler;

enum ArduinoDevices_t {
	DEVICE_ARDUINO_DATA = 0x0A,
	DEVICE_ARDUINO_CONTROLLER = 0x0B
};

#define DEVICE_ARDUINO_DATA_RESET_PIN RPI_BPLUS_GPIO_J8_37
#define DEVICE_ARDUINO_CONTROLLER_RESET_PIN RPI_BPLUS_GPIO_J8_38

class ArduinoHandler : public QObject {
    Q_OBJECT

private:
	IoControllerInterface *ioController;

public:
    explicit ArduinoHandler(IoControllerInterface *ioController, UpdateHandler *updateHandler, QObject *parent = nullptr);
    virtual ~ArduinoHandler();

    void resetDevice(ArduinoDevices_t device);
    QByteArray *readData(ArduinoDevices_t device, quint32 size = 0);
    bool writeData(ArduinoDevices_t device, QByteArray *data);

private slots:
	void prepareForUpdate();
};

#endif