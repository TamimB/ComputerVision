#include"minMaxFunction.h"

void minFilter(const cv::Mat& src, cv::Mat& dest, int kernelSize) {
	if (kernelSize % 2 == 0) return ; // Check kernel size
	cv::Mat kernel(kernelSize, kernelSize, src.type()); // kernal

	for (int i = 0; i < (src.rows - kernel.rows); i++) {
		for (int j = 0; j < (src.cols - kernel.cols); j++) {
			cv::Rect slidingWindow(j, i, kernel.cols, kernel.rows);
			cv::Mat tmp = src(slidingWindow);
			uchar res = findMin(tmp);
			dest.at<uchar>(i, j) = res;

		}

	}
}

void maxFilter(const cv::Mat& src, cv::Mat& dest, int kernelSize) {
	if (kernelSize % 2 == 0) return ; // Check kernal size
	cv::Mat kernel(kernelSize, kernelSize, src.type()); // kernel 

	for (int i = 0; i < src.rows-kernel.rows; i++) {
		for (int j = 0; j < src.cols - kernel.cols; j++) {
			cv::Rect slidingWindow(j, i, kernel.cols, kernel.rows);
			cv::Mat tmp = src(slidingWindow);
			uchar maxVal = 0;
			for (int k = 0; k < tmp.rows; k++) {
				for (int l = 0; l < tmp.cols; l++) {

					if (maxVal < tmp.at<uchar>(k, l)) {
						maxVal = tmp.at<uchar>(k, l);
					}					
				}
			}
			dest.at<uchar>(i, j) = maxVal;
		}
	}
}


uchar findMin(const cv::Mat& imgRect) {
	uchar minVal = 255;

	for (int i = 0; i < imgRect.rows; i++) {
		for (int j = 0; j < imgRect.cols; j++){
			minVal = (minVal < imgRect.at<uchar>(i, j) ? minVal : imgRect.at<uchar>(i, j));
		}
	}
	return minVal;
}
