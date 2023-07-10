#include"MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace lab11oop;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	lab11oop::Form1 form;
	Application::Run(% form);
	return 0;
}