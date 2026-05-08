#include <iostream>
#include <locale.h>
#include <cstring>

void sortStrings(char** arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void print(char** arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << "\n";
}

void test() {
    char* a1[] = { (char*)"яблоко", (char*)"банан", (char*)"апельсин", (char*)"груша" };
    char* a2[] = { (char*)"zzz", (char*)"aaa", (char*)"mmm" };
    char* a3[] = { (char*)"один" };
    char* a4[] = { (char*)"кот", (char*)"кот", (char*)"собака" };

    sortStrings(a1, 4); std::cout << "Тест 1:\n"; print(a1, 4); std::cout << "\n";
    sortStrings(a2, 3); std::cout << "Тест 2:\n"; print(a2, 3); std::cout << "\n";
    sortStrings(a3, 1); std::cout << "Тест 3:\n"; print(a3, 1); std::cout << "\n";
    sortStrings(a4, 3); std::cout << "Тест 4:\n"; print(a4, 3); std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cin.ignore();

    char** arr = new char* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new char[256];
        std::cout << "Строка " << i << ": ";
        std::cin.getline(arr[i], 256);
    }

    sortStrings(arr, n);
    std::cout << "\nОтсортированные строки:\n";
    print(arr, n);

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}