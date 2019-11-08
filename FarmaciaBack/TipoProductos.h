#pragma once
#include "TipoProducto.h"
#include <vector>
using namespace std;
class TipoProductos
{
private:
	vector<TipoProducto> tipoproductos;
	int bBusca(vector<TipoProducto>, int, int, int);
	int getIndexByCodigo(int);
	void loadData();
public:
	TipoProductos();
	void createTipoProducto(TipoProducto);
	void updateTipoProducto(TipoProducto);
	void deleteTipoProducto(int);
	TipoProducto getByCodigo(int);
	void toString();
	void saveData();
};

