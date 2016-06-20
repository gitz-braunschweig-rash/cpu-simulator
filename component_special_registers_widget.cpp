#include "component_special_registers_widget.h"
#include "ui_component_special_registers_widget.h"

ComponentSpecialRegistersWidget::ComponentSpecialRegistersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponentSpecialRegistersWidget)
{
    ui->setupUi(this);

    programCounter = new QLineEdit;
    stackPointer = new QLineEdit;
    statusRegister = new QLineEdit;
    layout_programCounter = new QVBoxLayout;
    layout_stackPointer = new QVBoxLayout;
    layout_statusRegister = new QVBoxLayout;


    layout_programCounter->addWidget(programCounter);
    layout_programCounter->addWidget(new QLabel("Program-Counter"));

    layout_stackPointer->addWidget(stackPointer);
    layout_stackPointer->addWidget(new QLabel("Stackpointer"));

    layout_statusRegister->addWidget(statusRegister);
    layout_statusRegister->addWidget(new QLabel("Status-Register"));

    ui->horizontalLayout->addLayout(layout_programCounter,0);
    ui->horizontalLayout->addLayout(layout_stackPointer,0);
    ui->horizontalLayout->addLayout(layout_statusRegister,0);

    stackPointer->setAlignment(Qt::AlignCenter);
    programCounter->setAlignment(Qt::AlignCenter);
    statusRegister->setAlignment(Qt::AlignCenter);

}

ComponentSpecialRegistersWidget::~ComponentSpecialRegistersWidget()
{
    delete ui;
}

void ComponentSpecialRegistersWidget::changeStackPointer(u_int16_t value)
{
    stackPointer->setText(QString::number(value,16));
}

void ComponentSpecialRegistersWidget::changeProgramCounter(u_int16_t value)
{
    programCounter->setText(QString::number(value,16));
}

void ComponentSpecialRegistersWidget::changeStatusRegister(u_int16_t value)
{
    statusRegister->setText(QString::number(value,10) + " "+ " (0b" + QString::number(value,2) + ")");
}

