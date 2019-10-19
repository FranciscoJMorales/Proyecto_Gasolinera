#include "Lista.h"

//Para la lista no se implementaron todos los m�todos caracter�sticos de una lista, puesto que no a todos de les dar�a uso
//Los �nicos m�todos implementados fueron para agregar y eliminar elementos a la lista

Lista::Lista()
{
	//Se asigna la cabeza como vac�a
	head = nullptr;
}


Lista::~Lista()
{
}

//Procedimiento que agrega un nuevo n�mero al final de la lista
void Lista::Agregar(Nodo *nuevo) {
	if (head == nullptr) {
		//Si la lista est� vac�a, se asigna inmediatamente a la cabeza
		head = nuevo;
	}
	else {
		//De lo contrario, se busca recursivamente la �ltima posici�n de la lista
		AgregarRecursivo(nuevo, head);
	}
}

//Funci�n que elimina el primer elemento de la lista y devuelve su valor
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
		//Devuelve el n�mero de la cabeza de la lista
		return n;
	}
	else {
		//Si la lista est� vac�a, devuelve -1
		return -1;
	}
}

//Devuelve una representaci�n de la lista actual, con formato "Q00.00"
System::String^Lista::String() {
	//Llama a una funci�n recursiva para mostrar todos los elementos
	System::String ^estado = StringRecursivo(head);
	//Le aplica el formato antes de devolver la cadena
	estado = "Q" + estado->Insert(2, ".");
	return estado;
}

//Procedimiento recursivo que agrega el nuevo n�mero al final de la lista
void Lista::AgregarRecursivo(Nodo *nuevo, Nodo *pos) {
	//Si no es el �ltimo elemento, llama al pr�ximo elemento
	if (pos->sig != nullptr) {
		AgregarRecursivo(nuevo, pos->sig);
	}
	else {
		//Si es el �litmo elemento, se enlaza con el nuevo elemento
		pos->sig = nuevo;
		nuevo->ant = pos;
	}
}

//Funci�n recursiva que devuelve todos los elementos de la lista
System::String^Lista::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			//Si no hay siguiente elemento, termina con la recursividad
			return System::Convert::ToString(pos->numero);
		}
		else {
			//Si hay m�s elementos, concatena la cadena actual con el siguiente elemento
			return System::Convert::ToString(pos->numero) + StringRecursivo(pos->sig);
		}
	}
	else {
		//Valor por retornar si la lista est� vac�a
		return "----";
	}
}