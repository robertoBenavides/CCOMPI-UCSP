#include "Almacenes.h"
#include "dataAdapter.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
Almacenes::Almacenes()
{
	loadData();
}
void Almacenes::createAlmacen(Almacen almacen) {
	if (almacen.getCodigo() == -1) {
		int l = almacenes.size();
		if (l == 0) almacen.setCodigo(1);
		else almacen.setCodigo(almacenes[l - 1].getCodigo() + 1);
	}
	almacenes.push_back(almacen);
}
void Almacenes::updateAlmacen(Almacen almacen)
{
	int pos = getByCodigo(almacen.getCodigo());
	this->almacenes[pos] = almacen;
}
void Almacenes::deleteAlmacen(int id)
{
	int pos = getByCodigo(id);
	this->almacenes.erase(this->almacenes.begin() + pos);
}
void Almacenes::loadData() {
	ifstream fs("Almacenes.txt", ios::in);
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs, line)) {
		if (line != "") {
			l = da.split(line);

			Almacen u(stoi(l[0]), l[1], l[2]);
			createAlmacen(u);
		}
	}
	fs.close();
}
void Almacenes::toString() {
	cout << left << setw(5) << "id" << setw(20) << "nombre" << setw(20) << "apellido"
		<< setw(20) << "direccion" << setw(10) << "dni" << setw(20) << "uname" << setw(20) << "upwd" << endl;
	for (int i = 0; i < almacenes.size(); i++)
		almacenes[i].toString();
}
void Almacenes::saveData()
{
	ofstream of;
	of.open("Almacenes.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";

	}
	for (int i = 0; i < this->almacenes.size(); i++) {
		Almacen a = almacenes[i];
		of << a.getCodigo() << "," << a.getNombre() << "," << a.getDireccion() << endl;
	}
	of.close();
}
int Almacenes::bBusca(vector<Almacen> L, int e, int inicio, int fin) {
	if (inicio > fin)
		return -1;
	if (inicio == fin)
		return (L[inicio].getCodigo() == e) ? inicio : -1;

	int i = (fin + inicio);

	if (L[i].getCodigo() == e)
		return i;

	if (L[i].getCodigo() > e)
		return bBusca(L, e, inicio, i - 1);
	else
		return bBusca(L, e, i + 1, fin);
}
int Almacenes::getByCodigo(int e) {
	if (this->almacenes.size() == 0)
		return -1;
	return bBusca(this->almacenes, e, 0, this->almacenes.size() - 1);
}
