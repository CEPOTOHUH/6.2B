#include "DetectedObjectRegistry.h"
#include "Person.h"
#include "Cyclist.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "UnattendedBag.h"
#include <locale> 

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "������������ �������� ������� � �������������� ����� ���������� � ������ ����������� ������������ �������� (� ������ �������� ����):\n\n";

    DetectedObjectRegistry objectCollection;
    char choice;

    while (true) {
        std::cout << "\n--- ���� ���������� ��������� ---\n";
        std::cout << "1. �������� ����� ������\n";
        std::cout << "2. ����������� ��� �������\n";
        std::cout << "3. ������� ������ �� �������\n";
        std::cout << "4. �������� ���� ������\n";
        std::cout << "0. �����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;
        std::cin.ignore(256, '\n');

        switch (choice) {
        case '1': {
            std::cout << "\n�������� ��� ������� ��� ����������:\n";
            std::cout << "1. �������\n";
            std::cout << "2. ������������\n";
            std::cout << "3. ����������\n";
            std::cout << "4. ��������\n";
            std::cout << "5. ��������� �����\n";
            std::cout << "��� �����: ";
            char objectType;
            std::cin >> objectType;
            std::cin.ignore(256, '\n');

            DetectedObject* newObject = nullptr;
            switch (objectType) {
            case '1': newObject = new Person(); break;
            case '2': newObject = new Cyclist(); break;
            case '3': newObject = new Car(); break;
            case '4': newObject = new Motorcycle(); break;
            case '5': newObject = new UnattendedBag(); break;
            default:
                std::cout << "�������� ����� ���� �������.\n";
                break;
            }

            if (newObject) {
                inputObjectInfo(newObject);
                objectCollection.addObject(newObject); 
            }
            break;
        }
        case '2': {
            objectCollection.displayAllObjects();
            break;
        }
        case '3': {
            if (objectCollection.getObjectCount() == 0) {
                std::cout << "������ ����, ��� �������� ��� ��������.\n";
                break;
            }
            std::cout << "������� ������ ������� ��� ��������: ";
            size_t indexToDelete;
            std::cin >> indexToDelete;
            std::cin.ignore(256, '\n');
            objectCollection.removeObject(indexToDelete);
            break;
        }
        case '4': {
            objectCollection.clearRegistry();
            break;
        }
        case '0': {
            std::cout << "����� �� ���������.\n";
            return 0;
        }
        default: {
            std::cout << "�������� �����. ����������, ���������� �����.\n";
            break;
        }
        }
    }

    return 0;
}