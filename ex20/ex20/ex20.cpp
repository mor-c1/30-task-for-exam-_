#include <iostream>
#include <locale.h>

double f(double x) {
    return x * x - 4;
}

double g(double x) {
    return x * x * x - 2 * x - 5;
}

double bisection(double (*func)(double), double a, double b, double eps = 1e-6) {
    double mid = (a + b) / 2;
    if (b - a < eps) return mid;

    double fa = func(a);
    double fmid = func(mid);

    if (fa * fmid < 0)
        return bisection(func, a, mid, eps);
    else
        return bisection(func, mid, b, eps);
}

void test() {
    std::cout << "Тест 1 f(x)=x²-4 на [0,3]:    " << bisection(f, 0.0, 3.0) << "\n";
    std::cout << "Тест 2 f(x)=x²-4 на [-3,0]:   " << bisection(f, -3.0, 0.0) << "\n";
    std::cout << "Тест 3 g(x)=x³-2x-5 на [2,3]: " << bisection(g, 2.0, 3.0) << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    double a, b;
    std::cout << "Введите отрезок [a, b] для f(x)=x²-4:\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "Корень: " << bisection(f, a, b) << "\n";

    return 0;
}