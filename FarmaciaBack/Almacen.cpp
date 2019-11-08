#include "Almacen.h"
#include <iostream>
#include <iomanip>
Almacen::Almacen()
{
	this->codigo = -1;
	this->nombre = "";
	this->direccion = "";
}

Almacen::Almacen(string nombre, string direccion)
{
	this->codigo = -1;
	this->nombre = nombre;
	this->direccion = direccion;
}

Almacen::Almacen(int codigo, string nombre, string direccion)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->direccion = direccion;
}

int Almacen::getCodigo()
{
	return this->codigo;
}

string Almacen::getNombre()
{
	return this->nombre;
}

string Almacen::getDireccion()
{
	return this->direccion;
}

void Almacen::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void Almacen::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Almacen::setDireccion(string direccion)
{
	this->direccion = direccion;
}

void Almacen::toString() {
	cout << left << setw(5) << codigo << setw(20) << nombre << setw(40) << direccion<<endl;
}
