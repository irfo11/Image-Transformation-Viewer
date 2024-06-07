#include "histogramequalizationdialog.h"
#include "ui_abstracttransformationdialog.h"

#include <QLabel>
#include <QCheckBox>

HistogramEqualizationDialog::HistogramEqualizationDialog(QWidget* parent, cv::Mat& img):
    AbstractTransformationDialog(parent, img)
{
    auto histogramEqualizationLabel = new QLabel("Histogram Equalization");
    auto histogramEqualizationCheckBox = new QCheckBox(parent);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(histogramEqualizationLabel, histogramEqualizationCheckBox);
    connect(histogramEqualizationCheckBox, &QCheckBox::stateChanged,
            this, &HistogramEqualizationDialog::on_histogramEqualizationCheckBox_stateChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->setContentsMargins(50, 0, 0, 0);
}

void HistogramEqualizationDialog::transform() {
    imgtools::histogramEqualization(this->original, this->transformed);
    emit updateImage();
}

void HistogramEqualizationDialog::on_histogramEqualizationCheckBox_stateChanged(int state) {
    if(state) transform();
    else restoreToOriginal();
}
