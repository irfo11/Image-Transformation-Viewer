#ifndef IMGTOOLS_IMGTOOLS_H
#define IMGTOOLS_IMGTOOLS_H

#include <functional>

#include <QPixmap>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace imgtools {

void negativeTransform(const cv::Mat& src, cv::Mat& dst);
void logTransform(const cv::Mat& src, cv::Mat& dst, double c);
void gammaTransform(const cv::Mat& src, cv::Mat& dst, double c, double g);
void histogramEqualization(const cv::Mat& src, cv::Mat& dst);
void highlightingIntensityLevelSlicing(const cv::Mat& src, cv::Mat& dst, int min, int max);
void binaryIntensityLevelSlicing(const cv::Mat& src, cv::Mat& dst, int min, int max);

void applyLowPassFilter(const cv::Mat& src, cv::Mat& dst, cv::Size_<int> ksize);
void applyHighPassFilter(const cv::Mat& src, cv::Mat& dst, cv::Size_<int> ksize);

bool AddGaussianNoise(const cv::Mat& mSrc, cv::Mat &mDst,double Mean=0.0, double StdDev=10.0);
void AddSaltAndPepperNoise(const cv::Mat& src, cv::Mat& dst, int probability=50);


QPixmap matToPixmap(cv::Mat src, QImage::Format format = QImage::Format_Grayscale8,
                    int pixWidth=600, int pixHeight=300);

cv::Mat plotHistogram(	const cv::Mat 	src,
                        const int 	width,
                        const int 	height,
                        const cv::Scalar 	background_colour = cv::Scalar(0, 0, 0));

cv::Mat plotFourrierTransform(const cv::Mat src);

} // namespace imgtools

#endif // IMGTOOLS_IMGTOOLS_H
