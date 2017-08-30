#include "DataWorker.h"
#include "UpdateHandler.h"
#include "DataHandler.h"

DataWorkerThread::DataWorkerThread(QObject *parent) : QThread(parent) {
    
}

DataWorkerThread::~DataWorkerThread() {
    
}

void DataWorkerThread::run() {
	QEventLoop eventLoop;
	forever {
		eventLoop.processEvents();
		if (isInterruptionRequested()) {
			break;
		}

		emit iteration();
	}
}

DataWorker::DataWorker(UpdateHandler *updateHandler, DataHandler *dataHandler, QObject *parent) : QObject(parent) {
    this->dataHandler = dataHandler;

    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &DataWorker::prepareForUpdate, Qt::DirectConnection);
    QObject::connect(updateHandler, &UpdateHandler::updateFinished, this, &DataWorker::onUpdateFinished, Qt::DirectConnection);
}

DataWorker::~DataWorker() {
    
}

// executerd on main thread, thread() still returns DataWorkerThread
void DataWorker::prepareForUpdate() {
    qDebug() << "DataWorker::prepareForUpdate";

    thread()->requestInterruption();
    thread()->wait();
}

void DataWorker::onUpdateFinished() {
	qDebug() << "DataWorker::onUpdateFinished";
	qDebug() << "DataWorker::thread() = " << (int) thread();
	qDebug() << "DataWorker::currentThreadId() = " << QThread::currentThreadId();

	thread()->start();
}

void DataWorker::run(DataWorkerThread *thread) {
    qDebug() << "Starting DataWorker...";

    moveToThread(thread);
    QObject::connect(thread, &DataWorkerThread::iteration, this, &DataWorker::iterate);
    thread->start();
}

void DataWorker::iterate() {
    DataPacket *packet = dataHandler->readData();
    if (packet) {
    	qDebug() << "Packet on";
    	emit dataUpdated(*packet);
    	delete packet;
    	QThread::msleep(500);
    } else {
    	qDebug() << "Packet off";
    	QThread::msleep(500);
    }
}