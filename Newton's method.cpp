#include <iostream>
#include <cmath>
#include <vector>
#include <process.h>
using namespace std;

double f(double x0)
{
	double y = 2 * pow(x0, 4) - 2;
	return y;
}

double derivative(double x0)
{
	double y = 8 * pow(x0, 3);
	return y;
}

double double_derivative(double x0)
{
	double y = 24 * pow(x0, 2);
	return y;
}

double Newtonsmethod(double x, double eps)
{
	while(abs(f(x) / derivative(x)) > eps)
	{
		double delta = f(x) / derivative(x);
		x-= delta;
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double left_border, right_border, eps, x;
	cout << "\tЧисленное решение нелинейного уравнения методом Ньютона";
	cout << "\n\nВыбор начального приближения";
	cout << "\nВведите левую границу приближения: ";
	cin >> left_border;
	cout << "Введите правую границу приближения: ";
	cin >> right_border;
	if (left_border >= right_border)
	{
		cout << "\nОшибка ввода!";
		cout << " Левая граница не может быть больше (или равной) правой. Попробуйте снова.";
		exit(1);
	}
	if (f(left_border) * double_derivative(left_border) > 0)
	{
		x = left_border;
		cout << "Начальным приближением является левая граница " << x;
	}
	else
	{
		x = right_border;
		cout << "Начальным приближением является правая граница " << x;
	}
	cout << "\n\nВведите требуемую точность вычислений: ";
	cin >> eps;
	if (eps <= 0)
	{
		cout << "\nОшибка ввода!";
		cout << "Требуемая точность не может быть меньше 0 (или равна ему). Попробуйте снова.";
		exit(1);
	}
	cout << "\nПриближенное значение корня уравнения: " << Newtonsmethod(x, eps) << endl;
	system("pause");
	return 0;
}