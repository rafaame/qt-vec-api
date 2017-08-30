#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H

#include "common.h"

class UpdateThread : public QThread {
    Q_OBJECT

private:
	QString component;

protected:
    void run() override;

public:
    UpdateThread(QObject *parent = nullptr);
    ~UpdateThread();

    void prepare(QString component);

signals:
	void updateError();
	void updateSuccess();
	void updateFinished();
};

class UpdateController : public QObject {
    Q_OBJECT

private:
	UpdateThread *updateThread;
    
public:
    UpdateController(QObject *parent = nullptr);
    virtual ~UpdateController();

    UpdateThread *getUpdateThread() { return updateThread; }

    void startUpdate(QString component);
};

#endif