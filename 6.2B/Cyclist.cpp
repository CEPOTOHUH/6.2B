#include "Cyclist.h"
#include <iostream>

// Реализация методов Cyclist
Cyclist::Cyclist() : Person() {}
Cyclist::Cyclist(int x1, int y1, int x2, int y2, int g, int c, int gl, int b) : Person(x1, y1, x2, y2, g, c, gl, b) {}
void Cyclist::print(std::ostream& os) const {
    os << "--- Велосипедист ---\n";
    Person::print(os);
}

void Cyclist::inputInfo() {
    std::cout << "--- Ввод данных Велосипедиста ---\n";
    Person::inputInfo();
}