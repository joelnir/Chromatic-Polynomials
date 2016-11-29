TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    poly.cpp \
    graph.cpp

HEADERS += \
    node.h \
    poly.h \
    graph.h
