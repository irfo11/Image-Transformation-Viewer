#include "abstracttransformationdialog.h"
#include "ui_abstracttransformationdialog.h"

#include "mainwindow.h"
#include <QFormLayout>

AbstractTransformationDialog::AbstractTransformationDialog(QWidget *parent, cv::Mat& original) :
    QDialog(parent),
    ui(new Ui::AbstractTransformationDialog),
    transformed(original)
{
    this->original = original.clone();
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &AbstractTransformationDialog::on_applyButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AbstractTransformationDialog::on_cancelButton_clicked);
    this->setWindowModality(Qt::WindowModal);
    this->setFixedSize(320, 240);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(this, &AbstractTransformationDialog::updateImage, static_cast<MainWindow*>(parent), &MainWindow::showImage);

    this->show();
}

void AbstractTransformationDialog::on_applyButton_clicked()
{
    accept();
}

void AbstractTransformationDialog::on_cancelButton_clicked()
{
    restoreToOriginal();
    reject();
}

AbstractTransformationDialog::~AbstractTransformationDialog()
{
    qDebug() << "calling parent destructor";
    delete ui;
}
