#include "Car.h"
#include <iostream>
#include <limits>

// Реализация методов Car
Car::Car() : Vehicle(), isTaxi(false) {}

Car::Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi)
    : Vehicle(x1, y1, x2, y2, color, plate) {
    setIsTaxi(taxi);
}

void Car::print(std::ostream& os) const {
    os << "--- Автомобиль ---\n";
    Vehicle::print(os);
    os << "  Такси (0=Нет, 1=Да): " << (isTaxi ? "Да" : "Нет") << "\n";
}

void Car::inputInfo() {
    std::cout << "--- Ввод данных Автомобиля ---\n";
    Vehicle::inputInfo();
    std::cout << "  Такси (0=Нет, 1=Да): ";
    int tempIsTaxi;
    while (!(std::cin >> tempIsTaxi) || (tempIsTaxi != 0 && tempIsTaxi != 1)) {
        std::cout << "Ошибка: Введите 0 (Нет) или 1 (Да) для такси: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setIsTaxi(tempIsTaxi == 1);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Car::setIsTaxi(bool taxi) {
    isTaxi = taxi;
}
bool Car::getIsTaxi() const { return isTaxi; }