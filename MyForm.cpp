#include "MyForm.h"
#include "Windows.h"
#include <opencv2/opencv.hpp>

using namespace ImageEditor;
using namespace cv;
using namespace std;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

}
//[STAThread]
//static void Main()
//{
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::Run(gcnew MyForm);
//}
//[STAThread]
//static void Main()