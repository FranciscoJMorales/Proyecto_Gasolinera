#pragma once
#include "Gasolinera.h"

namespace Proyecto1_FranciscoMorales_1223319 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ingresar_Btn;
	private: System::Windows::Forms::Label^  pila_Lbl;
	private: System::Windows::Forms::Label^  cola_Lbl;
	private: System::Windows::Forms::TextBox^  precio1Tbx;
	private: System::Windows::Forms::TextBox^  precio2Tbx;

	private: System::Windows::Forms::Label^  precio1Titulo;
	private: System::Windows::Forms::Label^  precio1Lbl;
	private: System::Windows::Forms::GroupBox^  estadosGbx;
	private: System::Windows::Forms::Label^  colaTitulo;
	private: System::Windows::Forms::Label^  pilaTitulo;
	private: System::Windows::Forms::Label^  precio2Lbl;

	private: System::Windows::Forms::Label^  precio2Titulo;

	private: System::Windows::Forms::Button^  ingresarPrecio2_Btn;
	private: System::Windows::Forms::Button^  eliminar1_Btn;
	private: System::Windows::Forms::Button^  eliminar2_Btn;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  ordenar_Btn;
	private: System::Windows::Forms::Button^  reiniciar_Btn;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ingresar_Btn = (gcnew System::Windows::Forms::Button());
			this->pila_Lbl = (gcnew System::Windows::Forms::Label());
			this->cola_Lbl = (gcnew System::Windows::Forms::Label());
			this->precio1Tbx = (gcnew System::Windows::Forms::TextBox());
			this->precio2Tbx = (gcnew System::Windows::Forms::TextBox());
			this->precio1Titulo = (gcnew System::Windows::Forms::Label());
			this->precio1Lbl = (gcnew System::Windows::Forms::Label());
			this->estadosGbx = (gcnew System::Windows::Forms::GroupBox());
			this->colaTitulo = (gcnew System::Windows::Forms::Label());
			this->pilaTitulo = (gcnew System::Windows::Forms::Label());
			this->precio2Lbl = (gcnew System::Windows::Forms::Label());
			this->precio2Titulo = (gcnew System::Windows::Forms::Label());
			this->ingresarPrecio2_Btn = (gcnew System::Windows::Forms::Button());
			this->eliminar1_Btn = (gcnew System::Windows::Forms::Button());
			this->eliminar2_Btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ordenar_Btn = (gcnew System::Windows::Forms::Button());
			this->reiniciar_Btn = (gcnew System::Windows::Forms::Button());
			this->estadosGbx->SuspendLayout();
			this->SuspendLayout();
			// 
			// ingresar_Btn
			// 
			this->ingresar_Btn->Location = System::Drawing::Point(25, 40);
			this->ingresar_Btn->Name = L"ingresar_Btn";
			this->ingresar_Btn->Size = System::Drawing::Size(75, 23);
			this->ingresar_Btn->TabIndex = 0;
			this->ingresar_Btn->Text = L"Ingresar";
			this->ingresar_Btn->UseVisualStyleBackColor = true;
			this->ingresar_Btn->Click += gcnew System::EventHandler(this, &MyForm::ingresar_Btn_Click);
			// 
			// pila_Lbl
			// 
			this->pila_Lbl->AutoSize = true;
			this->pila_Lbl->Location = System::Drawing::Point(6, 60);
			this->pila_Lbl->Name = L"pila_Lbl";
			this->pila_Lbl->Size = System::Drawing::Size(35, 13);
			this->pila_Lbl->TabIndex = 1;
			this->pila_Lbl->Text = L"<pila>";
			// 
			// cola_Lbl
			// 
			this->cola_Lbl->AutoSize = true;
			this->cola_Lbl->Location = System::Drawing::Point(121, 60);
			this->cola_Lbl->Name = L"cola_Lbl";
			this->cola_Lbl->Size = System::Drawing::Size(39, 13);
			this->cola_Lbl->TabIndex = 2;
			this->cola_Lbl->Text = L"<cola>";
			// 
			// precio1Tbx
			// 
			this->precio1Tbx->Location = System::Drawing::Point(106, 42);
			this->precio1Tbx->MaxLength = 5;
			this->precio1Tbx->Name = L"precio1Tbx";
			this->precio1Tbx->Size = System::Drawing::Size(100, 20);
			this->precio1Tbx->TabIndex = 3;
			// 
			// precio2Tbx
			// 
			this->precio2Tbx->Location = System::Drawing::Point(106, 108);
			this->precio2Tbx->MaxLength = 5;
			this->precio2Tbx->Name = L"precio2Tbx";
			this->precio2Tbx->Size = System::Drawing::Size(100, 20);
			this->precio2Tbx->TabIndex = 4;
			// 
			// precio1Titulo
			// 
			this->precio1Titulo->AutoSize = true;
			this->precio1Titulo->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->precio1Titulo->Location = System::Drawing::Point(366, 28);
			this->precio1Titulo->Name = L"precio1Titulo";
			this->precio1Titulo->Size = System::Drawing::Size(72, 22);
			this->precio1Titulo->TabIndex = 6;
			this->precio1Titulo->Text = L"Precio 1:";
			// 
			// precio1Lbl
			// 
			this->precio1Lbl->AutoSize = true;
			this->precio1Lbl->Font = (gcnew System::Drawing::Font(L"Garamond", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->precio1Lbl->Location = System::Drawing::Point(357, 61);
			this->precio1Lbl->Name = L"precio1Lbl";
			this->precio1Lbl->Size = System::Drawing::Size(218, 72);
			this->precio1Lbl->TabIndex = 7;
			this->precio1Lbl->Text = L"Q00.00";
			// 
			// estadosGbx
			// 
			this->estadosGbx->Controls->Add(this->colaTitulo);
			this->estadosGbx->Controls->Add(this->pilaTitulo);
			this->estadosGbx->Controls->Add(this->pila_Lbl);
			this->estadosGbx->Controls->Add(this->cola_Lbl);
			this->estadosGbx->Location = System::Drawing::Point(12, 159);
			this->estadosGbx->Name = L"estadosGbx";
			this->estadosGbx->Size = System::Drawing::Size(213, 228);
			this->estadosGbx->TabIndex = 8;
			this->estadosGbx->TabStop = false;
			this->estadosGbx->Text = L"Estados actuales:";
			// 
			// colaTitulo
			// 
			this->colaTitulo->AutoSize = true;
			this->colaTitulo->Location = System::Drawing::Point(121, 39);
			this->colaTitulo->Name = L"colaTitulo";
			this->colaTitulo->Size = System::Drawing::Size(31, 13);
			this->colaTitulo->TabIndex = 4;
			this->colaTitulo->Text = L"Cola:";
			// 
			// pilaTitulo
			// 
			this->pilaTitulo->AutoSize = true;
			this->pilaTitulo->Location = System::Drawing::Point(6, 39);
			this->pilaTitulo->Name = L"pilaTitulo";
			this->pilaTitulo->Size = System::Drawing::Size(27, 13);
			this->pilaTitulo->TabIndex = 3;
			this->pilaTitulo->Text = L"Pila:";
			// 
			// precio2Lbl
			// 
			this->precio2Lbl->AutoSize = true;
			this->precio2Lbl->Font = (gcnew System::Drawing::Font(L"Garamond", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->precio2Lbl->Location = System::Drawing::Point(358, 235);
			this->precio2Lbl->Name = L"precio2Lbl";
			this->precio2Lbl->Size = System::Drawing::Size(218, 72);
			this->precio2Lbl->TabIndex = 10;
			this->precio2Lbl->Text = L"Q00.00";
			// 
			// precio2Titulo
			// 
			this->precio2Titulo->AutoSize = true;
			this->precio2Titulo->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->precio2Titulo->Location = System::Drawing::Point(367, 202);
			this->precio2Titulo->Name = L"precio2Titulo";
			this->precio2Titulo->Size = System::Drawing::Size(72, 22);
			this->precio2Titulo->TabIndex = 9;
			this->precio2Titulo->Text = L"Precio 2:";
			// 
			// ingresarPrecio2_Btn
			// 
			this->ingresarPrecio2_Btn->Location = System::Drawing::Point(25, 106);
			this->ingresarPrecio2_Btn->Name = L"ingresarPrecio2_Btn";
			this->ingresarPrecio2_Btn->Size = System::Drawing::Size(75, 23);
			this->ingresarPrecio2_Btn->TabIndex = 11;
			this->ingresarPrecio2_Btn->Text = L"Ingresar";
			this->ingresarPrecio2_Btn->UseVisualStyleBackColor = true;
			this->ingresarPrecio2_Btn->Click += gcnew System::EventHandler(this, &MyForm::ingresarPrecio2_Btn_Click);
			// 
			// eliminar1_Btn
			// 
			this->eliminar1_Btn->Enabled = false;
			this->eliminar1_Btn->Location = System::Drawing::Point(212, 40);
			this->eliminar1_Btn->Name = L"eliminar1_Btn";
			this->eliminar1_Btn->Size = System::Drawing::Size(75, 23);
			this->eliminar1_Btn->TabIndex = 12;
			this->eliminar1_Btn->Text = L"Eliminar";
			this->eliminar1_Btn->UseVisualStyleBackColor = true;
			this->eliminar1_Btn->Click += gcnew System::EventHandler(this, &MyForm::eliminar1_Btn_Click);
			// 
			// eliminar2_Btn
			// 
			this->eliminar2_Btn->Enabled = false;
			this->eliminar2_Btn->Location = System::Drawing::Point(212, 106);
			this->eliminar2_Btn->Name = L"eliminar2_Btn";
			this->eliminar2_Btn->Size = System::Drawing::Size(75, 23);
			this->eliminar2_Btn->TabIndex = 13;
			this->eliminar2_Btn->Text = L"Eliminar";
			this->eliminar2_Btn->UseVisualStyleBackColor = true;
			this->eliminar2_Btn->Click += gcnew System::EventHandler(this, &MyForm::eliminar2_Btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(103, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Precio 1:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(103, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Precio 2:";
			// 
			// ordenar_Btn
			// 
			this->ordenar_Btn->Location = System::Drawing::Point(312, 345);
			this->ordenar_Btn->Name = L"ordenar_Btn";
			this->ordenar_Btn->Size = System::Drawing::Size(75, 23);
			this->ordenar_Btn->TabIndex = 16;
			this->ordenar_Btn->Text = L"Ordenar";
			this->ordenar_Btn->UseVisualStyleBackColor = true;
			this->ordenar_Btn->Click += gcnew System::EventHandler(this, &MyForm::ordenar_Btn_Click);
			// 
			// reiniciar_Btn
			// 
			this->reiniciar_Btn->Enabled = false;
			this->reiniciar_Btn->Location = System::Drawing::Point(465, 345);
			this->reiniciar_Btn->Name = L"reiniciar_Btn";
			this->reiniciar_Btn->Size = System::Drawing::Size(75, 23);
			this->reiniciar_Btn->TabIndex = 17;
			this->reiniciar_Btn->Text = L"Reiniciar";
			this->reiniciar_Btn->UseVisualStyleBackColor = true;
			this->reiniciar_Btn->Click += gcnew System::EventHandler(this, &MyForm::Reiniciar_Btn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(611, 399);
			this->Controls->Add(this->reiniciar_Btn);
			this->Controls->Add(this->ordenar_Btn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->eliminar2_Btn);
			this->Controls->Add(this->eliminar1_Btn);
			this->Controls->Add(this->ingresarPrecio2_Btn);
			this->Controls->Add(this->precio2Lbl);
			this->Controls->Add(this->precio2Titulo);
			this->Controls->Add(this->estadosGbx);
			this->Controls->Add(this->precio1Lbl);
			this->Controls->Add(this->precio1Titulo);
			this->Controls->Add(this->precio2Tbx);
			this->Controls->Add(this->precio1Tbx);
			this->Controls->Add(this->ingresar_Btn);
			this->Name = L"MyForm";
			this->Text = L"Gasolinera";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->estadosGbx->ResumeLayout(false);
			this->estadosGbx->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Gasolinera *simulador;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		simulador = new Gasolinera();
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio1Lbl->Text = simulador->EstadoPrecio1();
		precio2Lbl->Text = simulador->EstadoPrecio2();
	}

	private: System::Void ingresar_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador->Agregar(precio1Tbx->Text, true);
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio1Lbl->Text = simulador->EstadoPrecio1();
		eliminar1_Btn->Enabled = true;
		reiniciar_Btn->Enabled = true;
		ingresar_Btn->Text = "Cambiar";
	}

	private: System::Void ingresarPrecio2_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador->Agregar(precio2Tbx->Text, false);
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio2Lbl->Text = simulador->EstadoPrecio2();
		eliminar2_Btn->Enabled = true;
		reiniciar_Btn->Enabled = true;
		ingresarPrecio2_Btn->Text = "Cambiar";
	}

	private: System::Void eliminar1_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador->Eliminar(true);
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio1Lbl->Text = simulador->EstadoPrecio1();
		eliminar1_Btn->Enabled = false;
		ingresar_Btn->Text = "Ingresar";
		precio1Tbx->Clear();
	}

	private: System::Void eliminar2_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador->Eliminar(false);
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio2Lbl->Text = simulador->EstadoPrecio2();
		eliminar2_Btn->Enabled = false;
		ingresarPrecio2_Btn->Text = "Ingresar";
		precio2Tbx->Clear();
	}

	private: System::Void ordenar_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador->Ordenar();
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
	}

	private: System::Void Reiniciar_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		simulador = new Gasolinera();
		pila_Lbl->Text = simulador->EstadoPila();
		cola_Lbl->Text = simulador->EstadoCola();
		precio1Lbl->Text = simulador->EstadoPrecio1();
		precio2Lbl->Text = simulador->EstadoPrecio2();
		eliminar1_Btn->Enabled = false;
		eliminar2_Btn->Enabled = false;
		reiniciar_Btn->Enabled = false;
		precio1Tbx->Clear();
		precio2Tbx->Clear();
	}
};
}
