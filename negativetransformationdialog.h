#ifndef NEGATIVETRANSFORMATIONDIALOG_H
#define NEGATIVETRANSFORMATIONDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

#include "imgtools.h"

#include "opencv2/core.hpp"

namespace Ui {
class NegativeTransformationDialog;
}

class NegativeTransformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NegativeTransformationDialog(QWidget *parent, QListWidgetItem* item,
                                          cv::Mat& img);
    ~NegativeTransformationDialog();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_NegativeTransformationDialog_finished(int result);

signals:
    void updateImage();

private:
    Ui::NegativeTransformationDialog *ui;
    QListWidgetItem* item;
    cv::Mat& img;
    int negative;
};

#endif // NEGATIVETRANSFORMATIONDIALOG_H
