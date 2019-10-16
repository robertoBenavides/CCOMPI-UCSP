// ArreglosTipos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int tam_cad(char *a) {
	int tam = 0;
	while (*a++!='\0') {
		tam++;
	}
	return tam;
}

int tam_cad_recur(char *a) {
	if (*a == '\0') return 0;
	return 1 + tam_cad_recur(++a);
}
void change(char *a,char *b) {
	char c = *a;
	*a = *b;
	*b= c;
}
void invertir_Cad(char *a) {
	int tam= tam_cad_recur(a),i=0;
	char* ptr = a + tam-1;
	while (ptr>a) {
		change(a, ptr);
		a++;
		ptr--;
	}
}
void invertir_Cad_rec(char* a,int i=0) {
	char* fin = a + tam_cad(a)-1-i;
	if (fin <= a) return;
	change(a, fin);
	invertir_Cad_rec(++a, ++i);
}
bool isPalindromo(char *a) {
	int tam = tam_cad(a);
	char* ptr = a + tam - 1;
	while (ptr-- > a++) {
		if (*ptr != *a)return false;
	}
	return true;
}
bool isPalindromorec(char*a,int i=0) {
	char* fin = a + tam_cad(a) - 1 - i;
	if (*a != *fin) return false;
	if (i == tam_cad(a)/2) return true;
	return isPalindromorec(++a, ++i);
}
int main()
{
	char cadena[] = "reconocer";
	char cadena1[] = { 'h','o','l','a','\0'};
	invertir_Cad_rec(cadena);
	if (isPalindromorec(cadena)) cout << "es palindromo" << endl;
	else cout << "no es palindromo" << endl;
	//cout << tam_cad_recur(cadena) << endl;
    //cout << cadena<<endl;
	//cout << cadena1 << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
