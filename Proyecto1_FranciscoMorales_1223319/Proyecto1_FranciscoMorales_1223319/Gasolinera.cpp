#include "Gasolinera.h"



Gasolinera::Gasolinera()
{
	//Se inicializa la gasolinera en un método separado, ya que esta se puede reiniciar durante la ejecución del programa
	Inicializar();
}


Gasolinera::~Gasolinera()
{
}

//Método que crea todos los atributos de la clase
void Gasolinera::Inicializar() {
	//Se instancian los objetos
	pila = new Pila();
	cola = new Cola();
	lista1 = new Lista();
	lista2 = new Lista();
	aux = new Pila();
	//Se llenan tanto la pila como la cola
	pila->Llenar();
	cola->Llenar();
	//La pila auxiliar permanece vacía
}

//Procedimiento que recibe un precio en el formato "00.00" y que ingresa los números en la lista solicitada
void Gasolinera::Agregar(System::String ^nuevo, bool lista) {
	try {
		//Revisa que el formato esté correcto
		if (nuevo->Substring(2, 1) == ".") {
			//Elimina el punto del precio
			nuevo = nuevo->Remove(2, 1);
			//Lo convierte inmediatamente para verificar que todos los caracteres sean números y no ingresar los datos a medias
			int n = System::Convert::ToInt32(nuevo);
			//Vacía la lista especificada de todos los elementos que ya la ocupaban
			Eliminar(lista);
			for (int i = 0; i < 4; i++) {
				n = System::Convert::ToInt32(nuevo->Substring(i, 1));
				//Por cada uno de los 4 dígitos, llama al procedimiento insertar para extraerlos de su estructura y moverlos a la lista
				//Verifica en qué lista se van a guardar
				if (lista) {
					Insertar(n, lista1);
				}
				else {
					Insertar(n, lista2);
				}
			}
		}
		else {
			//Si no tiene el formato correcto, muestra un mensaje de error
			System::Windows::Forms::MessageBox::Show("El número ingresado no es válido\nEl número debe tener el formato 00.00");
		}
	}
	catch (...) {
		//Si no tiene el formato correcto, muestra un mensaje de error
		System::Windows::Forms::MessageBox::Show("El número ingresado no es válido\nEl número debe tener el formato 00.00");
	}
}

//Procedimiento que vacía todos los elementos de una lista y los devuelve a su estructura correspondiente
void Gasolinera::Eliminar(bool lista) {
	Lista *temp = lista2;
	//Se elige qué lista se va a vaciar
	if (lista) {
		temp = lista1;
	}
	//Mientras la lista tenga elementos
	while (temp->head != nullptr) {
		int n = temp->Eliminar();
		//Obtiene el primer elemento de la lista
		//Verifica si la pila ya contiene ese número
		int posicion = pila->Buscar(n);
		if (posicion < 0) {
			//Si no lo tiene, lo guarda en la pila
			pila->Push(new Nodo(n));
		}
		else {
			//Si ya lo tiene, lo guarda en la cola
			cola->Push(new Nodo(n));
		}
	}
}

//Procedimiento que llama a los métodos de ordenamiento de la pila y la cola
void Gasolinera::Ordenar() {
	pila->SelectionSort();
	cola->SelectionSort();
}

//Función que devuelve una cadena con todos los elementos de la pila
System::String^Gasolinera::EstadoPila() {
	return pila->String();
}

//Función que devuelve una cadena con todos los elementos de la cola
System::String^Gasolinera::EstadoCola() {
	return cola->String();
}

//Función que devuelve los elementos de la primera lista, en formato "Q00.00"
System::String^Gasolinera::EstadoPrecio1() {
	return lista1->String();
}
//Función que devuelve los elementos de la segunda lista, en formato "Q00.00"
System::String^Gasolinera::EstadoPrecio2() {
	return lista2->String();
}

//Función que obtiene un número especificado de la cola o pila, y lo envía a la lista de destino
//Si no encuentra el número en la pila ni en la cola, envía el siguiente número
void Gasolinera::Insertar(int n, Lista *destino) {
	int posicion = -1;
	//Valor booleano que indica de dónde se va a extraer el número
	bool desdePila = true;
	//Ciclo que sigue buscando hasta encontrar al número en la pila o cola
	do {
		//Busca si la pila contiene al número
		posicion = pila->Buscar(n);
		desdePila = true;
		if (posicion < 0) {
			//Si no lo tiene, revisa en la cola
			posicion = cola->Buscar(n);
			desdePila = false;
		}
		if (posicion < 0) {
			//Si no lo encuentra en ninguno de los dos, aumenta al dígito siguiente
			n++;
			if (n > 9) {
				//En caso de llegar a 10, se cambia por 0
				n = 0;
			}
		}
	} while (posicion < 0);
	//Si se encontró en la pila
	if (desdePila) {
		//Saca valores de la pila hasta encontrar al número, y los guarda en la pila auxiliar
		for (int i = 0; i < posicion; i++) {
			aux->Push(new Nodo(pila->Pop()));
		}
		//El número encontrado se transfiere a la lista de destino
		destino->Agregar(new Nodo(pila->Pop()));
		//Se vuelve a llenar la pila con los elementos de la pila auxiliar
		for (int i = 0; i < posicion; i++) {
			pila->Push(new Nodo(aux->Pop()));
		}
	}
	//Si se encontró en la cola
	else {
		//Envía los valores del inicio de la cola al final hasta llegar al número
		for (int i = 0; i < posicion; i++) {
			cola->Push(new Nodo(cola->Shift()));
		}
		//El número encontrado se transfiere a la lista de destino
		destino->Agregar(new Nodo(cola->Shift()));
	}
}