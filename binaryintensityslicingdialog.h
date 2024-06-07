#ifndef BINARYINTENSITYSLICINGDIALOG_H
#define BINARYINTENSITYSLICINGDIALOG_H

#include <QSpinBox>

#include "imgtools.h"
#include "abstracttransformationdialog.h"

class BinaryIntensityLevelSlicingDialog : public AbstractTransformationDialog
{
    Q_OBJECT
public:
    BinaryIntensityLevelSlicingDialog(QWidget* parent, cv::Mat& img);
    virtual ~BinaryIntensityLevelSlicingDialog() = default;
    void transform() override;

private slots:
    void on_minValueSpinBox_valueChanged(int value);
    void on_maxValueSpinBox_valueChanged(int value);

private:
    QSpinBox* minValueSpinBox;
    QSpinBox* maxValueSpinBox;
};

#endif // BINARYINTENSITYSLICINGDIALOG_H
