#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace forms11lab;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	forms11lab::Form1 form;
	Application::Run(% form);
	return 0;
}