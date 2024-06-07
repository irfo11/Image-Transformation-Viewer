#include "gammatransformationdialog.h"
#include "ui_abstracttransformationdialog.h"

#include <QLabel>

GammaTransformationDialog::GammaTransformationDialog(QWidget* parent, cv::Mat& img):
    AbstractTransformationDialog(parent, img)
{
    auto cLabel = new QLabel("c: ", this);
    cDoubleSpinBox = new QDoubleSpinBox(this);
    cDoubleSpinBox->setDecimals(1);
    cDoubleSpinBox->setMinimum(0.0);
    cDoubleSpinBox->setMaximum(30.0);
    cDoubleSpinBox->setSingleStep(0.1);
    cDoubleSpinBox->setValue(25.0);

    auto gLabel = new QLabel("g: ", this);
    gDoubleSpinBox = new QDoubleSpinBox(this);
    gDoubleSpinBox->setDecimals(2);
    gDoubleSpinBox->setMinimum(0.0);
    gDoubleSpinBox->setMaximum(5.0);
    gDoubleSpinBox->setSingleStep(0.01);
    gDoubleSpinBox->setValue(1.0);

    connect(cDoubleSpinBox, &QDoubleSpinBox::valueChanged, this, &GammaTransformationDialog::on_cDoubleSpinBox_valueChanged);
    connect(gDoubleSpinBox, &QDoubleSpinBox::valueChanged, this, &GammaTransformationDialog::on_gDoubleSpinBox_valueChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->addRow(cLabel, cDoubleSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(gLabel, gDoubleSpinBox);
}

void GammaTransformationDialog::transform() {
    imgtools::gammaTransform(this->original, this->transformed, cDoubleSpinBox->value(), gDoubleSpinBox->value());
    emit updateImage();
}

void GammaTransformationDialog::on_cDoubleSpinBox_valueChanged(double value) {
    transform();
}

void GammaTransformationDialog::on_gDoubleSpinBox_valueChanged(double value) {
    transform();
}


