#ifndef LOGTRANSFORMATIONDIALOG_H
#define LOGTRANSFORMATIONDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"

#include <QDoubleSpinBox>
#include "imgtools.h"

namespace Ui {
class LogTransformationDialog;
}

class LogTransformationDialog : public AbstractTransformationDialog
{
    Q_OBJECT

public:
    explicit LogTransformationDialog(QWidget *parent, cv::Mat& img);
    virtual ~LogTransformationDialog() = default;
    void transform() override;

private slots:
    void on_cDoubleSpinBox_valueChanged(double arg1);

private:
    QDoubleSpinBox* cDoubleSpinBox;
};

#endif // LOGTRANSFORMATIONDIALOG_H
