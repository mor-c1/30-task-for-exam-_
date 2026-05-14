#include <iostream>
#include <locale.h>

void getCurrentDate(char* result) {
    const char* months[] = { "январь", "февраль", "март", "апрель", "май", "июнь",
                           "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };

    int day = 14;
    int month = 4;
    int year = 2026;

    int i = 0;
    if (day >= 10) {
        result[i++] = '0' + day / 10;
        result[i++] = '0' + day % 10;
    }
    else {
        result[i++] = '0' + day;
    }
    result[i++] = '/';

    const char* monthName = months[month];
    for (int j = 0; monthName[j] != '\0'; j++)
        result[i++] = monthName[j];
    result[i++] = '/';

    int yearDigits[4];
    yearDigits[0] = year / 1000;
    yearDigits[1] = (year / 100) % 10;
    yearDigits[2] = (year / 10) % 10;
    yearDigits[3] = year % 10;
    for (int j = 0; j < 4; j++)
        result[i++] = '0' + yearDigits[j];

    result[i] = '\0';
}

void test() {
    char date[64];
    getCurrentDate(date);
    std::cout << "Текущая дата: " << date << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    char date[64];
    getCurrentDate(date);
    std::cout << "Сегодня: " << date << "\n";

    return 0;
}