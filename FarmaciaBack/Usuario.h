#pragma once
#include <iostream>
#include <string>
#include "TipoUsuario.h"
using namespace std;
class Usuario
{
	private:
		int id=-1;
		string nombre;
		string apellido;
		string uname;
		string upwd;
		string dni;
		string direccion;
		TipoUsuario tipo;
public:
	Usuario();
	Usuario(string, string, string, string, string, string,TipoUsuario);
	Usuario(int,string, string, string, string, string, string, TipoUsuario);
	bool validateDNI(string);
	//setters and getters
	void setId(int);
	int getId();

	void setnombre(string);
	string getnombre();

	void setapellido(string);
	string getapellido();
	
	void setuname(string);
	string getuname();
	
	void setpwd(string);
	string getpwd();
	
	void setdni(string);
	string getdni();
	
	void setdireccion(string);
	string getdireccion();

	void setTipoUsuario(TipoUsuario);
	TipoUsuario getTipoUsuario();

	void toString();
};

