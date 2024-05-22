#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = new QImage("C:\\Users\\Irfo\\Documents\\fakultet\\IV semestar\\digitalno procesiranje signala\\seminarski\\slike\\Slika1_mamografija.png");
    if(image->isNull()) {
        ui->label->setText("Its null bruh");
    }
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete image;
}

