#include <iostream>
#include <locale.h>

bool allUnique(int n) {
    bool used[10] = { false };
    while (n > 0) {
        int d = n % 10;
        if (used[d]) return false;
        used[d] = true;
        n /= 10;
    }
    return true;
}

void findUnique(int n) {
    std::cout << "Числа до " << n << " с различными цифрами:\n";
    for (int i = 1; i <= n; i++)
        if (allUnique(i))
            std::cout << i << " ";
    std::cout << "\n";
}

void test() {
    std::cout << "Тест 1 (123):  " << (allUnique(123) ? "все различны" : "есть повторы") << "\n";
    std::cout << "Тест 2 (112):  " << (allUnique(112) ? "все различны" : "есть повторы") << "\n";
    std::cout << "Тест 3 (9876): " << (allUnique(9876) ? "все различны" : "есть повторы") << "\n";
    std::cout << "Тест 4 (1001): " << (allUnique(1001) ? "все различны" : "есть повторы") << "\n";
    std::cout << "\n";
    findUnique(30);
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "\nВведите N: ";
    std::cin >> n;
    findUnique(n);

    return 0;
}