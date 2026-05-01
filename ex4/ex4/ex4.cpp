#include <iostream>
#include <locale.h>

double length(double* v, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += v[i] * v[i];

    double x = sum;
    double prev = 0.0;
    while (x - prev > 1e-10 || prev - x > 1e-10) {
        prev = x;
        x = (x + sum / x) / 2.0;
    }
    return x;
}

void test() {
    double v1[] = { 3.0, 4.0 };
    double res1 = length(v1, 2);
    std::cout << "Тест 1 (3,4): " << res1 << "\n";

    double v2[] = { 1.0, 1.0, 1.0 };
    double res2 = length(v2, 3);
    std::cout << "Тест 2 (1,1,1): " << res2 << "\n";

    double v3[] = { 5.0 };
    double res3 = length(v3, 1);
    std::cout << "Тест 3 (5): " << res3 << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");
    test();

    int n;
    std::cout << "\nВведите размерность вектора: ";
    std::cin >> n;

    double* v = new double[n];
    std::cout << "Введите элементы вектора:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }

    std::cout << "Длина вектора: " << length(v, n) << "\n";

    delete[] v;
    return 0;
}