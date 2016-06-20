#ifndef COMPONENT_RAM_WIDGET_H
#define COMPONENT_RAM_WIDGET_H

#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QRect>

namespace Ui {
class ComponentRamWidget;
}

class ComponentRamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentRamWidget(QVector<u_int16_t>& _ram, u_int16_t& _programm_counter, u_int16_t& _stack_pointer, QWidget *parent = 0);
    ~ComponentRamWidget();

    QVector<u_int16_t>& componentRam;
    u_int16_t& programm_counter;
    u_int16_t& stack_pointer;
    const u_int16_t constants_ram_size;
    QVector<QVBoxLayout*> layoutVector;
    QVector<QLineEdit*> lineEditVector;
    QHBoxLayout* horizentalLayout;

public slots:
    void refreshView();



private:
    Ui::ComponentRamWidget *ui;
};

#endif // COMPONENT_RAM_WIDGET_H
