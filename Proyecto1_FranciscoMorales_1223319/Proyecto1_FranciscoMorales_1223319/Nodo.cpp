#include "Nodo.h"



Nodo::Nodo(int n)
{
	//Se asigna el n�mero al nodo y se asignan la posici�n siguiente y anterior como nulas
	numero = n;
	sig = nullptr;
	ant = nullptr;
}


Nodo::~Nodo()
{
}
