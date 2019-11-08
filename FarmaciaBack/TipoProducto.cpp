#include "tipoProducto.h"
#include <iostream>
#include <iomanip>

TipoProducto::TipoProducto()
{
	this->codigo = -1;
	this->descripcion = "";
}

TipoProducto::TipoProducto(string descripcion)
{
	this->codigo = -1;
	this->descripcion = descripcion;
}

TipoProducto::TipoProducto(int codigo, string descripcion)
{
	this->codigo = codigo;
	this->descripcion = descripcion;
}

int TipoProducto::getCodigo()
{
	return this->codigo;
}

string TipoProducto::getDescripcion()
{
	return this->descripcion;
}

void TipoProducto::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void TipoProducto::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

void TipoProducto::toString()
{
	cout << left << setw(10) << codigo << setw(40) << descripcion << endl;
}