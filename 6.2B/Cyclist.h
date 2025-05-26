#pragma once
#include "Person.h"

class Cyclist : public Person {
public:
    Cyclist();
    Cyclist(int x1, int y1, int x2, int y2,
        int g, int c, int gl, int b);
    ~Cyclist() override = default; 

    Cyclist(const Cyclist& other);
    Cyclist& operator=(const Cyclist& other);
    Cyclist(Cyclist&& other) noexcept;
    Cyclist& operator=(Cyclist&& other) noexcept;

    DetectedObject* clone() const override; 
    void print(std::ostream& os) const override;
    void inputInfo() override;
};