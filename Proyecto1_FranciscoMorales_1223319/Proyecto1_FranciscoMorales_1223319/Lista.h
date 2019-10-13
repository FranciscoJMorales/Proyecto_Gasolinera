#pragma once
#include "Nodo.h"

class Lista
{
public:
	Nodo *head;
	void Lista::Agregar(Nodo *nuevo);
	int Lista::Eliminar(int n);
	Lista();
	~Lista();
private:
	void Lista::AgregarRecursivo(Nodo *nuevo, Nodo *pos);
	int Lista::EliminarRecursivo(int n, Nodo *pos);
};

