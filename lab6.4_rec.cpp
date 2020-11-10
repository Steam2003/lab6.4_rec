#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
void dob(double* a, double dobutok, int N, int l, int k, double max)
{
	if (k <= N - 1)                                             // 4) <- ����� ������������� ������� � ��������� �� ������ ��������
	{
		if (fabs(max) <= fabs(a[k]))
		{
			max = a[k];
			l = k;
		}
		return dob(a, dobutok, N, l, ++k, max);
	}
	if (l <= N - 1)                                             // 5) <- ��������� ������� �� ������� l (������������� �� ������) �� N-1
	{
		dobutok *= a[l];
		dob(a, dobutok, N, ++l, k, max);
	}
	else
	{
		cout << endl;
		cout << "������� �������� ������� ���� ���������� ������� �� ������� ��������: " << dobutok;
		cout << endl;
	}
}
void print_rec(double* a, int i, int N)
{
	cout << setw(5) << a[i] << " ";
}
void rec(double* a, int j, double C, int N, int i, double Low, double Max)             // 1) <- ��������� ������
{
	if (i <= N - 1)
	{
		a[i] = (Max - Low) * rand() / RAND_MAX + Low;
		if (a[i] > C)
			++j;
		print_rec(a, i, N);                                           // 2) <- ���� ������ 
		rec(a, j, C, N, ++i, Low, Max);                               
	}
	else
	dob(a, 1, N, 0, 1, a[0]);                                       // 3) <- ������ ������� ��������� �������
}
void print(double* b, int i, int N)
{
	if (i <= N - 1)
	{
		cout << setw(5) << b[i] << " ";
		return print(b, ++i, N);
	}
}
void change2(double* a, double* b, int N, int i, int l)
{
	if (i <= N - 1)
	{
		if (a[i] >= 0)
		{
			b[l] = a[i]; 
			++l;
		}
		return change2(a, b, N, ++i, l);
	}
	print(b, 0, N);                                               // 9) <- �������� �����

}
void change(double* a, double* b, int N, int i, int l)
{
	if(i <= N - 1)                                         // 7) <- �������� ��'���
	{
		if (a[i] < 0)
		{
			b[l] = a[i]; 
			++l;
		}
		return change(a, b, N, ++i, l);
	}
	change2(a, b, N, 0, l);                                // 8) <- ��� ������
}


int main()
{
	cout << fixed << setprecision(2);
	int N;
	double C, Max, Low;
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "������ ������� �������� ������: "; cin >> N;
	cout << "������ ����� �: "; cin >> C;
	cout << "������ �������� �������� ������: "; cin >> Low;
	cout << "������ ����������� �������� ������: "; cin >> Max;
	double* a = new double[N];
	cout << endl;
	cout << "�����������" << endl;
	rec(a, 0, C, N, 0, Low, Max);
	double* b = new double[N];
	change(a, b, N, 0, 0);                                          // 6) <- ������ ������� �������������� ������
	cout << endl;
	delete[] a;
	delete[] b;
}


