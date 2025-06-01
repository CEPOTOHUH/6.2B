#include "Person.h"
#include <iostream>

// Реализация методов Person
Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}
Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2) {
    setGender(g);
    setChildStatus(c);
    setGlassesStatus(gl);
    setBeardStatus(b);
}
void Person::print(std::ostream& os) const {
    os << "--- Человек ---\n";
    DetectedObject::print(os);
    os << "  Пол (0=Муж, 1=Жен, 2=Не опр.): " << gender << "\n";
    os << "  Ребёнок (0=Да, 1=Нет, 2=Не опр.): " << childStatus << "\n";
    os << "  Очки (0=Есть, 1=Нет, 2=Не опр.): " << glassesStatus << "\n";
    os << "  Борода (0=Есть, 1=Нет, 2=Не опр.): " << beardStatus << "\n";
}

void Person::inputInfo() {
    std::cout << "--- Ввод данных Человека ---\n";
    DetectedObject::inputInfo();

    std::cout << "  Введите пол (0=Муж, 1=Жен, 2=Не опр.): ";
    int tempGender;
    while (!(std::cin >> tempGender) || tempGender < 0 || tempGender > 2) {
        std::cout << "Ошибка: Введите число от 0 до 2 для пола: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGender(tempGender);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Введите статус ребёнка (0=Да, 1=Нет, 2=Не опр.): ";
    int tempChildStatus;
    while (!(std::cin >> tempChildStatus) || tempChildStatus < 0 || tempChildStatus > 2) {
        std::cout << "Ошибка: Введите число от 0 до 2 для статуса ребёнка: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setChildStatus(tempChildStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Введите статус очков (0=Есть, 1=Нет, 2=Не опр.): ";
    int tempGlassesStatus;
    while (!(std::cin >> tempGlassesStatus) || tempGlassesStatus < 0 || tempGlassesStatus > 2) {
        std::cout << "Ошибка: Введите число от 0 до 2 для статуса очков: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGlassesStatus(tempGlassesStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Введите статус бороды (0=Есть, 1=Нет, 2=Не опр.): ";
    int tempBeardStatus;
    while (!(std::cin >> tempBeardStatus) || tempBeardStatus < 0 || tempBeardStatus > 2) {
        std::cout << "Ошибка: Введите число от 0 до 2 для статуса бороды: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setBeardStatus(tempBeardStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Person::setGender(int g) {
    if (g >= 0 && g <= 2) {
        gender = g;
    }
    else {
        std::cerr << "Неверное значение для пола (" << g << "). Допустимо (0, 1, 2). Значение не изменено.\n";
    }
}
int Person::getGender() const { return gender; }

void Person::setChildStatus(int c) {
    if (c >= 0 && c <= 2) {
        childStatus = c;
    }
    else {
        std::cerr << "Неверное значение для статуса ребенка (" << c << "). Допустимо (0, 1, 2). Значение не изменено.\n";
    }
}
int Person::getChildStatus() const { return childStatus; }

void Person::setGlassesStatus(int gl) {
    if (gl >= 0 && gl <= 2) {
        glassesStatus = gl;
    }
    else {
        std::cerr << "Неверное значение для статуса очков (" << gl << "). Допустимо (0, 1, 2). Значение не изменено.\n";
    }
}
int Person::getGlassesStatus() const { return glassesStatus; }

void Person::setBeardStatus(int b) {
    if (b >= 0 && b <= 2) {
        beardStatus = b;
    }
    else {
        std::cerr << "Неверное значение для статуса бороды (" << b << "). Допустимо (0, 1, 2). Значение не изменено.\n";
    }
}
int Person::getBeardStatus() const { return beardStatus; }