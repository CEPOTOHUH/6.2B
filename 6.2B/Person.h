#pragma once

#include "DetectedObject.h" // Наследование от DetectedObject

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

    DetectedObject* clone() const override {
        return new Person(*this);
    }

    void print(std::ostream& os) const override;
    void inputInfo() override;

    void setGender(int g);
    int getGender() const;

    void setChildStatus(int c);
    int getChildStatus() const;

    void setGlassesStatus(int gl);
    int getGlassesStatus() const;

    void setBeardStatus(int b);
    int getBeardStatus() const;
};