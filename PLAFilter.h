#pragma once
#include "IFilter.h"

using namespace System::Collections::Generic;

public ref class PLAFilter : public IFilter
{
public:
	void PLAFilter::Filter(cv::Mat&, Dictionary<int, int>^, List<int>^) override;
};

