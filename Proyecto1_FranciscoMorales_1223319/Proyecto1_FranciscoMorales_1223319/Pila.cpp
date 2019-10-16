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

System::String^Pila::String() {
	return StringRecursivo(head);
}

int Pila::BuscarRecursivo(int n, Nodo *pos) {
	if (pos->numero == n) {
		return 0;
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

System::String^Pila::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			return System::Convert::ToString(pos->numero);
		}
		else {
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->sig);
		}
	}
	else {
		return "--";
	}
}