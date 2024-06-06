#ifndef IMGTOOLS_IMGTOOLS_H
#define IMGTOOLS_IMGTOOLS_H

#include <QPixmap>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace imgtools {

void negativeTransform(const cv::Mat& src, cv::Mat& dst);
void logTransform(const cv::Mat& src, cv::Mat& dst, double c);

QPixmap matToPixmap(cv::Mat src, QImage::Format format = QImage::Format_Grayscale8,
                    int pixWidth=600, int pixHeight=300);

cv::Mat plotHistogram(	const cv::Mat 	src,
                        const int 	width,
                        const int 	height,
                        const cv::Scalar 	background_colour = cv::Scalar(0, 0, 0));

cv::Mat plotFourrierTransform(const cv::Mat src);

} // namespace imgtools

#endif // IMGTOOLS_IMGTOOLS_H
