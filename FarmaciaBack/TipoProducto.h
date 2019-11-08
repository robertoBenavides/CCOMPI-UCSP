#pragma once
#include<string>
using namespace std;
class TipoProducto
{
private:
	int codigo;
	string descripcion;
public:
	TipoProducto();
	TipoProducto(string);
	TipoProducto(int, string);
	int getCodigo();
	string getDescripcion();

	void setCodigo(int);
	void setDescripcion(string);

	void toString();
};




