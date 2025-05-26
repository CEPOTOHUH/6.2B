#include "Car.h"

Car::Car() : Vehicle(), isTaxi(false) {}

Car::Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi)
    : Vehicle(x1, y1, x2, y2, color, plate), isTaxi(taxi) {
}

Car::Car(const Car& other) = default;
Car& Car::operator=(const Car& other) = default;
Car::Car(Car&& other) noexcept = default;
Car& Car::operator=(Car&& other) noexcept = default;

DetectedObject* Car::clone() const { 
    return new Car(*this);
}

void Car::print(std::ostream& os) const { 
    os << "--- ���������� ---\n";
    Vehicle::print(os);
    os << "  ����� (0=���, 1=��): " << (isTaxi ? "��" : "���") << "\n";
}

void Car::inputInfo() { 
    std::cout << "--- ���� ������ ���������� ---\n";
    Vehicle::inputInfo();
    std::cout << "  ����� (0=���, 1=��): "; std::cin >> isTaxi;
    std::cin.ignore(256, '\n');
}