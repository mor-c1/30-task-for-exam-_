#include <iostream>
#include <locale.h>

int F(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return 2 * F(n - 1) - F(n - 2);
}

void test() {
    std::cout << "Тест 1 F(0): " << F(0) << "\n";
    std::cout << "Тест 2 F(1): " << F(1) << "\n";
    std::cout << "Тест 3 F(2): " << F(2) << "\n";
    std::cout << "Тест 4 F(3): " << F(3) << "\n";
    std::cout << "Тест 5 F(4): " << F(4) << "\n";
    std::cout << "Тест 6 F(5): " << F(5) << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "F(" << n << ") = " << F(n) << "\n";

    std::cout << "\nПервые 10 элементов последовательности:\n";
    for (int i = 0; i < 10; i++)
        std::cout << "F(" << i << ") = " << F(i) << "\n";

    return 0;
}
