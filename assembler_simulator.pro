#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T11:24:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assembler_simulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    component_ram_widget.cpp \
    componentregisterwidget.cpp \
    component_special_registers_widget.cpp \
    hardwareinstructionfetcher.cpp \
    storageunit.cpp \
    hardware-instruction_decoder.cpp \
    helper.cpp \
    alu.cpp \
    genericcpucomponent.cpp \
    flowandstatuscontroller.cpp

HEADERS  += mainwindow.h \
    component_ram_widget.h \
    componentregisterwidget.h \
    component_special_registers_widget.h \
    hardwareinstructionfetcher.h \
    storageunit.h \
    hardware_instruction_decoder.h \
    helper.h \
    alu.h \
    genericcpucomponent.h \
    command_constants.h \
    flowandstatuscontroller.h

FORMS    += mainwindow.ui \
    component_ram_widget.ui \
    componentregisterwidget.ui \
    component_special_registers_widget.ui

CONFIG += c++11
