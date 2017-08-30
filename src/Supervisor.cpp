#include "Supervisor.h"
#include "I2cController.h"
#include "UpdateHandler.h"
#include "ArduinoHandler.h"

SupervisorThread::SupervisorThread(QObject *parent) : QThread(parent) {
    
}

SupervisorThread::~SupervisorThread() {
    
}

Supervisor::Supervisor(I2cController *i2cController, UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent) : QObject(parent) {
    this->i2cController = i2cController;
    this->arduinoHandler = arduinoHandler;

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &Supervisor::prepareForUpdate, Qt::BlockingQueuedConnection);
    QObject::connect(updateHandler, &UpdateHandler::updateFinished, this, &Supervisor::onUpdateFinished, Qt::DirectConnection);
}

Supervisor::~Supervisor() {
    
}

void Supervisor::prepareForUpdate() {
    qDebug() << "Supervisor::prepareForUpdate";

    thread()->exit(0);
}

void Supervisor::onUpdateFinished() {
	qDebug() << "Supervisor::onUpdateFinished";
	qDebug() << "Supervisor::thread() = " << (int) thread();
	qDebug() << "Supervisor::currentThreadId() = " << QThread::currentThreadId();

	thread()->start();
}

// void Supervisor::run() {
//     qDebug() << "Starting Supervisor...";

//     forever {
//         if (i2cController->probeI2c()) {
//             qDebug() << "I2C stuck...";
//             arduinoHandler->resetDevice(DEVICE_ARDUINO_DATA);
//             arduinoHandler->resetDevice(DEVICE_ARDUINO_CONTROLLER);
//         }

//         QThread::msleep(5000);

//     }
// }