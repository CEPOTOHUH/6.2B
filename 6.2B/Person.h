#pragma once
#include "DetectedObject.h" 

class Person : public DetectedObject {
private:
    int gender;
    int childStatus;
    int glassesStatus;
    int beardStatus;

public:
    Person();
    Person(int x1, int y1, int x2, int y2,
        int g, int c, int gl, int b);
    ~Person() override = default;
    Person(const Person& other) = default;
    Person& operator=(const Person& other) = default;
    Person(Person&& other) noexcept = default;
    Person& operator=(Person&& other) noexcept = default;
 //виртуальные функции
    DetectedObject* clone() const override;
    void print(std::ostream& os) const override;
    void inputInfo() override;
};