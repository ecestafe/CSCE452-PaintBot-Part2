#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
#define PI 3.14159265

using namespace std;

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE
    {
    }
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//! [0]
//! [1]
    robot = new Robot;
    robot->setTransform(QTransform::fromScale(1.2, 1.2), true);
    robot->setPos(0, 0);


    scene = new QGraphicsScene(this);
   // GraphicsView view(scene); // adds robot to the scene
    //view.setRenderHint(QPainter::Antialiasing);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
   // view.setBackgroundBrush(QColor(255, 255, 255));
   // view.setWindowTitle("PaintBot");
    //scene->setSceneRect(180, 90, -360, -180);
    ui->graphicsView->setScene(scene);
    scene->addItem(robot);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
   /* for (int i = 0; i < 10; ++i) {
        ColorItem *item = new ColorItem;
        item->setPos(::sin((i * 6.28) / 10.0) * 150,
                     ::cos((i * 6.28) / 10.0) * 150);

        scene.addItem(item);
    }*/




//! [1]
//! [2]


    // view.show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

int i = 5;

void MainWindow::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.setPen(Qt::green);
    //painter.setBrush(Qt::green);
   // painter.drawRect(10,10,100,100);

}

void MainWindow::on_pushButton_clicked()
{
    int rot = 0;
   ui->graphicsView->scene()->removeItem(robot);
    rot = robot->torsoItem->rotation();
    cout<<"left 1: "<<robot->torsoItem->rotation()<<endl;
    cout<<"x: "<<robot->Link3->scenePos().rx()<<"y: "<<robot->Link3->scenePos().ry()<<endl;
    robot->torsoItem->setRotation(rot - 10);
    cout<<"transfrom orgin: "<<robot->torsoItem->transformOriginPoint().x()<<"   "<<robot->torsoItem->transformOriginPoint().y() <<endl;
    scene->addItem(robot);
    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->updateGeometry();
}


void MainWindow::on_pushButton_2_clicked()
{
    int rot = 0;
    cout<<"right 1: "<< robot->torsoItem->rotation() << endl;

    rot = robot->torsoItem->rotation();
    robot->torsoItem->setRotation(rot + 10);
    //scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_3_clicked()
{
    int rot = 0;
    rot = robot->torsoItem2->rotation();
    cout<<"left 2"<<robot->torsoItem2->rotation()<<endl;
    robot->torsoItem2->setRotation(rot - 10);
    //scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_5_clicked()
{
    int rot = 0;
    rot = robot->torsoItem2->rotation();
    cout<<"right 2"<<robot->torsoItem2->rotation()<<endl;
    robot->torsoItem2->setRotation(rot + 10);
    //scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_4_clicked()
{
    int rot = 0;
    rot = robot->torsoItem3->rotation();
    cout<<"left 3"<<robot->torsoItem3->rotation()<<endl;
    robot->torsoItem3->setRotation(rot - 10);
    double Link3y = LINK3*sin((robot->torsoItem3->rotation())* PI/180.0);
    double Link3x = LINK3*cos((robot->torsoItem3->rotation())* PI/180.0);
    cout<<"Link3y: "<<Link3y<<"Lin3x: "<<Link3x <<endl;
    //scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_6_clicked()
{
    const QPen & pen = QPen(Qt::black);

    int rot = 0;
    // auto pos1x=robot->Link3->pos().x() + 20;
    // auto pos1y=robot->Link3->pos().y() + 50;
    cout<<"right 3"<<robot->torsoItem3->rotation()<<endl;
    rot = robot->torsoItem3->rotation();
    robot->torsoItem3->setRotation(rot + 10);
    // auto pos2x=robot->Link3->pos().x() + 10;
    // auto pos2y=robot->Link3->pos().y() + 50;

    //scene->addLine(pos1x,pos1y,pos2x,pos2y, pen);
   // scene->addItem(robot);
    ui->graphicsView->setScene(scene);
   // i = i +5;
}

void MainWindow::on_pushButton_7_clicked()
{
    const QBrush &brush = QBrush(Qt::SolidPattern);
    QGraphicsItemGroup *group = new QGraphicsItemGroup(0);
    QGraphicsItem* parent=robot->Link3;

    //double len = pow((long double)robot->Link3->pos().x(), 2) + pow((long double)robot->Link3->pos().y(), 2);
    //len = sqrt(len);
    //int x1= cos(len);
    //int y1= sin(len);
    auto pos1x=robot->Link3->pos().x()+40;
    auto pos1y=robot->Link3->pos().y();
    QGraphicsEllipseItem* test = new QGraphicsEllipseItem(pos1x,pos1y,10,10,parent);
    test->setBrush(brush);
    group->addToGroup(test);
    scene->addItem(group);
    //scene->addEllipse(pos1x,pos1y,10,10, pen, brush);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_8_clicked()
{

    double Link1y = LINK1*sin(robot->torsoItem->rotation()  * PI/180.0);
    double Link1x = LINK1*cos(robot->torsoItem->rotation()  * PI/180.0);
    cout<<"Link1y: "<<Link1y<<"Lin1x: "<<Link1x <<endl;

    double Link2y = LINK2*sin((robot->torsoItem2->rotation()+ robot->torsoItem->rotation())  * PI/180.0);
    double Link2x = LINK2*cos((robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link2y = Link1y+Link2y;
    Link2x = Link1x+Link2x;
    cout<<"Link2y: "<<Link2y<<"Lin2x: "<<Link2x <<endl;

    double Link3y = LINK3*sin((robot->torsoItem3->rotation()+robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link3x = LINK3*cos((robot->torsoItem3->rotation()+robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link3y = Link2y+Link3y;
    Link3x = Link2x+Link3x;
    cout<<"Link3y: "<<Link3y<<"Lin3x: "<<Link3x <<endl;

    double theta1;
    double theta2;
    double theta3;
    double x_prime;
    double y_prime;
    double phi = atan2((Link3y), (Link3x-20))*(180/PI);
    x_prime = (Link3x-20) - (double)LINK3*cos(phi*(PI/180));
    y_prime = (Link3y) - (double)LINK3*sin(phi*(PI/180));
    double x_prime_squared = pow(x_prime, 2);
    double y_prime_squared = pow(y_prime, 2);
    double link1_squared  = pow((double)LINK1, 2);
    double link2_squared  = pow((double)LINK2, 2);
    double c2 = (x_prime_squared + y_prime_squared - link1_squared - link2_squared)/(2*(double)LINK1*(double)LINK2);
    double s2 = sqrt(1-pow(c2,2));
    cout<<"tan(s2,c2):  "<< atan2(s2,c2)<<endl;
    theta2 = atan2(s2,c2)*(180/PI);
    double k1 = (double)LINK1+ (double)LINK2*c2;
    double k2 = (double)LINK2*s2;
    theta1 = atan2(y_prime,x_prime)*(180/PI) - atan2(k2,k1)*(180/PI);
    theta3 = phi-(theta1+theta2);
    robot->torsoItem->setRotation(theta1);
    robot->torsoItem2->setRotation(theta2);
    robot->torsoItem3->setRotation(theta3);
   // scene->
    cout<<"theta1: "<<theta1<<"theta2: "<<theta2<<"theta3: "<<theta3<<endl;
}


void MainWindow::on_pushButton_9_clicked()
{
    double Link1y = LINK1*sin(robot->torsoItem->rotation()  * PI/180.0);
    double Link1x = LINK1*cos(robot->torsoItem->rotation()  * PI/180.0);
    cout<<"Link1y: "<<Link1y<<"Lin1x: "<<Link1x <<endl;

    double Link2y = LINK2*sin((robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link2x = LINK2*cos((robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link2y = Link1y+Link2y;
    Link2x = Link1x+Link2x;
    cout<<"Link2y: "<<Link2y<<"Lin2x: "<<Link2x <<endl;

    double Link3y = LINK3*sin((robot->torsoItem3->rotation()+robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link3x = LINK3*cos((robot->torsoItem3->rotation()+robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link3y = Link2y+Link3y;
    Link3x = Link2x+Link3x;
    cout<<"Link3y: "<<Link3y<<"Lin3x: "<<Link3x <<endl;

    double theta1;
    double theta2;
    double theta3;
    double x_prime;
    double y_prime;
    double phi = atan2((Link3y), (Link3x+20))*(180/PI);
    x_prime = (Link3x+20) - (double)LINK3*cos(phi*(PI/180));
    y_prime = (Link3y) - (double)LINK3*sin(phi*(PI/180));
    double x_prime_squared = pow(x_prime, 2);
    double y_prime_squared = pow(y_prime, 2);
    double link1_squared  = pow((double)LINK1, 2);
    double link2_squared  = pow((double)LINK2, 2);
    double c2 = (x_prime_squared + y_prime_squared - link1_squared - link2_squared)/(2*(double)LINK1*(double)LINK2);
    double s2 = sqrt(1-pow(c2,2));
    theta2 = atan2(s2,c2)*(180/PI);
    double k1 = (double)LINK1+ (double)LINK2*c2;
    double k2 = (double)LINK2*s2;
    theta1 = atan2(y_prime,x_prime)*(180/PI) - atan2(k2,k1)*(180/PI);
    theta3 = phi-(theta1+theta2);
    robot->torsoItem->setRotation(theta1);
    robot->torsoItem2->setRotation(theta2);
    robot->torsoItem3->setRotation(theta3);
    cout<<"theta1: "<<theta1<<"theta2: "<<theta2<<"theta3: "<<theta3<<endl;

}

void MainWindow::on_pushButton_11_clicked()
{
    double Link1y = LINK1*sin(robot->torsoItem->rotation()  * PI/180.0);
    double Link1x = LINK1*cos(robot->torsoItem->rotation()  * PI/180.0);
    cout<<"Link1y: "<<Link1y<<"Lin1x: "<<Link1x <<endl;

    double Link2y = LINK2*sin((robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link2x = LINK2*cos((robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link2y = Link1y+Link2y;
    Link2x = Link1x+Link2x;
    cout<<"Link2y: "<<Link2y<<"Lin2x: "<<Link2x <<endl;

    double Link3y = LINK3*sin((robot->torsoItem3->rotation()+robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link3x = LINK3*cos((robot->torsoItem3->rotation()+robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link3y = Link2y+Link3y;
    Link3x = Link2x+Link3x;
    cout<<"Link3y: "<<Link3y<<"Lin3x: "<<Link3x <<endl;

    double theta1;
    double theta2;
    double theta3;
    double x_prime;
    double y_prime;
    double phi = atan2((Link3y+20), (Link3x))*(180/PI);
    x_prime = (Link3x) - (double)LINK3*cos(phi*(PI/180));
    y_prime = (Link3y+20) - (double)LINK3*sin(phi*(PI/180));
    double x_prime_squared = pow(x_prime, 2);
    double y_prime_squared = pow(y_prime, 2);
    double link1_squared  = pow((double)LINK1, 2);
    double link2_squared  = pow((double)LINK2, 2);
    double c2 = (x_prime_squared + y_prime_squared - link1_squared - link2_squared)/(2*(double)LINK1*(double)LINK2);
    double s2 = sqrt(1-pow(c2,2));
    theta2 = atan2(s2,c2)*(180/PI);
    double k1 = (double)LINK1+ (double)LINK2*c2;
    double k2 = (double)LINK2*s2;
    theta1 = atan2(y_prime,x_prime)*(180/PI) - atan2(k2,k1)*(180/PI);
    theta3 = phi-(theta1+theta2);
    robot->torsoItem->setRotation(theta1);
    robot->torsoItem2->setRotation(theta2);
    robot->torsoItem3->setRotation(theta3);
    cout<<"theta1: "<<theta1<<"theta2: "<<theta2<<"theta3: "<<theta3<<endl;
}

void MainWindow::on_pushButton_10_clicked()
{
    double Link1y = LINK1*sin(robot->torsoItem->rotation()  * PI/180.0);
    double Link1x = LINK1*cos(robot->torsoItem->rotation()  * PI/180.0);
    cout<<"Link1y: "<<Link1y<<"Lin1x: "<<Link1x <<endl;

    double Link2y = LINK2*sin((robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link2x = LINK2*cos((robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link2y = Link1y+Link2y;
    Link2x = Link1x+Link2x;
    cout<<"Link2y: "<<Link2y<<"Lin2x: "<<Link2x <<endl;

    double Link3y = LINK3*sin((robot->torsoItem3->rotation()+robot->torsoItem2->rotation()+robot->torsoItem->rotation())  * PI/180.0);
    double Link3x = LINK3*cos((robot->torsoItem3->rotation()+robot->torsoItem2->rotation() + robot->torsoItem->rotation())* PI/180.0);
    Link3y = Link2y+Link3y;
    Link3x = Link2x+Link3x;
    cout<<"Link3y: "<<Link3y<<"Lin3x: "<<Link3x <<endl;

    double theta1;
    double theta2;
    double theta3;
    double x_prime;
    double y_prime;
    double phi = atan2((Link3y-20), (Link3x))*(180/PI);
    x_prime = (Link3x) - (double)LINK3*cos(phi*(PI/180));
    y_prime = (Link3y-20) - (double)LINK3*sin(phi*(PI/180));
    double x_prime_squared = pow(x_prime, 2);
    double y_prime_squared = pow(y_prime, 2);
    double link1_squared  = pow((double)LINK1, 2);
    double link2_squared  = pow((double)LINK2, 2);
    double c2 = (x_prime_squared + y_prime_squared - link1_squared - link2_squared)/(2*(double)LINK1*(double)LINK2);
    double s2 = sqrt(1-pow(c2,2));
    theta2 = atan2(s2,c2)*(180/PI);
    double k1 = (double)LINK1+ (double)LINK2*c2;
    double k2 = (double)LINK2*s2;
    theta1 = atan2(y_prime,x_prime)*(180/PI) - atan2(k2,k1)*(180/PI);
    theta3 = phi-(theta1+theta2);
    robot->torsoItem->setRotation(theta1);
    robot->torsoItem2->setRotation(theta2);
    robot->torsoItem3->setRotation(theta3);
    cout<<"theta1: "<<theta1<<"theta2: "<<theta2<<"theta3: "<<theta3<<endl;

}


void MainWindow::on_pushButton_12_clicked()
{
   robot->torsoItem3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
   robot->torsoItem3->setRotation(90);
}
void MainWindow::on_pushButton_13_clicked()
{
   robot->torsoItem3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
   robot->torsoItem3->setRotation(90);
}

