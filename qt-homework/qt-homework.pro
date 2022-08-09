QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
RC_FILE = abc.rc
TARGET = Kriegspiel
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Create_the_connection.cpp \
    chesses.cpp \
    error_surrender.cpp \
    main.cpp \
    mainwindow.cpp \
    server.cpp

HEADERS += \
    Create_the_connection.h \
    chesses.h \
    error_surrender.h \
    mainwindow.h \
    server.h

FORMS += \
    Create_the_connection.ui \
    error_surrender.ui \
    mainwindow.ui \
    server.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myrc.qrc
