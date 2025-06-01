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
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите число от " << minVal << " до " << maxVal << ".\n";
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
        std::cout << "\n--- Меню управления базой данных объектов ---\n";
        std::cout << "1. Добавить объект\n";
        std::cout << "2. Удалить объект по индексу\n";
        std::cout << "3. Показать все объекты\n";
        std::cout << "4. Очистить базу данных\n";
        std::cout << "5. Показать размер базы данных\n";
        std::cout << "6. Проверить, пуста ли база данных\n";
        std::cout << "0. Выйти из меню\n";

        choice = getIntInput("Выберите действие: ", 0, 6);

        switch (choice) {
        case 1: {
            std::cout << "\nВыберите тип объекта для добавления:\n";
            std::cout << "1. Человек\n";
            std::cout << "2. Велосипедист\n";
            std::cout << "3. Автомобиль\n";
            std::cout << "4. Мотоцикл\n";
            std::cout << "5. Бесхозная сумка\n";
            int objType = getIntInput("Ваш выбор: ", 1, 5);
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
                std::cout << "Объект успешно добавлен.\n";
            }
            else {
                std::cout << "Неизвестный тип объекта.\n";
            }
            break;
        }
        case 2: {
            if (db.isEmpty()) {
                std::cout << "База данных пуста, нечего удалять.\n";
                break;
            }
            size_t indexToRemove = getIntInput("Введите индекс объекта для удаления (начиная с 0): ", 0, db.getSize() - 1);
            db.remove(indexToRemove);
            std::cout << "Объект по индексу " << indexToRemove << " удален.\n";
            break;
        }
        case 3:
            db.printAll();
            break;
        case 4:
            db.clear();
            std::cout << "База данных очищена.\n";
            break;
        case 5:
            std::cout << "Текущий размер базы данных: " << db.getSize() << "\n";
            break;
        case 6:
            std::cout << "База данных " << (db.isEmpty() ? "пуста" : "не пуста") << ".\n";
            break;
        case 0:
            std::cout << "Выход из меню базы данных.\n";
            break;
        default:
            break;
        }
    } while (choice != 0);
}


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Демонстрация работы динамического массива объектов с иерархией классов и ручным вводом.\n\n";
    interactiveDatabaseMenu();

    std::cout << "\nПрограмма завершена.\n";

    return 0;
}