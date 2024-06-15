#include "highpassfilterdialog.h"
#include "ui_abstracttransformationdialog.h"

HighPassFilterDialog::HighPassFilterDialog(QWidget* parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto dLabel = new QLabel("Kernel size: ", this);
    dSpinBox = new QSpinBox(this);
    dSpinBox->setMinimum(1);
    dSpinBox->setMaximum(30);
    dSpinBox->setSingleStep(1);
    connect(dSpinBox, &QSpinBox::valueChanged, this, &HighPassFilterDialog::on_dSpinBox_valueChanged);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(dLabel, dSpinBox);
}

void HighPassFilterDialog::transform() {
    imgtools::applyHighPassFilter(this->original, this->transformed, cv::Size_<int>(dSpinBox->value(), dSpinBox->value()));
    emit updateImage();
}

void HighPassFilterDialog::on_dSpinBox_valueChanged(int val)
{
    transform();
}
