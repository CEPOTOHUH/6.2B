#pragma once
#include <iostream>

class Person {
protected:
    int x1, y1, x2, y2;
    int gender;
    int childStatus;
    int glassesStatus;
    int beardStatus;

public:
    Person();
    Person(int x1, int y1, int x2, int y2, int gender, int childStatus, int glassesStatus, int beardStatus);

    virtual ~Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    Person(Person&& other) noexcept;
    Person& operator=(Person&& other) noexcept;

    virtual Person* clone() const = 0;

    virtual void print(std::ostream& os) const;
    virtual void inputInfo();

    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;
    int getGender() const;
    int getChildStatus() const;
    int getGlassesStatus() const;
    int getBeardStatus() const;

    void setX1(int x);
    void setY1(int y);
    void setX2(int x);
    void setY2(int y);
    void setGender(int g);
    void setChildStatus(int c);
    void setGlassesStatus(int gl);
    void setBeardStatus(int b);
};