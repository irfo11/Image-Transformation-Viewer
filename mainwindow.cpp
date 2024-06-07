#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "abstracttransformationdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QStringList transformationsList({
                                           "Negative",
                                           "Logarithm",
                                           "Gamma",
                                           "Histogram equalization",
                                           "Binary intenisity level slicing",
                                           "Highlighting intensity level slicing"
                                       });

    ui->setupUi(this);
    ui->transformationsList->addItems(transformationsList);

    original_img = imread("C://Users//Irfo//Documents//fakultet//IV semestar//digitalno procesiranje signala//seminarski//slike//Slika5b_contrast.png", cv::IMREAD_GRAYSCALE);
    if(original_img.empty()) {
        qDebug() << "Treba nesto smisliti";
    }
    original_img.copyTo(transformed_img);

    imageScene = new QGraphicsScene(ui->imageGraphicsView);
    histogramScene = new QGraphicsScene(ui->histogramGraphicsView);
    dftScene = new QGraphicsScene(ui->spectrumGraphicsView);
    showImage();
}

MainWindow::~MainWindow()
{
    qDebug() << "deleting window";
    delete ui;
}

void MainWindow::showImage() {
    imageScene->addPixmap(imgtools::matToPixmap(transformed_img));
    ui->imageGraphicsView->setScene(imageScene);

    cv::Mat histogram = imgtools::plotHistogram(transformed_img, 700, 500);
    histogramScene->addPixmap(imgtools::matToPixmap(histogram));
    ui->histogramGraphicsView->setScene(histogramScene);

    cv::Mat dft = imgtools::plotFourrierTransform(transformed_img);
    dftScene->addPixmap(imgtools::matToPixmap(dft));
    ui->spectrumGraphicsView->setScene(dftScene);
}

void MainWindow::on_resetButton_clicked()
{
    qDebug() << "pressed reset";
    original_img.copyTo(transformed_img);
    showImage();
}


void MainWindow::on_transformationsList_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << item->text();
    QDialog* transformationDialog = nullptr;
    if(item->text().compare("Negative") == 0)
    {
        transformationDialog = new NegativeTransformationDialog(this, transformed_img);
    } else if(item->text().compare("Logarithm") == 0) {
        transformationDialog = new LogTransformationDialog(this, transformed_img);
    } else if(item->text().compare("Gamma") == 0) {
        transformationDialog = new GammaTransformationDialog(this, transformed_img);
    } else if(item->text().compare("Histogram equalization") == 0) {
        transformationDialog = new HistogramEqualizationDialog(this, transformed_img);
    } else if(item->text().compare("Highlighting intensity level slicing") == 0) {
        transformationDialog = new HighlightingIntensityLevelSlicingDialog(this, transformed_img);
    } else if(item->text().compare("Binary intenisity level slicing") == 0) {
        transformationDialog = new BinaryIntensityLevelSlicingDialog(this, transformed_img);
    }
}

