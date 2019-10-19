#include "Gasolinera.h"



Gasolinera::Gasolinera()
{
	//Se inicializa la gasolinera en un m�todo separado, ya que esta se puede reiniciar durante la ejecuci�n del programa
	Inicializar();
}


Gasolinera::~Gasolinera()
{
}

//M�todo que crea todos los atributos de la clase
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
	//La pila auxiliar permanece vac�a
}

//Procedimiento que recibe un precio en el formato "00.00" y que ingresa los n�meros en la lista solicitada
void Gasolinera::Agregar(System::String ^nuevo, bool lista) {
	try {
		//Revisa que el formato est� correcto
		if (nuevo->Substring(2, 1) == ".") {
			//Elimina el punto del precio
			nuevo = nuevo->Remove(2, 1);
			//Lo convierte inmediatamente para verificar que todos los caracteres sean n�meros y no ingresar los datos a medias
			int n = System::Convert::ToInt32(nuevo);
			//Vac�a la lista especificada de todos los elementos que ya la ocupaban
			Eliminar(lista);
			for (int i = 0; i < 4; i++) {
				n = System::Convert::ToInt32(nuevo->Substring(i, 1));
				//Por cada uno de los 4 d�gitos, llama al procedimiento insertar para extraerlos de su estructura y moverlos a la lista
				//Verifica en qu� lista se van a guardar
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
			System::Windows::Forms::MessageBox::Show("El n�mero ingresado no es v�lido\nEl n�mero debe tener el formato 00.00");
		}
	}
	catch (...) {
		//Si no tiene el formato correcto, muestra un mensaje de error
		System::Windows::Forms::MessageBox::Show("El n�mero ingresado no es v�lido\nEl n�mero debe tener el formato 00.00");
	}
}

//Procedimiento que vac�a todos los elementos de una lista y los devuelve a su estructura correspondiente
void Gasolinera::Eliminar(bool lista) {
	Lista *temp = lista2;
	//Se elige qu� lista se va a vaciar
	if (lista) {
		temp = lista1;
	}
	//Mientras la lista tenga elementos
	while (temp->head != nullptr) {
		int n = temp->Eliminar();
		//Obtiene el primer elemento de la lista
		//Verifica si la pila ya contiene ese n�mero
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

//Procedimiento que llama a los m�todos de ordenamiento de la pila y la cola
void Gasolinera::Ordenar() {
	pila->SelectionSort();
	cola->SelectionSort();
}

//Funci�n que devuelve una cadena con todos los elementos de la pila
System::String^Gasolinera::EstadoPila() {
	return pila->String();
}

//Funci�n que devuelve una cadena con todos los elementos de la cola
System::String^Gasolinera::EstadoCola() {
	return cola->String();
}

//Funci�n que devuelve los elementos de la primera lista, en formato "Q00.00"
System::String^Gasolinera::EstadoPrecio1() {
	return lista1->String();
}
//Funci�n que devuelve los elementos de la segunda lista, en formato "Q00.00"
System::String^Gasolinera::EstadoPrecio2() {
	return lista2->String();
}

//Funci�n que obtiene un n�mero especificado de la cola o pila, y lo env�a a la lista de destino
//Si no encuentra el n�mero en la pila ni en la cola, env�a el siguiente n�mero
void Gasolinera::Insertar(int n, Lista *destino) {
	int posicion = -1;
	//Valor booleano que indica de d�nde se va a extraer el n�mero
	bool desdePila = true;
	//Ciclo que sigue buscando hasta encontrar al n�mero en la pila o cola
	do {
		//Busca si la pila contiene al n�mero
		posicion = pila->Buscar(n);
		desdePila = true;
		if (posicion < 0) {
			//Si no lo tiene, revisa en la cola
			posicion = cola->Buscar(n);
			desdePila = false;
		}
		if (posicion < 0) {
			//Si no lo encuentra en ninguno de los dos, aumenta al d�gito siguiente
			n++;
			if (n > 9) {
				//En caso de llegar a 10, se cambia por 0
				n = 0;
			}
		}
	} while (posicion < 0);
	//Si se encontr� en la pila
	if (desdePila) {
		//Saca valores de la pila hasta encontrar al n�mero, y los guarda en la pila auxiliar
		for (int i = 0; i < posicion; i++) {
			aux->Push(new Nodo(pila->Pop()));
		}
		//El n�mero encontrado se transfiere a la lista de destino
		destino->Agregar(new Nodo(pila->Pop()));
		//Se vuelve a llenar la pila con los elementos de la pila auxiliar
		for (int i = 0; i < posicion; i++) {
			pila->Push(new Nodo(aux->Pop()));
		}
	}
	//Si se encontr� en la cola
	else {
		//Env�a los valores del inicio de la cola al final hasta llegar al n�mero
		for (int i = 0; i < posicion; i++) {
			cola->Push(new Nodo(cola->Shift()));
		}
		//El n�mero encontrado se transfiere a la lista de destino
		destino->Agregar(new Nodo(cola->Shift()));
	}
}