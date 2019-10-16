#pragma once
#include "Nodo.h"

class Pila
{
public:
	Nodo *head;

	Pila();
	~Pila();
	void Pila::Push(Nodo *nuevo);
	int Pila::Pop();
	void Pila::Llenar();
	int Pila::Buscar(int n);
	System::String^Pila::String();

private:
	int Pila::BuscarRecursivo(int n, Nodo *pos);
	System::String^Pila::StringRecursivo(Nodo *pos);
};

