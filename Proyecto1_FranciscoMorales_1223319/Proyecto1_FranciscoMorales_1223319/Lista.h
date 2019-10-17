#pragma once
#include "Nodo.h"

//Toda la documentación de la clase Lista se realiza en el archivo .cpp
class Lista
{
public:
	//Primer elemento de la lista
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

