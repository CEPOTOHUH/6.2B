#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <limits>
#include <clocale>
#include <cstring> 
#include "DetectedObject.h"
#include "Person.h"
#include "Cyclist.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "UnattendedBag.h"
#include "object_database.h" 

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntInput(const char* prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= minVal && value <= maxVal) {
            clearInputBuffer();
            return value;
        }
        else {
            std::cout << "������: ������������ ����. ����������, ������� ����� �� " << minVal << " �� " << maxVal << ".\n";
            std::cin.clear();
            clearInputBuffer();
        }
    }
}
void getCharInput(const char* prompt, char* buffer, size_t bufferSize) {
    std::cout << prompt;
    std::cin.getline(buffer, bufferSize);
}
void interactiveDatabaseMenu() {
    ObjectDatabase db;
    int choice;

    do {
        std::cout << "\n--- ���� ���������� ����� ������ �������� ---\n";
        std::cout << "1. �������� ������\n";
        std::cout << "2. ������� ������ �� �������\n";
        std::cout << "3. �������� ��� �������\n";
        std::cout << "4. �������� ���� ������\n";
        std::cout << "5. �������� ������ ���� ������\n";
        std::cout << "6. ���������, ����� �� ���� ������\n";
        std::cout << "0. ����� �� ����\n";

        choice = getIntInput("�������� ��������: ", 0, 6);

        switch (choice) {
        case 1: {
            std::cout << "\n�������� ��� ������� ��� ����������:\n";
            std::cout << "1. �������\n";
            std::cout << "2. ������������\n";
            std::cout << "3. ����������\n";
            std::cout << "4. ��������\n";
            std::cout << "5. ��������� �����\n";
            int objType = getIntInput("��� �����: ", 1, 5);
            DetectedObject* newObj = nullptr; 

            switch (objType) {
            case 1: newObj = new Person(); break;
            case 2: newObj = new Cyclist(); break;
            case 3: newObj = new Car(); break;
            case 4: newObj = new Motorcycle(); break;
            case 5: newObj = new UnattendedBag(); break;
            default: break;
            }

            if (newObj) {
                newObj->inputInfo(); 
                db.add(newObj); 
                delete newObj; 
                std::cout << "������ ������� ��������.\n";
            }
            else {
                std::cout << "����������� ��� �������.\n";
            }
            break;
        }
        case 2: {
            if (db.isEmpty()) {
                std::cout << "���� ������ �����, ������ �������.\n";
                break;
            }
            size_t indexToRemove = getIntInput("������� ������ ������� ��� �������� (������� � 0): ", 0, db.getSize() - 1);
            db.remove(indexToRemove);
            std::cout << "������ �� ������� " << indexToRemove << " ������.\n";
            break;
        }
        case 3:
            db.printAll();
            break;
        case 4:
            db.clear();
            std::cout << "���� ������ �������.\n";
            break;
        case 5:
            std::cout << "������� ������ ���� ������: " << db.getSize() << "\n";
            break;
        case 6:
            std::cout << "���� ������ " << (db.isEmpty() ? "�����" : "�� �����") << ".\n";
            break;
        case 0:
            std::cout << "����� �� ���� ���� ������.\n";
            break;
        default:
            break;
        }
    } while (choice != 0);
}


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "������������ ������ ������������� ������� �������� � ��������� ������� � ������ ������.\n\n";
    interactiveDatabaseMenu();

    std::cout << "\n��������� ���������.\n";

    return 0;
}