#include "Productos.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "dataAdapter.h"

using namespace std;
Productos::Productos()
{
	loadData();
}
Productos::Productos(TipoProductos* tipoProductos)
{
	this->tipoProductos = tipoProductos;
	loadData();
}
void Productos::createProducto(Producto producto) {
	if (producto.getCodigo() == -1) {
		int l = productos.size();
		if (l == 0) producto.setCodigo(1);
		else producto.setCodigo(productos[l - 1].getCodigo() + 1);
	}
	productos.push_back(producto);
}
void Productos::updateProducto(Producto producto)
{
	int pos = getByCodigo(producto.getCodigo());
	this->productos[pos] = producto;
}
void Productos::deleteProducto(int id)
{
	int pos = getByCodigo(id);
	this->productos.erase(this->productos.begin() + pos);
}
void Productos::loadData() {
	ifstream fs("Productos.txt", ios::in);
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs, line)) {
		if (line != "") {
			l = da.split(line);
			Producto u(stoi(l[0]), l[1], l[2], tipoProductos->getByCodigo(stoi(l[3])));
			createProducto(u);
		}
	}
	fs.close();
}
void Productos::toString() {
	cout << left << setw(5) << "id" << setw(20) << "nombre" << setw(20) << "apellido"
		<< setw(20) << "direccion" << setw(10) << "dni" << setw(20) << "uname" << setw(20) << "upwd" << endl;
	for (int i = 0; i < productos.size(); i++)
		productos[i].toString();
}
void Productos::saveData()
{
	ofstream of;
	of.open("Productos.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";

	}
	for (int i = 0; i < this->productos.size(); i++) {
		Producto a = productos[i];
		of << a.getCodigo() << "," << a.getNombre() << "," << a.getDescripcion() << "," << a.getTipoprod().getDescripcion() << endl;
	}
	of.close();
}
int Productos::bBusca(vector<Producto> L, int e, int inicio, int fin) {
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
int Productos::getByCodigo(int e) {
	if (this->productos.size() == 0)
		return -1;
	return bBusca(this->productos, e, 0, this->productos.size() - 1);
}
