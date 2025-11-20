#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "Введите количество элементов в массиве : ";
	int n;
	cin >> n;
	cout << endl;

	if (n <= 0)
	{
		cout << "Введите положительное число: ";
		cin >> n;
	}

	int* A = new int[n];
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
		cout << "Расстояние от начала массива в элементах = " << &A[i] - A << endl;
		cout << "Расстояние от начала массива в байтах = " << (&A[i] - A) * sizeof(int) << endl;
		cout << endl;
	}

	delete[] A;
}
