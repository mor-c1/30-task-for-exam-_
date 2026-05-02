#include <iostream>
#include <locale.h>

bool isLucky(int n) {
    int d[6];
    for (int i = 5; i >= 0; i--) {
        d[i] = n % 10;
        n /= 10;
    }
    int left = d[0] + d[1] + d[2];
    int right = d[3] + d[4] + d[5];
    return left == right;
}

int countLucky() {
    int count = 0;
    for (int i = 0; i <= 999999; i++)
        if (isLucky(i))
            count++;
    return count;
}

void printLucky(int limit) {
    std::cout << "Счастливые билеты (первые " << limit << "):\n";
    int count = 0;
    for (int i = 0; i <= 999999 && count < limit; i++) {
        if (isLucky(i)) {
            for (int d = 100000; d >= 1; d /= 10)
                std::cout << (i / d) % 10;
            std::cout << " ";
            count++;
        }
    }
    std::cout << "\n";
}

void test() {
    std::cout << "Тест 1 (000000): " << (isLucky(0) ? "счастливый" : "нет") << "\n";
    std::cout << "Тест 2 (001001): " << (isLucky(1001) ? "счастливый" : "нет") << "\n";
    std::cout << "Тест 3 (123321): " << (isLucky(123321) ? "счастливый" : "нет") << "\n";
    std::cout << "Тест 4 (123456): " << (isLucky(123456) ? "счастливый" : "нет") << "\n";
    std::cout << "Тест 5 (кол-во): " << countLucky() << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    std::cout << "\nВсего счастливых билетов: " << countLucky() << "\n\n";

    int limit;
    std::cout << "Сколько билетов вывести? ";
    std::cin >> limit;
    printLucky(limit);

    return 0;
}
