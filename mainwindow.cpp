#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    storageUnit(component_ram, component_registers, component_status_register, component_program_counter, component_stack_pointer),
    hardwareInstructionFetcher(storageUnit),
    hardwareInstructionDecoder(storageUnit),
    helper(component_ram,component_registers),
    ui(new Ui::MainWindow)
{

    initAll();

    ui->setupUi(this);
    ramWidget = new ComponentRamWidget(component_ram,component_program_counter,component_stack_pointer, this);
    registerWidget = new ComponentRegisterWidget(component_registers,this);
    specialRegisterWidget = new ComponentSpecialRegistersWidget();

    scrollAreaRam = new QScrollArea;
    scrollAreaRam->setFixedHeight(90);
    scrollAreaRam->setWidget(ramWidget);



    ui->horizontalLayout->addWidget(scrollAreaRam);
    ui->horizontalLayout_2->addWidget(registerWidget);
    ui->horizontalLayout_4->addWidget(specialRegisterWidget);

    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(nextStep()));
    connect(this,SIGNAL(programCounterChanged(u_int16_t)),specialRegisterWidget,SLOT(changeProgramCounter(u_int16_t)));
    connect(this,SIGNAL(statusRegisterChanged(u_int16_t)),specialRegisterWidget,SLOT(changeStatusRegister(u_int16_t)));
    connect(this,SIGNAL(stackPointerChanged(u_int16_t)),specialRegisterWidget,SLOT(changeStackPointer(u_int16_t)));

    connect(this,SIGNAL(nextStepHappenedSignal() ), ramWidget, SLOT(refreshView() ) );
    connect(this,SIGNAL(nextStepHappenedSignal() ), registerWidget, SLOT(refreshView() ) );

    emit programCounterChanged(component_program_counter);
    emit stackPointerChanged(component_stack_pointer);
    emit statusRegisterChanged(component_status_register);


    /*
    //0100 0001 1100 0011
    component_ram[0] = 16835;

    //A=65, 0100 0001 0100 0001
    component_ram[component_ram.size()-4] = 16705;
    component_ram[component_ram.size()-3] = 16705;
    component_ram[component_ram.size()-2] = 16705;
    component_ram[component_ram.size()-1] = 16705;
    */

    //component_stack_pointer = component_ram.size()-5;

    helper.readRamFile("ramfile.txt");
    helper.readRegisterFile("registerfile.txt");

    ramWidget->refreshView();
    registerWidget->refreshView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAll()
{
    initRam();
    initRegisters();
    initOtherStuff();
}

void MainWindow::initRam()
{
    for(u_int16_t i = 0; i < this->constants_ram_size; i++)
    {
        component_ram.push_back(0);
    }
}

void MainWindow::initRegisters()
{
    for(u_int16_t i = 0; i < this->constants_number_of_registers; i++)
    {
        component_registers.push_back(0);
    }
}

void MainWindow::initOtherStuff()
{
    component_program_counter = 0;
    component_stack_pointer = component_ram.size()*2-10;
    component_status_register = 0;
}

void MainWindow::nextStep()
{
    u_int64_t instruction = hardwareInstructionFetcher.getInstruction(component_program_counter);

    component_program_counter++;
    component_program_counter++; //two times since we are doing 16 bit reads, not via uint16* but via simple QVector actions. Slower but better to debug
    hardwareInstructionDecoder.decode(instruction);

    //qDebug() << hardwareInstructionDecoder.opcodeFirstHalf << hardwareInstructionDecoder.opcodeSecondHalf << hardwareInstructionDecoder.secondOcted;

    emit programCounterChanged(component_program_counter);
    emit statusRegisterChanged(component_status_register);
    emit stackPointerChanged(component_stack_pointer);
    emit nextStepHappenedSignal();
    ui->lineEditCurrentInstruction->setText(QString::number(instruction));
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    char* display_text_pointer = (char*) (component_ram.data()+ component_ram.size() - constants_framebuffer_size);
    QString displayText (display_text_pointer);
    ui->lineEditDisplay->setText(displayText);
}
