#ifndef IOCONTROLLERINTERFACE_H
#define IOCONTROLLERINTERFACE_H

#include "common.h"

class IoControllerInterface {
public:
	virtual ~IoControllerInterface() {};

    virtual bool init() = 0;
    virtual QByteArray *readFrom(quint8 deviceAddress, quint32 size = 0) = 0;
    virtual bool writeTo(quint8 deviceAddress, QByteArray *data) = 0;
};

Q_DECLARE_INTERFACE(IoControllerInterface, "qt-vec-api.IoControllerInterface")

#endif