#pragma once
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"

//Toda la documentación de la clase Gasolinera se realiza en el archivo .cpp
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
	//Estructuras de datos para guardar los números
	//Son privados para evitar el manejo de la memoria desde el formulario MyForm
	Pila *pila;
	Cola *cola;
	Lista *lista1;
	Lista *lista2;
	//Pila auxiliar utiizada para mover los elementos de la pila principal
	Pila *aux;
	
	void Gasolinera::Insertar(int n, Lista *destino);
};

