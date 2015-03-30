// ROBOT_H

#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE
#define LINK1 160
#define LINK2 110
#define LINK3 60

class RobotPart : public QGraphicsObject
{
public:
    RobotPart(QGraphicsItem *parent = 0);


protected:
   // void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    //void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    //void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

    QColor color;
    bool dragOver;
};

class RobotTorso : public RobotPart
{
public:
    RobotTorso(QGraphicsItem *parent = 0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

class RobotLimb : public RobotPart
{
private:
    int link;
public:
    RobotLimb(QGraphicsItem *parent = 0, int link=0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};

class Robot : public RobotPart
{
public:
    Robot(QGraphicsItem *parent = 0);
    QGraphicsObject *torsoItem;
    QGraphicsObject *torsoItem2;
    QGraphicsObject *torsoItem3;
    QGraphicsObject *Link1;
    QGraphicsObject *Link2;
    QGraphicsObject *Link3;
   // QGraphicsObject *Link4;

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};


#endif
