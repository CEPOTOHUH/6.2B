#include "Person.h"

Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}

Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2), gender(g), childStatus(c), glassesStatus(gl), beardStatus(b) {
}

DetectedObject* Person::clone() const {
    return new Person(*this);
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
    std::cout << "  ������� ��� (0=���, 1=���, 2=�� ���.): "; std::cin >> gender;
    std::cout << "  ������� ������ ������ (0=��, 1=���, 2=�� ���.): "; std::cin >> childStatus;
    std::cout << "  ������� ������ ����� (0=����, 1=���, 2=�� ���.): "; std::cin >> glassesStatus;
    std::cout << "  ������� ������ ������ (0=����, 1=���, 2=�� ���.): "; std::cin >> beardStatus;
    std::cin.ignore(256, '\n');
}