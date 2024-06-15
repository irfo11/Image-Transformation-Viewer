#include "lowpassfilterdialog.h"
#include "ui_abstracttransformationdialog.h"

LowPassFilterDialog::LowPassFilterDialog(QWidget* parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto kLabel = new QLabel("Kernel size: ", this);
    dSpinBox = new QSpinBox(this);
    dSpinBox->setMinimum(1);
    dSpinBox->setMaximum(30);
    dSpinBox->setSingleStep(1);
    connect(dSpinBox, &QSpinBox::valueChanged, this, &LowPassFilterDialog::on_dSpinBox_valueChanged);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(kLabel, dSpinBox);
}

void LowPassFilterDialog::transform() {
    imgtools::applyLowPassFilter(this->original, this->transformed, cv::Size_<int>(dSpinBox->value(), dSpinBox->value()));
    emit updateImage();
}

void LowPassFilterDialog::on_dSpinBox_valueChanged(int val)
{
    transform();
}
