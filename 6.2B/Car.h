#pragma once
#include "vehicle.h"

class Car : public Vehicle {
public:
    Car();
    Car(int x1, int y1, int x2, int y2, int color, const char* plate);
    Person* clone() const override;
    void print(std::ostream& os) const override;
    void inputInfo() override;
};