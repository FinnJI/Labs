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
    //----------���������--------------------------------------
    const int K = 25; // ���������� �����
    const int R = 6; // ������������ ��������������
    const int OH = 100; // One Hundred
    const int ten = 10;
    const int one = 1;
    const int five = 5;
    const int two = 2;
    const int zero = 0;

    Figure** figureArr = new Figure*[K];
//    virtual ~Field() {};
private:
    //----------�������----------------------------------------
    void initElements();
    double xrand(double rmin, double rmax);
    //----------������-----------------------------------------
    QGraphicsScene mScene;
    QTimer *timer;

private slots:
    void TimerSlot();

};

#endif // FIELD_H
