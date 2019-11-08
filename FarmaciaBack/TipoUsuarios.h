#pragma once
#include "TipoUsuario.h"
#include <vector>
using namespace std;
class TipoUsuarios {
private:
	vector<TipoUsuario> tipoUsuarios;
	int bBusca(vector<TipoUsuario>, int, int, int);
	int getIndexByCodigo(int);
	void loadData();
public:
	TipoUsuarios();
	void createTipoUsuario(TipoUsuario);
	void updateTipoUsuario(TipoUsuario);
	void deleteTipoUsuario(int);
	TipoUsuario* getByCodigo(int);
	void toString();
	void saveData();
};



