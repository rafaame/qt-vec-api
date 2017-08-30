#include "DataModule.h"

using namespace std::placeholders;

DataModule::DataModule(QObject *parent) : Module(parent) {
	registerAction("attach", bind(&DataModule::attach, this, _1, _2, _3, _4));
}

DataModule::~DataModule() {

}

bool DataModule::dispatch(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response) {
	if (! actions.contains(QString(requestPacket->action.c_str()))) {
		return false;
	}

	QString error;
	bool success = actions[QString(requestPacket->action.c_str())](request, requestPacket, response, &error);
	
	QJsonObject responseBody = buildResponse(success, error);
	response->setStatusCode(success ? ESTATUS_OK : ESTATUS_INTERNAL_SERVER_ERROR);
	response->write(QJsonDocument(responseBody).toJson());

	return ! success;
}

void DataModule::receiveData(DataPacket *dataPacket) {
	QString json = dataPacket->toJson();
	for (QString remoteAddress : clients.keys()) {
		QHttpConnection *client = clients[remoteAddress];
		QTcpSocket *socket = client->tcpSocket();
		if (socket->state() != QAbstractSocket::ConnectedState) {
			continue;
		}

		socket->write(json.toUtf8());
	}
}

bool DataModule::attach(QHttpRequest *request, RequestPacket *requestPacket, QHttpResponse *response, QString *error) {
	if (clients.contains(request->remoteAddress())) {
		*error = "Remote address already attached.";
		return false;
	}

	QString remoteAddress = request->remoteAddress();
	QHttpConnection *connection = request->connection();
	clients.insert(remoteAddress, connection);

	QObject::connect(connection, &QHttpConnection::disconnected,
					 this, [remoteAddress, this]() { clients.remove(remoteAddress); });

	return true;
}