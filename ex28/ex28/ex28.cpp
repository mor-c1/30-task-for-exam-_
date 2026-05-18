#include <iostream>
#include <locale.h>

struct Date {
    int day, month, year;
};

struct Person {
    char fio[256];
    Date birthDate;
    int type;

    char schoolName[256];
    int grade;

    char university[256];
    char faculty[256];
    char group[256];
};

void inputPerson(Person& p) {
    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::cin.getline(p.fio, 256);

    std::cout << "Введите дату рождения (день месяц год): ";
    std::cin >> p.birthDate.day >> p.birthDate.month >> p.birthDate.year;

    std::cout << "Тип (1 - школьник, 2 - студент): ";
    std::cin >> p.type;

    if (p.type == 1) {
        std::cout << "Введите название школы: ";
        std::cin.ignore();
        std::cin.getline(p.schoolName, 256);
        std::cout << "Введите класс: ";
        std::cin >> p.grade;
    }
    else if (p.type == 2) {
        std::cout << "Введите название вуза: ";
        std::cin.ignore();
        std::cin.getline(p.university, 256);
        std::cout << "Введите факультет: ";
        std::cin.getline(p.faculty, 256);
        std::cout << "Введите группу: ";
        std::cin.getline(p.group, 256);
    }
}

void printPerson(const Person& p) {
    std::cout << "\nИнформация\n";
    std::cout << "ФИО: " << p.fio << "\n";
    std::cout << "Дата рождения: " << p.birthDate.day << "/"
        << p.birthDate.month << "/" << p.birthDate.year << "\n";

    if (p.type == 1) {
        std::cout << "Школа: " << p.schoolName << "\n";
        std::cout << "Класс: " << p.grade << "\n";
    }
    else if (p.type == 2) {
        std::cout << "Вуз: " << p.university << "\n";
        std::cout << "Факультет: " << p.faculty << "\n";
        std::cout << "Группа: " << p.group << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    Person person;
    inputPerson(person);
    printPerson(person);

    return 0;
}