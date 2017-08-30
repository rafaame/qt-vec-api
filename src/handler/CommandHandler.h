#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "common.h"

class RequestPacket;
class UpdateHandler;
class ArduinoHandler;

class CommandHandler : public QObject {
    Q_OBJECT

private:
	ArduinoHandler *arduinoHandler;

public:
    explicit CommandHandler(UpdateHandler *updateHandler, ArduinoHandler *arduinoHandler, QObject *parent = nullptr);
    virtual ~CommandHandler();

    bool issueCommand(RequestPacket *packet);

private slots:
	void prepareForUpdate();
};

#endif