#pragma once
#include "IFilter.h"


public ref class MaskFilter : public IFilter
{
public:
	void MaskFilter::Filter(cv::Mat&, cv::Mat&, int[][3], bool) override;
};
