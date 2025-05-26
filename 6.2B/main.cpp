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

    std::cout << "Демонстрация иерархии классов с использованием сырых указателей и ручным управлением динамическим массивом (с полным Правилом Пяти):\n\n";

    DetectedObjectRegistry objectCollection;
    char choice;

    while (true) {
        std::cout << "\n--- Меню управления объектами ---\n";
        std::cout << "1. Добавить новый объект\n";
        std::cout << "2. Просмотреть все объекты\n";
        std::cout << "3. Удалить объект по индексу\n";
        std::cout << "4. Очистить весь реестр\n";
        std::cout << "0. Выйти\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(256, '\n');

        switch (choice) {
        case '1': {
            std::cout << "\nВыберите тип объекта для добавления:\n";
            std::cout << "1. Человек\n";
            std::cout << "2. Велосипедист\n";
            std::cout << "3. Автомобиль\n";
            std::cout << "4. Мотоцикл\n";
            std::cout << "5. Бесхозная сумка\n";
            std::cout << "Ваш выбор: ";
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
                std::cout << "Неверный выбор типа объекта.\n";
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
                std::cout << "Реестр пуст, нет объектов для удаления.\n";
                break;
            }
            std::cout << "Введите индекс объекта для удаления: ";
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
            std::cout << "Выход из программы.\n";
            return 0;
        }
        default: {
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
        }
    }

    return 0;
}