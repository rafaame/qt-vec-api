#ifndef COMMANDWORKER_H
#define COMMANDWORKER_H

#include "common.h"

class RequestPacket;
class UpdateHandler;
class CommandHandler;

class CommandWorkerThread : public QThread {
	Q_OBJECT

public:
	CommandWorkerThread(QObject *parent = nullptr);
	~CommandWorkerThread();
};

class CommandWorker : public QObject {
    Q_OBJECT

private:
	CommandHandler *commandHandler;

public:
    CommandWorker(UpdateHandler *updateHandler, CommandHandler *commandHandler, QObject *parent = nullptr);
    ~CommandWorker();

private slots:
	void prepareForUpdate();
	void onUpdateFinished();

public slots:
    void executeCommand(RequestPacket *packet);

signals:
	void commandReceived(RequestPacket *packet);
	void commandExecuted(RequestPacket *packet);
};

#endif