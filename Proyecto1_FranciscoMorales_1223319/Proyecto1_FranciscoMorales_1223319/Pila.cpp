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
		//Únicamente se enlaza con la cabeza actual si esta existe
		nuevo->sig = head;
	}
	//Exista o no la cabeza, el nuevo nodo pasa a ser la nueva cabeza
	head = nuevo;
}

//Función que devuelve el número al tope de la pila
int Pila::Pop() {
	if (head != nullptr) {
		//Si la pila tiene elementos, se obtiene el número de la cabeza y el siguiente elemento pasa a ser la nueva cabeza
		int aux = head->numero;
		head = head->sig;
		return aux;
	}
	else {
		//Si la pila está vacía, devuelve -1
		return -1;
	}
}

//Procedimiento que llena la pila con los 10 dígitos
void Pila::Llenar() {
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

//Método de ordenamiento
void Pila::SelectionSort() {
	Nodo *pos = head;
	while (pos != nullptr) {
		//Busca cuál es el número mayor de la pila a partir de la posición que se esté ordenando
		int n = ObtenerMayor(pos->numero, pos);
		//Obtiene la posición del número mayor
		int posicion = BuscarRecursivo(n, pos);
		Nodo *aux = pos;
		//Conociendo la posición del número mayor, corre el puntero auxiliar hasta encontrarlo
		for (int i = 0; i < posicion; i++) {
			aux = aux->sig;
		}
		//Hace el intercambio de la posicíón por el número mayor
		aux->numero = pos->numero;
		pos->numero = n;
		//Se avanza a la siguiente posición
		pos = pos->sig;
	}
}

//Función que devuelve la posición en la que se encuentra un número
int Pila::Buscar(int n) {
	if (head != nullptr) {
		//Llama a una función recursiva para encontrar el número
		return BuscarRecursivo(n, head);
	}
	else {
		//Si la pila está vacía, devuelve un número negativo
		return -1;
	}
}

//Devuelve una cadena representativa de todos los elementos de la pila
System::String^Pila::String() {
	//Llama a una función recursiva para mostrar todos los elementos
	return StringRecursivo(head);
}

//Función recursiva que recorre la pila a partir de la posición indicada y devuelve el número mayor
int Pila::ObtenerMayor(int mayor, Nodo *pos) {
	if (pos->numero > mayor) {
		//Si el número actual es mayor al mayor anterior, lo reemplaza
		mayor = pos->numero;
	}
	if (pos->sig == nullptr) {
		//Si ya no hay más elementos, termina la recursividad
		return mayor;
	}
	else {
		//Si hay más elementos, compara con el siguiente
		return ObtenerMayor(mayor, pos->sig);
	}
}

//Función recursiva que devuelve la posición de un número en la pila
int Pila::BuscarRecursivo(int n, Nodo *pos) {
	if (pos->numero == n) {
		//Si lo encuentra, termina con la recursividad
		return 0;
	}
	else {
		if (pos->sig == nullptr) {
			//Si no lo encuentra, devuelve un número negativo
			return -100;
		}
		else {
			//Si hay más posiciones, verifica en la siguiente y suma uno por cada posición buscada
			return 1 + BuscarRecursivo(n, pos->sig);
		}
	}
}

//Función recursiva que devuelve todos los elementos de la pila en un string
System::String^Pila::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			//Si es el último elemento, termina la recursividad
			return System::Convert::ToString(pos->numero);
		}
		else {
			//Si hay más elementos, llama al siguiente y lo concatena con la cadena actual
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->sig);
		}
	}
	else {
		//Valor que devuelve si la pila está vacía
		return "--";
	}
}