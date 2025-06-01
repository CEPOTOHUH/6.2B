#pragma once

#include "Vehicle.h" // ������������ �� Vehicle

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate);
    ~Motorcycle() override = default;
    Motorcycle(const Motorcycle& other) = default;
    Motorcycle& operator=(const Motorcycle& other) = default;
    Motorcycle(Motorcycle&& other) noexcept = default;
    Motorcycle& operator=(Motorcycle&& other) noexcept = default;

    DetectedObject* clone() const override { // ���������� DetectedObject*
        return new Motorcycle(*this);
    }

    void print(std::ostream& os) const override;
    void inputInfo() override;
};