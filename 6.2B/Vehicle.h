#pragma once
#include "person.h"
#include <iostream>

class Vehicle : public Person {
protected:
    int color;
    char* plate;

public:
    Vehicle();
    Vehicle(int x1, int y1, int x2, int y2, int color, const char* plate);

    ~Vehicle() override;
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;

    Person* clone() const override;

    void print(std::ostream& os) const override;
    void inputInfo() override;

    int getColor() const;
    const char* getPlate() const;

    void setColor(int c);
    void setPlate(const char* p);

private:
    void copyPlate(const char* p);
    void deletePlate();
};