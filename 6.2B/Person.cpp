#include "person.h"
#include <iostream>

Person::Person() : x1(0), y1(0), x2(0), y2(0), gender(0), childStatus(0), glassesStatus(0), beardStatus(0) {}

Person::Person(int x1_val, int y1_val, int x2_val, int y2_val, int gender_val, int childStatus_val, int glassesStatus_val, int beardStatus_val)
    : x1(x1_val), y1(y1_val), x2(x2_val), y2(y2_val), gender(gender_val), childStatus(childStatus_val), glassesStatus(glassesStatus_val), beardStatus(beardStatus_val) {
}

Person::~Person() {}

Person::Person(const Person& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
    gender(other.gender), childStatus(other.childStatus),
    glassesStatus(other.glassesStatus), beardStatus(other.beardStatus) {
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        gender = other.gender;
        childStatus = other.childStatus;
        glassesStatus = other.glassesStatus;
        beardStatus = other.beardStatus;
    }
    return *this;
}

Person::Person(Person&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
    gender(other.gender), childStatus(other.childStatus),
    glassesStatus(other.glassesStatus), beardStatus(other.beardStatus)
{
    other.x1 = 0; other.y1 = 0; other.x2 = 0; other.y2 = 0;
    other.gender = 0; other.childStatus = 0; other.glassesStatus = 0; other.beardStatus = 0;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        x1 = other.x1; other.x1 = 0;
        y1 = other.y1; other.y1 = 0;
        x2 = other.x2; other.x2 = 0;
        y2 = other.y2; other.y2 = 0;
        gender = other.gender; other.gender = 0;
        childStatus = other.childStatus; other.childStatus = 0;
        glassesStatus = other.glassesStatus; other.glassesStatus = 0;
        beardStatus = other.beardStatus; other.beardStatus = 0;
    }
    return *this;
}

void Person::print(std::ostream& os) const {
    os << "  ����������: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")\n";
    os << "  ���: " << (gender == 0 ? "�������" : "�������") << "\n";
    os << "  ������: " << (childStatus == 0 ? "��������" : "�������") << "\n";
    os << "  ����: " << (glassesStatus == 0 ? "���" : "��") << "\n";
    if (gender == 0) {
        os << "  ������: " << (beardStatus == 0 ? "���" : "��") << "\n";
    }
}

void Person::inputInfo() {
    bool validInput = false;
    do {
        std::cout << "������� ���������� (x1 y1 x2 y2). x1 < x2 � y1 < y2: ";
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (std::cin.fail() || x1 >= x2 || y1 >= y2) {
            std::cout << "������������ ����������. ����������, ���������, ��� x1 < x2 � y1 < y2 � ������� �����.\n";
            std::cin.clear(); 
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);

    validInput = false;
    do {
        std::cout << "������� ��� (0-�������, 1-�������): ";
        std::cin >> gender;
        if (std::cin.fail() || (gender != 0 && gender != 1)) {
            std::cout << "������������ ���. ������� 0 ��� 1.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);

    validInput = false;
    do {
        std::cout << "������� ������ (0-��������, 1-�������): ";
        std::cin >> childStatus;
        if (std::cin.fail() || (childStatus != 0 && childStatus != 1)) {
            std::cout << "������������ ������. ������� 0 ��� 1.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);

    validInput = false;
    do {
        std::cout << "������� ����� (0-���, 1-��): ";
        std::cin >> glassesStatus;
        if (std::cin.fail() || (glassesStatus != 0 && glassesStatus != 1)) {
            std::cout << "������������ ��������. ������� 0 ��� 1.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);

    if (gender == 0) { // ������ ��� ������
        validInput = false;
        do {
            std::cout << "������� ������ (0-���, 1-��): ";
            std::cin >> beardStatus;
            if (std::cin.fail() || (beardStatus != 0 && beardStatus != 1)) {
                std::cout << "������������ ��������. ������� 0 ��� 1.\n";
                std::cin.clear();
                int c;
                while ((c = std::cin.get()) != '\n' && c != EOF);
            }
            else {
                validInput = true;
            }
        } while (!validInput);
    }
    else {
        beardStatus = 0; 
    }
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF);
}

int Person::getX1() const { return x1; }
int Person::getY1() const { return y1; }
int Person::getX2() const { return x2; }
int Person::getY2() const { return y2; }
int Person::getGender() const { return gender; }
int Person::getChildStatus() const { return childStatus; }
int Person::getGlassesStatus() const { return glassesStatus; }
int Person::getBeardStatus() const { return beardStatus; }

void Person::setX1(int x) { x1 = x; }
void Person::setY1(int y) { y1 = y; }
void Person::setX2(int x) { x2 = x; }
void Person::setY2(int y) { y2 = y; }
void Person::setGender(int g) { gender = g; }
void Person::setChildStatus(int c) { childStatus = c; }
void Person::setGlassesStatus(int gl) { glassesStatus = gl; }
void Person::setBeardStatus(int b) { beardStatus = b; }