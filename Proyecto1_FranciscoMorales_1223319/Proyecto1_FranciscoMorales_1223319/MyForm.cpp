#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//Método utilizado para iniciar a correr el programa
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Proyecto1_FranciscoMorales_1223319::MyForm form;
	Application::Run(%form);
}
