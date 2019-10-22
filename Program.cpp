#include "Form1.h"
#pragma optimize("gsy",on)
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TreeVisualizer::Form1());
	int a;
	return 0;
}