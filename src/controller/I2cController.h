#ifndef I2CCONTROLLER_H
#define I2CCONTROLLER_H

#include "common.h"
#include "IoControllerInterface.h"

class I2cController : public QObject, public IoControllerInterface {
    Q_OBJECT
    Q_INTERFACES(IoControllerInterface)

private:
	int handler;
	bool probe;
    QMutex mutex;
    
public:
    I2cController(QObject *parent = nullptr);
    virtual ~I2cController();

    virtual bool init();
    virtual QByteArray *readFrom(quint8 deviceAddress, quint32 size = 0);
    virtual bool writeTo(quint8 deviceAddress, QByteArray *data);

    bool probeI2c() {
    	bool before = probe;
    	probe = true;
    	return before;
    };
};

#endif