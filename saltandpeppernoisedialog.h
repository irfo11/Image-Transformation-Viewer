#ifndef SALTANDPEPPERNOISEDIALOG_H
#define SALTANDPEPPERNOISEDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"

#include <QSpinBox>
#include "imgtools.h"

class SaltAndPepperNoiseDialog: public AbstractTransformationDialog
{
    Q_OBJECT
public:
    SaltAndPepperNoiseDialog(QWidget* parent, cv::Mat& img);
    virtual ~SaltAndPepperNoiseDialog() = default;
    void transform() override;

private slots:
    void on_probSpinBox_valueChanged(int value);

private:
    QSpinBox* probSpinBox;
};

#endif // SALTANDPEPPERNOISEDIALOG_H
