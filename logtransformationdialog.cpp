#include "logtransformationdialog.h"
#include "ui_abstracttransformationdialog.h"

LogTransformationDialog::LogTransformationDialog(QWidget *parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto cLabel = new QLabel("c:", this);
    cDoubleSpinBox = new QDoubleSpinBox(this);
    cDoubleSpinBox->setDecimals(1);
    cDoubleSpinBox->setMinimum(0.);
    cDoubleSpinBox->setMaximum(30.0);
    cDoubleSpinBox->setSingleStep(0.1);
    connect(cDoubleSpinBox, &QDoubleSpinBox::valueChanged, this, &LogTransformationDialog::on_cDoubleSpinBox_valueChanged);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(cLabel, cDoubleSpinBox);
}

void LogTransformationDialog::transform() {
    imgtools::logTransform(this->original, this->transformed, cDoubleSpinBox->value());
}

void LogTransformationDialog::on_cDoubleSpinBox_valueChanged(double arg1)
{
    transform();
    emit updateImage();
}

