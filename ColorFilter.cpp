#include "ColorFilter.h"


void ColorFilter::Filter(cv::Mat& matImage, int colors[][2])
{
	for (int i = 1; i < matImage.rows - 2; i++)
	{
		for (int j = 1; j < matImage.cols - 2; j++)
		{
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				uchar color = matImage.at<cv::Vec3b>(i, j)[k];
				if (color >= colors[k][0] && color <= colors[k][1]) 
				{
					sum++;
				}
			}
			if (sum != 3)
			{
				matImage.at<cv::Vec3b>(i, j)[0] = 255;
				matImage.at<cv::Vec3b>(i, j)[1] = 255;
				matImage.at<cv::Vec3b>(i, j)[2] = 255;
			}
		}
	}
}
