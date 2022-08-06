#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>


public ref class IFilter
{
public:
	void virtual Filter(cv::Mat&);
	void virtual Filter(cv::Mat&, float);
	void virtual Filter(cv::Mat&, System::Collections::Generic::Dictionary<int, int>^, System::Collections::Generic::List<int>^);
	void virtual Filter(cv::Mat&, cv::Mat&);
	void virtual Filter(cv::Mat&, cv::Mat&, int[][3], bool);
	void virtual Filter(cv::Mat&, int[][2]);
};
