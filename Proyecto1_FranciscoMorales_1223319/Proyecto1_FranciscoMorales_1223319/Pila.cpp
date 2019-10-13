#include "Pila.h"
#include "Nodo.h"

Pila::Pila()
{
	head = nullptr;
}


Pila::~Pila()
{
}

void Pila::Push(Nodo *nuevo) {
	if (head != nullptr) {
		nuevo->sig = head;
	}
	head = nuevo;
}

int Pila::Pop() {
	if (head != nullptr) {
		int aux = head->numero;
		head = head->sig;
		return aux;
	}
	else {
		return -1;
	}
}

void Pila::Llenar() {
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

int Pila::Buscar(int n) {
	if (head != nullptr) {
		return BuscarRecursivo(n, head);
	}
	else {
		return -1;
	}
}

/*Carta *Pila::UltimaCartaVolteada() {
	return UltimaCartaVolteadaRecursiva(head);
}

int Pila::CantidadCartasVolteadas() {
	return CantidadCartasVolteadasRecursiva(head);
}
*/

System::String^Pila::String() {
	return StringRecursivo(head);
}

int Pila::BuscarRecursivo(int n, Nodo *pos) {
	if (pos->numero = n) {
		return 1;
	}
	else {
		if (pos->sig == nullptr) {
			return -100;
		}
		else {
			return 1 + BuscarRecursivo(n, pos->sig);
		}
	}
}

/*Carta *Pila::UltimaCartaVolteadaRecursiva(Carta *pos) {
	if (pos->sig != nullptr) {
		if (pos->sig->volteado) {
			return UltimaCartaVolteadaRecursiva(pos->sig);
		}
		else {
			return pos;
		}
	}
	else {
		return pos;
	}
}

int Pila::CantidadCartasVolteadasRecursiva(Carta *pos) {
	if (pos->sig != nullptr) {
		if (pos->sig->volteado) {
			return CantidadCartasVolteadasRecursiva(pos->sig) + 1;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}
*/

System::String^Pila::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			return System::Convert::ToString(pos->numero);
		}
		else {
			return StringRecursivo(pos->sig) + "\n" + pos->numero;
		}
	}
	else {
		return "--";
	}
}