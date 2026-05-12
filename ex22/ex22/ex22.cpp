#include <iostream>
#include <locale.h>
#include <ctime>

double getInterval() {
    std::cout << "Нажмите Enter...";
    std::cin.get();
    clock_t start = clock();

    std::cout << "Нажмите Enter снова...";
    std::cin.get();
    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    setlocale(LC_ALL, "Rus");

    double interval = getInterval();
    std::cout << "Интервал времени: " << interval << " секунд\n";

    return 0;
}