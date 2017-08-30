#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <sstream>

#include <QObject>
#include <QtNetwork>
#include <QCoreApplication>
#include <QDebug>

#define QHTTP_HAS_CLIENT
#include <qhttpserver.hpp>
#include <qhttpserverconnection.hpp>
#include <qhttpserverrequest.hpp>
#include <qhttpserverresponse.hpp>
#include <qhttpclient.hpp>
#include <qhttpclientrequest.hpp>
#include <qhttpclientresponse.hpp>