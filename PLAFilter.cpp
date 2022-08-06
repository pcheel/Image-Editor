#include "PLAFilter.h"



void PLAFilter::Filter(cv::Mat& matImage, Dictionary<int,int>^ dict, List<int>^ list)
{
	//bool b = false;
	/*for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int l = 0;
				bool isEnd = false;
				while (l < list->Count && !isEnd)
				{
					if (matImage.at<cv::Vec3b>(i, j)[k] <= list[l])
					{
						float newValue = (float)(dict[list[l]] / list[l]);
						matImage.at<cv::Vec3b>(i, j)[k] = newValue * matImage.at<cv::Vec3b>(i, j)[k];
						isEnd = true;
					}
					else { l++; }
				}
			}
		}
	}*/
	//cv::imshow("before", matImage);
	cvtColor(matImage, matImage, cv::COLOR_BGR2GRAY);
	for (int i = 0; i < matImage.rows; i++)
	{
		for (int j = 0; j < matImage.cols; j++)
		{
			int l = 0;
			bool isEnd = false;
			while (l < list->Count && !isEnd)
			{
				if (matImage.at<uchar>(i, j) <= list[l])
				{
					float newValue = (float)(dict[list[l]] / list[l]);
					matImage.at<uchar>(i, j) = newValue * matImage.at<uchar>(i, j);
					isEnd = true;
				}
				else { l++; }
			}
		}
	}
	cvtColor(matImage, matImage, cv::COLOR_GRAY2BGR);
}
