#include "motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle() : Vehicle() {}

Motorcycle::Motorcycle(int x1_val, int y1_val, int x2_val, int y2_val, int color_val, const char* plate_val)
    : Vehicle(x1_val, y1_val, x2_val, y2_val, color_val, plate_val) {
}

Person* Motorcycle::clone() const {
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