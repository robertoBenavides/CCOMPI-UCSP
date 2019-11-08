#include "Usuarios.h"

#include "dataAdapter.h"
#include "TipoUsuarios.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "TipoUsuarios.h"
using namespace std;
Usuarios::Usuarios()
{
	loadData();
}
Usuarios::Usuarios(TipoUsuarios* tu)
{
	this->tipousuarios = tu;
	loadData();
}
void Usuarios::createUser(Usuario usuario) {
	if (usuario.getId() == -1) {
		int l = usuarios.size();
		if (l == 0) usuario.setId(1);
		else usuario.setId(usuarios[l - 1].getId() + 1);
	}
	usuarios.push_back(usuario);
}
void Usuarios::updateUser(Usuario usuario)
{
	Usuario* pos=getById(usuario.getId());
	*pos=usuario;
}
void Usuarios::deleteUser(int id)
{
	int pos = getIndexById(id);
	this->usuarios.erase(this->usuarios.begin()+pos);
}
void Usuarios::loadData() {
	ifstream fs("Usuarios.txt", ios::in);
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs,line)) {
		if (line != "") {
			l = da.split(line);
			TipoUsuario a = *(this->tipousuarios->getByCodigo(stoi(l[7])));
			Usuario u(stoi(l[0]), l[1], l[2], l[3], l[4], l[5], l[6], a);
			createUser(u);
		}
	}
	fs.close();
}
void Usuarios::toString() {
	cout << "USUARIOS" << endl;
	cout << left << setw(5) << "id" << setw(20) << "nombre" << setw(20) << "apellido"
		<< setw(20) << "direccion" << setw(10) << "dni" << setw(20) << "uname" << setw(20) << "tipoUsuario" << endl;
	for (int i=0;i < usuarios.size();i++)
		usuarios[i].toString();
}
void Usuarios::saveData()
{
	ofstream of;
	of.open("Usuarios.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";
	}
	for (int i = 0; i < this->usuarios.size(); i++) {
		Usuario a = usuarios[i];
		of << a.getId() << "," << a.getnombre() << "," << a.getapellido() << "," << a.getuname() << "," << a.getpwd() << "," << a.getdni() << "," << a.getdireccion()<<"," << a.getTipoUsuario().getCodigo() << endl;
	}
	of.close();
}
int Usuarios::bBusca(vector<Usuario> L, int e, int inicio, int fin) {
	if (inicio > fin)
		return -1;
	if (inicio == fin)
		return (L[inicio].getId() == e) ? inicio : -1;

	int i = (fin + inicio)/2;

	if (L[i].getId() == e)
		return i;

	if (L[i].getId() > e)
		return bBusca(L, e, inicio, i - 1);
	else
		return bBusca(L, e, i + 1, fin);
}
int Usuarios::getIndexById(int e) {
	if (this->usuarios.size() == 0)
		return -1;
	return bBusca(this->usuarios, e, 0, this->usuarios.size() - 1);
}
Usuario* Usuarios::getById(int e) {
	if (this->usuarios.size() == 0)
		return &Usuario();
	return &this->usuarios.at( bBusca(this->usuarios, e, 0, this->usuarios.size() - 1));
}


