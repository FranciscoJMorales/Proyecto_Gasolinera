#pragma once
class Nodo
{
public:
	int numero;
	Nodo *sig;
	Nodo *ant;

	Nodo(int n);
	~Nodo();
};

