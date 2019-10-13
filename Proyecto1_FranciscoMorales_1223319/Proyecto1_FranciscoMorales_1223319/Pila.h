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
//	Carta *Pila::UltimaCartaVolteada();
//	int Pila::CantidadCartasVolteadas();
	System::String^Pila::String();
private:
/*	Carta *Pila::UltimaCartaVolteadaRecursiva(Carta *pos);
	int Pila::CantidadCartasVolteadasRecursiva(Carta *pos);
*/
	int Pila::BuscarRecursivo(int n, Nodo *pos);
	System::String^Pila::StringRecursivo(Nodo *pos);
};

