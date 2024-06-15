#include "gaussiannoisedialog.h"
#include "ui_abstracttransformationdialog.h"

GaussianNoiseDialog::GaussianNoiseDialog(QWidget* parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto meanLabel = new QLabel("Mean: ", this);
    auto devLabel = new QLabel("Deviation: ", this);
    meanDoubleSpinBox = new QDoubleSpinBox(this);
    devDoubleSpinBox = new QDoubleSpinBox(this);
    meanDoubleSpinBox->setDecimals(1);
    meanDoubleSpinBox->setRange(0, 30);
    meanDoubleSpinBox->setSingleStep(0.1);
    devDoubleSpinBox->setDecimals(1);
    devDoubleSpinBox->setRange(0, 30);
    devDoubleSpinBox->setSingleStep(0.1);

    connect(meanDoubleSpinBox, &QDoubleSpinBox::valueChanged, this, &GaussianNoiseDialog::on_meanDoubleSpinBox_valueChanged);
    connect(devDoubleSpinBox, &QDoubleSpinBox::valueChanged, this, &GaussianNoiseDialog::on_devDoubleSpinBox_valueChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->addRow(meanLabel, meanDoubleSpinBox);
    AbstractTransformationDialog::ui->parameterFormLayout->addRow(devLabel, devDoubleSpinBox);
}

void GaussianNoiseDialog::transform()
{
    imgtools::AddGaussianNoise(this->original, this->transformed, meanDoubleSpinBox->value(), devDoubleSpinBox->value());
    emit updateImage();
}


void GaussianNoiseDialog::on_meanDoubleSpinBox_valueChanged(double value)
{
    transform();
}
void GaussianNoiseDialog::on_devDoubleSpinBox_valueChanged(double value)
{
    transform();
}















