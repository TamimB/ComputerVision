#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include"minMaxFunction.h"



int main() {
	//Task one
	cv::Mat img = cv::imread("C:/Users/tamim/Documents/OpenCV/OpenCVTest/image.jpg");
	cv::Mat grayScaleImg(img.rows, img.cols, img.type());
	cv::cvtColor(img, grayScaleImg, cv::COLOR_BGR2GRAY);
	cv::imwrite("grayScale.jpg", grayScaleImg);


	//Task two:
	int kernelSize = 5;
	cv::Mat imgMaxFilter(grayScaleImg.rows, grayScaleImg.cols, grayScaleImg.type());
	maxFilter(grayScaleImg, imgMaxFilter, kernelSize); // (Src, Dest, kernelSize)
	cv::imshow("max filter", imgMaxFilter);

	cv::Mat imgMinFilter(grayScaleImg.rows, grayScaleImg.cols, grayScaleImg.type());
	minFilter(grayScaleImg, imgMinFilter, kernelSize);
	cv::imshow("min Filter", imgMinFilter);

	// Task three:
	cv::Mat medianResult;
	int medianKernelSize = 25;
	cv::medianBlur(grayScaleImg, medianResult, medianKernelSize); // Median filter reuslt.

	cv::Mat gaussianResult;
	int gaussiankernelSize = 5;
	cv::GaussianBlur(grayScaleImg, gaussianResult, cv::Size(gaussiankernelSize, gaussiankernelSize),0); // gaussian filter result.

	cv::imshow("Median", medianResult);
	cv::imshow("Gaussian", gaussianResult);


	// Task four:
	cv::Mat histResult;
	float ranges[] = { 0.0, 256.0 };
	const float* channelRanges = ranges;
	int bins = 256;
	int numImgs = 1;
	int dimensions = 1;
	const int* numChannels = {0};
	cv::calcHist(&grayScaleImg, numImgs, numChannels, cv::Mat(), histResult, dimensions, &bins, &channelRanges);

	// Plotting the histogram:
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins);
	cv::Mat histImage(hist_h, hist_w, CV_8U);

	for (int i = 1; i < bins; i++){
		cv::line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(histResult.at<uchar>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(histResult.at<uchar>(i))),
			cv::Scalar(255, 0, 0), 2, 8, 0);
	}

	cv::imshow("histogram", histImage);

	// Task Five:
	cv::Mat histogramResult, calcHistResult;
	cv::equalizeHist(grayScaleImg, histogramResult);
	cv::imshow("Histogram equalization", histogramResult);
	cv::imwrite("Equalized.jpg", histogramResult);

	cv::calcHist(&histogramResult, numImgs, numChannels, cv::Mat(), calcHistResult, dimensions, &bins, &channelRanges);
	cv::imwrite("Histogram.jpg", histImage);

	// Plotting the histogram:
	cv::Mat histImage2(hist_h, hist_w, CV_8U);

	for (int i = 1; i < bins; i++) {
		cv::line(histImage2, cv::Point(bin_w * (i - 1), hist_h - cvRound(calcHistResult.at<uchar>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(calcHistResult.at<uchar>(i))),
			cv::Scalar(255, 0, 0), 2, 8, 0);
	}
	cv::imshow("hisotgram result after equalization", histImage2);
	cv::imwrite("HistogramEqHist.jpg", histImage2);


	cv::waitKey(0);
	return 0;

}