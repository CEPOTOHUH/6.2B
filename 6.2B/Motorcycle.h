#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate);
    ~Motorcycle() override = default; 

    Motorcycle(const Motorcycle& other);
    Motorcycle& operator=(const Motorcycle& other);
    Motorcycle(Motorcycle&& other) noexcept;
    Motorcycle& operator=(Motorcycle&& other) noexcept;

    DetectedObject* clone() const override; 
    void print(std::ostream& os) const override;
    void inputInfo() override;
};