#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Рекурсивне формування масиву
void Create(double* a, const int size, const double Low, const double High, int i = 0)
{
	if (i < size)
	{
		a[i] = Low + (High - Low) * rand() / RAND_MAX;
		Create(a, size, Low, High, i + 1);
	}
}

// Рекурсивне виведення масиву
void Print(const double* a, const int size, int i = 0)
{
	if (i < size)
	{
		cout << setw(8) << fixed << setprecision(2) << a[i];
		Print(a, size, i + 1);
	}
	else
	{
		cout << endl;
	}
}

// 1.1. Рекурсивне обчислення кількості елементів, рівних нулю
int CountZero(const double* a, const int size, int i = 0)
{
	if (i < size)
	{
		if (a[i] == 0)
			return 1 + CountZero(a, size, i + 1);
		else
			return CountZero(a, size, i + 1);
	}
	else
	{
		return 0;
	}
}

// Рекурсивний пошук індексу мінімального елемента
int IndexMin(const double* a, const int size, int i = 1, int imin = 0)
{
	if (i < size)
	{
		if (a[i] < a[imin])
			imin = i;
		return IndexMin(a, size, i + 1, imin);
	}
	else
	{
		return imin;
	}
}

// 1.2. Рекурсивне обчислення суми елементів після мінімального
double SumAfterMin(const double* a, const int size, int imin, int i)
{
	if (i < size)
	{
		return a[i] + SumAfterMin(a, size, imin, i + 1);
	}
	else
	{
		return 0;
	}
}

// Допоміжна функція для обміну значень
void Swap(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}

// 2. Рекурсивне впорядкування непарних елементів (з непарними індексами) за зростанням модулів
void SortOddAscendingAbs(double* a, const int size, int i = 1, int j = 3)
{
	if (i < size)
	{
		if (j < size)
		{
			if (fabs(a[j]) < fabs(a[i]))
			{
				Swap(a[i], a[j]);
			}
			SortOddAscendingAbs(a, size, i, j + 2);
		}
		else
		{
			SortOddAscendingAbs(a, size, i + 2, i + 4);
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	if (n <= 0)
	{
		cout << "n must be > 0" << endl;
		return 0;
	}

	double* a = new double[n];
	Create(a, n, -10, 10, 0);

	cout << "Array:" << endl;
	Print(a, n, 0);

	cout << "Count of zero elements = " << CountZero(a, n, 0) << endl;

	int iMin = IndexMin(a, n, 1, 0);
	if (iMin < n - 1)
	{
		double sum = SumAfterMin(a, n, iMin, iMin + 1);
		cout << "Sum of elements after minimum = " << sum << endl;
	}
	else
	{
		cout << "There are no elements after the minimum element" << endl;
	}

	SortOddAscendingAbs(a, n, 1, 3);

	cout << "Modified array:" << endl;
	Print(a, n, 0);

	delete[] a;
	return 0;
}