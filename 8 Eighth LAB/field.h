#ifndef FIELD_H
#define FIELD_H
#include <QEvent>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "figure.h"

class Field : public QGraphicsView
{
    Q_OBJECT;
public:

    Field();
    //----------Константы--------------------------------------
    const int K = 25; // Количество фигур
    const int R = 6; // Максимальная геометрическая
    const int OH = 100; // One Hundred
    const int ten = 10;
    const int one = 1;
    const int five = 5;
    const int two = 2;
    const int zero = 0;

    Figure** figureArr = new Figure*[K];
//    virtual ~Field() {};
private:
    //----------Функции----------------------------------------
    void initElements();
    double xrand(double rmin, double rmax);
    //----------Классы-----------------------------------------
    QGraphicsScene mScene;
    QTimer *timer;

private slots:
    void TimerSlot();

};

#endif // FIELD_H
