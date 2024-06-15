#ifndef LOWPASSFILTERDIALOG_H
#define LOWPASSFILTERDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"

#include <QSpinBox>
#include "imgtools.h"

class LowPassFilterDialog: public AbstractTransformationDialog
{
    Q_OBJECT
public:
    LowPassFilterDialog(QWidget* parent, cv::Mat& img);
    virtual ~LowPassFilterDialog() = default;
    void transform() override;

private slots:
    void on_dSpinBox_valueChanged(int value);

private:
    QSpinBox* dSpinBox;
};

#endif // LOWPASSFILTERDIALOG_H
