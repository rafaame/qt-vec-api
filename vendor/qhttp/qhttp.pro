TEMPLATE = subdirs

SUBDIRS += src
SUBDIRS += example

example.depends = src
CONFIG += c++14
