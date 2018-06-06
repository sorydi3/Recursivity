// recursividadex.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include "recursividadex.h"
using namespace std;

int couts_A(){
	//pre:string that end with dot
	//post:count the number of apearences of a withing the string
	char a;
	cin >> a;
	if (a == '.')return 0;
	else if (a == 'a')
		return 1+couts_A();
	else return couts_A();
}
void A(int a) {
	if (a > 0) {
		cout << "primera vuelta" << endl;
		cout << a << endl;
		A(a - 1);
		cout << "--------------" << endl;
		cout << "segona vuleta" << endl;
		cout << a << endl;
	}else
	cout << "gonna start to rollBack" << a << endl;
}
int sum_(int n) {
	
	if (n < 9)return n;
	else {

		return n % 10 + sum_(n / 10); 
	
	}
	cout << "we gona start to roolbacknow" << endl;
}

int arrel_digital(int n) {
	if (sum_(n) <= 9)return sum_(n);
	else return arrel_digital(sum_(n));
}

void WriteNumber_reverse(int n) {
	if (n > 9) {
		cout << n%10;
		WriteNumber_reverse(n / 10);
		cout << endl;
		cout << "nothing to do getting borred :)" << endl;
	}
	else {
		cout << n;
//	cout << "starting to roolback" << endl;
	}
}
int pow_(int b, int e) {
	if (e == 1)return b;
	else return b*pow_(b, e - 1);
}
const int MAX = 5;
typedef int vector_enter[MAX];
void llegirVector(vector_enter v, unsigned max) {
	for (int i = 0; i < max; i++) {
		cin >> v[i];
	}
}
int i_sum_vector(vector_enter v, int n) {
	if (n == 0)return v[n];
	else return v[n - 1] + i_sum_vector(v, n - 1);
}
int i_max_vector(vector_enter v, int n) {
	int max;
	if (n == 0)max=v[n-1];
	else 
		max=i_max_vector(v, n - 1);
	if (v[n - 1] > max)max = v[n - 1];
	return max;
}
int sum_vector(vector_enter v) {
	return i_sum_vector(v, MAX);
}
int max_vector(vector_enter v) {
	return i_max_vector(v, MAX);
}
bool i_existeix(vector_enter v, unsigned  x, int n) {
	if (n == 0)return v[n - 1] == x;
	else if (v[n - 1] == x)return true;
	else return i_existeix(v, x, n - 1);
}

bool existeix(vector_enter v) {
	cout << "enter the number to be checked" << endl;
	unsigned num;
	cin >> num;
	return i_existeix(v,num, MAX);
}

void intercambia(int *A, int i, int p_I) {
	int aux = A[i];
	A[i] = A[p_I];
	A[p_I] = aux;
}

int particion(int *A, int start, int end) {
	int pivot = A[end];
	int p_index = start;
	for (int i = start; i < end; i++) {
		if (A[i] <= pivot) {
			intercambia(A, i, p_index);
			p_index++;
		}
	}
	intercambia(A, p_index, end);
	return p_index;
}
void quikSort(int *A, int start, int end) {
	if (start < end) {
		int particio = particion(A, start, end);
		quikSort(A, start, particio - 1);
		quikSort(A, particio + 1, end);
	}
}
int main()
{
	vector_enter v;
	cout << "entra la sequencia de lletres" << endl;
	//cout << "la suma de a es " << couts_A() << endl;
	//A(4);
	cout << "la suma de los digitos es " << sum_(55) << endl;
	cout << "l'arrel digital de sum es " << arrel_digital(99) << endl;
	WriteNumber_reverse(12345);
	cout << endl;
	cout << "la potencia es" << pow_(2, 2) << endl;
	cout << "we gonna sum an array using recursivity" << endl;
	llegirVector(v, MAX);
	cout << "la suma del elements del vector es " << sum_vector(v) << endl;
	cout << "l'elements maxim del vector es " << max_vector(v) << endl;
	cout << "chekking number" << endl;
	cout << existeix(v) << endl;
	cout << "sorting the array..." << endl;
	quikSort(v, 0, 5);
	for (int i = 0; i < 5; i++) cout << v[i] << " ";
    return 0;
}

