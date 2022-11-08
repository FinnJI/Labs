#include "field.h"
#include "figure.h"
#include <QTimer>
Field::Field()
{
    setRenderHint(QPainter::Antialiasing);

    setCacheMode(QGraphicsView::CacheNone);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


//    setWindowTitle("LAB");

    setFrameStyle(zero);
    setSceneRect(zero, zero, OH*R, OH*R);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setFixedSize(OH*R, OH*R);

    mScene.setItemIndexMethod(QGraphicsScene::NoIndex);

    setScene(&mScene);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(ten);

    initElements();


}

//------------------------------------------------------------------

double Field::xrand (double rmin, double rmax){
    double z;
    z = rmin + ((double)rand()/RAND_MAX)*(rmax-rmin);
    return z;
}

void Field::TimerSlot()
{
    for (int i = zero; i < K; i++) {
        figureArr[i]->move(R);
    }
}

void Field::initElements()
{
    QPolygon pol;
    pol << QPoint(zero,zero) << QPoint(OH*R,zero) << QPoint(OH*R,OH*R) << QPoint(zero,OH*R);
    mScene.addPolygon(pol);
    for (int i = zero; i < K; i++) {
        if(xrand(zero, one)>(double)five/ten){
            figureArr[i] = new Rectangle(R);
        }
        else{
            figureArr[i] = new Circle(R);
        }
        figureArr[i]->setPos(figureArr[i]->nowPos);
        mScene.addItem(figureArr[i]);
    }
}
