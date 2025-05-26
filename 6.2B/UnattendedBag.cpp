#include "UnattendedBag.h"

UnattendedBag::UnattendedBag() : DetectedObject(), detectedTimeSeconds(0) {}

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, long long time)
    : DetectedObject(x1, y1, x2, y2), detectedTimeSeconds(time) {
}
UnattendedBag::UnattendedBag(const UnattendedBag& other) = default;
UnattendedBag& UnattendedBag::operator=(const UnattendedBag& other) = default;
UnattendedBag::UnattendedBag(UnattendedBag&& other) noexcept = default;
UnattendedBag& UnattendedBag::operator=(UnattendedBag&& other) noexcept = default;

DetectedObject* UnattendedBag::clone() const { 
    return new UnattendedBag(*this);
}

void UnattendedBag::print(std::ostream& os) const { 
    os << "--- Бесхозная сумка ---\n";
    DetectedObject::print(os);
    os << "  Время первого обнаружения (секунды после полуночи): " << detectedTimeSeconds << "\n";
}

void UnattendedBag::inputInfo() { 
    std::cout << "--- Ввод данных Бесхозной сумки ---\n";
    DetectedObject::inputInfo();
    std::cout << "  Введите время первого обнаружения (секунды после полуночи): "; std::cin >> detectedTimeSeconds;
    std::cin.ignore(256, '\n');
}