#include "UpdateHandler.h"
#include "UpdateController.h"

UpdateHandler::UpdateHandler(UpdateController *updateController, QObject *parent) : QObject(parent) {
    this->updateController = updateController;

    QObject::connect(updateController->getUpdateThread(), &UpdateThread::updateError, this, &UpdateHandler::onUpdateError, Qt::QueuedConnection);
    QObject::connect(updateController->getUpdateThread(), &UpdateThread::updateSuccess, this, &UpdateHandler::onUpdateSuccess, Qt::QueuedConnection);
    QObject::connect(updateController->getUpdateThread(), &UpdateThread::updateFinished, this, &UpdateHandler::onUpdateFinished, Qt::QueuedConnection);
}

UpdateHandler::~UpdateHandler() {
    
}

QJsonDocument UpdateHandler::githubRequest(QString route) {
	static QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);

	QEventLoop loop;
	QNetworkReply *networkReply = networkManager->get(QNetworkRequest(QUrl("https://api.github.com" + route)));
	connect(networkReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	loop.exec();

	QByteArray data = networkReply->readAll();
	return QJsonDocument::fromJson(data);
}

QString UpdateHandler::getLastCommitHash(QString component) {
	QJsonDocument data = githubRequest("/repos/rafaame/" + component + "/commits");
	if (! data.isArray()) {
		qDebug() << "Error";
		return QString("");
	}

	QJsonObject lastCommit =  data.array()[0].toObject();
	return lastCommit["sha"].toString();
}

bool UpdateHandler::needsUpdate(QString component) {
	QString lastCommitHash = getLastCommitHash(component);
	qDebug() << lastCommitHash;
	return true;
}

bool UpdateHandler::startUpdate(QString component) {
	emit preparingUpdate();

	updateController->startUpdate(component);
}

void UpdateHandler::onUpdateError() {
	emit updateError();
}

void UpdateHandler::onUpdateSuccess() {
	emit updateSuccess();
}

void UpdateHandler::onUpdateFinished() {
	qDebug() << "UpdateHandler::onUpdateFinished";
	qDebug() << "UpdateHandler::thread() = " << (int) thread();
	qDebug() << "UpdateHandler::currentThreadId() = " << QThread::currentThreadId();

	emit updateFinished();
}