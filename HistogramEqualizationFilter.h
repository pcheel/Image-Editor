#pragma once
#include "IFilter.h"


public ref class HistogramEqualizationFilter : public IFilter
{
public:
	void HistogramEqualizationFilter::Filter(cv::Mat&, cv::Mat&) override;
	System::Collections::Generic::List<int>^ HistogramEqualizationFilter::DrawHistogram(cv::Mat&);
};

