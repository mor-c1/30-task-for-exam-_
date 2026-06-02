#include <iostream>
#include <locale.h>

struct Date {
    int day, month, year;
};

struct Worker {
    char professions[5][128];
    int categories[5];
    int profCount;
};

struct Programmer {
    char university[256];
    int gradYear;
    char languages[5][64];
    int levels[5];
    int langCount;
};

struct Employee {
    char fio[256];
    Date birthDate;
    int type;

    Worker worker;
    Programmer programmer;
};

void inputEmployee(Employee& e) {
    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::cin.getline(e.fio, 256);

    std::cout << "Введите дату рождения (день месяц год): ";
    std::cin >> e.birthDate.day >> e.birthDate.month >> e.birthDate.year;

    std::cout << "Тип (1 - рабочий, 2 - программист): ";
    std::cin >> e.type;

    if (e.type == 1) {
        std::cout << "Количество профессий (не более 5): ";
        std::cin >> e.worker.profCount;
        if (e.worker.profCount > 5) e.worker.profCount = 5;

        std::cin.ignore();
        for (int i = 0; i < e.worker.profCount; i++) {
            std::cout << "Профессия " << (i + 1) << ": ";
            std::cin.getline(e.worker.professions[i], 128);
            std::cout << "Категория: ";
            std::cin >> e.worker.categories[i];
            std::cin.ignore();
        }
    }
    else if (e.type == 2) {
        std::cout << "Название вуза: ";
        std::cin.ignore();
        std::cin.getline(e.programmer.university, 256);
        std::cout << "Год окончания: ";
        std::cin >> e.programmer.gradYear;

        std::cout << "Количество языков (не более 5): ";
        std::cin >> e.programmer.langCount;
        if (e.programmer.langCount > 5) e.programmer.langCount = 5;

        std::cin.ignore();
        for (int i = 0; i < e.programmer.langCount; i++) {
            std::cout << "Язык " << (i + 1) << ": ";
            std::cin.getline(e.programmer.languages[i], 64);
            std::cout << "Степень владения (1-5): ";
            std::cin >> e.programmer.levels[i];
            std::cin.ignore();
        }
    }
}

void printEmployee(const Employee& e) {
    std::cout << "\n--- Информация о сотруднике ---\n";
    std::cout << "ФИО: " << e.fio << "\n";
    std::cout << "Дата рождения: " << e.birthDate.day << "/"
        << e.birthDate.month << "/" << e.birthDate.year << "\n";

    if (e.type == 1) {
        std::cout << "\nРабочий:\n";
        for (int i = 0; i < e.worker.profCount; i++) {
            std::cout << "  Профессия: " << e.worker.professions[i]
                << ", категория: " << e.worker.categories[i] << "\n";
        }
    }
    else if (e.type == 2) {
        std::cout << "\nПрограммист:\n";
        std::cout << "Вуз: " << e.programmer.university
            << " (" << e.programmer.gradYear << ")\n";
        std::cout << "Языки программирования:\n";
        for (int i = 0; i < e.programmer.langCount; i++) {
            std::cout << "  " << e.programmer.languages[i]
                << " (уровень: " << e.programmer.levels[i] << ")\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    Employee employee;
    inputEmployee(employee);
    printEmployee(employee);

    return 0;
}