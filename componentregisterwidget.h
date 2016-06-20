#ifndef COMPONENTREGISTERWIDGET_H
#define COMPONENTREGISTERWIDGET_H

#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

namespace Ui {
class ComponentRegisterWidget;
}

class ComponentRegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentRegisterWidget(QVector<u_int16_t>& _registers, QWidget *parent = 0);
    ~ComponentRegisterWidget();

    QVector<u_int16_t>& componentRegisters;
    const u_int16_t constants_number_of_registers = 16;
    QVector<QVBoxLayout*> layoutVector;
    QVector<QLineEdit*> lineEditVector;

public slots:
    void refreshView();

private:
    Ui::ComponentRegisterWidget *ui;
};

#endif // COMPONENTREGISTERWIDGET_H
