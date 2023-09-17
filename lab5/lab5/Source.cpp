#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double f(double x) {
    return ((x * x) / (sqrt(x * x + 2)));
}

double center(double a, double b, int n) {
    double h;
    int i;
    h = (b - a) / n;
    double Integral = 0.0;

    for (i = 1; i <= n; i++) {
        Integral += h * f(a + h * (i - 0.5));
    }
    return Integral;
}

double left(double a, double b, int n) {
    double h;
    int i;
    h = (b - a) / n;
    double Integral = 0.0;

    for (i = 0; i <= n; i++) {
        Integral += h * f(a + h * i);
    }
    return Integral;
}

double right(double a, double b, int n) {
    double h;
    int i;
    h = (b - a) / n;
    double Integral = 0.0;

    for (i = 1; i <= n; i++) {
        Integral += h * f(a + h * i);
    }
    return Integral;
}

double F(double x) {
    return ((x * sqrt(x * x + 2)) / 2) - log(abs(sqrt(x * x + 2) + x));
}

double newton_leibniz(double a, double b) {
    return F(b) - F(a);
}

double trapecia(double a, double b, int n) {
    double h;
    int i;
    h = (b - a) / n;
    double Integral = 0.0;
    Integral = h * (f(a) + f(b)) / 2.0;
    for (i = 1; i <= n - 1; i++) {
        Integral += h * f(a + h * i);
    }
    return Integral;
}

double parables(double a, double b, int n) {
    double h;
    int i;
    h = (b - a) / n;
    double Integral = 0.0; //��������
    Integral = h * (f(a) + f(b)) / 6.0;
    for (i = 1; i <= n; i++) {
        Integral += 4.0 / 6.0 * h * f(a + h * (i - 0.5));
    }
    for (i = 1; i <= n - 1; i++) {
        Integral += 2.0 / 6.0 * h * f(a + h * i);
    }
    return Integral;
}



int main() {
	setlocale(LC_ALL, "RUS");
    int j = 1;
    int i; //�������
    double a = 0.6, b = 2; //������� ��������������
    int n = 10; //����� ��������� n
    int n1 = 50;
    int n2 = 100;

    cout << "   ��� 10 ���������: " << endl;
    cout << "������� ������� ���������������: " << center(a, b, n) << endl;
    cout << "���������� �����������: " << abs(center(a, b, n) - (round((center(a, b, n)) * 10000) / 10000)) << endl;
    cout << "������� ������ ���������������: " << right(a, b, n) << endl;
    cout << "���������� �����������: " << abs(right(a, b, n) - (round((right(a, b, n)) * 10000) / 10000)) << endl;
    cout << "������� ����� ���������������: " << left(a, b, n) << endl;
    cout << "���������� �����������: " << abs(left(a, b, n) - (round((left(a, b, n)) * 10000) / 10000)) << endl;
    cout << "�������� �������-��������: " << newton_leibniz(a, b) << endl;
    cout << "���������� �����������: " << abs(newton_leibniz(a, b) - (round((newton_leibniz(a, b)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << trapecia(a, b, n) << endl;
    cout << "���������� �����������: " << abs(trapecia(a, b, n) - (round((trapecia(a, b, n)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << parables(a, b, n) << endl;
    cout << "���������� �����������: " << abs(parables(a, b, n) - (round((parables(a, b, n)) * 10000) / 10000)) << endl;

    cout << endl << "   ��� 50 ���������: " << endl;
    cout << "������� ������� ���������������: " << center(a, b, n1) << endl;
    cout << "���������� �����������: " << abs(center(a, b, n1) - (round((center(a, b, n1)) * 10000) / 10000)) << endl;
    cout << "������� ������ ���������������: " << right(a, b, n1) << endl;
    cout << "���������� �����������: " << abs(right(a, b, n1) - (round((right(a, b, n1)) * 10000) / 10000)) << endl;
    cout << "������� ����� ���������������: " << left(a, b, n1) << endl;
    cout << "���������� �����������: " << abs(left(a, b, n1) - (round((left(a, b, n1)) * 10000) / 10000)) << endl;
    cout << "�������� �������-��������: " << newton_leibniz(a, b) << endl;
    cout << "���������� �����������: " << abs(newton_leibniz(a, b) - (round((newton_leibniz(a, b)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << trapecia(a, b, n1) << endl;
    cout << "���������� �����������: " << abs(trapecia(a, b, n1) - (round((trapecia(a, b, n1)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << parables(a, b, n1) << endl;
    cout << "���������� �����������: " << abs(parables(a, b, n1) - (round((parables(a, b, n1)) * 10000) / 10000)) << endl;

    cout << endl << "   ��� 100 ���������: " << endl;
    cout << "������� ������� ���������������: " << center(a, b, n2) << endl;
    cout << "���������� �����������: " << abs(center(a, b, n2) - (round((center(a, b, n2)) * 10000) / 10000)) << endl;
    cout << "������� ������ ���������������: " << right(a, b, n) << endl;
    cout << "���������� �����������: " << abs(right(a, b, n2) - (round((right(a, b, n2)) * 10000) / 10000)) << endl;
    cout << "������� ����� ���������������: " << left(a, b, n2) << endl;
    cout << "���������� �����������: " << abs(left(a, b, n2) - (round((left(a, b, n2)) * 10000) / 10000)) << endl;
    cout << "�������� �������-��������: " << newton_leibniz(a, b) << endl;
    cout << "���������� �����������: " << abs(newton_leibniz(a, b) - (round((newton_leibniz(a, b)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << trapecia(a, b, n2) << endl;
    cout << "���������� �����������: " << abs(trapecia(a, b, n2) - (round((trapecia(a, b, n2)) * 10000) / 10000)) << endl;
    cout << "������� ��������: " << parables(a, b, n2) << endl;
    cout << "���������� �����������: " << abs(parables(a, b, n2) - (round((parables(a, b, n2)) * 10000) / 10000)) << endl;
}

