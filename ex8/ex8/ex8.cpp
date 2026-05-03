#include <iostream>
#include <locale.h>

double f(double x) {
    return -x * x + 4 * x + 1;
}

double maxOnInterval(double (*func)(double), double a, double b, int steps) {
    double max = func(a);
    double step = (b - a) / steps;
    for (int i = 1; i <= steps; i++) {
        double val = func(a + i * step);
        if (val > max)
            max = val;
    }
    return max;
}

void test() {
    std::cout << "Тест 1 f(x) = -x^2 + 4x + 1 на [0, 4]: " << maxOnInterval(f, 0, 4, 1000) << "\n";
    std::cout << "Тест 2 f(x) = -x^2 + 4x + 1 на [0, 1]: " << maxOnInterval(f, 0, 1, 1000) << "\n";
    std::cout << "Тест 3 f(x) = -x^2 + 4x + 1 на [3, 4]: " << maxOnInterval(f, 3, 4, 1000) << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    double a, b;
    std::cout << "Введите интервал [a, b]:\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;

    std::cout << "Максимум f(x) на [" << a << ", " << b << "] = " << maxOnInterval(f, a, b, 1000) << "\n";

    return 0;
}