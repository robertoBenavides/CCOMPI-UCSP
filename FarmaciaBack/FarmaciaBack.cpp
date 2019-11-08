// FarmaciaBack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Usuarios.h"
#include "TipoUsuarios.h"
#include"TipoProductos.h"
#include"Productos.h"
#include "Almacenes.h"
#include <iostream>
using namespace std;
TipoUsuarios* tusers = new TipoUsuarios();
TipoProductos* tprods = new TipoProductos();
Usuarios* users = new Usuarios(tusers);
Productos* prod = new Productos(tprods);
Almacenes* almacenes = new Almacenes();
void printTables() {
	tusers->toString();
	cout << endl;

	tprods->toString();
	cout << endl;

	users->toString();
	cout << endl;

	prod->toString();
	cout << endl;

	almacenes->toString();
	cout << endl;
}
int main()
{
	cout << "loading data..." << endl;
	printTables();
	
	//updating User
	Usuario usuario(2,"nombre","c","name","pd","70000403","Direccion",*(tusers->getByCodigo(1)));
	users->updateUser(usuario);
	//prod->deleteProducto(1);
	users->deleteUser(3);


	printTables();

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