#include "NegativeFilter.h"

void NegativeFilter::Filter(cv::Mat& matImage) 
{
	for (int i = 0; i < matImage.rows; i++) 
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				matImage.at<cv::Vec3b>(i, j)[k] = 255 - matImage.at<cv::Vec3b>(i, j)[k];
			}
		}
	}
}