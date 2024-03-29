#-------------------------------------------------
#
# Project created by QtCreator 2019-12-07T16:18:46
#
#-------------------------------------------------

QT       += core gui sql multimedia multimediawidgets
QT       += core gui printsupport
QT       += core gui network
QT       += widgets multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Shopify
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    caisse.cpp \
    rayon.cpp \
    admin.cpp \
    connection.cpp \
    salaries.cpp \
    conges.cpp \
    employes.cpp \
    smtp.cpp \
    articles.cpp \
    evenement.cpp \
    client.cpp \
    cadeaux.cpp \
    cmdvente.cpp \
    cmdachat.cpp \
    statistique.cpp \
    nightchart.cpp \
    popup.cpp \
    fournisseurs.cpp \
    stock.cpp \
    arduino.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    caisse.h \
    rayon.h \
    admin.h \
    connection.h \
    salaries.h \
    conges.h \
    employes.h \
    smtp.h \
    articles.h \
    evenement.h \
    client.h \
    cadeaux.h \
    cmdvente.h \
    cmdachat.h \
    statistique.h \
    nightchart.h \
    popup.h \
    fournisseurs.h \
    stock.h \
    arduino.h \
    qcustomplot.h

FORMS += \
        mainwindow.ui \
    admin.ui \
    employes.ui \
    statistique.ui

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
