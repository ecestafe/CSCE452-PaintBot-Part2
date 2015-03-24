#include "mainwindow.h"
#include "ui_mainwindow.h"



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
    GraphicsView view(scene); // adds robot to the scene
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(255, 255, 255));
    view.setWindowTitle("PaintBot");
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);

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
    rot = robot->Link1->rotation();
    robot->Link1->setRotation(rot - 10);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_pushButton_2_clicked()
{
    int rot = 0;
    rot = robot->Link1->rotation();
    robot->Link1->setRotation(rot + 10);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_3_clicked()
{
    int rot = 0;
    rot = robot->Link2->rotation();
    robot->Link2->setRotation(rot - 10);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_5_clicked()
{
    int rot = 0;
    rot = robot->Link2->rotation();
    robot->Link2->setRotation(rot + 10);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_4_clicked()
{
    int rot = 0;
    rot = robot->Link3->rotation();
    robot->Link3->setRotation(rot - 10);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_6_clicked()
{
    const QPen & pen = QPen(Qt::black);

    int rot = 0;
    // auto pos1x=robot->Link3->pos().x() + 20;
    // auto pos1y=robot->Link3->pos().y() + 50;
    rot = robot->Link3->rotation();
    robot->Link3->setRotation(rot + 5);
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

    double len = pow((long double)robot->Link3->pos().x(), 2) + pow((long double)robot->Link3->pos().y(), 2);
    len = sqrt(len);
    int x1= cos(len);
    int y1= sin(len);
    auto pos1x=x1+40;
    auto pos1y=y1-10;
    QGraphicsEllipseItem* test = new QGraphicsEllipseItem(pos1x,pos1y,20,20,parent);
    test->setBrush(brush);
    group->addToGroup(test);
    scene->addItem(group);
    //scene->addEllipse(pos1x,pos1y,10,10, pen, brush);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_8_clicked()
{
    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);

    double rot = robot->Link2->rotation();
    robot->Link2->setRotation(rot - 5);

    //double rot2 = robot->Link3->rotation();
    //robot->Link3->setRotation(rot2 + 5);

    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
}

void MainWindow::on_pushButton_9_clicked()
{
    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);

    double rot = robot->Link2->rotation();
    robot->Link2->setRotation(rot + 5);

    //double rot2 = robot->Link3->rotation();
    //robot->Link3->setRotation(rot2 - 5);

    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
}

void MainWindow::on_pushButton_11_clicked()
{
    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);

    if(robot->Link1->rotation() > -90){
        double rot = robot->Link1->rotation();
        robot->Link1->setRotation(rot + 5);
        //double rot2 = robot->Link2->rotation();
        //robot->Link2->setRotation(rot2 + 10);
    }
    else{
        double rot = robot->Link1->rotation();
        robot->Link1->setRotation(rot - 5);
        //double rot2 = robot->Link2->rotation();
        //robot->Link2->setRotation(rot2 - 10);
    }


    if(robot->Link2->rotation() > -90){
        double rot2 = robot->Link2->rotation();
        robot->Link2->setRotation(rot2 + 10);
    }
    else{
        double rot2 = robot->Link2->rotation();
        robot->Link2->setRotation(rot2 - 10);
    }

    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
}

void MainWindow::on_pushButton_10_clicked()
{
    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);

    if(robot->Link1->rotation() < -90){
        double rot = robot->Link1->rotation();
        robot->Link1->setRotation(rot + 5);
        //double rot2 = robot->Link2->rotation();
        //robot->Link2->setRotation(rot2 + 10);
    }
    else if(robot->Link1->rotation() == -90)
        ;
    else{
        double rot = robot->Link1->rotation();
        robot->Link1->setRotation(rot - 5);
        //double rot2 = robot->Link2->rotation();
        //robot->Link2->setRotation(rot2 - 10);
    }


    if(robot->Link2->rotation() < -90){
        double rot2 = robot->Link2->rotation();
        robot->Link2->setRotation(rot2 + 10);
    }
    else{
        double rot2 = robot->Link2->rotation();
        robot->Link2->setRotation(rot2 - 10);
    }

    //robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
}
void MainWindow::on_pushButton_12_clicked()
{
   robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
   robot->Link3->setRotation(-90);
}
void MainWindow::on_pushButton_13_clicked()
{
   robot->Link3->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
   robot->Link3->setRotation(90);
}
