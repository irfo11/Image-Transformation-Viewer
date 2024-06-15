#ifndef HIGHPASSFILTERDIALOG_H
#define HIGHPASSFILTERDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"

#include <QSpinBox>
#include "imgtools.h"

class HighPassFilterDialog: public AbstractTransformationDialog
{
    Q_OBJECT
public:
    HighPassFilterDialog(QWidget* parent, cv::Mat& img);
    virtual ~HighPassFilterDialog() = default;
    void transform() override;

private slots:
    void on_dSpinBox_valueChanged(int value);

private:
    QSpinBox* dSpinBox;
};

#endif // LOWPASSFILTERDIALOG_H
