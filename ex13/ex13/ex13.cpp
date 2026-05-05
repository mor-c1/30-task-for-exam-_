#include <iostream>
#include <locale.h>

bool hasZeroInEach(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool found = false;
        for (int j = 0; j < cols; j++)
            if (m[i][j] == 0) { found = true; break; }
        if (!found) return false;
    }
    for (int j = 0; j < cols; j++) {
        bool found = false;
        for (int i = 0; i < rows; i++)
            if (m[i][j] == 0) { found = true; break; }
        if (!found) return false;
    }
    return true;
}

int** create(int r, int c) {
    int** m = new int* [r];
    for (int i = 0; i < r; i++) m[i] = new int[c];
    return m;
}

void del(int** m, int r) {
    for (int i = 0; i < r; i++) delete[] m[i];
    delete[] m;
}

void print(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) std::cout << m[i][j] << "\t";
        std::cout << "\n";
    }
}

void test() {
    int** m1 = create(2, 3);
    int v1[2][3] = { {1, 0, 3}, {0, 2, 0} };
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) m1[i][j] = v1[i][j];

    int** m2 = create(2, 2);
    int v2[2][2] = { {1, 2}, {3, 4} };
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) m2[i][j] = v2[i][j];

    int** m3 = create(3, 3);
    int v3[3][3] = { {0, 1, 2}, {3, 0, 4}, {5, 6, 0} };
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) m3[i][j] = v3[i][j];

    std::cout << "Тест 1:\n"; print(m1, 2, 3);
    std::cout << "Результат: " << (hasZeroInEach(m1, 2, 3) ? "есть" : "нет") << "\n\n";

    std::cout << "Тест 2:\n"; print(m2, 2, 2);
    std::cout << "Результат: " << (hasZeroInEach(m2, 2, 2) ? "есть" : "нет") << "\n\n";

    std::cout << "Тест 3:\n"; print(m3, 3, 3);
    std::cout << "Результат: " << (hasZeroInEach(m3, 3, 3) ? "есть" : "нет") << "\n\n";

    del(m1, 2); del(m2, 2); del(m3, 3);
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int r, c;
    std::cout << "Введите размеры матрицы (строки столбцы): ";
    std::cin >> r >> c;

    int** m = create(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            std::cout << "m[" << i << "][" << j << "] = ";
            std::cin >> m[i][j];
        }

    std::cout << "В каждой строке и столбце есть ноль: " << (hasZeroInEach(m, r, c) ? "да" : "нет") << "\n";

    del(m, r);
    return 0;
}