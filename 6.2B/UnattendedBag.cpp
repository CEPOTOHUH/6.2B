#include "UnattendedBag.h"

UnattendedBag::UnattendedBag() : DetectedObject(), detectedTimeSeconds(0) {}

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, long long time)
    : DetectedObject(x1, y1, x2, y2), detectedTimeSeconds(time) {
}
UnattendedBag::UnattendedBag(const UnattendedBag& other) = default;
UnattendedBag& UnattendedBag::operator=(const UnattendedBag& other) = default;
UnattendedBag::UnattendedBag(UnattendedBag&& other) noexcept = default;
UnattendedBag& UnattendedBag::operator=(UnattendedBag&& other) noexcept = default;

DetectedObject* UnattendedBag::clone() const { 
    return new UnattendedBag(*this);
}

void UnattendedBag::print(std::ostream& os) const { 
    os << "--- ��������� ����� ---\n";
    DetectedObject::print(os);
    os << "  ����� ������� ����������� (������� ����� ��������): " << detectedTimeSeconds << "\n";
}

void UnattendedBag::inputInfo() { 
    std::cout << "--- ���� ������ ��������� ����� ---\n";
    DetectedObject::inputInfo();
    std::cout << "  ������� ����� ������� ����������� (������� ����� ��������): "; std::cin >> detectedTimeSeconds;
    std::cin.ignore(256, '\n');
}