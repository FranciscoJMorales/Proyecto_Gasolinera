#include "Pila.h"
#include "Nodo.h"

Pila::Pila()
{
	//Se asigna la cabeza como nula
	head = nullptr;
}


Pila::~Pila()
{
}

//Procedimiento que ingresa un nuevo elemento a la pila
void Pila::Push(Nodo *nuevo) {
	if (head != nullptr) {
		//�nicamente se enlaza con la cabeza actual si esta existe
		nuevo->sig = head;
	}
	//Exista o no la cabeza, el nuevo nodo pasa a ser la nueva cabeza
	head = nuevo;
}

//Funci�n que devuelve el n�mero al tope de la pila
int Pila::Pop() {
	if (head != nullptr) {
		//Si la pila tiene elementos, se obtiene el n�mero de la cabeza y el siguiente elemento pasa a ser la nueva cabeza
		int aux = head->numero;
		head = head->sig;
		return aux;
	}
	else {
		//Si la pila est� vac�a, devuelve -1
		return -1;
	}
}

//Procedimiento que llena la pila con los 10 d�gitos
void Pila::Llenar() {
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

//M�todo de ordenamiento
void Pila::SelectionSort() {
	Nodo *pos = head;
	while (pos != nullptr) {
		//Busca cu�l es el n�mero mayor de la pila a partir de la posici�n que se est� ordenando
		int n = ObtenerMayor(pos->numero, pos);
		//Obtiene la posici�n del n�mero mayor
		int posicion = BuscarRecursivo(n, pos);
		Nodo *aux = pos;
		//Conociendo la posici�n del n�mero mayor, corre el puntero auxiliar hasta encontrarlo
		for (int i = 0; i < posicion; i++) {
			aux = aux->sig;
		}
		//Hace el intercambio de la posic��n por el n�mero mayor
		aux->numero = pos->numero;
		pos->numero = n;
		//Se avanza a la siguiente posici�n
		pos = pos->sig;
	}
}

//Funci�n que devuelve la posici�n en la que se encuentra un n�mero
int Pila::Buscar(int n) {
	if (head != nullptr) {
		//Llama a una funci�n recursiva para encontrar el n�mero
		return BuscarRecursivo(n, head);
	}
	else {
		//Si la pila est� vac�a, devuelve un n�mero negativo
		return -1;
	}
}

//Devuelve una cadena representativa de todos los elementos de la pila
System::String^Pila::String() {
	//Llama a una funci�n recursiva para mostrar todos los elementos
	return StringRecursivo(head);
}

//Funci�n recursiva que recorre la pila a partir de la posici�n indicada y devuelve el n�mero mayor
int Pila::ObtenerMayor(int mayor, Nodo *pos) {
	if (pos->numero > mayor) {
		//Si el n�mero actual es mayor al mayor anterior, lo reemplaza
		mayor = pos->numero;
	}
	if (pos->sig == nullptr) {
		//Si ya no hay m�s elementos, termina la recursividad
		return mayor;
	}
	else {
		//Si hay m�s elementos, compara con el siguiente
		return ObtenerMayor(mayor, pos->sig);
	}
}

//Funci�n recursiva que devuelve la posici�n de un n�mero en la pila
int Pila::BuscarRecursivo(int n, Nodo *pos) {
	if (pos->numero == n) {
		//Si lo encuentra, termina con la recursividad
		return 0;
	}
	else {
		if (pos->sig == nullptr) {
			//Si no lo encuentra, devuelve un n�mero negativo
			return -100;
		}
		else {
			//Si hay m�s posiciones, verifica en la siguiente y suma uno por cada posici�n buscada
			return 1 + BuscarRecursivo(n, pos->sig);
		}
	}
}

//Funci�n recursiva que devuelve todos los elementos de la pila en un string
System::String^Pila::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			//Si es el �ltimo elemento, termina la recursividad
			return System::Convert::ToString(pos->numero);
		}
		else {
			//Si hay m�s elementos, llama al siguiente y lo concatena con la cadena actual
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->sig);
		}
	}
	else {
		//Valor que devuelve si la pila est� vac�a
		return "--";
	}
}