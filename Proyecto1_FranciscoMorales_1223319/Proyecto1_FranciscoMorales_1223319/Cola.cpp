#include "Cola.h"
#include "Nodo.h"

Cola::Cola()
{
	//Se asignan como nulos la cabeza y la cola
	head = nullptr;
	tail = nullptr;
}


Cola::~Cola()
{
}

//Agregar a la cola
void Cola::Push(Nodo *nuevo) {
	//Si la cabeza está vacía, indica que la cola está vacía
	if (head == nullptr) {
		//En este caso, el nuevo nodo se asigna también a la cola
		tail = nuevo;
	}
	else {
		//En caso que no esté vacío, únicamente se agrega el nuevo nodo y se enlaza con la cabeza actual
		nuevo->sig = head;
		head->ant = nuevo;
	}
	//El nuevo nodo pasa a ser la nueva cabeza
	head = nuevo;
}

//Sacar de la cola
int Cola::Shift() {
	//Si la cola está vacía, devuelve -1 indicando que no hay número por retornar
	if (tail == nullptr) {
		return -1;
	}
	else {
		//En caso de tener al menos un elemento, devuelve el valor en la cola (puntero) y esta se desenlaza de la cola
		int aux = tail->numero;
		tail = tail->ant;
		return aux;
	}
}

//Llenar la cola con los 10 dígitos ordenados
void Cola::Llenar() {
	//Crea 10 nuevos nodos con cada número y los agrega a la cola. Utilizado al inicializar la cola en el simulador
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

//Método de ordenamiento
void Cola::SelectionSort() {
	if (head != tail) {
		Nodo *pos = tail;
		while (pos != nullptr) {
			//Obtiene el número menor y su posición
			int n = ObtenerMenor(pos->numero, pos);
			int posicion = BuscarRecursivo(n, pos);
			Nodo *aux = pos;
			//Se cambia la dirección del puntero auxiliar para encontrar la posición del número menor
			for (int i = 0; i < posicion; i++) {
				aux = aux->ant;
			}
			//Se realiza el intercambio
			aux->numero = pos->numero;
			pos->numero = n;
			//Se avanza a la próxima posición de la cola
			pos = pos->ant;
		}
	}
}

//Función que devuelve la posición de un número en la cola 
//Cuando devuelve un número negativo es porque no encontró el número en la cola
int Cola::Buscar(int n) {
	//Si la cola está vacía, devuelve un número negativo
	if (tail == nullptr) {
		return -1;
	}
	else {
		//Llama a una función recursiva para encontrar la posición del número
		return BuscarRecursivo(n, tail);
	}
}

//Devuelve una cadena representativa del estado actual de la cola
System::String^Cola::String() {
	//Llama a una función recursiva para mostrar todos los elementos de la cola
	return StringRecursivo(tail);
}

//Obtiene el número menor de la cola a partir de la primera posición enviada. Función recursiva
int Cola::ObtenerMenor(int menor, Nodo *pos) {
	//Si el nuevo número es menor al enviado, ese número pasa a ser el nuevo número menor
	if (pos->numero < menor) {
		menor = pos->numero;
	}
	if (pos->ant == nullptr) {
		//Si se llegó a la última posición de la cola, devuelve el número menor encontrado
		return menor;
	}
	else {
		//Si todavía hay más posiciones, llama a la misma función en la posición anterior
		return ObtenerMenor(menor, pos->ant);
	}
}

//Función recursiva que devuelve la posición en la que se encuentra un número
//Si no se encuentra el número, devuelve un número negativo
int Cola::BuscarRecursivo(int n, Nodo *pos) {
	//Si encuentra el número, detiene la recursividad
	if (pos->numero == n) {
		return 0;
	}
	else {
		if (pos->ant == nullptr) {
			//Si no lo encuentra y llega al final de la cola, devuelve un número negativo bastante alto
			return -100;
		}
		else {
			//Si no lo encuentra y hay más elementos, busca en el elemento anterior
			return 1 + BuscarRecursivo(n, pos->ant);
		}
	}
}

//Función recursiva que muestra todos los números actuales de la cola
System::String^Cola::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->ant == nullptr) {
			//Si es el último elemento, detiene la recursividad
			return System::Convert::ToString(pos->numero);
		}
		else {
			//Si todavía no es el último elemento, llama al elemento anterior y lo concatena con el actual
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->ant);
		}
	}
	else {
		//Si la cola está vacía, devuelve "--"
		return "--";
	}
}