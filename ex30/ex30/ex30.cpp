#include <iostream>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");

    int x = 40, y = 10;
    int centerX = 40, centerY = 10;
    int steps = 0;

    while (steps < 200) {
        system("clear");

        std::cout << "\nБроуновское движение (шаг " << steps << ")\n\n";

        for (int row = 0; row < 21; row++) {
            for (int col = 0; col < 80; col++) {
                if (row == centerY && col == centerX)
                    std::cout << "O";
                else if (row == y && col == x)
                    std::cout << "*";
                else
                    std::cout << ".";
            }
            std::cout << "\n";
        }

        int dir = rand() % 4;
        if (dir == 0) x += 2;
        else if (dir == 1) x -= 2;
        else if (dir == 2) y += 2;
        else y -= 2;

        if (x < 2) x = 2;
        if (x > 78) x = 78;
        if (y < 1) y = 1;
        if (y > 19) y = 19;

        std::cout << "\nПозиция: (" << x << ", " << y << ")\n";
        std::cout << "Расстояние от центра: " << (int)sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY)) << "\n";

        steps++;
        for (int i = 0; i < 100000000; i++);
    }

    return 0;
}