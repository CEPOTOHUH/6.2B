#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle() {}

Motorcycle::Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : Vehicle(x1, y1, x2, y2, color, plate) {
}
Motorcycle::Motorcycle(const Motorcycle& other) = default;
Motorcycle& Motorcycle::operator=(const Motorcycle& other) = default;
Motorcycle::Motorcycle(Motorcycle&& other) noexcept = default;
Motorcycle& Motorcycle::operator=(Motorcycle&& other) noexcept = default;

DetectedObject* Motorcycle::clone() const { 
    return new Motorcycle(*this);
}

void Motorcycle::print(std::ostream& os) const { 
    os << "--- Мотоцикл ---\n";
    Vehicle::print(os);
}

void Motorcycle::inputInfo() { 
    std::cout << "--- Ввод данных Мотоцикла ---\n";
    Vehicle::inputInfo();
}