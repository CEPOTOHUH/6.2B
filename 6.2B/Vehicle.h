#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "DetectedObject.h" // Наследование от DetectedObject
#include <cstring> 

class Vehicle : public DetectedObject {
protected:
    int colorRGB;
    char* licensePlate;
    size_t licensePlateLength;
    size_t licensePlateCapacity;

public:
    Vehicle();
    Vehicle(int x1, int y1, int x2, int y2, int color, const char* plate);
    virtual ~Vehicle() override;
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;

    DetectedObject* clone() const override { 
        return new Vehicle(*this);
    }

    void print(std::ostream& os) const override;
    void inputInfo() override;

    void setLicensePlate(const char* newPlate);
    const char* getLicensePlate() const;

    void setColorRGB(int color);
    int getColorRGB() const;
};