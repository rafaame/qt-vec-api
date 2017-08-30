#include "I2cController.h"

I2cController::I2cController(QObject *parent) : QObject(parent) {
    handler = -1;
    probe = false;
}

I2cController::~I2cController() {
    
}

bool I2cController::init() {
    if (! bcm2835_init() || ! bcm2835_i2c_begin()) {
        return false;
    }

    bcm2835_i2c_set_baudrate(100000);

    return true;
}

QByteArray *I2cController::readFrom(quint8 deviceAddress, quint32 size) {
    QMutexLocker locker(&mutex);
    bcm2835_i2c_setSlaveAddress(deviceAddress);

    char *buffer = new char[size ? size : 2048];
    uint8_t reason = BCM2835_I2C_REASON_ERROR_DATA;
    quint32 i = 0;
    do {
        reason = size ? bcm2835_i2c_read(buffer, size) : bcm2835_i2c_read(&(buffer[i++]), 1);
    } while (! size && reason == BCM2835_I2C_REASON_ERROR_DATA);
    
    if (reason != BCM2835_I2C_REASON_OK) {
        return nullptr;
    }

    QByteArray *data = new QByteArray(buffer, size ? size : i);
    delete buffer;

    probe = false;
    return data;
}

bool I2cController::writeTo(quint8 deviceAddress, QByteArray *data) {
    QMutexLocker locker(&mutex);
    bcm2835_i2c_setSlaveAddress(deviceAddress);

    if (bcm2835_i2c_write(data->constData(), data->length()) == BCM2835_I2C_REASON_OK) {
        probe = false;
        return true;
    }

    return false;
}