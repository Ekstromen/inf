#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double metod1_dichotomy(double a, double b, double eps);
double metod2_hord(double a, double b, double eps);
double metod3_Newton(double a, double b, double eps);
double metod4_simple_iteration(double a, double b, double x0, double eps);
double metod5_sowing(double a, double b, double x0, double eps);
double f_hord(double x1, double x2);
double f_kas(double x0);
double komb(double a, double b, double e);
double func(double  x);
double func1(double x);
double func2(double x);
int main() {
	setlocale(LC_ALL, "RUS");
	double a, b, eps = 0.000001, x0;
	unsigned int choice = 0;
	while (choice != 7) {
		cout << "�������� ����� ����: " << endl;
		cout << "1. ����� ������� ������� �������;" << endl;
		cout << "2. ����� ����;" << endl;
		cout << "3. ����� �������;" << endl;
		cout << "4. ����� ���������������� �����������;" << endl;
		cout << "5. ����� �������;" << endl;
		cout << "6. ��������������� ������� ���� � �����������;" << endl;
		cout << "7. �����" << endl;
		cout << "��� �����: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			if (func(a) * func(b) > 0) {
				cout << "�� ���� ������� ������ ���!" << endl;
			}
			else {
				metod1_dichotomy(a, b, eps);
			}
			break;
		case 2:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			if (func(a) * func(b) < 0) {
				metod2_hord(a, b, eps);
			}
			else {
				cout << "�� ���� ������� ������ ���!" << endl;
			}
			break;
		case 3:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			if (func(a) * func(b) < 0) {
				metod3_Newton(a, b, eps);
			}
			else {
				cout << "�� ���� ������� ������ ���!" << endl;
			}
			break;
		case 4:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			cout << "������� �������� 'x0': ";
			cin >> x0;
			metod4_simple_iteration(a, b, x0, eps);
			break;
		case 5:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			cout << "������� �������� 'x0': ";
			cin >> x0;
			metod5_sowing(a, b, x0, eps);
			break;
		case 6:
			cout << "������� �������� 'a': ";
			cin >> a;
			cout << "������� �������� 'b': ";
			cin >> b;
			cout << "������� �������� 'eps': ";
			cin >> eps;
			komb(a, b, eps);
			break;
		case 7:
			break;
		default:
			cout << "������� ������������ ��������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

double metod1_dichotomy(double a, double b, double eps) {
	unsigned int n = 1;
	double t, f2, x, f_res;

	while (fabs(b - a) >= eps) {
		t = (a + b) / 2;
		f2 = func(t);
		if (func(a) * f2 < 0) {
			b = t;
		}
		else {
			a = t;
		}
		n += 1;
		if (fabs(b - a) <= eps) {
			x = (a + b) / 2;
			cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
			return x;
		}
	}
	return 0;
}

double metod2_hord(double a, double b, double eps) {
	double f1 = func(a), f2 = func2(a), x, z, fz, h = a;
	unsigned n = 1;
	if (f1 * f2 > 0) {
		x = b;
		z = a;
	}
	else {
		x = a;
		z = b;
	}
	fz = func(z);

	while (fabs(h) >= eps) {
		f1 = func(x);
		h = ((x - z) * f1) / ((f1 - fz));
		x = x - h;
		n += 1;
		if (fabs(h) <= eps) {
			cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
		}
	}
	return x;
}

double metod3_Newton(double a, double b, double eps) {
	double f = func(b), f2 = func2(b), x, h = a, f1;
	unsigned n = 1;
	if (f * f2 > 0) {
		x = b;
	}
	else {
		x = a;
	}

	while (fabs(h) >= eps) {
		f = func(x);
		f1 = func1(x);
		h = f / f1;
		x = x - h;
		n += 1;
		if (fabs(h) <= eps) {
			cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
		}
	}
	return x;
}

double metod4_simple_iteration(double a, double b, double x0, double eps) {
	double x = x0, f; 
	double xn = x;
	unsigned int n = 1;
	do {
		x = xn; 
		xn = x - func(x) / (0.25 + 1 / x); 
		n += 1;
	} while (fabs(xn - x) >= eps && xn >= a && xn <= b);
	if (xn < a || xn > b) { 
		cout << "�� ���� ������� ������ ���!" << endl;
	}
	else {
		cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
	}
	return xn; 
}

double metod5_sowing(double a, double b, double x0, double eps) {
	int n = 0;
	double x1 = x0 - func(x0) / ((func(x0) - func(a)) / (x0 - a)); 
	double x2 = x1 - func(x1) / ((func(x1) - func(x0)) / (x1 - x0)); 
	double x = x2; 
	double xn = x; 
	do {
		x = xn; 
		xn = x - func(x) / ((func(x) - func(x1)) / (x - x1)); 
		x1 = x;
		n++;
	} while (fabs(xn - x) >= eps);
	cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
	return x;
}

double f_hord(double x1, double x2) {
	double y1 = func(x1);
	double y2 = func(x2);
	return x2 - y2 * (x2 - x1) / (y2 - y1);
}

double f_kas(double x0) {
	double y0 = func(x0);
	double dy0 = 2 * x0;
	return x0 - y0 / dy0;
}

double komb(double a, double b, double e) {
	int n = 0;
	double x = a;
	double x_prev = b;
	while (fabs(x - x_prev) > e) {
		x_prev = x;
		x = f_hord(x_prev, f_kas(x_prev));
		n++;
	}

	cout << "������ ��������� = " << x << "; �������� ������� = " << func(x) << "; ���-�� �������� ������� = " << n << endl;
	return x;
}

double func(double x) { 
	return pow(log(x), 2) + (0.25 * x) - 3;
}

double func1(double x) { 
	return (func(x + 0.1) - func(x - 0.1)) / (2 * 0.1);
}

double func2(double x) {
	return (func(x + 0.1) - 2 * func(x) + func(x - 0.1)) / (0.1 * 0.1);
}
