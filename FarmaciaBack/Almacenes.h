#pragma once
#include<vector>
#include "Almacen.h"
using namespace std;
class Almacenes
{
private:
	int bBusca(vector<Almacen>, int, int, int);
	void loadData();
public:
	vector<Almacen> almacenes;
	Almacenes();
	void createAlmacen(Almacen);
	void updateAlmacen(Almacen);
	void deleteAlmacen(int);
	int getByCodigo(int);
	void toString();
	void saveData();
};

