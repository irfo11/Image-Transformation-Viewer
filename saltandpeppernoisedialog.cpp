#include "saltandpeppernoisedialog.h"
#include "ui_abstracttransformationdialog.h"

SaltAndPepperNoiseDialog::SaltAndPepperNoiseDialog(QWidget* parent, cv::Mat& img) :
    AbstractTransformationDialog(parent, img)
{
    auto probLabel = new QLabel("Probability: ", this);
    probSpinBox = new QSpinBox(this);
    probSpinBox->setRange(0, 100);
    probSpinBox->setSingleStep(1);

    connect(probSpinBox, &QSpinBox::valueChanged, this, &SaltAndPepperNoiseDialog::on_probSpinBox_valueChanged);

    AbstractTransformationDialog::ui->parameterFormLayout->addRow(probLabel, probSpinBox);
}

void SaltAndPepperNoiseDialog::transform()
{
    imgtools::AddSaltAndPepperNoise(this->original, this->transformed, probSpinBox->value());
    emit updateImage();
}


void SaltAndPepperNoiseDialog::on_probSpinBox_valueChanged(int value)
{
    transform();
}

