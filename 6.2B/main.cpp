#include <iostream>
#include <clocale> // ��� setlocale

#include "object_database.h"
#include "cyclist.h"
#include "motorcycle.h"
#include "detected_object.h"
#include "unattended_bag.h"
#include "car.h"
#include "person.h"

// ��������������� ������� ��� ������� ������ �����
void clearInputBuffer() {
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF);
}
void createAndAddObject(ObjectDatabase& db) {
    std::cout << "\n�������� ��� ������� ��� ����������:\n";
    std::cout << "1. ������������\n";
    std::cout << "2. ��������\n";
    std::cout << "3. ��������� �����\n";
    std::cout << "4. ����������\n";
    std::cout << "������� �����: ";
    int type_choice;
    std::cin >> type_choice;
    clearInputBuffer(); 

    Person* newObj = nullptr;

    switch (type_choice) {
    case 1:
        newObj = new Cyclist();
        break;
    case 2:
        newObj = new Motorcycle();
        break;
    case 3:
        newObj = new UnattendedBag();
        break;
    case 4:
        newObj = new Car();
        break;
    default:
        std::cout << "�������� ��� �������. ���������� �����.\n";
        return;
    }

    if (newObj) {
        newObj->inputInfo(); 
        db.add(newObj);     
        delete newObj;       
        std::cout << "������ ������� ��������.\n";
    }
}

void removeObjectByIndex(ObjectDatabase& db) {
    if (db.isEmpty()) {
        std::cout << "���� ������ �����, ��� �������� ��� ��������.\n";
        return;
    }

    std::cout << "������� ������ ������� ��� �������� (�� 0 �� " << db.getSize() - 1 << "): ";
    size_t index;
    std::cin >> index;
    clearInputBuffer();

    if (index < db.getSize()) {
        db.remove(index);
        std::cout << "������ �� ������� " << index << " ������� ������.\n";
    }
    else {
        std::cout << "�������� ������. ������ �� ������.\n";
    }
}

void runObjectDatabaseInteractiveTest() {
    ObjectDatabase my_database;
    int choice;

    do {
        std::cout << "\n=== ���� ���� ������ �������� ===\n";
        std::cout << "1. �������� ����� ������ (���� �������)\n";
        std::cout << "2. ������� ������ �� �������\n";
        std::cout << "3. ������� ��� �������\n";
        std::cout << "4. �������� ��� ���� ������\n";
        std::cout << "0. ����� � ������� ����\n";
        std::cout << "������� ��� �����: ";
        std::cin >> choice;
        clearInputBuffer(); 

        switch (choice) {
        case 1:
            createAndAddObject(my_database);
            break;
        case 2:
            removeObjectByIndex(my_database);
            break;
        case 3:
            my_database.printAll();
            break;
        case 4:
            my_database.clear();
            std::cout << "���� ������ ��������� �������.\n";
            break;
        case 0:
            std::cout << "������� � ������� ����.\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
            break;
        }
    } while (choice != 0);
}


int main() {
    setlocale(LC_ALL, "ru");
    int main_choice;

    do {
        std::cout << "\n=== ������� ���� ��������� ===\n";
        std::cout << "1. ��������� ������������� ������������ ���� ������ ��������\n";
        std::cout << "0. �����\n";
        std::cout << "������� ��� �����: ";
        std::cin >> main_choice;
        clearInputBuffer(); // ������� ����� ����� ����� �����

        switch (main_choice) {
        case 1:
            runObjectDatabaseInteractiveTest();
            break;
        case 0:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
            break;
        }
    } while (main_choice != 0);

    return 0;
}