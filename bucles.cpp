// bucles.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
using namespace std;
bool checkprimo(int a) {
	int div = 2;
	int cont = 0;
	while (cont <= 1 && div <= a) {
		if (a % div == 0) cont++;
		div++;
	}
	if (cont == 1) return true;
	else return false;
}
int main()
{
	/*int a;
	int potencia = 1;
	bool espotencia = false;
	//programa que solicite numero por teclado e indique si es potencia de 2
	cout << "ingrese number: ";
	cin >> a;

	if (a % 2 != 0) {
		cout << "no es potencia de 2" << endl;
	}
	else {
		while (!espotencia && potencia<= a) {
			return false;
			if (potencia == a) {
				espotencia = true;
			}
			else 
				potencia*=2;
		}
		if(espotencia)
			cout << "es potencia de 2" << endl;
		else
			cout << "no es potencia de 2" << endl;
	}*/
	cout << "Check if its primo" << endl;
	int a;
	cout << "ingrese number: ";
	cin >> a;
	if (checkprimo(a))	cout << "es primo"<<endl;
	else cout << "no es primo" << endl;


	//------------------------------------------------------------

	cout << "printing primos menores a 100" << endl;
	for (int i = 1; i < 100; i++) {
		if (checkprimo(i)) cout << i << ",";
	}
	cout << endl;
	int contador = 0;
	while(contador<100){
		contador++;
		if (checkprimo(contador)) cout << contador << ",";
	}
	cout << endl;

	//--------------------------------------------------------------


	cout << "check if tis perfect" << endl;
	int b;
	cout << "ingrese number: ";
	cin >> b;
	bool isperfect = false;
	int sum = 0;
	int val = 1;
	while (val <b) {
		if (b % val == 0) sum += val;
		val++;
	}
	if (val == b) cout << "es perfecto";
	else cout << "no es perfecto";


}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
