#include "DetectedObject.h"
#include <iostream>
DetectedObject::Coordinates::Coordinates() : Xmin(0), Ymin(0), Xmax(0), Ymax(0) {}
DetectedObject::Coordinates::Coordinates(int x1, int y1, int x2, int y2)
    : Xmin(x1), Ymin(y1), Xmax(x2), Ymax(y2) {
}

// ���������� ������� DetectedObject
DetectedObject::DetectedObject() : coordinates() {}
DetectedObject::DetectedObject(int x1, int y1, int x2, int y2)
    : coordinates(x1, y1, x2, y2) {
}

void DetectedObject::print(std::ostream& os) const {
    os << "  ����������: (" << coordinates.Xmin << ", " << coordinates.Ymin
        << ") - (" << coordinates.Xmax << ", " << coordinates.Ymax << ")\n";
}

void DetectedObject::inputInfo() {
    std::cout << "  ������� Xmin: ";
    while (!(std::cin >> coordinates.Xmin) || coordinates.Xmin < 0) {
        std::cout << "������: ������� ��������������� ����� ��� Xmin: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "  ������� Ymin: ";
    while (!(std::cin >> coordinates.Ymin) || coordinates.Ymin < 0) {
        std::cout << "������: ������� ��������������� ����� ��� Ymin: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "  ������� Xmax: ";
    while (!(std::cin >> coordinates.Xmax) || coordinates.Xmax < coordinates.Xmin) {
        std::cout << "������: ������� ����� ��� Xmax, �� ������ Xmin (" << coordinates.Xmin << "): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "  ������� Ymax: ";
    while (!(std::cin >> coordinates.Ymax) || coordinates.Ymax < coordinates.Ymin) {
        std::cout << "������: ������� ����� ��� Ymax, �� ������ Ymin (" << coordinates.Ymin << "): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void DetectedObject::setXmin(int x) {
    if (x >= 0) coordinates.Xmin = x;
    else std::cerr << "������: Xmin �� ����� ���� �������������. �������� �� ��������.\n";
}
int DetectedObject::getXmin() const { return coordinates.Xmin; }

void DetectedObject::setYmin(int y) {
    if (y >= 0) coordinates.Ymin = y;
    else std::cerr << "������: Ymin �� ����� ���� �������������. �������� �� ��������.\n";
}
int DetectedObject::getYmin() const { return coordinates.Ymin; }

void DetectedObject::setXmax(int x) {
    if (x >= coordinates.Xmin) coordinates.Xmax = x;
    else std::cerr << "������: Xmax �� ����� ���� ������ Xmin. �������� �� ��������.\n";
}
int DetectedObject::getXmax() const { return coordinates.Xmax; }

void DetectedObject::setYmax(int y) {
    if (y >= coordinates.Ymin) coordinates.Ymax = y;
    else std::cerr << "������: Ymax �� ����� ���� ������ Ymin. �������� �� ��������.\n";
}
int DetectedObject::getYmax() const { return coordinates.Ymax; }

void DetectedObject::setCoordinates(int x1, int y1, int x2, int y2) {
    if (x1 >= 0 && y1 >= 0 && x2 >= x1 && y2 >= y1) {
        coordinates.Xmin = x1;
        coordinates.Ymin = y1;
        coordinates.Xmax = x2;
        coordinates.Ymax = y2;
    }
    else {
        std::cerr << "������: ������������ ���������� (Xmin,Ymin ������ ���� >=0, Xmax>=Xmin, Ymax>=Ymin). �������� �� ��������.\n";
    }
}
DetectedObject::Coordinates DetectedObject::getCoordinates() const {
    return coordinates;
}

std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
    obj.print(os);
    return os;
}