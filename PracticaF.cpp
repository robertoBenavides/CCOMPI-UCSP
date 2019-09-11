// PracticaF.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
void printDigits() {
	int n1;
	char tab= '\t';
	cout << "ingrese numero: ";
	cin >> n1;
	int a, b, c, d, e,m;

	a = n1/10000;
	m = n1 % 10000;
	b = m/1000;
	m = m % 1000;
	c = m / 100;
	m = m % 100;
	d = m / 10;
	m = m % 10;
	e = m / 1;

	cout << a <<tab <<b<< tab<< c << tab<<d << tab<<e<<endl;
}
int countDigits(int n1) {
	int n0,div=10;
	n0 = n1;
	int c = 0;
	while (n1 != 0) {
		c++;
		n1 /= div;
	}
	return c;
}
void getcantDigits() {
	int n1;
	cout << "ingrese caracter: ";
	cin >> n1;
	
	cout << n1 << " tiene " << countDigits(n1) << " digito(s)" << endl;
}

bool isPalindrome(int a) {
	int div=10, n=countDigits(a);
	int c = a / 10000;
	int d = c % 10;
	int e = a / 1000- c * 10 ;
	int f = ((a % 100) - d) / 10;
	return (c==d && e==f);

}
void palindrome() {
	int n1;
	cout << "ingrese numero: ";
	cin >> n1;
	if (isPalindrome(n1)) cout << "es plaindrome";
	else cout << "no es plaindrome";
}
int getFibonacciNumberByPos(int n1) {
	int rpta=0;
	if(n1==0 || n1==1){
		return 1;
	}
	else {
		int a = 1, b = 1,c;
		for (int i = 2; i <= n1; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		rpta = b;
	}
	return rpta;
}
void getnumposfib() {
	int n1;
	cout << "ingrese pos iniciando en 0: ";
	cin >> n1;
	cout <<getFibonacciNumberByPos(n1)<<endl;
}

void isNumber() {
	char n1;
	cout << "ingrese caracter: ";
	cin >> n1;

	int nn1 = static_cast<int>(n1);
	if (nn1 >= 48 && nn1 <= 57) cout << n1 << " es numero" << endl;
	else cout << n1 << " no es numero" << endl;
}
int isLetter(char c) {
	int nc = static_cast<int>(c);
	if ((nc >= 65 && nc <= 90) || (nc >= 97 && nc <= 122)) return nc;
	else return -1;

}
char MaytoMin(int a) {
	return static_cast<char>(a + 32);
}
char MintoMay(int a) {
	return static_cast<char>(a - 32);
}
void ifTextConvert() {
	char n1;
	cout << "ingrese caracter: ";
	cin >> n1;
	int a = isLetter(n1);
	if (a != -1) {
		if (a < 91) cout << (MaytoMin(a))<<endl;
		else cout << (MintoMay(a))<<endl;
	}
	else {
		cout << "no es numero" << endl;
	}

}
int main()
{
	//printDigits();
	getcantDigits();
	//palindrome();
	//getnumposfib();
	//isNumber();
	//ifTextConvert();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
