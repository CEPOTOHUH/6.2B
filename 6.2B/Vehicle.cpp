#include "vehicle.h"
#include <iostream>
#include <cstring>  

void Vehicle::copyPlate(const char* p) {
    if (p) {
        size_t len = 0;
        while (p[len] != '\0') {
            len++;
        }
        plate = new char[len + 1];
        for (size_t i = 0; i <= len; ++i) {
            plate[i] = p[i];
        }
    }
    else {
        plate = nullptr;
    }
}

void Vehicle::deletePlate() {
    if (plate) {
        delete[] plate;
        plate = nullptr;
    }
}

Vehicle::Vehicle() : Person(), color(0), plate(nullptr) {}

Vehicle::Vehicle(int x1_val, int y1_val, int x2_val, int y2_val, int color_val, const char* plate_val)
    : Person(x1_val, y1_val, x2_val, y2_val, 0, 0, 0, 0), color(color_val), plate(nullptr) {
    copyPlate(plate_val);
}

Vehicle::~Vehicle() {
    deletePlate();
}

Vehicle::Vehicle(const Vehicle& other)
    : Person(other), color(other.color), plate(nullptr) {
    copyPlate(other.plate);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        Person::operator=(other);
        deletePlate();
        color = other.color;
        copyPlate(other.plate);
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : Person(static_cast<Person&&>(other)), color(other.color), plate(other.plate)
{
    other.color = 0;
    other.plate = nullptr;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
    if (this != &other) {
        Person::operator=(static_cast<Person&&>(other));
        deletePlate();
        color = other.color; other.color = 0;
        plate = other.plate; other.plate = nullptr;
    }
    return *this;
}

Person* Vehicle::clone() const {
    return new Vehicle(*this);
}

void Vehicle::print(std::ostream& os) const {
    os << "  Координаты: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")\n";
    os << "  Цвет: " << color << "\n";
    os << "  Номерной знак: " << (plate ? plate : "N/A") << "\n";
}

void Vehicle::inputInfo() {
    bool validInput = false;
    do {
        std::cout << "Введите координаты (x1 y1 x2 y2). x1 < x2 и y1 < y2: ";
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (std::cin.fail() || x1 >= x2 || y1 >= y2) {
            std::cout << "Некорректные координаты. Пожалуйста, убедитесь, что x1 < x2 и y1 < y2 и вводите числа.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);

    validInput = false;
    do {
        std::cout << "Введите цвет (целое число, например, 1-Красный, 2-Синий и т.д.): ";
        std::cin >> color;
        if (std::cin.fail() || color < 1 || color > 100) { 
            std::cout << "Некорректный цвет. Введите число от 1 до 100.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF);

    validInput = false;
    do {
        std::cout << "Введите номерной знак (строка, без пробелов, макс 255 символов): ";
        char temp_plate_buffer[256];
        std::cin >> temp_plate_buffer;
        bool hasSpace = false;
        size_t len = 0;
        while (temp_plate_buffer[len] != '\0') {
            if (temp_plate_buffer[len] == ' ') {
                hasSpace = true;
                break;
            }
            len++;
        }

        if (hasSpace || len == 0 || len > 255) {
            std::cout << "Некорректный номерной знак. Он не должен содержать пробелов и быть не пустым.\n";
        }
        else {
            deletePlate();
            copyPlate(temp_plate_buffer);
            validInput = true;
        }
    } while (!validInput);
}

int Vehicle::getColor() const { return color; }
const char* Vehicle::getPlate() const { return plate; }

void Vehicle::setColor(int c) { color = c; }
void Vehicle::setPlate(const char* p) {
    deletePlate();
    copyPlate(p);
}