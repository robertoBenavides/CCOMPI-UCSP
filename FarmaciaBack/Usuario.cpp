#include "Usuario.h"
#include "TipoUsuarios.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;
Usuario::Usuario() {}
Usuario::Usuario(string nombre, string apellido, string uname, string upwd,string dni,string direccion,TipoUsuario tipo) {
	if (validateDNI(dni)) {
		this->dni = dni;
		this->nombre = nombre;
		this->apellido = apellido;
		this->direccion = direccion;
		this->uname = uname;
		this->upwd = upwd;
		this->tipo = tipo;

	}
}
Usuario::Usuario(int id, string nombre, string apellido, string uname, string upwd, string dni, string direccion, TipoUsuario tipo)
{
	if (validateDNI(dni)) {
		this->id = id;
		this->dni = dni;
		this->nombre = nombre;
		this->apellido = apellido;
		this->direccion = direccion;
		this->uname = uname;
		this->upwd = upwd;
		this->tipo = tipo;

	}
}
bool Usuario::validateDNI(string dni) {
	if (dni.length() != 8) {
		cout << "Longitud de DNI incorrecta" << endl;
		return false;
	}
	//if (isnan(dni)) cout << "el DNI debe ser numérico"<<endl;
	return true;
}
void Usuario::setId(int id) {
	this->id = id;	
}
int Usuario::getId() {
	return this->id;
}
void Usuario::setnombre(string nombre)
{
	this->nombre = nombre;
}
string Usuario::getnombre()
{
	return this->nombre;
}
void Usuario::setapellido(string apellido)
{
	this->apellido = apellido;
}
string Usuario::getapellido()
{
	return this->apellido;
}
void Usuario::setuname(string uname)
{
	this->nombre = uname;
}
string Usuario::getuname()
{
	return this->uname;
}
void Usuario::setpwd(string pwd)
{
	this->upwd = pwd;
}
string Usuario::getpwd()
{
	return this->upwd;
}
void Usuario::setdni(string dni)
{
	this->dni = dni;
}
string Usuario::getdni()
{
	return this->dni;
}
void Usuario::setdireccion(string direccion)
{
	this->direccion = direccion;
}
string Usuario::getdireccion()
{
	return this->direccion = direccion;
}
void Usuario::setTipoUsuario(TipoUsuario tipousuario)
{
	this->tipo = tipousuario;
}
TipoUsuario Usuario::getTipoUsuario()
{
	return this->tipo;
}
void Usuario::toString() {
	cout <<left<<setw(5)<< id <<setw(20)<< nombre << setw(20) << apellido 
		<< setw(20) << direccion << setw(10) << dni << setw(20) << uname<< setw(20) << tipo.getDescripcion()<< endl;
}
