#include "TipoUsuarios.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "dataAdapter.h"
using namespace std;
TipoUsuarios::TipoUsuarios()
{
	loadData();
}
void TipoUsuarios::createTipoUsuario(TipoUsuario tipousuario) {
	if (tipousuario.getCodigo() == -1) {
		int l = this->tipoUsuarios.size();
		if (l == 0) tipousuario.setCodigo(1);
		else tipousuario.setCodigo(this->tipoUsuarios[l - 1].getCodigo() + 1);
	}
	this->tipoUsuarios.push_back(tipousuario);
}
void TipoUsuarios::updateTipoUsuario(TipoUsuario tipoproducto)
{
	TipoUsuario* pos = getByCodigo(tipoproducto.getCodigo());
	*pos = tipoproducto;
}
void TipoUsuarios::deleteTipoUsuario(int id)
{
	int pos = getIndexByCodigo(id);
	this->tipoUsuarios.erase(this->tipoUsuarios.begin() + pos);
}
void TipoUsuarios::loadData() {
	ifstream fs;
	fs.open("TipoUsuarios.txt");
	if (!fs) cerr << "no se puedo abrir el file" << endl;
	string line;
	vector<string> l;
	dataAdapter da;
	while (getline(fs, line)) {
		if (line != "") {
			l = da.split(line);
			TipoUsuario u(stoi(l[0]), l[1]);
			createTipoUsuario(u);
		}
	}
	fs.close();
}
void TipoUsuarios::toString() {
	cout << "TIPOUSUARIOS" << endl;
	cout << left << setw(10) << "codigo" << setw(40) << "descripcion" <<  endl;
	for (int i = 0; i < tipoUsuarios.size(); i++)
		tipoUsuarios[i].toString();
}
void TipoUsuarios::saveData()
{
	ofstream of;
	of.open("TipoUsuarios.txt");
	if (!of) {
		cerr << "no pude abrirlo :(";

	}
	for (int i = 0; i < this->tipoUsuarios.size(); i++) {
		TipoUsuario a = this->tipoUsuarios[i];
		of << a.getCodigo() << "," << a.getDescripcion() << endl;
	}
	of.close();
}
int TipoUsuarios::bBusca(vector<TipoUsuario> L, int e, int inicio, int fin) {
	if (inicio > fin)
		return -1;
	if (inicio == fin)
		return (L[inicio].getCodigo() == e) ? inicio : -1;

	int i = (fin + inicio)/2;

	if (L[i].getCodigo() == e)
		return i;

	if (L[i].getCodigo() > e)
		return bBusca(L, e, inicio, i - 1);
	else
		return bBusca(L, e, i + 1, fin);
}
int TipoUsuarios::getIndexByCodigo(int e) {
	if (this->tipoUsuarios.size() == 0)
		return -1;
	return bBusca(this->tipoUsuarios, e, 0, this->tipoUsuarios.size() - 1);
}
TipoUsuario* TipoUsuarios::getByCodigo(int e) {
	if (this->tipoUsuarios.size() == 0)
		return &TipoUsuario();
	return &this->tipoUsuarios.at(bBusca(this->tipoUsuarios, e, 0, this->tipoUsuarios.size()-1));
}
