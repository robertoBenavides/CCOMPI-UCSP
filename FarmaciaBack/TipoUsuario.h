#pragma once
#include<string>
using namespace std;
class TipoUsuario
{
private:
	int codigo;
	string descripcion;

public:
	TipoUsuario();
	TipoUsuario(string);
	TipoUsuario(int, string);
	
	int getCodigo();
	string getDescripcion();

	void setCodigo(int);
	void setDescripcion(string);

	void toString();
};


