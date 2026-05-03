#include <iostream>
#include <locale.h>

void multiplyMatrix(int** a, int** b, int** c, int n, int m, int k) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            c[i][j] = 0;
            for (int p = 0; p < m; p++)
                c[i][j] += a[i][p] * b[p][j];
        }
}

void printMatrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << m[i][j] << "\t";
        std::cout << "\n";
    }
}

int** createMatrix(int rows, int cols) {
    int** m = new int* [rows];
    for (int i = 0; i < rows; i++)
        m[i] = new int[cols];
    return m;
}

void deleteMatrix(int** m, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}

void test() {
    // Матрица A 2x3
    int** a = createMatrix(2, 3);
    a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
    a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;

    // Матрица B 3x2
    int** b = createMatrix(3, 2);
    b[0][0] = 7;  b[0][1] = 8;
    b[1][0] = 9;  b[1][1] = 10;
    b[2][0] = 11; b[2][1] = 12;

    // Результат 2x2
    int** c = createMatrix(2, 2);
    multiplyMatrix(a, b, c, 2, 3, 2);

    std::cout << "Матрица A:\n";
    printMatrix(a, 2, 3);
    std::cout << "Матрица B:\n";
    printMatrix(b, 3, 2);
    std::cout << "Результат A * B:\n";
    printMatrix(c, 2, 2);

    deleteMatrix(a, 2);
    deleteMatrix(b, 3);
    deleteMatrix(c, 2);
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    int n, m, k;
    std::cout << "Введите размеры матрицы A (n x m): ";
    std::cin >> n >> m;
    std::cout << "Введите количество столбцов матрицы B (k): ";
    std::cin >> k;

    int** a = createMatrix(n, m);
    int** b = createMatrix(m, k);
    int** c = createMatrix(n, k);

    std::cout << "Введите элементы матрицы A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cout << "A[" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }

    std::cout << "Введите элементы матрицы B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++) {
            std::cout << "B[" << i << "][" << j << "] = ";
            std::cin >> b[i][j];
        }

    multiplyMatrix(a, b, c, n, m, k);

    std::cout << "Результат A * B:\n";
    printMatrix(c, n, k);

    deleteMatrix(a, n);
    deleteMatrix(b, m);
    deleteMatrix(c, n);

    return 0;
}
