#include <iostream>
#include <locale.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void primes(int n) {
    std::cout << "Простые числа до " << n << ":\n";
    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            std::cout << i << " ";
    std::cout << "\n";
}

void test() {

    std::cout << "Тест 1 (до 10): ";
    primes(10);

    std::cout << "Тест 2 (до 2): ";
    primes(2);

    std::cout << "Тест 3 (до 1): ";
    primes(1);

    std::cout << "Тест 4 (до 20): ";
    primes(20);
   
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "\nВведите N: ";
    std::cin >> n;
    primes(n);

    return 0;
}