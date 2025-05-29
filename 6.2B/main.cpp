#include <iostream>
#include <clocale> // Для setlocale

#include "object_database.h"
#include "cyclist.h"
#include "motorcycle.h"
#include "detected_object.h"
#include "unattended_bag.h"
#include "car.h"
#include "person.h"

// Вспомогательная функция для очистки буфера ввода
void clearInputBuffer() {
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF);
}
void createAndAddObject(ObjectDatabase& db) {
    std::cout << "\nВыберите тип объекта для добавления:\n";
    std::cout << "1. Велосипедист\n";
    std::cout << "2. Мотоцикл\n";
    std::cout << "3. Бесхозная сумка\n";
    std::cout << "4. Автомобиль\n";
    std::cout << "Введите номер: ";
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
        std::cout << "Неверный тип объекта. Попробуйте снова.\n";
        return;
    }

    if (newObj) {
        newObj->inputInfo(); 
        db.add(newObj);     
        delete newObj;       
        std::cout << "Объект успешно добавлен.\n";
    }
}

void removeObjectByIndex(ObjectDatabase& db) {
    if (db.isEmpty()) {
        std::cout << "База данных пуста, нет объектов для удаления.\n";
        return;
    }

    std::cout << "Введите индекс объекта для удаления (от 0 до " << db.getSize() - 1 << "): ";
    size_t index;
    std::cin >> index;
    clearInputBuffer();

    if (index < db.getSize()) {
        db.remove(index);
        std::cout << "Объект по индексу " << index << " успешно удален.\n";
    }
    else {
        std::cout << "Неверный индекс. Объект не найден.\n";
    }
}

void runObjectDatabaseInteractiveTest() {
    ObjectDatabase my_database;
    int choice;

    do {
        std::cout << "\n=== Меню Базы Данных Объектов ===\n";
        std::cout << "1. Добавить новый объект (ввод вручную)\n";
        std::cout << "2. Удалить объект по индексу\n";
        std::cout << "3. Вывести все объекты\n";
        std::cout << "4. Очистить всю базу данных\n";
        std::cout << "0. Назад в главное меню\n";
        std::cout << "Введите ваш выбор: ";
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
            std::cout << "База данных полностью очищена.\n";
            break;
        case 0:
            std::cout << "Возврат в главное меню.\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (choice != 0);
}


int main() {
    setlocale(LC_ALL, "ru");
    int main_choice;

    do {
        std::cout << "\n=== Главное Меню Программы ===\n";
        std::cout << "1. Запустить интерактивное тестирование Базы Данных Объектов\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> main_choice;
        clearInputBuffer(); // Очищаем буфер после ввода числа

        switch (main_choice) {
        case 1:
            runObjectDatabaseInteractiveTest();
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (main_choice != 0);

    return 0;
}