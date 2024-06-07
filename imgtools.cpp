#include "imgtools.h"
#include <QtCore> //qDebug

namespace imgtools {

void negativeTransform(const cv::Mat& src, cv::Mat& dst) {
    cv::bitwise_not(src, dst);
}

void logTransform(const cv::Mat& src, cv::Mat& dst, double c) {
    cv::Mat srcCopy = cv::Mat();
    src.convertTo(srcCopy, CV_32F);
    dst = srcCopy + 1;
    cv::log(dst, dst);
    dst *= c;
    dst.convertTo(dst, CV_8U);
}


//Za gamma=1 ne dobije se originalna slika
void gammaTransform(const cv::Mat& src, cv::Mat& dst, double c, double g) {
    cv::Mat srcCopy = cv::Mat();
    src.convertTo(srcCopy, CV_32F);
    cv::pow(srcCopy, g, dst);
    dst *= c;
    dst.convertTo(dst, CV_8U);
}

void histogramEqualization(const cv::Mat& src, cv::Mat& dst) {
    cv::equalizeHist(src, dst);
}

typedef uint8_t pixel;

void highlightingIntensityLevelSlicing(const cv::Mat& src, cv::Mat& dst, int min, int max) {
    src.copyTo(dst);
    for(int i=0; i<dst.rows; i++) {
        for(int j=0; j<dst.cols; j++) {
            if(dst.at<pixel>(i, j) >= min && dst.at<pixel>(i, j) <= max)
                   dst.at<pixel>(i, j) = 230;
        }
    }
}

void binaryIntensityLevelSlicing(const cv::Mat& src, cv::Mat& dst, int min, int max) {
    src.copyTo(dst);
    for(int i=0; i<dst.rows; i++) {
        for(int j=0; j<dst.cols; j++) {
            if(dst.at<pixel>(i, j) >= min && dst.at<pixel>(i, j) <= max)
                   dst.at<pixel>(i, j) = 230;
            else dst.at<pixel>(i, j) = 0;
        }
    }
}

QPixmap matToPixmap(cv::Mat src, QImage::Format format, int pixWidth, int pixHeight) {
    int bpp=src.channels();
    QImage img(src.cols,src.rows,format);
    uchar *sptr,*dptr;
    int linesize=src.cols*bpp;
    for(int y=0;y<src.rows;y++){
        sptr=src.ptr(y);
        dptr=img.scanLine(y);
        memcpy(dptr,sptr,linesize);
    }

    return QPixmap::fromImage(img.scaled(pixWidth, pixHeight, Qt::KeepAspectRatio));
}


cv::Mat plotHistogram(	const cv::Mat src,
                        const int width,
                        const int height,
                        const cv::Scalar background_colour) {

    // "src" is the cv::Mat input image
    const size_t number_of_channels = src.channels();

    std::vector<cv::Mat> split;
    cv::split(src, split);

    const int       histogram_size  = 256; // the number of "bins"
    const float     range[]         = {0, 256}; // upper bound is exclusive, meaning 0-255
    const float *   ranges          = {range};
    const bool      uniform         = true;
    const bool      accumulate      = false;
    cv::Mat         mask;

    // prepare the destination image
    const int margin        = 4;
    const int min_y         = margin;
    const int max_y         = height - margin;
    const int thickness     = 1;
    const int line_type     = cv::LINE_AA;
    const float bin_width   = static_cast<float>(width) / static_cast<float>(histogram_size);
    cv::Mat dst(height, width, CV_8UC1, background_colour); // create the output image, starting with a pure colour

    cv::Scalar colours[] =
    {
        {255, 0, 0},    // blue
        {0, 255, 0},    // green
        {0, 0, 255}     // red
    };
    if (number_of_channels == 1)
    {
        // for greyscale images, we only have a single colour channel, so ignore
        // the RGB colour definitions and use either black or white for the histogram

        colours[0] = (background_colour == cv::Scalar(0, 0, 0)) ?
                cv::Scalar(255, 255, 255) :
                cv::Scalar(0, 0, 0);
    }

    // iterate through all the channels in this image
    for (size_t idx=0; idx < split.size(); idx++)
    {
        const cv::Scalar colour = colours[idx % 3];

        cv::Mat & m = split[idx];

        cv::Mat histogram;
        cv::calcHist(&m, 1, 0, mask, histogram, 1, &histogram_size, &ranges, uniform, accumulate);

        cv::normalize(histogram, histogram, 0, dst.rows, cv::NORM_MINMAX);

        for (int i = 1; i < histogram_size; i++)
        {
            const int x1 = std::round(bin_width * (i - 1));
            const int x2 = std::round(bin_width * (i - 0));

            const int y1 = std::clamp(height - static_cast<int>(std::round(histogram.at<float>(i - 1))), min_y, max_y);
            const int y2 = std::clamp(height - static_cast<int>(std::round(histogram.at<float>(i - 0))), min_y, max_y);

            cv::line(dst, cv::Point(x1, y1), cv::Point(x2, y2), colour, thickness, line_type);
        }
    }

    return dst;
    // histogram is in "dst"
}

cv::Mat plotFourrierTransform(const cv::Mat src) {
    cv::Mat padded;
    int m = cv::getOptimalDFTSize(src.rows);
    int n = cv::getOptimalDFTSize(src.cols);
    copyMakeBorder(src, padded, 0, m-src.rows, 0, n-src.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexSrc;
    merge(planes, 2, complexSrc);

    cv::dft(complexSrc, complexSrc);

    split(complexSrc, planes);
    magnitude(planes[0], planes[1], planes[0]);
    cv::Mat magSrc = planes[0];

    magSrc += cv::Scalar::all(1);
    cv::log(magSrc, magSrc);

    magSrc = magSrc(cv::Rect(0, 0, magSrc.cols & -2, magSrc.rows & -2));

    int cx = magSrc.cols/2;
    int cy = magSrc.rows/2;

    cv::Mat q0(magSrc, cv::Rect(0, 0, cx, cy)); // Top-Left - Create a ROI per quadrant
    cv::Mat q1(magSrc, cv::Rect(cx, 0, cx, cy)); // Top-Right
    cv::Mat q2(magSrc, cv::Rect(0, cy, cx, cy)); // Bottom-Left
    cv::Mat q3(magSrc, cv::Rect(cx, cy, cx, cy)); // Bottom-Right

    cv::Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magSrc, magSrc, 0, 1, cv::NORM_MINMAX);
    cv::Mat mag;
    magSrc.convertTo(mag, CV_8UC1, 255.0);

    return mag;
}

} // namespace imgtools






















