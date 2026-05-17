#include <iostream>
#include <locale.h>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Rus");

    const int N = 10000;
    const char* filename = "numbers.bin";

    std::ofstream out(filename, std::ios::binary);
    unsigned int seed = 12345;
    for (int i = 0; i < N; i++) {
        seed = seed * 1664525u + 1013904223u;
        int num = (seed % 2 == 0) ? 1 : -1;
        out.write((char*)&num, sizeof(int));
    }
    out.close();
    std::cout << "Записано " << N << " чисел в файл " << filename << "\n";

    int* arr = new int[N];
    std::ifstream in(filename, std::ios::binary);
    in.read((char*)arr, N * sizeof(int));
    in.close();
    std::cout << "Считано " << N << " чисел из файла\n";

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];

    std::cout << "Сумма всех чисел: " << sum << "\n";

    delete[] arr;
    return 0;
}