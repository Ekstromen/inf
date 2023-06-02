#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    //task a
    double c, d, f;
    cout << "������� ��� �����:" << endl;
    cin >> c;
    cin >> d;

    cout << "������� �����:" << endl;
    cin >> f;

    double a = c / d;
    double b = sqrt(f);

    cout << fixed << setprecision(6);

    cout << "�������� ��������� � ������� ����������� ���������� ������: " << endl;
    cout << "1) " << a << endl;
    cout << "2) " << b << endl;

    double abs_error_a = abs(a - (ceil(a * 1000) / 1000));
    double abs_error_b = abs(b - (round(b * 100) / 100));

    double rel_error_a = abs_error_a / a;
    double rel_error_b = abs_error_b / b;

    cout << "\n���������� ���������� �����������, �������� �� � ��������:\n";
    cout << "1) " << abs_error_a << endl;
    cout << "2) " << abs_error_b << endl;

    cout << "\n���������� ���������� ����������� ���������� � %:\n";
    cout << "1) " << abs_error_a / a * 100.0 << endl;
    cout << "2) " << abs_error_b / b * 100.0 << endl;

    if ((abs_error_a / a * 100.0) < (abs_error_b / b * 100.0)) cout << "������, ����� ������ ���������: " << c << " / " << d << " = " << c/d << endl;
    else cout << "������, ����� ������ ���������: " << "sqrt(" << f << ") = " << sqrt(f) << endl;

    cout << std::resetiosflags(std::ios::fixed) << "  " << endl;

    //Task b
    cout << "\nTask b:\n";
    double value;
    cout << "������� �����:" << endl;
    cin >> value;

    double infelicity;
    cout << "������� ������������� �����������:" << endl;
    cin >> infelicity;
    
    double p,l,k,j, g = value;
    while (g > 1) g--;
    j = g;
    l = 0;
    for (int i = 1; i < 1000; i++) {
        k = trunc(j * pow(10, i)) / pow(10, i);
        //cout << k - l << endl;
        
        if ((k - l) < (infelicity / 100)) {
            p = trunc(value * pow(10, i - 1)) / pow(10, i - 1);
            cout << "������� ������� ��������: " << p << endl;
            break;
        }
        l = k;
    }
    cout << endl << "���������� ����������� ����������: " << p*(infelicity/100) << endl;
 
    // Task c
    cout << endl << "������� c" << endl;
    double exact_value;
    cout << "������� ��������: " << endl;
    cin >> exact_value;
    double approx_value;

    double num = exact_value;
    int numDigits = 0;
    while (abs(num - round(num)) > 1e-7) {
        num *= 10;
        numDigits++;
    }
    
    double abs_error_c = 5 / (pow(10, numDigits+1));
    double rel_error_c = abs_error_c / exact_value * 100;
    cout << "���������� ���������� �����������: " << abs_error_c << setprecision(6) << endl;
    cout << "���������� ������������� �����������: " << rel_error_c << "%" << endl;

}