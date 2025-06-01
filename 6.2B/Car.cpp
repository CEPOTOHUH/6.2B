#include "Car.h"
#include <iostream>
#include <limits>

// ���������� ������� Car
Car::Car() : Vehicle(), isTaxi(false) {}

Car::Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi)
    : Vehicle(x1, y1, x2, y2, color, plate) {
    setIsTaxi(taxi);
}

void Car::print(std::ostream& os) const {
    os << "--- ���������� ---\n";
    Vehicle::print(os);
    os << "  ����� (0=���, 1=��): " << (isTaxi ? "��" : "���") << "\n";
}

void Car::inputInfo() {
    std::cout << "--- ���� ������ ���������� ---\n";
    Vehicle::inputInfo();
    std::cout << "  ����� (0=���, 1=��): ";
    int tempIsTaxi;
    while (!(std::cin >> tempIsTaxi) || (tempIsTaxi != 0 && tempIsTaxi != 1)) {
        std::cout << "������: ������� 0 (���) ��� 1 (��) ��� �����: ";
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