#include <iostream>

int main() {
    const int ROWS = 100;
    const int COLS = 200;

    float** arr = new float* [ROWS];

    for (int i = 0; i < ROWS; i++)
        arr[i] = new float[COLS];

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = -1.0f + (i + j) % 200 / 100.0f;

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