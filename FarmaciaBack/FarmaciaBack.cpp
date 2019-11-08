// FarmaciaBack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Usuarios.h"
#include "TipoUsuarios.h"
#include"TipoProductos.h"
#include"Productos.h"
#include "Almacenes.h"
#include <iostream>
using namespace std;
int main()
{
	cout << "loading data..." << endl;
	TipoUsuarios *tusers=new TipoUsuarios();
	tusers->toString();
	TipoProductos* tprods = new TipoProductos();
	tprods->toString();
	Usuarios* users = new Usuarios(tusers);
	users->toString();
	Productos *prod = new Productos(tprods);
	prod->toString();
	Almacenes* almacenes = new Almacenes();
	almacenes->toString();

	tusers->saveData();
	tprods->saveData();
	users->saveData();
	prod->saveData();
	almacenes->saveData();
	/*string nombre,apellido,uname,upwd,dni,direccion,tipo;
	cout << "ingresar Usuario" << endl;
	cout << "nombre:" << endl;
	getline(cin,nombre);
	cout << "apellido:" << endl;
	getline(cin, apellido);
	cout << "nickname:" << endl;
	getline(cin, uname);
	cout << "psw:" << endl;
	getline(cin, upwd);
	cout << "dni:" << endl;
	getline(cin, dni);
	cout << "direccion:" << endl;
	getline(cin, direccion);
	cout << "idtipo:" << endl;
	getline(cin, tipo);
	Usuario c(nombre, apellido, uname, upwd, dni, direccion, tusers->getByCodigo(stoi(tipo)));
	users->createUser(c);
	users->toString();
	users->saveData();*/

}