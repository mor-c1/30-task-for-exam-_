#include <iostream>
#include <locale.h>

void trim(char* str) {
    int start = 0;
    while (str[start] == ' ') start++;

    int end = 0;
    for (int i = 0; str[i] != '\0'; i++) end = i;
    while (end >= start && str[end] == ' ') end--;

    int k = 0;
    for (int i = start; i <= end; i++)
        str[k++] = str[i];
    str[k] = '\0';
}

void printStr(const char* label, const char* str) {
    std::cout << label << "|" << str << "|\n";
}

void test() {
    char s1[] = "   привет   ";
    char s2[] = "   пробелы слева";
    char s3[] = "пробелы справа   ";
    char s4[] = "без пробелов";
    char s5[] = "     ";

    trim(s1); printStr("Тест 1: ", s1);
    trim(s2); printStr("Тест 2: ", s2);
    trim(s3); printStr("Тест 3: ", s3);
    trim(s4); printStr("Тест 4: ", s4);
    trim(s5); printStr("Тест 5: ", s5);
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    char str[256];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 256);
    trim(str);
    printStr("Результат: ", str);

    return 0;
}