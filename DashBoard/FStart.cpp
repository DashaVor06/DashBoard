#include "FStart.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ arg) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    DashBoard::FStart form;
    Application::Run(% form);
}