#pragma once
#include "IFilter.h"


public ref class NegativeFilter : public IFilter
{
public:
	void NegativeFilter::Filter(cv::Mat&) override;
};

