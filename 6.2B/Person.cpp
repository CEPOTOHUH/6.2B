#include "Person.h"

Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}

Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2), gender(g), childStatus(c), glassesStatus(gl), beardStatus(b) {
}

DetectedObject* Person::clone() const {
    return new Person(*this);
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
    std::cout << "  Введите пол (0=Муж, 1=Жен, 2=Не опр.): "; std::cin >> gender;
    std::cout << "  Введите статус ребёнка (0=Да, 1=Нет, 2=Не опр.): "; std::cin >> childStatus;
    std::cout << "  Введите статус очков (0=Есть, 1=Нет, 2=Не опр.): "; std::cin >> glassesStatus;
    std::cout << "  Введите статус бороды (0=Есть, 1=Нет, 2=Не опр.): "; std::cin >> beardStatus;
    std::cin.ignore(256, '\n');
}