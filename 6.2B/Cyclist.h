#pragma once
#include "person.h"

class Cyclist : public Person {
public:
    Cyclist();
    Cyclist(int x1, int y1, int x2, int y2, int gender, int childStatus, int glassesStatus, int beardStatus);

    Person* clone() const override;
    void print(std::ostream& os) const override;
    void inputInfo() override;
};