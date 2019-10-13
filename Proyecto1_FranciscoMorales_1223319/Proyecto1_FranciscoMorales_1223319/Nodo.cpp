#include "Nodo.h"



Nodo::Nodo(int n)
{
	numero = n;
	sig = nullptr;
	ant = nullptr;
}

Nodo::Nodo(int n, Nodo *s, Nodo *a)
{
	numero = n;
	sig = s;
	ant = a;
}


Nodo::~Nodo()
{
}
