#pragma once
#include "Nodo.h"

class Lista
{
public:
	Nodo *head;
	
	Lista();
	~Lista();
	void Lista::Agregar(Nodo *nuevo);
	int Lista::Eliminar();
	System::String^Lista::String();

private:
	void Lista::AgregarRecursivo(Nodo *nuevo, Nodo *pos);
	System::String^Lista::StringRecursivo(Nodo *pos);
};

