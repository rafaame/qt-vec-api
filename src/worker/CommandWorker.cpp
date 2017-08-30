#include "CommandWorker.h"
#include "Packet.h"
#include "UpdateHandler.h"
#include "CommandHandler.h"

CommandWorkerThread::CommandWorkerThread(QObject *parent) : QThread(parent) {
    
}

CommandWorkerThread::~CommandWorkerThread() {
    
}

CommandWorker::CommandWorker(UpdateHandler *updateHandler, CommandHandler *commandHandler, QObject *parent) : QObject(parent) {
    this->commandHandler = commandHandler;

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &CommandWorker::prepareForUpdate, Qt::BlockingQueuedConnection);
    QObject::connect(updateHandler, &UpdateHandler::updateFinished, this, &CommandWorker::onUpdateFinished, Qt::DirectConnection);
}

CommandWorker::~CommandWorker() {
    
}

void CommandWorker::prepareForUpdate() {
    qDebug() << "CommandWorker::prepareForUpdate";

    thread()->exit(0);
}

void CommandWorker::onUpdateFinished() {
	qDebug() << "CommandWorker::onUpdateFinished";
	qDebug() << "CommandWorker::thread() = " << (int) thread();
	qDebug() << "CommandWorker::currentThreadId() = " << QThread::currentThreadId();

	thread()->start();
}

void CommandWorker::executeCommand(RequestPacket *packet) {
    emit commandReceived(packet);
    commandHandler->issueCommand(packet);
    emit commandExecuted(packet);
    
    delete packet;
}