#ifndef GAUSSIANNOISEDIALOG_H
#define GAUSSIANNOISEDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"

#include <QDoubleSpinBox>
#include "imgtools.h"

class GaussianNoiseDialog: public AbstractTransformationDialog
{
    Q_OBJECT
public:
    GaussianNoiseDialog(QWidget* parent, cv::Mat& img);
    virtual ~GaussianNoiseDialog() = default;
    void transform() override;

private slots:
    void on_meanDoubleSpinBox_valueChanged(double value);
    void on_devDoubleSpinBox_valueChanged(double value);

private:
    QDoubleSpinBox* meanDoubleSpinBox;
    QDoubleSpinBox* devDoubleSpinBox;
};

#endif // GAUSSIANNOISEDIALOG_H
