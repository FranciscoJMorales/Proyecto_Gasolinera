#pragma once
#include "Nodo.h"

//Toda la documentación de la clase Cola se realiza en el archivo .cpp
class Pila
{
public:
	//Puntero que indica la cima de la pila
	Nodo *head;

	Pila();
	~Pila();
	void Pila::Push(Nodo *nuevo);
	int Pila::Pop();
	void Pila::Llenar();
	void Pila::SelectionSort();
	int Pila::Buscar(int n);
	System::String^Pila::String();

private:
	int Pila::ObtenerMayor(int mayor, Nodo *pos);
	int Pila::BuscarRecursivo(int n, Nodo *pos);
	System::String^Pila::StringRecursivo(Nodo *pos);
};

