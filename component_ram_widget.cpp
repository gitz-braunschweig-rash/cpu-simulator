#include "component_ram_widget.h"
#include "ui_component_ram_widget.h"

ComponentRamWidget::ComponentRamWidget(QVector<u_int16_t>& _ram, u_int16_t& _programm_counter, u_int16_t &_stack_pointer, QWidget *parent) :
    QWidget(parent), componentRam(_ram), constants_ram_size(_ram.size()), programm_counter(_programm_counter), stack_pointer(_stack_pointer), ui(new Ui::ComponentRamWidget)
{
    ui->setupUi(this);
    this->setGeometry(0,0,_ram.size()*72,70);
    this->setMinimumSize(_ram.size()*72,70);
    this->setMinimumWidth(_ram.size()*72);
    this->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

    horizentalLayout = new QHBoxLayout;

    //horizentalLayout->setContentsMargins(0,0,80,0);
    //horizentalLayout->setSpacing(40);

    this->setLayout(horizentalLayout);

    for(u_int16_t i = 0; i < constants_ram_size; i++)
    {
        layoutVector.push_back(new QVBoxLayout);
        lineEditVector.push_back(new QLineEdit());
        lineEditVector.last()->setMinimumWidth(70);
        lineEditVector.last()->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
        lineEditVector.last()->setReadOnly(true);

        layoutVector.last()->addWidget(lineEditVector.last());
        layoutVector.last()->addWidget(new QLabel(" 0x"+QString::number(i*2,16).toUpper()));

        this->horizentalLayout->addLayout(layoutVector.last(),0);
    }

    refreshView();
}

ComponentRamWidget::~ComponentRamWidget()
{
    delete ui;
}

void ComponentRamWidget::refreshView()
{
    for(size_t i = 0; i < constants_ram_size; i++)
    {
        lineEditVector[i]->setText("0x"+QString::number(componentRam[i],16));
        lineEditVector[i]->setStyleSheet("");
    }

    lineEditVector[programm_counter/2]->setStyleSheet("QLineEdit {background-color: Yellow;}");
    lineEditVector[stack_pointer/2]->setStyleSheet("QLineEdit {background-color: Orange;}");

}
