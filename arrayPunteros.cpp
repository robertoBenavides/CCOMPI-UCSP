// arrayPunteros.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
using namespace std;
void imprimir(int *arr, int tam) {
	cout << "[";
	for (int i = 0; i < tam; i++) {
		cout << *arr << ",";
		arr++;
	}
	cout << "]" << endl;
	arr -= tam;
}
int sumar(int *arr, int tam) {
	int sum = 0;
	for (int i = 0; i < tam; i++) {
		sum += *arr;
		arr++;
	}
	arr -= tam;
	return sum;
}
int sumarrecur(int *arr, int tam, int ind = 0) {
	if (ind == tam) {
		arr -= tam;
		return 0;
	}
	int c = *arr;
	arr++;
	return c+ sumarrecur(arr, tam, ++ind);
}
void change(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}
void invertir(int *arr, int tam) {
	int d = tam / 2;
	int last = tam - 1;
	int* ptr = arr + last;
	for (int i = 0; i < d; i++) {
		change(ptr-=i, arr+=i);
	}
}
void invertirrecur(int *arr, int tam, int i = 0) {
	int* ptr = arr + tam - 1;
	if (i == tam / 2) return;
	change(arr+=i, ptr-=i);
	invertirrecur(arr, tam, ++i);

}
void burbuja(int *arr, int tam) {
	for (int i = 1; i < tam; i++) {
		for (int j = 0; j < tam - i; j++) {
			arr += j;
			int* ptr = arr+1;
			if (*arr > *ptr ){
				change(arr, ptr);
			}
			arr -= j;
		}
	}
}
void insersion(int *arr, int tam) {
	for (int i = 1; i < tam; i++) {
		int c = i;
		int* ptr1=arr + i;
		int* ptr= ptr1 - 1;
		while (c != 0 && *ptr > *ptr1) {
			change(ptr, ptr1);
			ptr1--;
			c--;
			ptr--;
		}		
	}
}
void quicksort(int arr[], int tam,int inicio=0,int fin=0) {
	fin = tam - 1;
	if (inicio < fin) {
		int piv = tam / 2;
		// Ordeno la lista de los menores
		quicksort(arr, tam, inicio,piv);
		// Ordeno la lista de los mayores
		quicksort(arr,tam, piv + 1, fin);
	}
}
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

	quicksort(arr, tam);
	imprimir(arr, tam);
}
