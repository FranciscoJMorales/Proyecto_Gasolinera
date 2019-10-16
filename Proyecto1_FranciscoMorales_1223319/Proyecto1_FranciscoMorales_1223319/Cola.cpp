#include "Cola.h"
#include "Nodo.h"


Cola::Cola()
{
	head = nullptr;
	tail = nullptr;
}


Cola::~Cola()
{
}

void Cola::Push(Nodo *nuevo) {
	if (head == nullptr) {
		tail = nuevo;
		tail->ant = head;
		nuevo->sig = tail;
	}
	else {
		nuevo->sig = head;
		head->ant = nuevo;
	}
	head = nuevo;
}

int Cola::Shift() {
	if (tail == nullptr) {
		return -1;
	}
	else {
		if (tail == head) {
			int aux = tail->numero;
			tail = nullptr;
			head = nullptr;
			return aux;
		}
		else {
			int aux = tail->numero;
			tail = tail->ant;
			return aux;
		}
	}
}

void Cola::Llenar() {
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

int Cola::Buscar(int n) {
	if (tail == nullptr) {
		return -1;
	}
	else {
		if (tail == head) {
			if (tail->numero == n) {
				return 0;
			}
			else {
				return -1;
			}
		}
		else {
			return BuscarRecursivo(n, tail);
		}
	}
}

System::String^Cola::String() {
	if (tail == head) {
		return System::Convert::ToString(tail->numero);
	}
	else {
		return StringRecursivo(tail);
	}
}

int Cola::BuscarRecursivo(int n, Nodo *pos) {
	if (pos->numero == n) {
		return 0;
	}
	else {
		if (pos->ant == nullptr) {
			return -100;
		}
		else {
			return 1 + BuscarRecursivo(n, pos->ant);
		}
	}
}

System::String^Cola::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->ant == nullptr) {
			return System::Convert::ToString(pos->numero);
		}
		else {
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->ant);
		}
	}
	else {
		return "--";
	}
}