#include "DetalleAlmacenes.h"
#include "dataAdapter.h"
#include "Producto.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
/*using namespace std;
DetalleAlmacenes::DetalleAlmacenes()
{
	loadData();
}

DetalleAlmacenes::DetalleAlmacenes(Almacenes* almacenes, Productos* productos)
{
	this->almacenes = almacenes;
	this->productos = productos;
	loadData();
}

void DetalleAlmacenes::createDetalleAlmacen(DetalleAlmacen detallealmacen) {
	this->detalmacenes.push_back(detallealmacen);
}
void DetalleAlmacenes::updateDetalleAlmacen(DetalleAlmacen detallealmacen)
{
	int pos = getIndexByCodigo(detallealmacen.getAlmacen().getCodigo(),detallealmacen.getProducto().getCodigo());
	this->detalmacenes[pos] = detallealmacen;
}
void DetalleAlmacenes::deleteDetalleAlmacen(int ida, int idp)
{
	int pos = getIndexByCodigo(ida,idp);
	this->detalmacenes.erase(this->detalmacenes.begin() + pos);
}
void DetalleAlmacenes::loadData() {
	ifstream fs("DetalleAlmacenes.txt", ios::in);
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs, line)) {
		if (line != "") {
			l = da.split(line);
			Almacen a = this->almacenes->getByCodigo(stoi(l[0]));
			Producto p = this->productos->getByCodigo(stoi(l[1]));
			DetalleAlmacen u(a,p,stod( l[2]),stoi(l[3]));
			createDetalleAlmacen(u);
		}
	}
	fs.close();
}
void DetalleAlmacenes::toString() {
	cout << "USUARIOS" << endl;
	cout << left << setw(5) << "id" << setw(20) << "nombre" << setw(20) << "apellido"
		<< setw(20) << "direccion" << setw(10) << "dni" << setw(20) << "uname" << setw(20) << "tipoAlmacene" << endl;
	for (int i = 0; i < detalmacenes.size(); i++)
		almacenes[i].toString();
}
void DetalleAlmacenes::saveData()
{
	ofstream of;
	of.open("DetalleAlmacenes.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";
	}
	for (int i = 0; i < this->detalmacenes.size(); i++) {
		DetalleAlmacen a = detalmacenes[i];
		Producto p = a.getProducto();
		Almacen al = a.getAlmacen();
		of << p.getCodigo()<< "," << al.getCodigo() << "," << a.getPrecio << "," << a.getCantidad() << endl;
	}
	of.close();
}
int DetalleAlmacenes::bBusca(vector<DetalleAlmacen> L, int e,int p, int inicio, int fin) {
	if (inicio > fin)
		return -1;
	if (inicio == fin)
		return (L[inicio].getAlmacen().getCodigo() == e && L[inicio].getProducto().getCodigo()==p) ? inicio : -1;

	int i = (fin + inicio)/2;

	if (L[inicio].getAlmacen().getCodigo() == e && L[inicio].getProducto().getCodigo()==p)
		return i;

	if (L[inicio].getAlmacen().getCodigo() > e)
		return bBusca(L, e,p, inicio, i - 1);
	else
		return bBusca(L, e,p, i + 1, fin);
}
DetalleAlmacen DetalleAlmacenes::getByCodigo(int a,int p) {
	if (this->detalmacenes.size() == 0)
		return DetalleAlmacen();
	return this->detalmacenes.at(bBusca(this->detalmacenes, a,p, 0, this->detalmacenes.size() - 1));
}
int DetalleAlmacenes::getIndexByCodigo(int a, int p) {
	if (this->detalmacenes.size() == 0)
		return -1;
	return bBusca(this->detalmacenes, a, p, 0, this->detalmacenes.size() - 1);
}

*/