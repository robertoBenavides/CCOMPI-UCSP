#pragma once
#include "Almacen.h"
#include "Producto.h"
#include <iostream>
using namespace std;
class DetalleAlmacen
{
private:
	Almacen almacen;
	Producto producto;
	double precio;
	int cantidad;
public:
	DetalleAlmacen();
	DetalleAlmacen(Almacen, Producto, double, int);

	Almacen getAlmacen();
	Producto getProducto();
	double getPrecio();
	int getCantidad();

	void setAlmacen(Almacen);
	void setProducto(Producto);
	void setCantidad(int);
	void setPrecio(double);

	void toString();
};

