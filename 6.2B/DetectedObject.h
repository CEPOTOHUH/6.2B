#pragma once

#include <iostream>
#include <limits>

class DetectedObject {
public:
    struct Coordinates {
        int Xmin, Ymin, Xmax, Ymax;

        Coordinates();
        Coordinates(int x1, int y1, int x2, int y2);
    };

protected:
    Coordinates coordinates;

public:
    DetectedObject();
    DetectedObject(int x1, int y1, int x2, int y2);
    virtual ~DetectedObject() = default;
    DetectedObject(const DetectedObject& other) = default;
    DetectedObject& operator=(const DetectedObject& other) = default;
    DetectedObject(DetectedObject&& other) noexcept = default;
    DetectedObject& operator=(DetectedObject&& other) noexcept = default;

    virtual DetectedObject* clone() const = 0; // Чистый виртуальный метод для глубокого копирования

    virtual void print(std::ostream& os) const;
    virtual void inputInfo();

    virtual void setXmin(int x);
    virtual int getXmin() const;

    virtual void setYmin(int y);
    virtual int getYmin() const;

    virtual void setXmax(int x);
    virtual int getXmax() const;

    virtual void setYmax(int y);
    virtual int getYmax() const;

    virtual void setCoordinates(int x1, int y1, int x2, int y2);
    virtual Coordinates getCoordinates() const;
};
std::ostream& operator<<(std::ostream& os, const DetectedObject& obj);