#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	cout << "Количество элементов в массиве: " << n;
	cout << endl;

	short* A = new short[n];
	srand(time(0));

	cout << "Содержимое массива: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 101;
		cout << A[i] << " ";
	}
	cout << endl << endl;

	cout << "Адрес начала массива: " << A << endl;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Элемент " << i << ", его адрес: " << &A[i] << endl;
		cout << "Расстояние от начала массива = " << &A[i] - A << endl;
		cout << "Расстояние от начала массива в байтах = " << (&A[i] - A) * sizeof(short) << endl;
		cout << endl;
	}

	delete[] A;
}
