#pragma once
#include "IFilter.h"


public ref class ColorFilter : public IFilter
{
public:
	void ColorFilter::Filter(cv::Mat&, int[][2]) override;
};

