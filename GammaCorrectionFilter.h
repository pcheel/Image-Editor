#pragma once
#include "IFilter.h"


public ref class GammaCorrectionFilter : public IFilter
{
public:
	void GammaCorrectionFilter::Filter(cv::Mat&, float) override;
};

