

#include <QtWidgets>
#include "robot.h"

RobotPart::RobotPart(QGraphicsItem *parent)
    : QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
{
    setAcceptDrops(true);
}

RobotTorso::RobotTorso(QGraphicsItem *parent)
    : RobotPart(parent)
{
}

QRectF RobotTorso::boundingRect() const
{
    return QRectF(-30, -20, 60, 200);
}

void RobotTorso::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawEllipse(5, 350, 20, 20);
}

RobotLimb::RobotLimb(QGraphicsItem *parent, int link)
    : RobotPart(parent)
{
   this->link = link;
}

QRectF RobotLimb::boundingRect() const
{


    if(link == 1){
        return QRectF(-5, -5, 150, 10);
    }
    if(link == 2){
        return QRectF(-5, -5, 100, 10);
    }
    if(link == 3){
        return QRectF(-5, -5, 50, 10);
    }
}

void RobotLimb::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

   // painter->setBrush(dragOver ? color.light(130) : color);
   // painter->drawRoundedRect(boundingRect(), 50, 50, Qt::RelativeSize);
    //painter->drawEllipse(-5, -5, 10, 10);
    if(link == 1){
        painter->drawEllipse(-5, -5, 150, 10);
    }
    if(link == 2){
        painter->drawEllipse(-5, -5, 100, 10);
    }
    if(link == 3){
        painter->drawEllipse(-5, -5, 50, 10);
    }
}


Robot::Robot(QGraphicsItem *parent)
    : RobotPart(parent)
{
    setFlag(ItemHasNoContents);
    torsoItem = new RobotTorso(this);
    Link1 = new RobotLimb(torsoItem,1);
    Link2 = new RobotLimb(Link1,2);
    Link3 = new RobotLimb(Link2,3);
    //Link4 = new RobotLimb(Link3,4);

    auto pos = mapToScene(0,0);
    torsoItem->setPos(pos);
    Link1->setPos(15, 360);
    Link1->setRotation(-90);
    Link2->setPos(140, 0);
    Link2->setRotation(0);
    Link3->setPos(90,0);
    Link3->setRotation(0);
   // Link4->setPos(40,0);
   // Link4->setRotation(0);

}


QRectF Robot::boundingRect() const
{
    return QRectF();
}

void Robot::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

