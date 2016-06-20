#ifndef RAM_WIDGET_H
#define RAM_WIDGET_H

#include <QWidget>
#include <QVector>

class ram_widget : public QWidget
{
    Q_OBJECT
public:
    explicit ram_widget(QWidget *parent = 0, QVector& _ram);

    QVector& componentRam;

signals:

public slots:

};

#endif // RAM_WIDGET_H
