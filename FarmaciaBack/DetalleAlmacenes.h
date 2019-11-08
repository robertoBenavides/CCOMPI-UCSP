#pragma once
#include<vector>
#include "DetalleAlmacen.h"
#include "Almacenes.h"
#include "Productos.h"
using namespace std;
class DetalleAlmacenes
{
private:
	Almacenes *almacenes;
	Productos *productos;
	vector<DetalleAlmacen> detalmacenes;
	int bBusca(vector<DetalleAlmacen>,int, int, int, int);
	void loadData();
	int getIndexByCodigo(int,int);
public:
	DetalleAlmacenes();
	DetalleAlmacenes(Almacenes*,Productos*);
	void createDetalleAlmacen(DetalleAlmacen);
	void updateDetalleAlmacen(DetalleAlmacen);
	void deleteDetalleAlmacen(int,int);
	DetalleAlmacen getByCodigo(int,int);
	void toString();
	void saveData();

};

