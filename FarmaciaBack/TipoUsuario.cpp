#include "TipoUsuario.h"
#include <iostream>
#include <iomanip>

TipoUsuario::TipoUsuario() {
	this->codigo = -1;
	this->descripcion = "";
}
TipoUsuario::TipoUsuario(string desc) {
	this->codigo = -1;
	this->descripcion = desc;
}
TipoUsuario::TipoUsuario(int id, string desc) {
	this->codigo= id;
	this->descripcion=desc;
}

int TipoUsuario::getCodigo()
{
	return this->codigo;
}

string TipoUsuario::getDescripcion()
{
	return this->descripcion;
}

void TipoUsuario::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void TipoUsuario::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

void TipoUsuario::toString()
{
	cout << left << setw(5) << codigo << setw(20) << descripcion << endl;
}
