#include <iostream>
using namespace std;

struct Complex
{
    double real; // Действительная часть
    double imag; // Мнимая часть
};

// Сложение
Complex add(const Complex& a, const Complex& b)
{
    return { a.real + b.real, a.imag + b.imag };
}

// Вычитание
Complex subtract(const Complex& a, const Complex& b)
{
    return { a.real - b.real, a.imag - b.imag };
}

// Умножение
Complex multiply(const Complex& a, const Complex& b)
{
    return { a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real };
}

// Деление
Complex divide(const Complex& a, const Complex& b)
{
    double denominator = b.real * b.real + b.imag * b.imag;
    return { (a.real * b.real + a.imag * b.imag) / denominator,
            (a.imag * b.real - a.real * b.imag) / denominator };
}

// Функция для печати комплексного числа
void printComplex(const Complex& c)
{
    cout << c.real;
    if (c.imag >= 0)
    {
        cout << " + " << c.imag << "i";
    }
    else
    {
        cout << " - " << -c.imag << "i";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    Complex c1 = { 2.0, 3.0 }; // 2 + 3i
    Complex c2 = { 4.0, -1.0 }; // 4 - i

    Complex sum = add(c1, c2);
    Complex difference = subtract(c1, c2);
    Complex product = multiply(c1, c2);
    Complex quotient = divide(c1, c2);

    cout << "c1 = "; printComplex(c1); cout << endl;
    cout << "c2 = "; printComplex(c2); cout << endl;
    cout << "Сумма: "; printComplex(sum); cout << endl;
    cout << "Разность: "; printComplex(difference); cout << endl;
    cout << "Произведение: "; printComplex(product); cout << endl;
    cout << "Частное: "; printComplex(quotient); cout << endl;

    return 0;
}
