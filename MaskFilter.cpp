#include "MaskFilter.h"

void MaskFilter::Filter(cv::Mat& matImage, cv::Mat& supImage, int weights[][3], bool withNegative)
{
	supImage = matImage.clone();
	int borderSize = 1;
	int borderType = cv::BORDER_CONSTANT;
	cv::Scalar value(255, 255, 255);
	cv::copyMakeBorder(matImage, supImage, borderSize, borderSize, borderSize, borderSize, borderType, value);
	int sum = 0;
	int weightsSum = 0;
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
		{
			weightsSum += weights[n][m];
		}
	}
	for (int i = 1; i < supImage.rows - 2; i++)
	{
		for (int j = 1; j < supImage.cols - 2; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int n = 0; n < 3; n++)
				{
					for (int m = 0; m < 3; m++)
					{
						int a = supImage.at<cv::Vec3b>(i + n - 1, j + m - 1)[k] * weights[n][m];
						sum += a;
					}
				}
				if (withNegative)
				{
					matImage.at<cv::Vec3b>(i - 1, j - 1)[k] = cv::saturate_cast<uchar>(sum);
				}
				else
				{
					matImage.at<cv::Vec3b>(i - 1, j - 1)[k] = cv::saturate_cast<uchar>(sum / weightsSum);
				}
				sum = 0;
			}
		}
	}
}
