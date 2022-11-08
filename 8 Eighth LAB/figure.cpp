#include "figure.h"
#include <field.h>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QWidget>
#include <windows.h>
#include <QDebug>
#include <cmath>
#define PI 3.14159265


Figure::Figure(){
}

//-------------------------------------------------------------------------------------


Rectangle::Rectangle(int R){
    vx = (rand()%(OH*two)-OH)*((double)one/OH);
    vy = (rand()%(OH*two)-OH)*((double)one/OH);
    r = (rand()%(OH*two)-OH)*((double)one/OH);
    vr = (rand()%(OH*two)-OH)*((double)one/OH);

    geometry = new double[two*two];
    geometry[two] = rand()%(OH*R/5); // Width
    geometry[three] = rand()%(OH*R/5); // Height
    geometry[zero] = (geometry[two]) + (rand()%(OH*R - 2*(int)geometry[two])); // x
    geometry[one] = (geometry[three]) + (rand()%(OH*R - 2*(int)geometry[three])); // y

    mypoints[0][0] = geometry[two] / two;
    mypoints[0][1] = geometry[three] / two;// bottom right corner

    mypoints[1][0] = geometry[two] / two;
    mypoints[1][1] = -geometry[three] / two; // top right corner

    mypoints[2][0] = -geometry[two] / two;
    mypoints[2][1] = -geometry[three] / two; // top left corner

    mypoints[3][0] = -geometry[two] / two;
    mypoints[3][1] = geometry[three] / two; // bottom left corner

    for (int i = 0; i < 4; i++) {
        dx = (cos(r * PI / 180)*mypoints[i][0])-(sin(r * PI / 180)*mypoints[i][1]);
        dy = (sin(r * PI / 180)*mypoints[i][0])+(cos(r * PI / 180)*mypoints[i][1]);
        mypoints[i][0] = dx;
        mypoints[i][1] = dy;
    }

    nowPos = QPointF(geometry[zero] , geometry[one] );
}


//void Rectangle::print(std::ostream &out) const{
//    out << "Rectangle " << std::endl << " x = " << geometry[zero]  << ", y=" << geometry[one]<<
//            std::endl<< "Width: " << geometry[two] << std::endl << "Height: " << geometry[three];
//}


void Rectangle::print() const{
    qWarning() << "Rectangle" << "\n" << " x = " << geometry[zero]  << ", y=" << geometry[one]<<
            "\n" << "Width: " << geometry[two] << "\n"  << "Height: " << geometry[three];
}


void Rectangle::move(int R){
    QTransform trans;
    r += vr;
    if (abs(r) >= 360)   {r = (r>0)?r-360:r+360;}
    trans.rotate(r);
    trans.translate(-geometry[two]/2, -geometry[three]/2);
    this->setTransform(trans);

    for (int i = 0; i < 4; i++) {
        dx = (cos(vr * PI / 180)*mypoints[i][0])-(sin(vr * PI / 180)*mypoints[i][1]);
        dy = (sin(vr * PI / 180)*mypoints[i][0])+(cos(vr * PI / 180)*mypoints[i][1]);
        mypoints[i][0] = dx;
        mypoints[i][1] = dy;
    }

    if ((r<90 && r>=0) || (r<-270 && r>=-360)){
        // Top border
        if(geometry[1] + mypoints[2][1] <= (double)zero)
        {
            vy=-vy;
            vr=((vr>0 && mypoints[2][0]<0)||(vr<0 && mypoints[2][0]>0))?-vr:vr;
        }
        // Right border
        if(geometry[0] + mypoints[1][0] >= (double)(OH*R))
        {
            vx=-vx;
            vr=((vr>0 && mypoints[1][1]<0)||(vr<0 && mypoints[1][1]>0))?-vr:vr;
        }
        // Bottom border
        if(geometry[1] + mypoints[0][1] >= (double)(OH*R))
        {
            vy=-vy;
            vr=((vr>0 && mypoints[0][0]>0)||(vr<0 && mypoints[0][0]<0))?-vr:vr;
        }
        // Left border
        if(geometry[0] + mypoints[3][0] <= (double)zero)
        {
            vx=-vx;
            vr=((vr>0 && mypoints[3][1]>0)||(vr<0 && mypoints[3][1]<0))?-vr:vr;
        }

    }
    else if ((r<180 && r>=90) || (r<-180 && r>=-270)){
        // Top border
        if(geometry[1] + mypoints[3][1] <= (double)zero)
        {
            vy=-vy;
            vr=((vr>0 && mypoints[3][0]<0)||(vr<0 && mypoints[3][0]>0))?-vr:vr;
        }
        // Right border
        if(geometry[0] + mypoints[2][0] >= (double)(OH*R))
        {
            vx=-vx;
            vr=((vr>0 && mypoints[2][1]<0)||(vr<0 && mypoints[2][1]>0))?-vr:vr;
        }
        // Bottom border
        if(geometry[1] + mypoints[1][1] >= (double)(OH*R))
        {
            vy=-vy;
            vr=((vr>0 && mypoints[1][0]>0)||(vr<0 && mypoints[1][0]<0))?-vr:vr;
        }
        // Left border
        if(geometry[0] + mypoints[0][0] <= (double)zero)
        {
            vx=-vx;
            vr=((vr>0 && mypoints[0][1]>0)||(vr<0 && mypoints[0][1]<0))?-vr:vr;
        }
    }
    else if ((r<270 && r>=180) || (r<-90 && r>=-180)){
        // Top border
        if(geometry[1] + mypoints[0][1] <= (double)zero)
        {
            vy=-vy;
            vr=((vr>0 && mypoints[0][0]<0)||(vr<0 && mypoints[0][0]>0))?-vr:vr;
        }
        // Right border
        if(geometry[0] + mypoints[3][0] >= (double)(OH*R))
        {
            vx=-vx;
            vr=((vr>0 && mypoints[3][1]<0)||(vr<0 && mypoints[3][1]>0))?-vr:vr;
        }
        // Bottom border
        if(geometry[1] + mypoints[2][1] >= (double)(OH*R))
        {
            vy=-vy;
            vr=((vr>0 && mypoints[2][0]>0)||(vr<0 && mypoints[2][0]<0))?-vr:vr;
        }
        // Left border
        if(geometry[0] + mypoints[1][0] <= (double)zero)
        {
            vx=-vx;
            vr=((vr>0 && mypoints[1][1]>0)||(vr<0 && mypoints[1][1]<0))?-vr:vr;
        }
    }
    else {
        // Top border
        if(geometry[1] + mypoints[1][1] <= (double)zero)
        {
            vy=-vy;
            vr=((vr>0 && mypoints[1][0]<0)||(vr<0 && mypoints[1][0]>0))?-vr:vr;
        }
        // Right border
        if(geometry[0] + mypoints[0][0] >= (double)(OH*R))
        {
            vx=-vx;
            vr=((vr>0 && mypoints[0][1]<0)||(vr<0 && mypoints[0][1]>0))?-vr:vr;
        }
        // Bottom border
        if(geometry[1] + mypoints[3][1] >= (double)(OH*R))
        {
            vy=-vy;
            vr=((vr>0 && mypoints[3][0]>0)||(vr<0 && mypoints[3][0]<0))?-vr:vr;
        }
        // Left border
        if(geometry[0] + mypoints[2][0] <= (double)zero)
        {
            vx=-vx;
            vr=((vr>0 && mypoints[2][1]>0)||(vr<0 && mypoints[2][1]<0))?-vr:vr;
        }
    }

    geometry[zero]+=vx;
    geometry[one]+=vy;
    nowPos.setX(nowPos.x()+vx);
    nowPos.setY(nowPos.y()+vy);
    this->setPos(nowPos);

}


QRectF Rectangle::boundingRect() const
{
    return QRectF(zero, zero, geometry[two], geometry[three]);
}


void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRoundedRect(zero, zero, geometry[two], geometry[three], zero, zero);
}


//-------------------------------------------------------------------------------------


Circle::Circle(int R){
    vx = (rand()%(OH*two)-OH)*((double)one/OH);
    vy = (rand()%(OH*two)-OH)*((double)one/OH);
    geometry = new double[three];
    geometry[two] = rand()%(OH*R/5); // Rad
    geometry[zero] = (geometry[two]/two) + (rand()%(OH*R - (int)geometry[two])); // x
    geometry[one] = (geometry[two]/two) + (rand()%(OH*R - (int)geometry[two])); // y
    nowPos = QPointF(geometry[zero] - (geometry[two]/two), geometry[one] - (geometry[two]/two));
}


//void Circle::print(std::ostream &out) const{
//    out << "Circle " << endl << " x = " << geometry[zero]  << ", y=" << geometry[one]<<
//             endl<< "Radius: " << geometry[two];
//}


void Circle::print() const{
    qWarning() << "Circle " << "\n" << " x = " << geometry[zero]  << ", y=" << geometry[one]<<
                     "\n"<< "Radius: " << geometry[two];
}


void Circle::move(int R){
    // Top border
    if(nowPos.y() <= (double)zero)                       {vy=-vy;}
    // Right border
    if(nowPos.x()+geometry[two] >= (double)(OH*R)){vx=-vx;}
    // Bottom border
    if(nowPos.y()+geometry[two] >= (double)(OH*R)){vy=-vy;}
    // Left border
    if(nowPos.x() <= (double)zero)                       {vx=-vx;}

    nowPos.setX(nowPos.x()+vx);
    nowPos.setY(nowPos.y()+vy);
    this->setPos(nowPos);

}


QRectF Circle::boundingRect() const
{
    return QRectF(zero, zero, geometry[two], geometry[two]);
}


void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(QRectF(zero, zero, geometry[two], geometry[two]));
}
