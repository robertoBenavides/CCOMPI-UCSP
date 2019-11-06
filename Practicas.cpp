#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Empleado {
private:
	string nombre;
	string apellido;
	double salario;
	void fixSalary(double);
public:
	Empleado(string, string, double);
	void setSalary(double);
	void tostring();
	double getsalary();
	string getapellido();
	void reduceSalary();
	double getAnualsalary();
};


//---------------------------------------------------------------------------------------------
void Empleado::fixSalary(double salario) {
	if (salario < 0) this->salario = 0;
	else this->salario = salario;
}
Empleado::Empleado(string nombre, string apellido, double salario) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->fixSalary(salario);
}
void Empleado::setSalary(double salario) {
	this->fixSalary(salario);
}
void Empleado::tostring() {
	cout << left << setw(25) << this->nombre << setw(25) << this->apellido << setw(15) << this->salario;
}
double Empleado::getsalary() {
	return this->salario;
}
string Empleado::getapellido() {
	return this->apellido;
}
void Empleado::reduceSalary() {
	this->salario*= .9;
}
double Empleado::getAnualsalary() {
	return this->salario * 12;
}

//---------------------------------------------------------------------------------------------


void print(Empleado a[], int tam) {
	cout << left << setw(25) << "nombre" << setw(25) << "apellido" << setw(15) << "salario" << endl;
	for (int i = 0; i < tam; i++) {
		a[i].tostring(); cout << endl;
	}
}
bool mayor(Empleado e1, Empleado e2) {
	string a1 = e1.getapellido(), a2 = e2.getapellido();
	int tam1 = a1.length(), tam2 = a2.length();
	int tam = (tam1 > tam2) ? tam2 : tam1;
	for (int i = 0; i < tam; i++) {
		if (static_cast<int>(a1[i]) > static_cast<int>(a2[i])) {
			return true;
		}
	}
	if (tam == tam1) return true;
	return false;
}
void change(Empleado* a, Empleado* b) {
	Empleado c = *a;
	*a = *b;
	*b = c;
}
void ord(Empleado* emps, int tam) {
	for (int i = 2; i < tam; i++) {
		int c = i;
		Empleado* ptr1 = emps + i;
		Empleado* ptr = ptr1 - 1;
		Empleado emp = *ptr1;
		while (c != 0 && mayor(*ptr, *ptr1)) {
			*ptr1 = *ptr;
			c--;
			ptr1--;
			ptr--;
		}
		*(ptr + 1) = emp;
	}
}
int main()
{
	//ejercicio 1
	Empleado emp1("roberto", "benavides", 500.45);
	Empleado emp2("jesus", "franco", 300.68);
	cout << left << setw(25) << "nombre" << setw(25) << "apellido" << setw(15) << "salario" << endl;
	emp1.tostring(); cout << endl;
	emp2.tostring(); cout << endl;
	cout << "reduciendo salarios" << endl;
	cout << left << setw(25) << "nombre" << setw(25) << "apellido" << setw(15) << "salario" << setw(15)<<"salario Anual" << endl;
	emp1.reduceSalary();
	emp2.reduceSalary();
	emp1.tostring(); cout<< (emp1.getAnualsalary()) << endl;
	emp2.tostring(); cout<< (emp2.getAnualsalary())<< endl;
	//ejercicio 2
	Empleado emp3("ana", "alarcon", 600);
	Empleado emp4("ana", "alar", 850);
	Empleado empleados[] = { emp1,emp2,emp3,emp4 };
	cout << "ordenando....." << endl;
	ord(empleados, 4);
	print(empleados, 4);


}