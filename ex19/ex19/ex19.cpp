#include <iostream>
#include <locale.h>

void factorize(int n, int divisor = 2) {
    if (n <= 1) return;
    if (n % divisor == 0) {
        std::cout << divisor << " ";
        factorize(n / divisor, divisor);
    }
    else {
        factorize(n, divisor + 1);
    }
}

void test() {
    std::cout << "Тест 1 (12):  "; factorize(12);  std::cout << "\n";
    std::cout << "Тест 2 (15):  "; factorize(15);  std::cout << "\n";
    std::cout << "Тест 3 (17):  "; factorize(17);  std::cout << "\n";
    std::cout << "Тест 4 (100): "; factorize(100); std::cout << "\n";
    std::cout << "Тест 5 (1):   "; factorize(1);   std::cout << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Простые множители: ";
    factorize(n);
    std::cout << "\n";

    return 0;
}