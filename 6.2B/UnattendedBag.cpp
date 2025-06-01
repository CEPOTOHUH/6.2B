#include "UnattendedBag.h"
#include <iostream>

// Реализация методов UnattendedBag
UnattendedBag::UnattendedBag() : DetectedObject(), detectedTimeSeconds(0) {}

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, long long time)
    : DetectedObject(x1, y1, x2, y2) {
    setDetectedTimeSeconds(time);
}

void UnattendedBag::print(std::ostream& os) const {
    os << "--- Бесхозная сумка ---\n";
    DetectedObject::print(os);
    os << "  Время первого обнаружения (секунды после полуночи): " << detectedTimeSeconds << "\n";
}

void UnattendedBag::inputInfo() {
    std::cout << "--- Ввод данных Бесхозной сумки ---\n";
    DetectedObject::inputInfo();
    std::cout << "  Введите время первого обнаружения (секунды после полуночи, 0-86399): ";
    long long tempTime;
    while (!(std::cin >> tempTime) || tempTime < 0 || tempTime > 86399) {
        std::cout << "Ошибка: Введите число от 0 до 86399 для времени: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setDetectedTimeSeconds(tempTime);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UnattendedBag::setDetectedTimeSeconds(long long time) {
    if (time >= 0 && time <= 86399) {
        detectedTimeSeconds = time;
    }
    else {
        std::cerr << "Ошибка: Некорректное время обнаружения (" << time << "). Допустимо (0-86399). Значение не изменено.\n";
    }
}
long long UnattendedBag::getDetectedTimeSeconds() const { return detectedTimeSeconds; }