#!/bin/sh
systemctl stop vec-api

cd /opt/qt-vec-api
qmake
make

systemctl start vec-api