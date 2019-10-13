#pragma once
#include "Nodo.h"

class Cola
{
public:
	Nodo *head;
	Nodo *tail;

	Cola();
	~Cola();
	void Cola::Push(Nodo *nuevo);
	int Cola::Shift();
	void Cola::Llenar();
	int Cola::Buscar(int n);

private:
	int Cola::BuscarRecursivo(int n, Nodo *pos);
};

