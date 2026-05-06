#include <iostream>
#include <locale.h>

void sort(float* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void print(float* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void test() {
    float a1[] = { 5.0, 3.0, 8.0, 1.0, 4.0 };
    float a2[] = { -1.5, 0.0, -3.2, 2.7 };
    float a3[] = { 1.0 };
    float a4[] = { 3.0, 3.0, 1.0, 2.0 };

    sort(a1, 5); std::cout << "Тест 1: "; print(a1, 5);
    sort(a2, 4); std::cout << "Тест 2: "; print(a2, 4);
    sort(a3, 1); std::cout << "Тест 3: "; print(a3, 1);
    sort(a4, 4); std::cout << "Тест 4: "; print(a4, 4);
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    float* arr = new float[n];
    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    sort(arr, n);
    std::cout << "Отсортированный массив: ";
    print(arr, n);

    delete[] arr;
    return 0;
}
