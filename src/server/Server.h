#ifndef SERVER_H
#define SERVER_H

#include "common.h"

using namespace qhttp::server;

class UpdateHandler;
class ModuleHandler;
class DataWorker;
class CommandWorker;

class Server : public QObject {
    Q_OBJECT

private:
	ModuleHandler *moduleHandler;
	DataWorker *dataWorker;
	CommandWorker *commandWorker;
    
    QHttpServer *qHttpServer;

public:
    explicit Server(UpdateHandler *updateHandler, ModuleHandler *moduleHandler, DataWorker *dataWorker, CommandWorker *commandWorker, QCoreApplication *app);
    virtual ~Server();

    void listen(quint16 port);

private slots:
	void prepareForUpdate();
    void newRequest(QHttpRequest *request, QHttpResponse *response);
};

#endif