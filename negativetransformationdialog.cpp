#include "negativetransformationdialog.h"
#include "ui_abstracttransformationdialog.h"

#include <QPushButton>
#include <QFormLayout>
#include <QCheckBox>
#include <mainwindow.h>

NegativeTransformationDialog::NegativeTransformationDialog(QWidget *parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto negativeLabel = new QLabel("Negative:", this);
    auto negativeCheckBox = new QCheckBox(this);
    connect(negativeCheckBox, &QCheckBox::stateChanged, this, &NegativeTransformationDialog::on_negativeCheckBox_stateChanged);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(negativeLabel, negativeCheckBox);
}

NegativeTransformationDialog::~NegativeTransformationDialog()
{
    qDebug() << "Deleting dialog";
}

void NegativeTransformationDialog::on_negativeCheckBox_stateChanged(int state)
{
    transform();
}

void NegativeTransformationDialog::transform() {
    imgtools::negativeTransform(this->transformed, this->transformed);
    emit updateImage();
}



