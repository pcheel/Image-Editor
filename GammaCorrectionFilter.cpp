#include "GammaCorrectionFilter.h"

void GammaCorrectionFilter::Filter(cv::Mat& matImage, float gamma)
{
	//cv::Mat newMat = cv::Mat::zeros(matImage.size(), matImage.type());
	for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				float normalizedColorValue = ((float)matImage.at<cv::Vec3b>(i, j)[k]) / 255;
				//matImage.at<cv::Vec3b>(i, j)[k] = pow(normalizedColorValue, gamma) * 255;
				matImage.at<cv::Vec3b>(i, j)[k] = pow(normalizedColorValue, gamma) * 255;
			}
		}
	}
}
