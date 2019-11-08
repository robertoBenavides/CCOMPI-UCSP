#pragma once
#include<vector>
#include "Almacen.h"
using namespace std;
class Almacenes
{
private:
	int bBusca(vector<Almacen>, int, int, int);
	void loadData();
	int getIndexByCodigo(int);
public:
	vector<Almacen> almacenes;
	Almacenes();
	void createAlmacen(Almacen);
	void updateAlmacen(Almacen);
	void deleteAlmacen(int);
	Almacen* getByCodigo(int);
	void toString();
	void saveData();
};

