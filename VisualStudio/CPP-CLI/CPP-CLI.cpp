#include "pch.h"
#include "GUI.hpp"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CPP_CLI::GUI());
  return 0;
}