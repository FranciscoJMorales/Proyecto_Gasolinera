#include "Lista.h"



Lista::Lista()
{
	head = nullptr;
}


Lista::~Lista()
{
}

void Lista::Agregar(Nodo *nuevo) {
	if (head == nullptr) {
		head = nuevo;
	}
	else {
		AgregarRecursivo(nuevo, head);
	}
}

int Lista::Eliminar(int n) {
	if (head != nullptr) {
		EliminarRecursivo(n, head);
	}
	else {
		return -1;
	}
}

void Lista::AgregarRecursivo(Nodo *nuevo, Nodo *pos) {
	if (pos->sig != nullptr) {
		AgregarRecursivo(nuevo, pos->sig);
	}
	else {
		pos->sig = nuevo;
		nuevo->ant = pos;
	}
}

int Lista::EliminarRecursivo(int n, Nodo *pos) {
	if (pos->numero == n) {
		if (pos->sig != nullptr) {
			pos->sig->ant = pos->ant;

		}
		if (pos->ant != nullptr) {
			pos->ant->sig = pos->sig;

		}
		return pos->numero;
	}
	else {
		if (pos->sig != nullptr) {
			return EliminarRecursivo(n, pos->sig);
		}
		else {
			return -1;
		}
	}
}