#include "TipoProductos.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "dataAdapter.h"

using namespace std;
TipoProductos::TipoProductos()
{
	loadData();
}
void TipoProductos::createTipoProducto(TipoProducto tipoproducto) {
	if (tipoproducto.getCodigo() == -1) {
		int l = this->tipoproductos.size();
		if (l == 0) tipoproducto.setCodigo(1);
		else tipoproducto.setCodigo(this->tipoproductos[l - 1].getCodigo() + 1);
	}
	this->tipoproductos.push_back(tipoproducto);
}
void TipoProductos::updateTipoProducto(TipoProducto tipoproducto)
{
	int pos = getIndexByCodigo(tipoproducto.getCodigo());
	this->tipoproductos[pos] = tipoproducto;
}
void TipoProductos::deleteTipoProducto(int id)
{
	int pos = getIndexByCodigo(id);
	this->tipoproductos.erase(this->tipoproductos.begin() + pos);
}
void TipoProductos::loadData() {
	ifstream fs("TipoProductos.txt", ios::in);
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs, line)) {
		if (line != "") {
			l = da.split(line);
			TipoProducto u(stoi(l[0]), l[1]);
			createTipoProducto(u);
		}
	}
	fs.close();
}
void TipoProductos::toString() {
	cout << left << setw(5) << "id" << setw(20) << "nombre" << setw(20) << "apellido"
		<< setw(20) << "direccion" << setw(10) << "dni" << setw(20) << "uname" << setw(20) << "upwd" << endl;
	for (int i = 0; i < tipoproductos.size(); i++)
		tipoproductos[i].toString();
}
void TipoProductos::saveData()
{
	ofstream of;
	of.open("TipoProductos.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";

	}
	for (int i = 0; i < this->tipoproductos.size(); i++) {
		TipoProducto a = this->tipoproductos[i];
		of << a.getCodigo() << "," << a.getDescripcion() << endl;
	}
	of.close();
}
int TipoProductos::bBusca(vector<TipoProducto> L, int e, int inicio, int fin) {
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
int TipoProductos::getIndexByCodigo(int e) {
	if (this->tipoproductos.size() == 0)
		return -1;
	return bBusca(this->tipoproductos, e, 0, this->tipoproductos.size() - 1);
}
TipoProducto TipoProductos::getByCodigo(int e) {
	if (this->tipoproductos.size() == 0)
		return TipoProducto();
	return this->tipoproductos.at(bBusca(this->tipoproductos, e, 0, this->tipoproductos.size() - 1));
}
