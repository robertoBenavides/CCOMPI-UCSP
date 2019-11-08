#pragma once
#include <string>
using namespace std;
class Almacen
{
private:
	int codigo;
	string nombre;
	string direccion;
public:
	Almacen();
	Almacen(string, string);
	Almacen(int,string, string);

	int getCodigo();
	string getNombre();
	string getDireccion();

	void setCodigo(int);
	void setNombre(string);
	void setDireccion(string);

	void toString();

};

