#include "cyclist.h"
#include <iostream>

Cyclist::Cyclist() : Person() {}

Cyclist::Cyclist(int x1_val, int y1_val, int x2_val, int y2_val, int gender_val, int childStatus_val, int glassesStatus_val, int beardStatus_val)
    : Person(x1_val, y1_val, x2_val, y2_val, gender_val, childStatus_val, glassesStatus_val, beardStatus_val) {
}

Person* Cyclist::clone() const {
    return new Cyclist(*this);
}

void Cyclist::print(std::ostream& os) const {
    os << "--- Велосипедист ---\n";
    Person::print(os);
}

void Cyclist::inputInfo() {
    std::cout << "--- Ввод данных Велосипедиста ---\n";
    Person::inputInfo();
}