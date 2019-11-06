// TrabajoPractico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
class Estudiante {
private:
	string nombre;
	string apellido;
	string codigo;

public:
	Estudiante();
	Estudiante(string, string, string);
	string getNombre();
	string getApellido();
	string getCodigo();
	void toString();
};

//------------------------------------
Estudiante::Estudiante() {
	this->nombre = "";
	this->apellido = "";
	this->codigo = "";
}
Estudiante::Estudiante(string nombre, string apellido, string codigo) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigo = codigo;
}
void Estudiante::toString() {
	cout << this->nombre << "\t" << this->apellido << "\t" << this->codigo << endl;
}
string Estudiante::getNombre() {
	return this->nombre;
}
string Estudiante::getApellido() {
	return this->apellido;
}
string Estudiante::getCodigo() {
	return this->codigo;
}
//---------------------------------------------
class Curso {
private:
	string nombre;
	string codigo;
	Estudiante* alumnos;
	int cantAlumnos;
public:
	Curso(string,string,Estudiante*,int);
	Curso(Curso& o);

	void addAlumno(Estudiante);

	string getNombre();
	string getCodigo();
	int getCantidad();
	Estudiante* getAlumnos();

	void setNombre(string);
	void setCodigo(string);
	void setCantidadAlumnos(int);
	void setAlumnos(Estudiante*);

	void toString();
};
//-------------------------------------------
Curso::Curso(string nombre,string codigo,Estudiante* alumnos,int cantAlumnos) {
	this->nombre = nombre;
	this->codigo = codigo;
	this->cantAlumnos = cantAlumnos;
	this->alumnos = alumnos;
}
Curso::Curso(Curso& a) {
	this->nombre = a.getNombre();
	this->codigo = a.getCodigo();
	this->cantAlumnos = a.getCantidad();
	this->alumnos = a.getAlumnos();
}
void Curso::addAlumno(Estudiante e) {
	this->cantAlumnos++;
	Estudiante *al = new Estudiante[this->cantAlumnos];
	for (int i = 0; i < this->cantAlumnos - 1; i++) {
		*(al + i) = *(this->alumnos + i);
	}
	*(al + this->cantAlumnos - 1) = e;
	this->alumnos = al;
}
string Curso::getNombre() {
	return this->nombre;
}
string Curso::getCodigo() {
	return this->codigo;
}
int Curso::getCantidad() {
	return this->cantAlumnos;
}
Estudiante* Curso::getAlumnos() {
	return this->alumnos;
}

void Curso::setNombre(string nombre) {
	this->nombre = nombre;
}
void Curso::setCodigo(string codigo) {
	this->codigo = codigo;
}
void Curso::setCantidadAlumnos(int cant) {
	this->cantAlumnos = cant;
}
void Curso::setAlumnos(Estudiante* alumnos) {
	this->alumnos = alumnos;
}

void Curso::toString() {
	cout << "Codigo: " << this->codigo << endl;
	cout << "nombre: " << this->nombre << endl;
	for (int i = 0; i < this->cantAlumnos; i++) {
		(*(this->alumnos)).toString();
		this->alumnos++;
		cout << endl;
	}
	this->alumnos -= cantAlumnos - 1;
}
int main()
{
    //a
	Estudiante e1("roberto", "benavides", "R-001");
	Estudiante e2("juan", "Valverdi", "R-002");
	cout<<e1.getNombre()<<e1.getApellido()<<e1.getCodigo()<<endl;
	cout << e2.getNombre() << e2.getApellido() << e2.getCodigo() << endl;

	//b
	Estudiante e3("lizeth", "noseq", "R-012");
	Estudiante e4("jeremayha", "rivioca", "R-031");

	Estudiante a[] = { e1,e2,e3 };
	Estudiante b[] = { e4,e2,e3 };

	Curso curso1("discretas", "EDII", a, 3); 
	curso1.setNombre("Estructuras Discretas II");
	curso1.addAlumno(e4);
	curso1.toString();
	Curso curso2("introduccion", "ICC", b, 2);
	curso2.setCantidadAlumnos(3);
	curso2.setCodigo("ICC-I");
	curso2.toString();

	cout <<"El "<< curso1.getNombre() << "tiene " << curso1.getCantidad()<<"alumno(s)";





}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
