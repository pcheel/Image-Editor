#include "HistogramEqualizationFilter.h"

void HistogramEqualizationFilter::Filter(cv::Mat& matImage, cv::Mat& supImage)
{
	cvtColor(matImage, matImage, cv::COLOR_BGR2GRAY);
	System::Collections::Generic::List<int>^ histogram = DrawHistogram(matImage);
	//histogram
	//int histogram[256];
	//DrawHistogram(matImage, histogram, 244);
	/*for (int i = 0; i < 256; i++)
	{
		histogram->Add(0);
	}
	for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			histogram[matImage.at<uchar>(i, j)]++;
		}
	}*/
	int sum = 0;
	for (int i = 0; i < 256; i++)
	{
		sum += histogram[i];
		histogram[i] = sum;
	}
	supImage = matImage.clone();
	for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			matImage.at<uchar>(i, j) = ((float)histogram[supImage.at<uchar>(i,j)] / (matImage.rows * matImage.cols)) * matImage.at<uchar>(i,j);
		}
	}
	cvtColor(matImage, matImage, cv::COLOR_GRAY2BGR);
}
System::Collections::Generic::List<int>^ HistogramEqualizationFilter::DrawHistogram(cv::Mat& matImage)
{
	System::Collections::Generic::List<int>^ histogram = gcnew System::Collections::Generic::List<int>();
	for (int i = 0; i < 256; i++)
	{
		histogram->Add(0);
	}
	for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			histogram[matImage.at<uchar>(i, j)]++;
		}
	}
	return histogram;
}
