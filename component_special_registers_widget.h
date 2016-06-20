#ifndef COMPONENT_SPECIAL_REGISTERS_WIDGET_H
#define COMPONENT_SPECIAL_REGISTERS_WIDGET_H

#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>


namespace Ui {
class ComponentSpecialRegistersWidget;
}

class ComponentSpecialRegistersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentSpecialRegistersWidget(QWidget *parent = 0);
    ~ComponentSpecialRegistersWidget();

    QLineEdit* programCounter;
    QLineEdit* stackPointer;
    QLineEdit* statusRegister;
    QVBoxLayout* layout_programCounter;
    QVBoxLayout* layout_stackPointer;
    QVBoxLayout* layout_statusRegister;

public slots:
    void changeStackPointer(u_int16_t value);
    void changeProgramCounter(u_int16_t value);
    void changeStatusRegister(u_int16_t value);

private:
    Ui::ComponentSpecialRegistersWidget *ui;
};

#endif // COMPONENT_SPECIAL_REGISTERS_WIDGET_H
