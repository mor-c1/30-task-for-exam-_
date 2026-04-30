#include <iostream>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");

    float eps_f = 1.0f;
    while (1.0f + eps_f / 2.0f != 1.0f)
        eps_f /= 2.0f;

    double eps_d = 1.0;
    while (1.0 + eps_d / 2.0 != 1.0)
        eps_d /= 2.0;

    float zero_f = 1.0f;
    while (zero_f / 2.0f != 0.0f)
        zero_f /= 2.0f;

    double zero_d = 1.0;
    while (zero_d / 2.0 != 0.0)
        zero_d /= 2.0;

    std::cout << "float:\n";
    std::cout << "  Машинный эпсилон: " << eps_f << "\n";
    std::cout << "  Машинный ноль:    " << zero_f << "\n";

    std::cout << "double:\n";
    std::cout << "  Машинный эпсилон: " << eps_d << "\n";
    std::cout << "  Машинный ноль:    " << zero_d << "\n";

    return 0;
}