#include "UpdateController.h"

UpdateThread::UpdateThread(QObject *parent) : QThread(parent) {

}

UpdateThread::~UpdateThread() {

}

void UpdateThread::run() {
    QProcess process;
    if (component == "qt-vec-api") {
        if (! QProcess::startDetached("/bin/sh", QStringList() << "/opt/qt-vec-api/bin/self-update.sh", "/opt/qt-vec-api")) {
            emit updateError();
            emit updateFinished();
            return;
        }
    }

    process.setWorkingDirectory(QString("/opt/") + component);
    qDebug() << "Starting update process...";

    qDebug() << "Running 'git pull origin master'";
    process.start("git", QStringList() << "pull" << "origin" << "master");
    if (! process.waitForStarted() || ! process.waitForFinished() || process.exitCode()) {
        emit updateError();
        emit updateFinished();
        return;
    }
    
    qDebug() << "Running 'platformio run --disable-auto-clean -t upload -t nobuild'";
    process.start("platformio", QStringList() << "run" << "--disable-auto-clean" << "-t" << "upload" << "-t" << "nobuild");
    if (! process.waitForStarted() || ! process.waitForFinished(60000) || process.exitCode()) {
        emit updateError();
        emit updateFinished();
        return;
    }

    qDebug() << "Updated succeeded!";

    // @FIXME sleep to wait devices init?
    emit updateSuccess();
    emit updateFinished();
}

void UpdateThread::prepare(QString component) {
    this->component = component;
}

UpdateController::UpdateController(QObject *parent) : QObject(parent) {
    updateThread = new UpdateThread(this);
}

UpdateController::~UpdateController() {
    
}

void UpdateController::startUpdate(QString component) {
    updateThread->prepare(component);
    updateThread->start();
}