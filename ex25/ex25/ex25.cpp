#include <iostream>
#include <locale.h>
#include <fstream>

int countLines(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return -1;

    int count = 0;
    char ch;
    while (file.get(ch))
        if (ch == '\n')
            count++;

    file.close();
    return count;
}

void test() {
    std::ofstream out("test1.txt");
    out << "Строка 1\nСтрока 2\nСтрока 3\n";
    out.close();

    std::ofstream out2("test2.txt");
    out2 << "Одна строка";
    out2.close();

    std::ofstream out3("test3.txt");
    out3 << "";
    out3.close();

    std::cout << "Тест 1 (3 строки): " << countLines("test1.txt") << "\n";
    std::cout << "Тест 2 (без \\n):   " << countLines("test2.txt") << "\n";
    std::cout << "Тест 3 (пустой):   " << countLines("test3.txt") << "\n";
    std::cout << "Тест 4 (нет файла): " << countLines("nofile.txt") << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    char filename[256];
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    int lines = countLines(filename);
    if (lines == -1)
        std::cout << "Файл не найден\n";
    else
        std::cout << "Количество строк: " << lines << "\n";

    return 0;
}