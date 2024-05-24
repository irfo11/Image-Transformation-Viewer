#include "negativetransformationdialog.h"
#include "ui_negativetransformationdialog.h"

NegativeTransformationDialog::NegativeTransformationDialog(QWidget *parent, QListWidgetItem* item,
                                                           cv::Mat& img) :
    QDialog(parent),
    ui(new Ui::NegativeTransformationDialog),
    item(item),
    img(img)
{
    ui->setupUi(this);
}

NegativeTransformationDialog::~NegativeTransformationDialog()
{
    qDebug() << "Deleting dialog";
    delete ui;
}

void NegativeTransformationDialog::on_pushButton_clicked()
{
    close();
}


void NegativeTransformationDialog::on_horizontalSlider_sliderMoved(int position)
{
    imgtools::negativeTransform(img, img);
    emit updateImage();
}


void NegativeTransformationDialog::on_NegativeTransformationDialog_finished(int result)
{
    qDebug() << "yo";
    item->setHidden(false);
}

