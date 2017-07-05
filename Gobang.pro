#-------------------------------------------------
#
# Project created by QtCreator 2017-05-30T23:57:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gobang
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        gamemain.cpp \
    piece.cpp \
    Human.cpp \
    Player.cpp \
    ChessBoard.cpp \
    Computer.cpp \
    start.cpp \
    gobang_point.cpp \
    gobang_turn.cpp

HEADERS  += gamemain.h \
    piece.h \
    Gobang.h \
    Human.hpp \
    Player.hpp \
    ChessBoard.hpp \
    Computer.hpp \
    Gobang_point.h \
    Gobang_turn.h \
    start.h

FORMS    += gamemain.ui \
    start.ui

RESOURCES += \
    icon.qrc

RC_FILE += icon.rc
