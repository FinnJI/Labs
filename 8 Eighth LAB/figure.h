#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <QPointF>
#include <QMainWindow>


//--------------------------------------------------------------------------------------------

class Figure : public QGraphicsItem
{
public:

    Figure();
    const int OH = 100; // One Hundred
    const int ten = 10;
    const int one = 1;
    const int five = 5;
    const int two = 2;
    const int zero = 0;
    const int three = 3;
    double vx, vy, r, vr;

    double *geometry;
    QPointF nowPos;
//    virtual void print(std::ostream &out) const = 0;
    virtual void print() const = 0;
    virtual void move(int R) = 0;
    QRectF boundingRect() const override = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    friend std::ostream& operator<< (std::ostream& out , Figure const& figure);
    ~Figure(){
        delete [] geometry;
    }
};

//--------------------------------------------------------------------------------------------

class Rectangle : public Figure
{
public:
    Rectangle(int R);
//    void print(std::ostream &out) const override;
    double mypoints[4][2];
    double dx, dy;
    void print() const override;
    void move(int R) override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

//--------------------------------------------------------------------------------------------

class Circle : public Figure
{
public:
    Circle(int R);
//    void print(std::ostream &out) const override;
    void print() const override;
    void move(int R) override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // FIGURE_H
