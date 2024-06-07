#ifndef HIGHLIGHTINGINTENSITYLEVELSLICINGDIALOG_H
#define HIGHLIGHTINGINTENSITYLEVELSLICINGDIALOG_H

#include <QSpinBox>

#include "imgtools.h"
#include "abstracttransformationdialog.h"

class HighlightingIntensityLevelSlicingDialog : public AbstractTransformationDialog
{
    Q_OBJECT
public:
    HighlightingIntensityLevelSlicingDialog(QWidget* parent, cv::Mat& img);
    virtual ~HighlightingIntensityLevelSlicingDialog() = default;
    void transform() override;

private slots:
    void on_minValueSpinBox_valueChanged(int value);
    void on_maxValueSpinBox_valueChanged(int value);

private:
    QSpinBox* minValueSpinBox;
    QSpinBox* maxValueSpinBox;
};

#endif // HIGHLIGHTINGINTENSITYLEVELSLICINGDIALOG_H
