#include "binaryintensityslicingdialog.h"
#include "ui_abstracttransformationdialog.h"

#include <QLabel>
#include <QMessageBox>

BinaryIntensityLevelSlicingDialog::BinaryIntensityLevelSlicingDialog(QWidget* parent, cv::Mat& img):
    AbstractTransformationDialog(parent, img)
{
    auto minValueLabel = new QLabel("Min: ", this);
    auto maxValueLabel = new QLabel("Max: ", this);

    minValueSpinBox = new QSpinBox(this);
    minValueSpinBox->setRange(0, 254);
    minValueSpinBox->setSingleStep(1);
    minValueSpinBox->setValue(10);

    maxValueSpinBox = new QSpinBox(this);
    maxValueSpinBox->setRange(1, 255);
    maxValueSpinBox->setSingleStep(1);
    maxValueSpinBox->setValue(50);

    connect(minValueSpinBox, &QSpinBox::valueChanged,
            this, &BinaryIntensityLevelSlicingDialog::on_minValueSpinBox_valueChanged);

    connect(maxValueSpinBox, &QSpinBox::valueChanged,
            this, &BinaryIntensityLevelSlicingDialog::on_maxValueSpinBox_valueChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->addRow(minValueLabel, minValueSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(maxValueLabel, maxValueSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->setContentsMargins(50, 0, 0, 0);
}

void BinaryIntensityLevelSlicingDialog::transform() {
    if(minValueSpinBox->value() < maxValueSpinBox->value()) {
        imgtools::binaryIntensityLevelSlicing(this->original, this->transformed,
                                                    minValueSpinBox->value(), maxValueSpinBox->value());
        emit updateImage();
    }
}

void BinaryIntensityLevelSlicingDialog::on_minValueSpinBox_valueChanged(int value) {
    transform();
}

void BinaryIntensityLevelSlicingDialog::on_maxValueSpinBox_valueChanged(int value) {
    transform();
}
