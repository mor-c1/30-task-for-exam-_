#include <iostream>
#include <locale.h>

bool isPalindrome(int n) {
    if (n < 0) return false;
    int original = n;
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

void printPalindromes(int n) {
    std::cout << "Числа-перевертыши до " << n << ":\n";
    for (int i = 1; i <= n; i++)
        if (isPalindrome(i))
            std::cout << i << " ";
    std::cout << "\n";
}

void test() {
    std::cout << "Тест 1 (121):  " << (isPalindrome(121) ? "перевертыш" : "нет") << "\n";
    std::cout << "Тест 2 (123):  " << (isPalindrome(123) ? "перевертыш" : "нет") << "\n";
    std::cout << "Тест 3 (1):    " << (isPalindrome(1) ? "перевертыш" : "нет") << "\n";
    std::cout << "Тест 4 (1221): " << (isPalindrome(1221) ? "перевертыш" : "нет") << "\n";
    std::cout << "Тест 5 (120):  " << (isPalindrome(120) ? "перевертыш" : "нет") << "\n";
    std::cout << "\n";
    printPalindromes(200);
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "\nВведите N: ";
    std::cin >> n;
    printPalindromes(n);

    return 0;
}
