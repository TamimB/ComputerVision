#include<opencv2/highgui/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

void minFilter(const cv::Mat& , cv::Mat& , int );

void maxFilter(const cv::Mat& , cv::Mat& , int );


uchar findMin(const cv:: Mat&);