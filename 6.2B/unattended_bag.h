#pragma once
#include "detected_object.h"

class UnattendedBag : public DetectedObject {
public:
    UnattendedBag();
    UnattendedBag(int x1, int y1, int x2, int y2, int confidence);
    Person* clone() const override; 
    void print(std::ostream& os) const override;
    void inputInfo() override;
};