#include <iostream>
#include <locale.h>

int lastIndexOf(const char* str, char ch) {
    int last = -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            last = i;
    return last;
}

void test() {
    std::cout << "Тест 1 ('привет', 'и'): " << lastIndexOf("привет", 'и') << "\n";
    std::cout << "Тест 2 ('hello', 'l'):  " << lastIndexOf("hello", 'l') << "\n";
    std::cout << "Тест 3 ('abc', 'd'):    " << lastIndexOf("abc", 'd') << "\n";
    std::cout << "Тест 4 ('aaaa', 'a'):   " << lastIndexOf("aaaa", 'a') << "\n";
    std::cout << "Тест 5 ('test', 't'):   " << lastIndexOf("test", 't') << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    char str[256];
    char ch;
    std::cout << "Введите строку: ";
    std::cin.getline(str, 256);
    std::cout << "Введите символ: ";
    std::cin >> ch;

    int pos = lastIndexOf(str, ch);
    if (pos != -1)
        std::cout << "Последнее вхождение на позиции: " << pos << "\n";
    else
        std::cout << "Символ не найден\n";

    return 0;
}