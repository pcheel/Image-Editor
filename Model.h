#pragma once
#include <opencv2/opencv.hpp>
#include "IFilter.h"
#include "NegativeFilter.h"
#include "GammaCorrectionFilter.h"
#include "PLAFilter.h"
#include "HistogramEqualizationFilter.h"
#include "MaskFilter.h"
#include "ColorFilter.h"

using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace 
{
	cv::Mat _generalImage;
	cv::Mat _supportImage;
	cv::Mat _imageForConvert;
	cv::Mat _imageForHist;
}

public ref class Model
{
public:
	delegate void ChangeImageEvent(Bitmap^);
	delegate void ChangeImageForHistogramEvent(List<int>^);
	event ChangeImageEvent^ OnImageChanged;
	event ChangeImageForHistogramEvent^ OnImageForHistogramChanged;

	void GeneralImage(Bitmap^ bitImage)
	{
		// = cv::imread("D:/Games/forGammaCorrection");
		_generalImage = ConvertBitmapToMat(bitImage);
		_supportImage = _generalImage.clone();
	}
	void DrawHistogram()
	{
		OnImageForHistogramChanged(_histogramEqualizationFilter->DrawHistogram(_supportImage));
	}
	void Negative() 
	{
		BaseFilter(_negativeFilter, _generalImage);
	}
	void GammaCorrection(float gamma) 
	{
		BaseFilter(_gammaCorrectionFilter, _generalImage, gamma);
	}
	void PLA(Dictionary<int, int>^ pointsDict, List<int>^ pointsList)
	{
		pointsList->Sort();
		if (!pointsList->Contains(255)) 
		{
			pointsList->Add(255);
			pointsDict->Add(255, 255);
		}
		BaseFilter(_PLAFilter, _generalImage, pointsDict, pointsList);
	}
	void HistogramEqualization()
	{
		BaseFilter(_histogramEqualizationFilter, _generalImage, _imageForHist);
		//OnImageForHistogramChanged(_histogramEqualizationFilter->DrawHistogram(_generalImage));
	}
	void Gaussian()
	{
		int weights[3][3] =
		{
			{1,2,1},
			{2,4,2},
			{1,2,1}
		};
		BaseFilter(_maskFilter, _generalImage, _imageForHist, weights, false);
	}
	void Blur()
	{
		int weights[3][3] =
		{
			{1,1,1},
			{1,1,1},
			{1,1,1}
		};
		BaseFilter(_maskFilter, _generalImage, _imageForHist, weights, false);
	}
	void Sharpening()
	{
		int weights[3][3] =
		{
			{-1,-1,-1},
			{-1,9,-1},
			{-1,-1,-1}
		};
		BaseFilter(_maskFilter, _generalImage, _imageForHist, weights, true);
	}
	void Color(int redFrom, int redBefore, int greenFrom, int greenBefore, int blueFrom, int blueBefore)
	{
		int colors[3][2] =
		{
			{redFrom,redBefore},
			{greenFrom,greenBefore},
			{blueFrom,blueBefore}
		};
		BaseFilter(_colorFilter, _generalImage, colors);
	}

	Bitmap^ ConvertMatToBitmap(cv::Mat& matImage)
	{
		cvtColor(matImage, _imageForConvert, cv::COLOR_BGR2BGRA);
		Bitmap^ bitImage = gcnew Bitmap(_imageForConvert.cols, _supportImage.rows, _imageForConvert.step, Imaging::PixelFormat::Format32bppArgb, System::IntPtr(_imageForConvert.data));
		return bitImage;
	}
	cv::Mat ConvertBitmapToMat(Bitmap^ bitmap)
	{
		System::Drawing::Rectangle blank = System::Drawing::Rectangle(0, 0, bitmap->Width, bitmap->Height);
		System::Drawing::Imaging::BitmapData^ bmpdata = bitmap->LockBits(blank, System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		cv::Mat image(cv::Size(bitmap->Width, bitmap->Height), CV_8UC3, bmpdata->Scan0.ToPointer(), ((bitmap->Width * 24 + 31) / 32) * 4);
		bitmap->UnlockBits(bmpdata);
		return image;
	}
	void ApplyChanges()
	{
		_generalImage = _supportImage.clone();
		OnImageChanged(ConvertMatToBitmap(_generalImage));
	}

private:
	NegativeFilter^ _negativeFilter = gcnew NegativeFilter();
	GammaCorrectionFilter^ _gammaCorrectionFilter = gcnew GammaCorrectionFilter();
	PLAFilter^ _PLAFilter = gcnew PLAFilter();
	HistogramEqualizationFilter^ _histogramEqualizationFilter = gcnew HistogramEqualizationFilter();
	MaskFilter^ _maskFilter = gcnew MaskFilter();
	ColorFilter^ _colorFilter = gcnew ColorFilter();

	void BaseFilter(IFilter^ filter, cv::Mat& matImage)
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
	void BaseFilter(IFilter^ filter, cv::Mat& matImage, float argument) 
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage, argument);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
	void BaseFilter(IFilter^ filter, cv::Mat& matImage, Dictionary<int, int>^ dict, List<int>^ list)
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage, dict, list);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
	void BaseFilter(IFilter^ filter, cv::Mat& matImage, cv::Mat& supImage)
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage, supImage);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
	void BaseFilter(IFilter^ filter, cv::Mat& matImage, cv::Mat& supImage, int weights[][3], bool withNegative)
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage, supImage, weights, withNegative);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
	void BaseFilter(IFilter^ filter, cv::Mat& matImage, int colors[][2])
	{
		_supportImage = _generalImage.clone();
		filter->Filter(_supportImage, colors);
		OnImageChanged(ConvertMatToBitmap(_supportImage));
	}
};

