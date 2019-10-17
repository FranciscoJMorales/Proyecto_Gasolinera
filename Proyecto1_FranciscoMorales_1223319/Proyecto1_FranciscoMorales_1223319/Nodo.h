#pragma once
class Nodo
{
public:
	//La clase cuenta con un valor y dos punteros hacia el valor siguiente y anterior
	int numero;
	Nodo *sig;
	Nodo *ant;

	Nodo(int n);
	~Nodo();
};

