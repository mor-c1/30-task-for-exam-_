#include <iostream>
#include <locale.h>
#include <fstream>

bool compareFiles(const char* file1, const char* file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) return false;

    char ch1, ch2;
    while (f1.get(ch1) && f2.get(ch2)) {
        if (ch1 != ch2) {
            f1.close();
            f2.close();
            return false;
        }
    }

    bool result = f1.eof() && f2.eof();
    f1.close();
    f2.close();
    return result;
}

void test() {
    std::ofstream out1("file1.txt");
    out1 << "Привет мир\n";
    out1.close();

    std::ofstream out2("file2.txt");
    out2 << "Привет мир\n";
    out2.close();

    std::ofstream out3("file3.txt");
    out3 << "Другой текст\n";
    out3.close();

    std::ofstream out4("file4.txt");
    out4 << "Привет мир\nЕще строка\n";
    out4.close();

    std::cout << "Тест 1 (одинаковые):     " << (compareFiles("file1.txt", "file2.txt") ? "совпадают" : "не совпадают") << "\n";
    std::cout << "Тест 2 (разный текст):   " << (compareFiles("file1.txt", "file3.txt") ? "совпадают" : "не совпадают") << "\n";
    std::cout << "Тест 3 (разная длина):   " << (compareFiles("file1.txt", "file4.txt") ? "совпадают" : "не совпадают") << "\n";
    std::cout << "Тест 4 (файл не найден): " << (compareFiles("file1.txt", "nofile.txt") ? "совпадают" : "не совпадают") << "\n";
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");

    if (argc == 1) {
        test();

        char file1[256], file2[256];
        std::cout << "Введите первый файл: ";
        std::cin >> file1;
        std::cout << "Введите второй файл: ";
        std::cin >> file2;

        if (compareFiles(file1, file2))
            std::cout << "Файлы совпадают\n";
        else
            std::cout << "Файлы не совпадают\n";
    }
    else if (argc == 3) {
        if (compareFiles(argv[1], argv[2]))
            std::cout << "Файлы совпадают\n";
        else
            std::cout << "Файлы не совпадают\n";
    }
    else {
        std::cout << "Использование: " << argv[0] << " <файл1> <файл2>\n";
    }

    return 0;
}