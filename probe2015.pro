TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fahrzeug.cpp \
        lkw.cpp \
        main.cpp \
        mystack.cpp \
        pkw.cpp \
        verwaltung.cpp

HEADERS += \
    fahrzeug.h \
    lkw.h \
    mystack.h \
    pkw.h \
    verwaltung.h
