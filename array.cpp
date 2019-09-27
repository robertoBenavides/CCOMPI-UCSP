// array.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<iostream>
using namespace std;
void imprimir(int arr[], int tam) {
	cout << "[";
	for (int i = 0; i < tam; i++) cout << arr[i] << ",";
	cout << "]" << endl;
}
int sumar(int arr[], int tam) {
	int sum = 0;
	for (int i = 0; i < tam; i++) {
		sum += arr[i];
	}
	return sum;
}
int sumarrecur(int arr[], int tam, int ind = 0) {
	if (ind == tam) return 0;
	return arr[ind] + sumarrecur(arr, tam, ++ind);
}
void change(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}
void invertir(int arr[], int tam) {
	int d = tam / 2;
	int last = tam - 1;
	for (int i = 0; i < d; i++) {
		change(arr[last - i], arr[i]);
	}
}
void invertirrecur(int arr[], int tam, int i = 0) {
	if (i == tam / 2) return;
	change(arr[i], arr[tam - 1 - i]);
	invertirrecur(arr, tam, ++i);

}

void burbuja(int arr[], int tam) {
	for (int i = 1; i < tam; i++) {
		for (int j = 0; j < tam - i; j++) {
			if (arr[j] > arr[j + 1]) {
				change(arr[j], arr[j + 1]);
			}
		}
	}
}
void insersion(int arr[], int tam) {
	for (int i = 1; i < tam; i++) {
		while (i != 0 && arr[i - 1] > arr[i]) {
			change(arr[i - 1], arr[i]);
			i--;
		}
	}
}
/*void quicksort(int arr[], int tam,int inicio=0,int fin=0) {
	fin = tam - 1;
	if (inicio < fin) {
		int piv = tam / 2;

		// Ordeno la lista de los menores
		quicksort(arr, tam, inicio,piv);

		// Ordeno la lista de los mayores
		quicksort(arr,tam, piv + 1, fin);
	}
}*/
int main()
{
	int arr[] = { 15,59,34,47 };
	int tam = 4;
	imprimir(arr, tam);
	/*cout<<"suma: "<<sumar(arr,tam)<<endl;
	cout<<"sumrecursiva: "<<sumarrecur(arr,tam)<<endl;
	invertir(arr,tam);
	imprimir(arr,tam);
	invertirrecur(arr,tam);
	imprimir(arr,tam);*/

	/*burbuja(arr,tam);
	imprimir(arr,tam);*/

	/*insersion(arr,tam);
	imprimir(arr,tam);*/

	/*quicksort(arr, tam);
	imprimir(arr, tam);*/
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
