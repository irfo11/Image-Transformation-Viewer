#ifndef GAMMATRANSFORMATIONDIALOG_H
#define GAMMATRANSFORMATIONDIALOG_H

#include "abstracttransformationdialog.h"

#include "opencv2/core.hpp"
#include "imgtools.h"

#include <QDoubleSpinBox>

class GammaTransformationDialog : public AbstractTransformationDialog
{
    Q_OBJECT
public:
    GammaTransformationDialog(QWidget* parent, cv::Mat& img);
    virtual ~GammaTransformationDialog() = default;
    void transform() override;

private slots:
    void on_cDoubleSpinBox_valueChanged(double value);
    void on_gDoubleSpinBox_valueChanged(double value);

private:
    QDoubleSpinBox* cDoubleSpinBox;
    QDoubleSpinBox* gDoubleSpinBox;


};

#endif // GAMMATRANSFORMATIONDIALOG_H
