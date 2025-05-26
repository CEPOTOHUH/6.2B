#pragma once
#include "DetectedObject.h"

class UnattendedBag : public DetectedObject {
private:
    long long detectedTimeSeconds;

public:
    UnattendedBag();
    UnattendedBag(int x1, int y1, int x2, int y2, long long time);
    ~UnattendedBag() override = default; 

    UnattendedBag(const UnattendedBag& other);
    UnattendedBag& operator=(const UnattendedBag& other);
    UnattendedBag(UnattendedBag&& other) noexcept;
    UnattendedBag& operator=(UnattendedBag&& other) noexcept;

    DetectedObject* clone() const override; 
    void print(std::ostream& os) const override;
    void inputInfo() override;
};