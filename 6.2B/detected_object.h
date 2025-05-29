#pragma once
#include "person.h" 

class DetectedObject : public Person {
protected:
    int detectionConfidence; 

public:
    DetectedObject();
    DetectedObject(int x1, int y1, int x2, int y2, int confidence);
    Person* clone() const override = 0; 
    void print(std::ostream& os) const override;
    void inputInfo() override;

    int getDetectionConfidence() const;
    void setDetectionConfidence(int confidence);
};