#ifndef UPDATEHANDLER_H
#define UPDATEHANDLER_H

#include "common.h"

class UpdateController;

class UpdateHandler : public QObject {
    Q_OBJECT

private:
	UpdateController *updateController;

public:
    explicit UpdateHandler(UpdateController *updateController, QObject *parent = nullptr);
    virtual ~UpdateHandler();

    QJsonDocument githubRequest(QString route);
	QString getLastCommitHash(QString component);
	bool needsUpdate(QString component);
	bool startUpdate(QString component);

signals:
	void preparingUpdate();
	void updateError();
	void updateSuccess();
	void updateFinished();

private slots:
	void onUpdateError();
	void onUpdateSuccess();
	void onUpdateFinished();
};

#endif