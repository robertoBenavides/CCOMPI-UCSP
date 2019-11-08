#pragma once
#include <vector>
#include "Producto.h"
#include "TipoProductos.h"
using namespace std;
class Productos
{
private:
	vector<Producto> productos;
	TipoProductos* tipoProductos;
	vector<TipoProducto> tipoproductos;
	int bBusca(vector<Producto>, int, int, int);
	int getIndexByCodigo(int);
	void loadData();
public:
	Productos();
	Productos(TipoProductos*);
	void createProducto(Producto);
	void updateProducto(Producto);
	void deleteProducto(int);
	Producto getByCodigo(int);
	void toString();
	void saveData();
};



