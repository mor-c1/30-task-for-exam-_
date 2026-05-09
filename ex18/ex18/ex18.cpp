#include <iostream>
#include <locale.h>

double f(double x) {
    return x * x + 2 * x + 1;
}

double g(double x) {
    return x * x * x;
}

double derivative(double (*func)(double), double x, double h = 1e-6) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

void test() {
    std::cout << "Тест 1 f(x)=x²+2x+1 в x=0: " << derivative(f, 0.0) << "\n";
    std::cout << "Тест 2 f(x)=x²+2x+1 в x=1: " << derivative(f, 1.0) << "\n";
    std::cout << "Тест 3 g(x)=x³ в x=2:      " << derivative(g, 2.0) << "\n";
    std::cout << "Тест 4 g(x)=x³ в x=0:      " << derivative(g, 0.0) << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    double x;
    std::cout << "Введите точку x для f(x)=x²+2x+1: ";
    std::cin >> x;
    std::cout << "Производная в точке x=" << x << ": " << derivative(f, x) << "\n";

    std::cout << "Введите точку x для g(x)=x³: ";
    std::cin >> x;
    std::cout << "Производная в точке x=" << x << ": " << derivative(g, x) << "\n";

    return 0;
}