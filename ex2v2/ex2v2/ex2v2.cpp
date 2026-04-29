#include <iostream>

int main() {
    const int ROWS = 100;
    const int COLS = 200;

    int** arr = new int* [ROWS];

    for (int i = 0; i < ROWS; i++)
        arr[i] = new int[COLS];

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = -3 + (i * COLS + j) % 14;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < ROWS; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}