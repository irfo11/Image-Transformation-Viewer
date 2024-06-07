#include "highlightingintensitylevelslicingdialog.h"
#include "ui_abstracttransformationdialog.h"

#include <QLabel>
#include <QMessageBox>

HighlightingIntensityLevelSlicingDialog::HighlightingIntensityLevelSlicingDialog(QWidget* parent, cv::Mat& img):
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
            this, &HighlightingIntensityLevelSlicingDialog::on_minValueSpinBox_valueChanged);

    connect(maxValueSpinBox, &QSpinBox::valueChanged,
            this, &HighlightingIntensityLevelSlicingDialog::on_maxValueSpinBox_valueChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->addRow(minValueLabel, minValueSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(maxValueLabel, maxValueSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->setContentsMargins(50, 0, 0, 0);
}

void HighlightingIntensityLevelSlicingDialog::transform() {
    if(minValueSpinBox->value() < maxValueSpinBox->value()) {
        imgtools::highlightingIntensityLevelSlicing(this->original, this->transformed,
                                                    minValueSpinBox->value(), maxValueSpinBox->value());
        emit updateImage();
    }
}

void HighlightingIntensityLevelSlicingDialog::on_minValueSpinBox_valueChanged(int value) {
    transform();
}

void HighlightingIntensityLevelSlicingDialog::on_maxValueSpinBox_valueChanged(int value) {
    transform();
}
