#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(double* a, int N, int i, double Low, double Max);
void print(double* a, int i, int N);
int moreC(double* a, int N, double C, int i, int j);
int find_last_fabs(double* a, int N, double max, int i, int l);
void dob(double* a, int N, int l, double dobutok);
int change(double* a, int N, int l, int i);

int main()
{
	cout << fixed << setprecision(2);
	int N;
	double C, Max, Low;
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введіть кількість елементів масиву: "; cin >> N;
	cout << "Введіть число С: "; cin >> C;
	cout << "Введіть мінімальне значення масиву: "; cin >> Low;
	cout << "Введіть максимальне значення масиву: "; cin >> Max;
	double* a = new double[N];
	cout << endl;
	cout << "Рекурсивний" << endl;
	create(a, N, 0, Low, Max);
	print(a, 0, N);
	cout << endl;
	cout << "Кількість елементів більших від С: " << moreC(a, N, C, 0, 0) << endl;
	int l = find_last_fabs(a, N, a[0], 0, 0);
	dob(a, N, l, 1);
	change(a, N, 0, 0);
	print(a, 0, N);
	cout << endl;
	delete[] a;
}
void create(double* a, int N, int i, double Low, double Max)             
{
	if (i < N)
	{
		a[i] = (Max - Low) * rand() / RAND_MAX + Low;
		create(a, N, ++i, Low, Max);                                           
	}
}
void print(double* a, int i, int N)
{
	if (i <N )
	{
		cout << setw(5) << a[i] << " ";
		print(a, ++i, N);
	}
}
int moreC(double* a, int N, double C, int i, int j)
{
	if (i<N)
	{ 
		if (a[i] > C)
			++j;
		moreC(a, N, C, ++i, j);
	}
	else
	return j;

}
int find_last_fabs(double* a, int N, double max, int i, int l)
{
	if (i<N)
	{
		if (fabs(max) <= fabs(a[i]))
		{
			max = a[i];
			l = i;
		}
	find_last_fabs(a, N, max, ++i, l);
	}
	else

	return l;
}
void dob(double* a, int N, int l, double dobutok)
{
	if (l < N)
	{
		dobutok *= a[l];
		dob(a, N, ++l, dobutok);
	}
	else
		cout << "Добуток: " << dobutok << endl;

}
int change(double* a, int N, int l, int i)
{
	if (i < N)
	{
		if (a[i] < 0)
		{
			double tmp = a[l];
			a[l] = a[i];
			a[i] = tmp;
			++l;
		}
		change(a, N, l, ++i);
	}
	else
		return l;
}


