#include "unattended_bag.h"
#include <iostream>

UnattendedBag::UnattendedBag() : DetectedObject() {}

UnattendedBag::UnattendedBag(int x1_val, int y1_val, int x2_val, int y2_val, int confidence_val)
    : DetectedObject(x1_val, y1_val, x2_val, y2_val, confidence_val) {
}

Person* UnattendedBag::clone() const {
    return new UnattendedBag(*this);
}

void UnattendedBag::print(std::ostream& os) const {
    os << "--- Обнаруженная Бесхозная Сумка ---\n";
    DetectedObject::print(os); 
}

void UnattendedBag::inputInfo() {
    std::cout << "--- Ввод данных Бесхозной Сумки ---\n";
    DetectedObject::inputInfo(); 
}