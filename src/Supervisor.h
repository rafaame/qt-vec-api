#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "common.h"

class I2cController;
class UpdateHandler;
class ArduinoHandler;

class SupervisorThread : public QThread {
	Q_OBJECT

public:
	SupervisorThread(QObject *parent = nullptr);
	~SupervisorThread();
};

class Supervisor : public QObject {
    Q_OBJECT

private:
	I2cController *i2cController;
	ArduinoHandler *arduinoHandler;

public:
    Supervisor(I2cController *i2cController, UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent = nullptr);
    ~Supervisor();

private slots:
	void prepareForUpdate();
	void onUpdateFinished();
};

#endif