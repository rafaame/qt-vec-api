#ifndef DATAWORKER_H
#define DATAWORKER_H

#include "common.h"
#include "Packet.h"

class DataPacket;
class UpdateHandler;
class DataHandler;

class DataWorkerThread : public QThread {
	Q_OBJECT

public:
	DataWorkerThread(QObject *parent = nullptr);
	~DataWorkerThread();

	void run();

signals:
	void iteration();
};

class DataWorker : public QObject {
    Q_OBJECT

private:
	DataHandler *dataHandler;

public:
    DataWorker(UpdateHandler *updateHandler, DataHandler *dataHandler, QObject *parent = nullptr);
    ~DataWorker();

    void run(DataWorkerThread *thread);

private slots:
	void prepareForUpdate();
	void onUpdateFinished();
	void iterate();

signals:
	void dataUpdated(DataPacket dataPacket);
};

#endif