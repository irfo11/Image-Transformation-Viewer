#ifndef NEGATIVETRANSFORMATIONDIALOG_H
#define NEGATIVETRANSFORMATIONDIALOG_H

#include "abstracttransformationdialog.h"

#include "imgtools.h"

#include "opencv2/core.hpp"

namespace Ui {
class NegativeTransformationDialog;
}

class NegativeTransformationDialog : public AbstractTransformationDialog
{
    Q_OBJECT

public:
    explicit NegativeTransformationDialog(QWidget *parent, cv::Mat& img);
    virtual ~NegativeTransformationDialog();
    void transform() override;

private slots:
    void on_negativeCheckBox_stateChanged(int state);

//signals:
  //  void updateImage();

private:

};

#endif // NEGATIVETRANSFORMATIONDIALOG_H
