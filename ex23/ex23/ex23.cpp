#include <iostream>
#include <locale.h>

struct Date {
    int day, month, year;
};

Date parseDate(const char* str) {
    Date d;
    int i = 0, num = 0, field = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        }
        else if (str[i] == '/') {
            if (field == 0) d.day = num;
            else if (field == 1) d.month = num;
            num = 0;
            field++;
        }
        i++;
    }
    d.year = num;
    return d;
}

int compareDate(const char* date1, const char* date2) {
    Date d1 = parseDate(date1);
    Date d2 = parseDate(date2);

    if (d1.year != d2.year) return d1.year - d2.year;
    if (d1.month != d2.month) return d1.month - d2.month;
    return d1.day - d2.day;
}

void test() {
    std::cout << "Тест 1 (15/03/2024 vs 20/03/2024): " << compareDate("15/03/2024", "20/03/2024") << "\n";
    std::cout << "Тест 2 (01/01/2025 vs 01/01/2024): " << compareDate("01/01/2025", "01/01/2024") << "\n";
    std::cout << "Тест 3 (10/05/2023 vs 10/05/2023): " << compareDate("10/05/2023", "10/05/2023") << "\n";
    std::cout << "Тест 4 (31/12/2023 vs 01/01/2024): " << compareDate("31/12/2023", "01/01/2024") << "\n";
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");

    test();

    char date1[32], date2[32];
    std::cout << "Введите первую дату (dd/mm/yyyy): ";
    std::cin >> date1;
    std::cout << "Введите вторую дату (dd/mm/yyyy): ";
    std::cin >> date2;

    int result = compareDate(date1, date2);
    if (result < 0)
        std::cout << "Первая дата раньше\n";
    else if (result > 0)
        std::cout << "Вторая дата раньше\n";
    else
        std::cout << "Даты равны\n";

    return 0;
}