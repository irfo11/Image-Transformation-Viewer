#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include "negativetransformationdialog.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "imgtools.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_resetButton_clicked();

    void on_transformationsList_itemDoubleClicked(QListWidgetItem *item);

    void showImage();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* imageScene = nullptr;
    QGraphicsScene* histogramScene = nullptr;
    QGraphicsScene* dftScene = nullptr;
    cv::Mat original_img;
    cv::Mat transformed_img;

    NegativeTransformationDialog* negativeTransformationDialog = nullptr;
};
#endif // MAINWINDOW_H
