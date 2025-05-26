#include "DetectedObject.h"

DetectedObject::Coordinates::Coordinates() : Xmin(0), Ymin(0), Xmax(0), Ymax(0) {}
DetectedObject::Coordinates::Coordinates(int x1, int y1, int x2, int y2)
    : Xmin(x1), Ymin(y1), Xmax(x2), Ymax(y2) {
}

DetectedObject::DetectedObject() : coordinates() {}
DetectedObject::DetectedObject(int x1, int y1, int x2, int y2)
    : coordinates(x1, y1, x2, y2) {
}

// DetectedObject::~DetectedObject() = default; // ��� ������ ����� �������!

// ����������� �����������
DetectedObject::DetectedObject(const DetectedObject& other) = default;

// �������� ������������ ������������
DetectedObject& DetectedObject::operator=(const DetectedObject& other) = default;

// ����������� �����������
DetectedObject::DetectedObject(DetectedObject&& other) noexcept = default;

// �������� ������������ ������������
DetectedObject& DetectedObject::operator=(DetectedObject&& other) noexcept = default;

// ����� ��� �������� ����� ������� � ���� (��� ������������ �����������)
DetectedObject* DetectedObject::clone() const {
    return new DetectedObject(*this);
}

void DetectedObject::print(std::ostream& os) const {
    os << "  ����������: (" << coordinates.Xmin << ", " << coordinates.Ymin
        << ") - (" << coordinates.Xmax << ", " << coordinates.Ymax << ")\n";
}

void DetectedObject::inputInfo() {
    std::cout << "  ������� Xmin: "; std::cin >> coordinates.Xmin;
    std::cout << "  ������� Ymin: "; std::cin >> coordinates.Ymin;
    std::cout << "  ������� Xmax: "; std::cin >> coordinates.Xmax;
    std::cout << "  ������� Ymax: "; std::cin >> coordinates.Ymax;
    std::cin.ignore(256, '\n');
}

std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
    obj.print(os);
    return os;
}