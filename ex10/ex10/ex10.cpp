#include <iostream>
#include <locale.h>

int digitSum(int n) {
    return n / 100 + (n / 10) % 10 + n % 10;
}

void findBySum(int n) {
    std::cout << "Трёхзначные числа с суммой цифр " << n << ":\n";
    for (int i = 100; i <= 999; i++)
        if (digitSum(i) == n)
            std::cout << i << " ";
    std::cout << "\n";
}

void test() {
    std::cout << "Тест 1 (сумма цифр 100): " << digitSum(100) << "\n";
    std::cout << "Тест 2 (сумма цифр 999): " << digitSum(999) << "\n";
    std::cout << "Тест 3 (сумма цифр 123): " << digitSum(123) << "\n";
    std::cout << "\n";
    findBySum(5);
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "\nВведите N: ";
    std::cin >> n;
    findBySum(n);

    return 0;
}