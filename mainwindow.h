#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLineEdit>
#include <QScrollArea>
#include <QPushButton>
#include <QRect>
#include "component_ram_widget.h"
#include "componentregisterwidget.h"
#include "component_special_registers_widget.h"
#include "storageunit.h"
#include "hardwareinstructionfetcher.h"
#include "hardware_instruction_decoder.h"
#include "helper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    const u_int16_t constants_ram_size = 64;
    const u_int16_t constants_number_of_registers = 16;
    const u_int16_t constants_framebuffer_size = 4;

    u_int16_t component_program_counter = 0;
    u_int16_t component_stack_pointer = 0;
    u_int16_t component_status_register = 0;
    QVector<u_int16_t> component_ram;
    QVector<u_int16_t> component_registers;
    QScrollArea* scrollAreaRam;
    ComponentRamWidget* ramWidget;
    ComponentRegisterWidget* registerWidget;
    ComponentSpecialRegistersWidget* specialRegisterWidget;
    StorageUnit storageUnit;
    HardwareInstructionFetcher hardwareInstructionFetcher;
    HardwareInstructionDecoder hardwareInstructionDecoder;
    Helper helper;

    void initAll();
    void initRam();
    void initRegisters();
    void initOtherStuff();

public slots:
    void nextStep();
    void updateDisplay();

signals:
    void programCounterChanged(u_int16_t newValue);
    void statusRegisterChanged(u_int16_t newValue);
    void stackPointerChanged(u_int16_t newValue);
    void nextStepHappenedSignal();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
