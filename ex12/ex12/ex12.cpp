#include <iostream>
#include <locale.h>

int countEven(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count++;
    return count;
}

void test() {
    int a1[] = { 1, 2, 3, 4, 5, 6 };
    int a2[] = { 1, 3, 5, 7 };
    int a3[] = { 2, 4, 6, 8 };
    int a4[] = { 0, -2, 3, -4 };

    std::cout << "Тест 1 {1,2,3,4,5,6}: " << countEven(a1, 6) << "\n";
    std::cout << "Тест 2 {1,3,5,7}:     " << countEven(a2, 4) << "\n";
    std::cout << "Тест 3 {2,4,6,8}:     " << countEven(a3, 4) << "\n";
    std::cout << "Тест 4 {0,-2,3,-4}:   " << countEven(a4, 4) << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    std::cout << "Количество чётных чисел: " << countEven(arr, n) << "\n";

    delete[] arr;
    return 0;
}