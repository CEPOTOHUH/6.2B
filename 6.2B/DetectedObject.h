#pragma once
#include <iostream> // Для std::cout, std::cin, std::ostream

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

    // Конструктор копирования
    DetectedObject(const DetectedObject& other);
    // Оператор присваивания копированием
    DetectedObject& operator=(const DetectedObject& other);

    // Конструктор перемещения
    DetectedObject(DetectedObject&& other) noexcept;
    // Оператор присваивания перемещением
    DetectedObject& operator=(DetectedObject&& other) noexcept;

    // Метод для создания копии объекта в куче (для полиморфного копирования)
    virtual DetectedObject* clone() const;
    virtual void print(std::ostream& os) const;
    virtual void inputInfo();
};

// Перегрузка оператора << для вывода информации об объекте
std::ostream& operator<<(std::ostream& os, const DetectedObject& obj);