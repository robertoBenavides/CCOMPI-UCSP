#include "Producto.h"
#include "Producto.h"
#include <iomanip>
#include <iostream>

Producto::Producto() {
	this->descripcion = descripcion;
	this->nombre = nombre;
}

Producto::Producto(string nombre, string desc, TipoProducto tipoprod)
{
	this->descripcion = descripcion;
	this->tipoprod = tipoprod;
	this->nombre = nombre;
}

Producto::Producto(int codigo, string nombre, string descripcion, TipoProducto tipoprod)
{
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->tipoprod = tipoprod;
	this->nombre = nombre;
}

int Producto::getCodigo()
{
	return this->codigo;
}

string Producto::getNombre()
{
	return this->nombre;
}

string Producto::getDescripcion()
{
	return this->descripcion;
}

TipoProducto Producto::getTipoprod()
{
	return this->tipoprod;
}

void Producto::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Producto::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

void Producto::setTipoprod(TipoProducto tipoprod)
{
	this->tipoprod = tipoprod;
}

void Producto::toString()
{
	cout << left << setw(10) << codigo << setw(20) << nombre << setw(40) << descripcion << setw(20) << tipoprod.getDescripcion() << endl;
}