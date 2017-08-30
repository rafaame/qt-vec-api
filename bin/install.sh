#!/bin/sh
cp vec-api.service /lib/systemd/system/vec-api.service
chmod 644 /lib/systemd/system/vec-api.service

systemctl daemon-reload
systemctl enable vec-api