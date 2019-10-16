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

int Lista::Eliminar() {
	if (head != nullptr) {
		int n = head->numero;
		head = head->sig;
		if (head != nullptr) {
			head->ant = nullptr;
		}
		return n;
	}
	else {
		return -1;
	}
}

System::String^Lista::String() {
	System::String ^estado = StringRecursivo(head);
	estado = "Q" + estado->Insert(2, ".");
	return estado;
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

System::String^Lista::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			return System::Convert::ToString(pos->numero);
		}
		else {
			return System::Convert::ToString(pos->numero) + StringRecursivo(pos->sig);
		}
	}
	else {
		return "----";
	}
}