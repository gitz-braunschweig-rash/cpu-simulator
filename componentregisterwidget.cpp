#include "componentregisterwidget.h"
#include "ui_componentregisterwidget.h"

ComponentRegisterWidget::ComponentRegisterWidget(QVector<u_int16_t> &_registers, QWidget *parent) :
    QWidget(parent), componentRegisters(_registers), constants_number_of_registers(_registers.size()), ui(new Ui::ComponentRegisterWidget)
{
    ui->setupUi(this);

    for(u_int16_t i = 0; i < constants_number_of_registers; i++)
    {
        layoutVector.push_back(new QVBoxLayout);
        lineEditVector.push_back(new QLineEdit());
        lineEditVector.last()->setReadOnly(true);
        layoutVector.last()->addWidget(lineEditVector.last());
        layoutVector.last()->addWidget(new QLabel("     R" +QString::number(i) ) );

        ui->horizontalLayout->addLayout(layoutVector.last(),0);
    }

    refreshView();
}


ComponentRegisterWidget::~ComponentRegisterWidget()
{
    delete ui;
}

void ComponentRegisterWidget::refreshView()
{
    for(u_int16_t i = 0; i < constants_number_of_registers; i++)
    {
        lineEditVector[i]->setText("0x"+QString::number(componentRegisters[i],16) );
    }
}
