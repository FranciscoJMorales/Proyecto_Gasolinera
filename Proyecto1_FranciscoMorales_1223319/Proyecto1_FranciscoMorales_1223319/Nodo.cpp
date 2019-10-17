#include "Nodo.h"



Nodo::Nodo(int n)
{
	//Se asigna el número al nodo y se asignan la posición siguiente y anterior como nulas
	numero = n;
	sig = nullptr;
	ant = nullptr;
}


Nodo::~Nodo()
{
}
