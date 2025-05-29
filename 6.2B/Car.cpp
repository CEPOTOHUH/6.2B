#include "car.h"
#include <iostream>

Car::Car() : Vehicle() {}

Car::Car(int x1_val, int y1_val, int x2_val, int y2_val, int color_val, const char* plate_val)
    : Vehicle(x1_val, y1_val, x2_val, y2_val, color_val, plate_val) {
}

Person* Car::clone() const {
    return new Car(*this);
}

void Car::print(std::ostream& os) const {
    os << "--- Автомобиль ---\n";
    Vehicle::print(os); 
}

void Car::inputInfo() {
    std::cout << "--- Ввод данных Автомобиля ---\n";
    Vehicle::inputInfo(); 
}