#-------------------------------------------------
#
# Project created by QtCreator 2020-04-09T06:08:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
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


SOURCES += \
    objects/units/Archer.cpp \
    objects/units/DemonWarrior.cpp \
    objects/units/ElfArcher.cpp \
    objects/units/HumanWarrior.cpp \
    objects/units/SkeletonArcher.cpp \
    objects/units/Unit.cpp \
    objects/units/Warrior.cpp \
    objects/Object.cpp \
    main.cpp \
    MainWindow.cpp \
    fabrics/UnitFabric.cpp \
    fabrics/ObjectFabric.cpp \
    fabrics/GoodFabric.cpp \
    fabrics/EvilFabric.cpp \
    objects/Point.cpp \
    objects/units/Arrow.cpp \
    objects/units/EconomicArmy.cpp \
    objects/units/Army.cpp

HEADERS += \
    objects/units/Archer.h \
    objects/units/DemonWarrior.h \
    objects/units/ElfArcher.h \
    objects/units/HumanWarrior.h \
    objects/units/SkeletonArcher.h \
    objects/units/Unit.h \
    objects/units/Warrior.h \
    objects/Object.h \
    MainWindow.h \
    fabrics/UnitFabric.h \
    fabrics/ObjectFabric.h \
    fabrics/GoodFabric.h \
    fabrics/EvilFabric.h \
    objects/Point.h \
    objects/units/Arrow.h \
    objects/units/EconomicArmy.h \
    objects/units/Army.h

FORMS += \
    MainWindow.ui
