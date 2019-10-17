#pragma once
#include "Nodo.h"

//Toda la documentación de la clase Cola se realiza en el archivo .cpp
class Cola
{
public:
	//Punteros que indican el inicio y el fin de la cola
	Nodo *head;
	Nodo *tail;

	Cola();
	~Cola();
	void Cola::Push(Nodo *nuevo);
	int Cola::Shift();
	void Cola::Llenar();
	void Cola::SelectionSort();
	int Cola::Buscar(int n);
	System::String^Cola::String();

private:
	int Cola::ObtenerMenor(int menor, Nodo *pos);
	int Cola::BuscarRecursivo(int n, Nodo *pos);
	System::String^Cola::StringRecursivo(Nodo *pos);
};

