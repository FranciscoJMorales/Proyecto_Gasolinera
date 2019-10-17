#include "Gasolinera.h"



Gasolinera::Gasolinera()
{
	Inicializar();
}


Gasolinera::~Gasolinera()
{
}

void Gasolinera::Inicializar() {
	pila = new Pila();
	cola = new Cola();
	lista1 = new Lista();
	lista2 = new Lista();
	aux = new Pila();
	pila->Llenar();
	cola->Llenar();
}

void Gasolinera::Agregar(System::String ^nuevo, bool lista) {
	try {
		if (nuevo->Substring(2, 1) == ".") {
			nuevo = nuevo->Remove(2, 1);
			int n = System::Convert::ToInt32(nuevo);
			Eliminar(lista);
			for (int i = 0; i < 4; i++) {
				n = System::Convert::ToInt32(nuevo->Substring(i, 1));
				if (lista) {
					Insertar(n, lista1);
				}
				else {
					Insertar(n, lista2);
				}
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("El número ingresado no es válido\nEl número debe tener el formato 00.00");
		}
	}
	catch (...) {
		System::Windows::Forms::MessageBox::Show("El número ingresado no es válido\nEl número debe tener el formato 00.00");
	}
}

void Gasolinera::Eliminar(bool lista) {
	Lista *temp = lista2;
	if (lista) {
		temp = lista1;
	}
	while (temp->head != nullptr) {
		int n = temp->Eliminar();
		int posicion = pila->Buscar(n);
		if (posicion < 0) {
			pila->Push(new Nodo(n));
		}
		else {
			cola->Push(new Nodo(n));
		}
	}
}

void Gasolinera::Ordenar() {
	pila->SelectionSort();
	cola->SelectionSort();
}

System::String^Gasolinera::EstadoPila() {
	return pila->String();
}

System::String^Gasolinera::EstadoCola() {
	return cola->String();
}

System::String^Gasolinera::EstadoPrecio1() {
	return lista1->String();
}

System::String^Gasolinera::EstadoPrecio2() {
	return lista2->String();
}

void Gasolinera::Insertar(int n, Lista *destino) {
	int posicion = -1;
	bool desdePila = true;
	do {
		posicion = pila->Buscar(n);
		desdePila = true;
		if (posicion < 0) {
			posicion = cola->Buscar(n);
			desdePila = false;
		}
		if (posicion < 0) {
			n++;
			if (n > 9) {
				n = 0;
			}
		}
	} while (posicion < 0);
	if (desdePila) {
		for (int i = 0; i < posicion; i++) {
			aux->Push(new Nodo(pila->Pop()));
		}
		destino->Agregar(new Nodo(pila->Pop()));
		for (int i = 0; i < posicion; i++) {
			pila->Push(new Nodo(aux->Pop()));
		}
	}
	else {
		for (int i = 0; i < posicion; i++) {
			cola->Push(new Nodo(cola->Shift()));
		}
		destino->Agregar(new Nodo(cola->Shift()));
	}
}