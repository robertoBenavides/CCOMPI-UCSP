#include "DetalleAlmacen.h"

DetalleAlmacen::DetalleAlmacen()
{
	
}

DetalleAlmacen::DetalleAlmacen(Almacen almacen, Producto producto, double precio, int cantidad)
{
	this->almacen = almacen;
	this->producto = producto;
	this->precio = precio;
	this->cantidad = cantidad;
}

Almacen DetalleAlmacen::getAlmacen()
{
	return this->almacen;
}

Producto DetalleAlmacen::getProducto()
{
	return this->producto;
}

double DetalleAlmacen::getPrecio()
{
	return this->precio;
}

int DetalleAlmacen::getCantidad()
{
	return this->cantidad;
}

void DetalleAlmacen::setAlmacen(Almacen almacen)
{
	this->almacen = almacen;
}

void DetalleAlmacen::setProducto(Producto producto)
{
	this->producto = producto;
}

void DetalleAlmacen::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void DetalleAlmacen::setPrecio(double precio)
{
	this->precio = precio;
}
