#include "Cyclist.h"

Cyclist::Cyclist() : Person() {}

Cyclist::Cyclist(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : Person(x1, y1, x2, y2, g, c, gl, b) {
}
Cyclist::Cyclist(const Cyclist& other) = default;
Cyclist& Cyclist::operator=(const Cyclist& other) = default;
Cyclist::Cyclist(Cyclist&& other) noexcept = default;
Cyclist& Cyclist::operator=(Cyclist&& other) noexcept = default;

DetectedObject* Cyclist::clone() const { 
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