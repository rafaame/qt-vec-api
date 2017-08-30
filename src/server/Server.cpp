#include "Server.h"
#include "Packet.h"
#include "UpdateHandler.h"
#include "ModuleHandler.h"
#include "DataWorker.h"
#include "CommandWorker.h"

using namespace qhttp;
using namespace qhttp::server;

Server::Server(UpdateHandler *updateHandler, ModuleHandler *moduleHandler, DataWorker *dataWorker, CommandWorker *commandWorker, QCoreApplication *app) : QObject(app) {
    this->moduleHandler = moduleHandler;
    this->dataWorker = dataWorker;
    this->commandWorker = commandWorker;

    qHttpServer = new QHttpServer(app);
    QObject::connect(updateHandler, &UpdateHandler::preparingUpdate, this, &Server::prepareForUpdate, Qt::DirectConnection);
}

Server::~Server() {
    delete qHttpServer;
}

void Server::prepareForUpdate() {
    qDebug() << "Server::prepareForUpdate";
}

void Server::listen(quint16 port) {
    qHttpServer->listen(QHostAddress::Any, port);

    if (! qHttpServer->isListening()) {
        qCritical() << "Failed to start TCP server.";
        exit(1);
    }

    connect(qHttpServer, &QHttpServer::newRequest, this, &Server::newRequest);
}

void Server::newRequest(QHttpRequest *request, QHttpResponse *response) {
    request->collectData();
    request->onEnd([this, request, response]() -> void {
        QByteArray data = request->collectedData();
        QJsonDocument json = QJsonDocument::fromJson(data);

        if (json.isNull()) {
            response->setStatusCode(ESTATUS_BAD_REQUEST);
            response->end();
        }

        bool endRequest = moduleHandler->dispatch(request, RequestPacket::fromJson(json), response);
        if (endRequest) {
            response->end();
        }
    });

    /*QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);
    
    QByteArray request;
    while (clientConnection->bytesAvailable()) {
        qDebug() << clientConnection->readAll();
    }

    clientConnection->disconnectFromHost();*/
}