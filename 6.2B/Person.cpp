#include "Person.h"
#include <iostream>

// ���������� ������� Person
Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}
Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2) {
    setGender(g);
    setChildStatus(c);
    setGlassesStatus(gl);
    setBeardStatus(b);
}
void Person::print(std::ostream& os) const {
    os << "--- ������� ---\n";
    DetectedObject::print(os);
    os << "  ��� (0=���, 1=���, 2=�� ���.): " << gender << "\n";
    os << "  ������ (0=��, 1=���, 2=�� ���.): " << childStatus << "\n";
    os << "  ���� (0=����, 1=���, 2=�� ���.): " << glassesStatus << "\n";
    os << "  ������ (0=����, 1=���, 2=�� ���.): " << beardStatus << "\n";
}

void Person::inputInfo() {
    std::cout << "--- ���� ������ �������� ---\n";
    DetectedObject::inputInfo();

    std::cout << "  ������� ��� (0=���, 1=���, 2=�� ���.): ";
    int tempGender;
    while (!(std::cin >> tempGender) || tempGender < 0 || tempGender > 2) {
        std::cout << "������: ������� ����� �� 0 �� 2 ��� ����: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGender(tempGender);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  ������� ������ ������ (0=��, 1=���, 2=�� ���.): ";
    int tempChildStatus;
    while (!(std::cin >> tempChildStatus) || tempChildStatus < 0 || tempChildStatus > 2) {
        std::cout << "������: ������� ����� �� 0 �� 2 ��� ������� ������: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setChildStatus(tempChildStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  ������� ������ ����� (0=����, 1=���, 2=�� ���.): ";
    int tempGlassesStatus;
    while (!(std::cin >> tempGlassesStatus) || tempGlassesStatus < 0 || tempGlassesStatus > 2) {
        std::cout << "������: ������� ����� �� 0 �� 2 ��� ������� �����: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGlassesStatus(tempGlassesStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  ������� ������ ������ (0=����, 1=���, 2=�� ���.): ";
    int tempBeardStatus;
    while (!(std::cin >> tempBeardStatus) || tempBeardStatus < 0 || tempBeardStatus > 2) {
        std::cout << "������: ������� ����� �� 0 �� 2 ��� ������� ������: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setBeardStatus(tempBeardStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Person::setGender(int g) {
    if (g >= 0 && g <= 2) {
        gender = g;
    }
    else {
        std::cerr << "�������� �������� ��� ���� (" << g << "). ��������� (0, 1, 2). �������� �� ��������.\n";
    }
}
int Person::getGender() const { return gender; }

void Person::setChildStatus(int c) {
    if (c >= 0 && c <= 2) {
        childStatus = c;
    }
    else {
        std::cerr << "�������� �������� ��� ������� ������� (" << c << "). ��������� (0, 1, 2). �������� �� ��������.\n";
    }
}
int Person::getChildStatus() const { return childStatus; }

void Person::setGlassesStatus(int gl) {
    if (gl >= 0 && gl <= 2) {
        glassesStatus = gl;
    }
    else {
        std::cerr << "�������� �������� ��� ������� ����� (" << gl << "). ��������� (0, 1, 2). �������� �� ��������.\n";
    }
}
int Person::getGlassesStatus() const { return glassesStatus; }

void Person::setBeardStatus(int b) {
    if (b >= 0 && b <= 2) {
        beardStatus = b;
    }
    else {
        std::cerr << "�������� �������� ��� ������� ������ (" << b << "). ��������� (0, 1, 2). �������� �� ��������.\n";
    }
}
int Person::getBeardStatus() const { return beardStatus; }