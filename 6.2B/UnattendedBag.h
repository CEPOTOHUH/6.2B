#pragma once

#include "DetectedObject.h" // Наследование от DetectedObject

class UnattendedBag : public DetectedObject {
private:
    long long detectedTimeSeconds;

public:
    UnattendedBag();
    UnattendedBag(int x1, int y1, int x2, int y2, long long time);
    ~UnattendedBag() override = default;
    UnattendedBag(const UnattendedBag& other) = default;
    UnattendedBag& operator=(const UnattendedBag& other) = default;
    UnattendedBag(UnattendedBag&& other) noexcept = default;
    UnattendedBag& operator=(UnattendedBag&& other) noexcept = default;

    DetectedObject* clone() const override { 
        return new UnattendedBag(*this);
    }

    void print(std::ostream& os) const override;
    void inputInfo() override;

    void setDetectedTimeSeconds(long long time);
    long long getDetectedTimeSeconds() const;
};