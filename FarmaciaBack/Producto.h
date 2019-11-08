#pragma once
#include "TipoProducto.h"
#include <vector>
#include <string>
using namespace std;

class Producto
{
private:
	int codigo;
	string nombre;
	string descripcion;
	TipoProducto tipoprod;
public:
	Producto();
	Producto(string, string, TipoProducto);
	Producto(int,string, string, TipoProducto);
	int getCodigo();
	string getNombre();
	string getDescripcion();
	TipoProducto getTipoprod();
	void setCodigo(int);
	void setNombre(string);
	void setDescripcion(string);
	void setTipoprod(TipoProducto);

	void toString();
};

