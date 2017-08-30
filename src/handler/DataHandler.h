#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "common.h"

class UpdateHandler;
class ArduinoHandler;
class DataPacket;

class DataHandler : public QObject {
    Q_OBJECT

private:
	ArduinoHandler *arduinoHandler;

public:
    explicit DataHandler(UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent = nullptr);
    virtual ~DataHandler();

    DataPacket *readData();

private slots:
	void prepareForUpdate();
};

#endif