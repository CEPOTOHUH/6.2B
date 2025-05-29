#include "detected_object.h"
#include <iostream>

DetectedObject::DetectedObject() : Person(), detectionConfidence(0) {}

DetectedObject::DetectedObject(int x1_val, int y1_val, int x2_val, int y2_val, int confidence_val)
    : Person(x1_val, y1_val, x2_val, y2_val, 0, 0, 0, 0), detectionConfidence(confidence_val) {
}

void DetectedObject::print(std::ostream& os) const {
    os << "  ����������: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")\n";
    os << "  ����������� �����������: " << detectionConfidence << "%\n";
}

void DetectedObject::inputInfo() {
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
        std::cout << "������� ����������� ����������� (0-100%): ";
        std::cin >> detectionConfidence;
        if (std::cin.fail() || detectionConfidence < 0 || detectionConfidence > 100) {
            std::cout << "������������ �������� �����������. ������� ����� �� 0 �� 100.\n";
            std::cin.clear();
            int c;
            while ((c = std::cin.get()) != '\n' && c != EOF);
        }
        else {
            validInput = true;
        }
    } while (!validInput);
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF);
}

int DetectedObject::getDetectionConfidence() const { return detectionConfidence; }
void DetectedObject::setDetectionConfidence(int confidence) { detectionConfidence = confidence; }