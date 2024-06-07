#ifndef HISTOGRAMEQUALIZATIONDIALOG_H
#define HISTOGRAMEQUALIZATIONDIALOG_H

#include "abstracttransformationdialog.h"

#include <QCheckBox>
#include "imgtools.h"


class HistogramEqualizationDialog : public AbstractTransformationDialog
{
    Q_OBJECT
public:
    HistogramEqualizationDialog(QWidget* parent, cv::Mat& img);
    virtual ~HistogramEqualizationDialog() = default;
    void transform() override;

private slots:
    void on_histogramEqualizationCheckBox_stateChanged(int state);

};

#endif // HISTOGRAMEQUALIZATIONDIALOG_H
