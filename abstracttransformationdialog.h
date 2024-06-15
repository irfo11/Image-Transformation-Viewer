#ifndef ABSTRACTTRANSFORMATIONDIALOG_H
#define ABSTRACTTRANSFORMATIONDIALOG_H

#include <QDialog>

#include "opencv2/core.hpp"

/*
 * This class is used to crate tranformation dialog that apply transformations
 * to the original image. The original image from the program is stored in
 * the transformed attribute of this dialog, for it will be changed. The original
 * attribute stores the image before the creation of the dialog, so if the
 * transformation is canceled the image can be restored.
 */
namespace Ui {
class AbstractTransformationDialog;
}

class AbstractTransformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AbstractTransformationDialog(QWidget *parent, cv::Mat& original);
    virtual ~AbstractTransformationDialog();
    virtual void transform() = 0;
    void restoreToOriginal() {
        this->original.copyTo(this->transformed);
        emit updateImage();
        qDebug() << "restoring";
    }

private:
    void on_applyButton_clicked();
    void on_cancelButton_clicked();
    virtual void closeEvent(QCloseEvent* event) override;

signals:
    void updateImage();

protected:
    Ui::AbstractTransformationDialog *ui;
    cv::Mat original;
    cv::Mat& transformed;
};

#endif // ABSTRACTTRANSFORMATIONDIALOG_H
