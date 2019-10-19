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
	//Si la cabeza est� vac�a, indica que la cola est� vac�a
	if (head == nullptr) {
		//En este caso, el nuevo nodo se asigna tambi�n a la cola
		tail = nuevo;
	}
	else {
		//En caso que no est� vac�o, �nicamente se agrega el nuevo nodo y se enlaza con la cabeza actual
		nuevo->sig = head;
		head->ant = nuevo;
	}
	//El nuevo nodo pasa a ser la nueva cabeza
	head = nuevo;
}

//Sacar de la cola
int Cola::Shift() {
	//Si la cola est� vac�a, devuelve -1 indicando que no hay n�mero por retornar
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

//Llenar la cola con los 10 d�gitos ordenados
void Cola::Llenar() {
	//Crea 10 nuevos nodos con cada n�mero y los agrega a la cola. Utilizado al inicializar la cola en el simulador
	for (int i = 0; i < 10; i++) {
		Nodo *nuevo = new Nodo(i);
		Push(nuevo);
	}
}

//M�todo de ordenamiento
void Cola::SelectionSort() {
	if (head != tail) {
		Nodo *pos = tail;
		while (pos != nullptr) {
			//Obtiene el n�mero menor y su posici�n
			int n = ObtenerMenor(pos->numero, pos);
			int posicion = BuscarRecursivo(n, pos);
			Nodo *aux = pos;
			//Se cambia la direcci�n del puntero auxiliar para encontrar la posici�n del n�mero menor
			for (int i = 0; i < posicion; i++) {
				aux = aux->ant;
			}
			//Se realiza el intercambio
			aux->numero = pos->numero;
			pos->numero = n;
			//Se avanza a la pr�xima posici�n de la cola
			pos = pos->ant;
		}
	}
}

//Funci�n que devuelve la posici�n de un n�mero en la cola 
//Cuando devuelve un n�mero negativo es porque no encontr� el n�mero en la cola
int Cola::Buscar(int n) {
	//Si la cola est� vac�a, devuelve un n�mero negativo
	if (tail == nullptr) {
		return -1;
	}
	else {
		//Llama a una funci�n recursiva para encontrar la posici�n del n�mero
		return BuscarRecursivo(n, tail);
	}
}

//Devuelve una cadena representativa del estado actual de la cola
System::String^Cola::String() {
	//Llama a una funci�n recursiva para mostrar todos los elementos de la cola
	return StringRecursivo(tail);
}

//Obtiene el n�mero menor de la cola a partir de la primera posici�n enviada. Funci�n recursiva
int Cola::ObtenerMenor(int menor, Nodo *pos) {
	//Si el nuevo n�mero es menor al enviado, ese n�mero pasa a ser el nuevo n�mero menor
	if (pos->numero < menor) {
		menor = pos->numero;
	}
	if (pos->ant == nullptr) {
		//Si se lleg� a la �ltima posici�n de la cola, devuelve el n�mero menor encontrado
		return menor;
	}
	else {
		//Si todav�a hay m�s posiciones, llama a la misma funci�n en la posici�n anterior
		return ObtenerMenor(menor, pos->ant);
	}
}

//Funci�n recursiva que devuelve la posici�n en la que se encuentra un n�mero
//Si no se encuentra el n�mero, devuelve un n�mero negativo
int Cola::BuscarRecursivo(int n, Nodo *pos) {
	//Si encuentra el n�mero, detiene la recursividad
	if (pos->numero == n) {
		return 0;
	}
	else {
		if (pos->ant == nullptr) {
			//Si no lo encuentra y llega al final de la cola, devuelve un n�mero negativo bastante alto
			return -100;
		}
		else {
			//Si no lo encuentra y hay m�s elementos, busca en el elemento anterior
			return 1 + BuscarRecursivo(n, pos->ant);
		}
	}
}

//Funci�n recursiva que muestra todos los n�meros actuales de la cola
System::String^Cola::StringRecursivo(Nodo *pos) {
	if (pos != nullptr) {
		if (pos->ant == nullptr) {
			//Si es el �ltimo elemento, detiene la recursividad
			return System::Convert::ToString(pos->numero);
		}
		else {
			//Si todav�a no es el �ltimo elemento, llama al elemento anterior y lo concatena con el actual
			return System::Convert::ToString(pos->numero) + "\n" + StringRecursivo(pos->ant);
		}
	}
	else {
		//Si la cola est� vac�a, devuelve "--"
		return "--";
	}
}