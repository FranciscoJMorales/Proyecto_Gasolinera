#include "Lista.h"



Lista::Lista()
{
	//Se asigna la cabeza como vacía
	head = nullptr;
}


Lista::~Lista()
{
}

//Procedimiento que agrega un nuevo número al final de la lista
void Lista::Agregar(Nodo *nuevo) {
	if (head == nullptr) {
		//Si la lista está vacía, se asigna inmediatamente a la cabeza
		head = nuevo;
	}
	else {
		//De lo contrario, se busca recursivamente la última posición de la lista
		AgregarRecursivo(nuevo, head);
	}
}

//Función que elimina el primer elemento de la lista y devuelve su valor
int Lista::Eliminar() {
	if (head != nullptr) {
		//Se guarda el valor de la cabeza de la lista
		int n = head->numero;
		//La nueva cabeza se vuelve el siguiente valor
		head = head->sig;
		if (head != nullptr) {
			//Si la nueva cabeza no es nula, se desenlaza de la cabeza anterior
			head->ant = nullptr;
		}
		//Devuelve el número de la cabeza de la lista
		return n;
	}
	else {
		//Si la lista está vacía, devuelve -1
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