#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include "Model.h"

namespace ImageEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->_model = gcnew Model();
			_model->OnImageChanged += gcnew Model::ChangeImageEvent(this, &MyForm::ChangeImage);
			_model->OnImageForHistogramChanged += gcnew Model::ChangeImageForHistogramEvent(this, &MyForm::DrawHistogram);
			this->_pointsDict = gcnew System::Collections::Generic::Dictionary<int, int>();
			this->_pointsListX = gcnew System::Collections::Generic::List<int>();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Model^ _model;
	private: System::Collections::Generic::Dictionary<int, int>^ _pointsDict;
	private: System::Collections::Generic::List<int>^ _pointsListX;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ LoadImageButton;

	private: System::Windows::Forms::Button^ SaveImageButton;


	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;






	private: System::Windows::Forms::TabPage^ tabPage2;









	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Button^ negativeButton;

	private: System::Windows::Forms::TextBox^ textBoxGammaCorrection;


	private: System::Windows::Forms::Label^ gammaLabel;
	private: System::Windows::Forms::Button^ GammaButton;


	private: System::Windows::Forms::Button^ Apply;
	private: System::Windows::Forms::Label^ PLAYLabel;

	private: System::Windows::Forms::Label^ PLAXLabel;
	private: System::Windows::Forms::TextBox^ PLAYTextBox;






	private: System::Windows::Forms::TextBox^ PLAXTextBox;

	private: System::Windows::Forms::Label^ PLAPointsLabel;
	private: System::Windows::Forms::Button^ PLAAddPointButton;
	private: System::Windows::Forms::Button^ PLAClearButton;
	private: System::Windows::Forms::Button^ PLAFilterButton;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Button^ HistogramEqualizationButton;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Button^ GaussianFilterButton;
	private: System::Windows::Forms::Button^ SharpeningFilterButton;
	private: System::Windows::Forms::Button^ BlurFilterButton;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ColorButton;
	private: System::Windows::Forms::TextBox^ BeforeBlueColorTextBox;
	private: System::Windows::Forms::TextBox^ FromBlueColorTextBox;

	private: System::Windows::Forms::TextBox^ BeforeGreenColorTextBox;
	private: System::Windows::Forms::TextBox^ FromGreenColorTextBox;
	private: System::Windows::Forms::TextBox^ BeforeRedColorTextBox;
	private: System::Windows::Forms::TextBox^ FromRedColorTextBox;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ histogramChart;
private: System::Windows::Forms::Button^ DrawHistogramButton;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->LoadImageButton = (gcnew System::Windows::Forms::Button());
			this->SaveImageButton = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->PLAFilterButton = (gcnew System::Windows::Forms::Button());
			this->PLAClearButton = (gcnew System::Windows::Forms::Button());
			this->PLAAddPointButton = (gcnew System::Windows::Forms::Button());
			this->PLAPointsLabel = (gcnew System::Windows::Forms::Label());
			this->PLAYLabel = (gcnew System::Windows::Forms::Label());
			this->PLAXLabel = (gcnew System::Windows::Forms::Label());
			this->PLAYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PLAXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->GammaButton = (gcnew System::Windows::Forms::Button());
			this->textBoxGammaCorrection = (gcnew System::Windows::Forms::TextBox());
			this->gammaLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->negativeButton = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->DrawHistogramButton = (gcnew System::Windows::Forms::Button());
			this->histogramChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->HistogramEqualizationButton = (gcnew System::Windows::Forms::Button());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->SharpeningFilterButton = (gcnew System::Windows::Forms::Button());
			this->BlurFilterButton = (gcnew System::Windows::Forms::Button());
			this->GaussianFilterButton = (gcnew System::Windows::Forms::Button());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->ColorButton = (gcnew System::Windows::Forms::Button());
			this->BeforeBlueColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FromBlueColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BeforeGreenColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FromGreenColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BeforeRedColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FromRedColorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Apply = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->histogramChart))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(401, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(896, 504);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->ShowHelp = true;
			// 
			// LoadImageButton
			// 
			this->LoadImageButton->Location = System::Drawing::Point(47, 42);
			this->LoadImageButton->Name = L"LoadImageButton";
			this->LoadImageButton->Size = System::Drawing::Size(130, 28);
			this->LoadImageButton->TabIndex = 1;
			this->LoadImageButton->Text = L"Load Image";
			this->LoadImageButton->UseVisualStyleBackColor = true;
			this->LoadImageButton->Click += gcnew System::EventHandler(this, &MyForm::LoadImage_Click);
			// 
			// SaveImageButton
			// 
			this->SaveImageButton->Location = System::Drawing::Point(197, 42);
			this->SaveImageButton->Name = L"SaveImageButton";
			this->SaveImageButton->Size = System::Drawing::Size(115, 26);
			this->SaveImageButton->TabIndex = 2;
			this->SaveImageButton->Text = L"Save Image";
			this->SaveImageButton->UseVisualStyleBackColor = true;
			this->SaveImageButton->Click += gcnew System::EventHandler(this, &MyForm::SaveImageButton_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->ShowHelp = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Location = System::Drawing::Point(12, 92);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(383, 261);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->PLAFilterButton);
			this->tabPage1->Controls->Add(this->PLAClearButton);
			this->tabPage1->Controls->Add(this->PLAAddPointButton);
			this->tabPage1->Controls->Add(this->PLAPointsLabel);
			this->tabPage1->Controls->Add(this->PLAYLabel);
			this->tabPage1->Controls->Add(this->PLAXLabel);
			this->tabPage1->Controls->Add(this->PLAYTextBox);
			this->tabPage1->Controls->Add(this->PLAXTextBox);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(375, 232);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"PLA";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// PLAFilterButton
			// 
			this->PLAFilterButton->Location = System::Drawing::Point(24, 120);
			this->PLAFilterButton->Name = L"PLAFilterButton";
			this->PLAFilterButton->Size = System::Drawing::Size(75, 23);
			this->PLAFilterButton->TabIndex = 7;
			this->PLAFilterButton->Text = L"PLA Filter";
			this->PLAFilterButton->UseVisualStyleBackColor = true;
			this->PLAFilterButton->Click += gcnew System::EventHandler(this, &MyForm::PLAFilterButton_Click);
			// 
			// PLAClearButton
			// 
			this->PLAClearButton->Location = System::Drawing::Point(221, 149);
			this->PLAClearButton->Name = L"PLAClearButton";
			this->PLAClearButton->Size = System::Drawing::Size(75, 23);
			this->PLAClearButton->TabIndex = 6;
			this->PLAClearButton->Text = L"Clear";
			this->PLAClearButton->UseVisualStyleBackColor = true;
			this->PLAClearButton->Click += gcnew System::EventHandler(this, &MyForm::PLAClearButton_Click);
			// 
			// PLAAddPointButton
			// 
			this->PLAAddPointButton->Location = System::Drawing::Point(24, 70);
			this->PLAAddPointButton->Name = L"PLAAddPointButton";
			this->PLAAddPointButton->Size = System::Drawing::Size(75, 23);
			this->PLAAddPointButton->TabIndex = 5;
			this->PLAAddPointButton->Text = L"Add Point";
			this->PLAAddPointButton->UseVisualStyleBackColor = true;
			this->PLAAddPointButton->Click += gcnew System::EventHandler(this, &MyForm::PLAAddPointButton_Click);
			// 
			// PLAPointsLabel
			// 
			this->PLAPointsLabel->BackColor = System::Drawing::Color::Gainsboro;
			this->PLAPointsLabel->Location = System::Drawing::Point(188, 22);
			this->PLAPointsLabel->Name = L"PLAPointsLabel";
			this->PLAPointsLabel->Size = System::Drawing::Size(140, 107);
			this->PLAPointsLabel->TabIndex = 4;
			this->PLAPointsLabel->Text = L"Points:";
			// 
			// PLAYLabel
			// 
			this->PLAYLabel->AutoSize = true;
			this->PLAYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PLAYLabel->Location = System::Drawing::Point(69, 19);
			this->PLAYLabel->Name = L"PLAYLabel";
			this->PLAYLabel->Size = System::Drawing::Size(19, 20);
			this->PLAYLabel->TabIndex = 3;
			this->PLAYLabel->Text = L"Y";
			// 
			// PLAXLabel
			// 
			this->PLAXLabel->AutoSize = true;
			this->PLAXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PLAXLabel->Location = System::Drawing::Point(24, 19);
			this->PLAXLabel->Name = L"PLAXLabel";
			this->PLAXLabel->Size = System::Drawing::Size(20, 20);
			this->PLAXLabel->TabIndex = 2;
			this->PLAXLabel->Text = L"X";
			// 
			// PLAYTextBox
			// 
			this->PLAYTextBox->Location = System::Drawing::Point(61, 42);
			this->PLAYTextBox->Name = L"PLAYTextBox";
			this->PLAYTextBox->Size = System::Drawing::Size(38, 22);
			this->PLAYTextBox->TabIndex = 1;
			this->PLAYTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PLAYTextBox_KeyPress);
			// 
			// PLAXTextBox
			// 
			this->PLAXTextBox->Location = System::Drawing::Point(14, 42);
			this->PLAXTextBox->Name = L"PLAXTextBox";
			this->PLAXTextBox->Size = System::Drawing::Size(40, 22);
			this->PLAXTextBox->TabIndex = 0;
			this->PLAXTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PLAXTextBox_KeyPress);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->GammaButton);
			this->tabPage2->Controls->Add(this->textBoxGammaCorrection);
			this->tabPage2->Controls->Add(this->gammaLabel);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(375, 232);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Gamma Correction";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// GammaButton
			// 
			this->GammaButton->Location = System::Drawing::Point(50, 79);
			this->GammaButton->Name = L"GammaButton";
			this->GammaButton->Size = System::Drawing::Size(75, 23);
			this->GammaButton->TabIndex = 4;
			this->GammaButton->Text = L"Gamma";
			this->GammaButton->UseVisualStyleBackColor = true;
			this->GammaButton->Click += gcnew System::EventHandler(this, &MyForm::GammaButton_Click);
			// 
			// textBoxGammaCorrection
			// 
			this->textBoxGammaCorrection->Location = System::Drawing::Point(102, 28);
			this->textBoxGammaCorrection->Name = L"textBoxGammaCorrection";
			this->textBoxGammaCorrection->Size = System::Drawing::Size(47, 22);
			this->textBoxGammaCorrection->TabIndex = 1;
			this->textBoxGammaCorrection->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxGammaCorrection_KeyPress);
			// 
			// gammaLabel
			// 
			this->gammaLabel->AutoSize = true;
			this->gammaLabel->Location = System::Drawing::Point(29, 31);
			this->gammaLabel->Name = L"gammaLabel";
			this->gammaLabel->Size = System::Drawing::Size(55, 16);
			this->gammaLabel->TabIndex = 0;
			this->gammaLabel->Text = L"Gamma";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->negativeButton);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(375, 232);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Negative";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// negativeButton
			// 
			this->negativeButton->Location = System::Drawing::Point(86, 62);
			this->negativeButton->Name = L"negativeButton";
			this->negativeButton->Size = System::Drawing::Size(75, 23);
			this->negativeButton->TabIndex = 0;
			this->negativeButton->Text = L"Negative";
			this->negativeButton->UseVisualStyleBackColor = true;
			this->negativeButton->Click += gcnew System::EventHandler(this, &MyForm::negativeButton_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->DrawHistogramButton);
			this->tabPage4->Controls->Add(this->histogramChart);
			this->tabPage4->Controls->Add(this->HistogramEqualizationButton);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(375, 232);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Histogram";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// DrawHistogramButton
			// 
			this->DrawHistogramButton->Location = System::Drawing::Point(14, 85);
			this->DrawHistogramButton->Name = L"DrawHistogramButton";
			this->DrawHistogramButton->Size = System::Drawing::Size(121, 23);
			this->DrawHistogramButton->TabIndex = 2;
			this->DrawHistogramButton->Text = L"Draw Histogram";
			this->DrawHistogramButton->UseVisualStyleBackColor = true;
			this->DrawHistogramButton->Click += gcnew System::EventHandler(this, &MyForm::DrawHistogramButton_Click);
			// 
			// histogramChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->histogramChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->histogramChart->Legends->Add(legend1);
			this->histogramChart->Location = System::Drawing::Point(136, 3);
			this->histogramChart->Name = L"histogramChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->histogramChart->Series->Add(series1);
			this->histogramChart->Size = System::Drawing::Size(356, 225);
			this->histogramChart->TabIndex = 1;
			this->histogramChart->Text = L"chart2";
			// 
			// HistogramEqualizationButton
			// 
			this->HistogramEqualizationButton->Location = System::Drawing::Point(14, 34);
			this->HistogramEqualizationButton->Name = L"HistogramEqualizationButton";
			this->HistogramEqualizationButton->Size = System::Drawing::Size(107, 27);
			this->HistogramEqualizationButton->TabIndex = 0;
			this->HistogramEqualizationButton->Text = L"Equalization";
			this->HistogramEqualizationButton->UseVisualStyleBackColor = true;
			this->HistogramEqualizationButton->Click += gcnew System::EventHandler(this, &MyForm::HistogramEqualizationButton_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->SharpeningFilterButton);
			this->tabPage5->Controls->Add(this->BlurFilterButton);
			this->tabPage5->Controls->Add(this->GaussianFilterButton);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(375, 232);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Mask";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// SharpeningFilterButton
			// 
			this->SharpeningFilterButton->Location = System::Drawing::Point(31, 112);
			this->SharpeningFilterButton->Name = L"SharpeningFilterButton";
			this->SharpeningFilterButton->Size = System::Drawing::Size(96, 26);
			this->SharpeningFilterButton->TabIndex = 2;
			this->SharpeningFilterButton->Text = L"Sharpening";
			this->SharpeningFilterButton->UseVisualStyleBackColor = true;
			this->SharpeningFilterButton->Click += gcnew System::EventHandler(this, &MyForm::SharpeningFilterButton_Click);
			// 
			// BlurFilterButton
			// 
			this->BlurFilterButton->Location = System::Drawing::Point(31, 31);
			this->BlurFilterButton->Name = L"BlurFilterButton";
			this->BlurFilterButton->Size = System::Drawing::Size(75, 23);
			this->BlurFilterButton->TabIndex = 1;
			this->BlurFilterButton->Text = L"Blur";
			this->BlurFilterButton->UseVisualStyleBackColor = true;
			this->BlurFilterButton->Click += gcnew System::EventHandler(this, &MyForm::BlurFilterButton_Click);
			// 
			// GaussianFilterButton
			// 
			this->GaussianFilterButton->Location = System::Drawing::Point(31, 70);
			this->GaussianFilterButton->Name = L"GaussianFilterButton";
			this->GaussianFilterButton->Size = System::Drawing::Size(77, 24);
			this->GaussianFilterButton->TabIndex = 0;
			this->GaussianFilterButton->Text = L"Gaussian";
			this->GaussianFilterButton->UseVisualStyleBackColor = true;
			this->GaussianFilterButton->Click += gcnew System::EventHandler(this, &MyForm::GaussianFilterButton_Click);
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->ColorButton);
			this->tabPage7->Controls->Add(this->BeforeBlueColorTextBox);
			this->tabPage7->Controls->Add(this->FromBlueColorTextBox);
			this->tabPage7->Controls->Add(this->BeforeGreenColorTextBox);
			this->tabPage7->Controls->Add(this->FromGreenColorTextBox);
			this->tabPage7->Controls->Add(this->BeforeRedColorTextBox);
			this->tabPage7->Controls->Add(this->FromRedColorTextBox);
			this->tabPage7->Controls->Add(this->label3);
			this->tabPage7->Controls->Add(this->label2);
			this->tabPage7->Controls->Add(this->label1);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Size = System::Drawing::Size(375, 232);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Color";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// ColorButton
			// 
			this->ColorButton->Location = System::Drawing::Point(85, 198);
			this->ColorButton->Name = L"ColorButton";
			this->ColorButton->Size = System::Drawing::Size(75, 23);
			this->ColorButton->TabIndex = 9;
			this->ColorButton->Text = L"Color";
			this->ColorButton->UseVisualStyleBackColor = true;
			this->ColorButton->Click += gcnew System::EventHandler(this, &MyForm::ColorButton_Click);
			// 
			// BeforeBlueColorTextBox
			// 
			this->BeforeBlueColorTextBox->Location = System::Drawing::Point(155, 115);
			this->BeforeBlueColorTextBox->Name = L"BeforeBlueColorTextBox";
			this->BeforeBlueColorTextBox->Size = System::Drawing::Size(43, 22);
			this->BeforeBlueColorTextBox->TabIndex = 8;
			this->BeforeBlueColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::BeforeBlueColorTextBox_KeyPress);
			// 
			// FromBlueColorTextBox
			// 
			this->FromBlueColorTextBox->Location = System::Drawing::Point(103, 115);
			this->FromBlueColorTextBox->Name = L"FromBlueColorTextBox";
			this->FromBlueColorTextBox->Size = System::Drawing::Size(46, 22);
			this->FromBlueColorTextBox->TabIndex = 7;
			this->FromBlueColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FromBlueColorTextBox_KeyPress);
			// 
			// BeforeGreenColorTextBox
			// 
			this->BeforeGreenColorTextBox->Location = System::Drawing::Point(155, 82);
			this->BeforeGreenColorTextBox->Name = L"BeforeGreenColorTextBox";
			this->BeforeGreenColorTextBox->Size = System::Drawing::Size(43, 22);
			this->BeforeGreenColorTextBox->TabIndex = 6;
			this->BeforeGreenColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::BeforeGreenColorTextBox_KeyPress);
			// 
			// FromGreenColorTextBox
			// 
			this->FromGreenColorTextBox->Location = System::Drawing::Point(103, 82);
			this->FromGreenColorTextBox->Name = L"FromGreenColorTextBox";
			this->FromGreenColorTextBox->Size = System::Drawing::Size(46, 22);
			this->FromGreenColorTextBox->TabIndex = 5;
			this->FromGreenColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FromGreenColorTextBox_KeyPress);
			// 
			// BeforeRedColorTextBox
			// 
			this->BeforeRedColorTextBox->Location = System::Drawing::Point(155, 50);
			this->BeforeRedColorTextBox->Name = L"BeforeRedColorTextBox";
			this->BeforeRedColorTextBox->Size = System::Drawing::Size(43, 22);
			this->BeforeRedColorTextBox->TabIndex = 4;
			this->BeforeRedColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::BeforeRedColorTextBox_KeyPress);
			// 
			// FromRedColorTextBox
			// 
			this->FromRedColorTextBox->Location = System::Drawing::Point(103, 51);
			this->FromRedColorTextBox->Name = L"FromRedColorTextBox";
			this->FromRedColorTextBox->Size = System::Drawing::Size(46, 22);
			this->FromRedColorTextBox->TabIndex = 3;
			this->FromRedColorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::FromRedColorTextBox_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Blue";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Green";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Red";
			// 
			// Apply
			// 
			this->Apply->Location = System::Drawing::Point(161, 371);
			this->Apply->Name = L"Apply";
			this->Apply->Size = System::Drawing::Size(75, 23);
			this->Apply->TabIndex = 1;
			this->Apply->Text = L"Apply";
			this->Apply->UseVisualStyleBackColor = true;
			this->Apply->Click += gcnew System::EventHandler(this, &MyForm::Apply_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->Apply);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->SaveImageButton);
			this->Controls->Add(this->LoadImageButton);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->histogramChart))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->ResumeLayout(false);

		}
		void ChangeImage(Bitmap^ bitImage)
		{
			this->pictureBox1->Image = bitImage;
		}
		void DrawHistogram(List<int>^ histogram)
		{
			histogramChart->Series["Series1"]->Points->Clear();
			for (int i = 0; i < histogram->Count; i++)
			{
				histogramChart->Series["Series1"]->Points->AddXY(i, histogram[i]);
			}
		}
		void ChangeTrackBarValue(TrackBar^ trackBar, System::String^ text)
		{
			if (text == "")
			{
				return;
			}
			int value = Int16::Parse(text);
			if (value > trackBar->Maximum)
			{
				value = trackBar->Maximum;
			}
			trackBar->Value = value;
		}
		void ChangeTextBoxValue(TextBox^ textBox, int value)
		{
			textBox->Text = value.ToString();
		}
		void CorrectHandleInput(TextBox^ textBox, KeyPressEventArgs^ e, int maxValue, int minValue)
		{
			if (!(e->KeyChar == ',' || Char::IsNumber(e->KeyChar) || e->KeyChar == '\b'))
			{
				e->Handled = true;
			}
			if (textBox->Text != "")
			{
				int value = Int16::Parse(textBox->Text);
				if (value > maxValue)
				{
					textBox->Text = maxValue.ToString();
				}
				else if (value < minValue)
				{
					textBox->Text = minValue.ToString();
				}
			}
		}
#pragma endregion
private: System::Void LoadImage_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Bitmap^ newImage = gcnew  Bitmap(openFileDialog1->FileName);
		_model->GeneralImage(newImage);
		this->pictureBox1->Image = newImage;
	}
}
private: System::Void SaveImageButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		pictureBox1->Image->Save(saveFileDialog1->FileName, Imaging::ImageFormat::Bmp);
	}
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
//Negative


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	//??
}
private: System::Void negativeButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	_model->Negative();
}
//gamma
private: System::Void GammaButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->textBoxGammaCorrection->Text != "") 
	{
		_model->GammaCorrection(Convert::ToDouble(this->textBoxGammaCorrection->Text));
	}
}
private: System::Void textBoxGammaCorrection_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 40, 0);
}
//pla
private: System::Void PLAAddPointButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	int x = Int16::Parse(this->PLAXTextBox->Text);
	int y = Int16::Parse(PLAYTextBox->Text);
	if (_pointsDict->ContainsKey(x))
	{
		return;
	}
	_pointsDict->Add(x, y);
	_pointsListX->Add(x);
	PLAPointsLabel->Text += "\n" + Convert::ToString(x) + ", " + Convert::ToString(y);
}
private: System::Void PLAClearButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	PLAPointsLabel->Text = "Points:";
	_pointsDict->Clear();
	_pointsListX->Clear();
}
private: System::Void PLAXTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void PLAYTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void PLAFilterButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (_pointsDict->Count > 0)
	{
		this->_model->PLA(_pointsDict, _pointsListX);
	}
}
//histogram
private: System::Void HistogramEqualizationButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	_model->HistogramEqualization();
}
private: System::Void GaussianFilterButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	_model->Gaussian();
}
private: System::Void BlurFilterButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	_model->Blur();
}
private: System::Void SharpeningFilterButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	_model->Sharpening();
}
//color
private: System::Void ColorButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (FromRedColorTextBox->Text != "", BeforeRedColorTextBox->Text != "", FromGreenColorTextBox->Text != "",
		BeforeGreenColorTextBox->Text != "", FromBlueColorTextBox->Text != "", BeforeBlueColorTextBox->Text != "")
	{
		int redFrom = Int16::Parse(FromRedColorTextBox->Text);
		int redBefore = Int16::Parse(BeforeRedColorTextBox->Text);
		int greenFrom = Int16::Parse(FromGreenColorTextBox->Text);
		int greenBefore = Int16::Parse(BeforeGreenColorTextBox->Text);
		int blueFrom = Int16::Parse(FromBlueColorTextBox->Text);
		int blueBefore = Int16::Parse(BeforeBlueColorTextBox->Text);
		_model->Color(redFrom, redBefore, greenFrom, greenBefore, blueFrom, blueBefore);
	}
}
private: System::Void FromRedColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void BeforeRedColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void FromGreenColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void BeforeGreenColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void FromBlueColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
private: System::Void BeforeBlueColorTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	CorrectHandleInput(FromRedColorTextBox, e, 255, 0);
}
//apply
private: System::Void Apply_Click(System::Object^ sender, System::EventArgs^ e)
{
	_model->ApplyChanges();
}
private: System::Void DrawHistogramButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	_model->DrawHistogram();
}
};
}
