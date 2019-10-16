#pragma once
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"

class Gasolinera
{
public:
	Gasolinera();
	~Gasolinera();
	void Gasolinera::Inicializar();
	void Gasolinera::Agregar(System::String ^nuevo, bool lista);
	void Gasolinera::Eliminar(bool lista);
	void Gasolinera::Ordenar();
	System::String^Gasolinera::EstadoPila();
	System::String^Gasolinera::EstadoCola();
	System::String^Gasolinera::EstadoPrecio1();
	System::String^Gasolinera::EstadoPrecio2();

private:
	Pila *pila;
	Cola *cola;
	Lista *lista1;
	Lista *lista2;
	Pila *aux;
	
	void Gasolinera::Insertar(int n, Lista *destino);
};

