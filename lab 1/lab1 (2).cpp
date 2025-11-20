#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	cout << "Количество элементов в массиве: " << n;
	cout << endl;

	double* A = new double[n];
	srand(time(0));

	cout << "Содержимое массива: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = (rand() % 1000) / 10.0;
		cout << A[i] << " ";
	}
	cout << endl << endl;

	cout << "Адрес начала массива: " << A << endl;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Элемент " << i << ", его адрес: " << &A[i] << endl;
		cout << "Расстояние от начала массива = " << &A[i] - A << endl;
		cout << "Расстояние от начала массива в байтах = " << (&A[i] - A) * sizeof(double) << endl;
		cout << endl;
	}

	delete[] A;
}
