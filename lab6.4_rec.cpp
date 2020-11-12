#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(double* a, int N, int i, double Low, double Max);
void print(double* a, int i, int N);
int moreC(double* a, int N, double C, int i, int j);
int find_last_fabs(double* a, int N, double max, int i, int l);
void dob(double* a, int N, int l, double dobutok);
void create3(double* a, double* b, int N, int l, int i);
int create2(double* a, double* b, int N, int l, int i);

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
	double* b = new double[N];
	cout << endl;
	cout << "Рекурсивний" << endl;
	create(a, N, 0, Low, Max);
	print(a, 0, N);
	cout << endl;
	cout << "Кількість елементів більших від С: " << moreC(a, N, C, 0, 0) << endl;
	int l = find_last_fabs(a, N, a[0], 0, 0);
	dob(a, N, l, 1);
	l = create2(a, b, N, 0, 0);
	create3(a, b, N, l, 0);
	print(b, 0, N);
	cout << endl;
	delete[] a;
	delete[] b;
}
void create(double* a, int N, int i, double Low, double Max)             
{
	if (i <= N - 1)
	{
		a[i] = (Max - Low) * rand() / RAND_MAX + Low;
		create(a, N, ++i, Low, Max);                                           
	}
}
void print(double* a, int i, int N)
{
	if (i <= N - 1)
	{
		cout << setw(5) << a[i] << " ";
		print(a, ++i, N);
	}
}
int moreC(double* a, int N, double C, int i, int j)
{
	if (i<=N-1)
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
	if (i<=N-1)
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
	if (l <= N - 1)
	{
		dobutok *= a[l];
		dob(a, N, ++l, dobutok);
	}
	else
		cout << "Добуток: " << dobutok << endl;

}
void create3(double* a, double* b, int N, int l, int i)
{
	if (i <= N - 1)
	{
		if (a[i] >= 0)
		{
			b[l] = a[i];
			++l;
		}
		create3(a, b, N, l, ++i);
	}
}
int create2(double* a, double* b, int N, int l, int i)
{
	if(i<=N-1)
	{
		if (a[i] < 0)
		{
			b[l] = a[i];
			++l;
		}
		create2(a, b, N, l, ++i);
	}
else 
return l;
}


