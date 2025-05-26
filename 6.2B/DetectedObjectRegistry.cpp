#include "DetectedObjectRegistry.h"
#include <iostream> // Для std::cout, std::cerr
#include <cstdlib>  // Для exit
// #include <utility> // Уже включен в DetectedObjectRegistry.h для std::swap

DetectedObjectRegistry::DetectedObjectRegistry() : objects(nullptr), capacity(0), count(0) {
    std::cout << "DetectedObjectRegistry: Конструктор по умолчанию.\n";
}

void DetectedObjectRegistry::clearInternal() {
    for (size_t i = 0; i < count; ++i) {
        delete objects[i]; // Освобождаем память для каждого объекта
        objects[i] = nullptr;
    }
    if (objects != nullptr) {
        delete[] objects; // Освобождаем память для самого массива указателей
        objects = nullptr;
    }
    capacity = 0;
    count = 0;
}

DetectedObjectRegistry::~DetectedObjectRegistry() {
    std::cout << "DetectedObjectRegistry: Деструктор.\n";
    clearInternal(); // Вызываем внутреннюю функцию очистки
}

DetectedObjectRegistry::DetectedObjectRegistry(const DetectedObjectRegistry& other)
    : objects(nullptr), capacity(0), count(0) {
    std::cout << "DetectedObjectRegistry: Конструктор копирования.\n";
    if (other.count > 0) {
        resize(other.count); // Выделяем память под массив такого же размера
        for (size_t i = 0; i < other.count; ++i) {
            if (other.objects[i]) {
                objects[i] = other.objects[i]->clone(); // Используем полиморфное копирование
            }
            else {
                objects[i] = nullptr;
            }
        }
        count = other.count;
    }
}

DetectedObjectRegistry& DetectedObjectRegistry::operator=(const DetectedObjectRegistry& other) {
    std::cout << "DetectedObjectRegistry: Оператор присваивания копированием.\n";
    if (this != &other) {
        // Идиома копирования и обмена (Copy-and-Swap Idiom) для безопасности исключений
        // Создаем временную копию, используя конструктор копирования
        DetectedObjectRegistry temp = other;
        // Обмениваемся данными с временным объектом
        std::swap(this->objects, temp.objects);
        std::swap(this->capacity, temp.capacity);
        std::swap(this->count, temp.count);
        // temp теперь содержит старые данные *this*, которые будут уничтожены при выходе из области видимости
    }
    return *this;
}

DetectedObjectRegistry::DetectedObjectRegistry(DetectedObjectRegistry&& other) noexcept
    : objects(other.objects), // Просто копируем указатель
    capacity(other.capacity),
    count(other.count) {
    other.objects = nullptr; // Обнуляем указатель у источника
    other.capacity = 0;
    other.count = 0;
    std::cout << "DetectedObjectRegistry: Конструктор перемещения.\n";
}

DetectedObjectRegistry& DetectedObjectRegistry::operator=(DetectedObjectRegistry&& other) noexcept {
    std::cout << "DetectedObjectRegistry: Оператор присваивания перемещением.\n";
    if (this != &other) {
        clearInternal(); // Очищаем текущие ресурсы
        objects = other.objects; // Перемещаем указатель
        capacity = other.capacity;
        count = other.count;
        other.objects = nullptr; // Обнуляем указатель у источника
        other.capacity = 0;
        other.count = 0;
    }
    return *this;
}

DetectedObject& DetectedObjectRegistry::operator[](size_t index) {
    if (index >= count) {
        std::cerr << "Ошибка: Индекс за пределами диапазона (" << index << " >= " << count << ")\n";
        if (count > 0) {
            // В случае ошибки, возвращаем ссылку на существующий объект (первый).
            // Это не идеальное решение, но соответствует отсутствию исключений.
            return *objects[0];
        }
        // Если массив пуст и индекс некорректен, нет безопасного способа продолжить.
        exit(1); // Завершаем программу.
    }
    return *objects[index];
}

const DetectedObject& DetectedObjectRegistry::operator[](size_t index) const {
    if (index >= count) {
        std::cerr << "Ошибка (const): Индекс за пределами диапазона (" << index << " >= " << count << ")\n";
        if (count > 0) {
            return *objects[0];
        }
        exit(1);
    }
    return *objects[index];
}

void DetectedObjectRegistry::addObject(DetectedObject* obj) {
    if (!obj) {
        std::cout << "Не удалось добавить нулевой объект.\n";
        return;
    }

    if (count == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    objects[count++] = obj; // Просто присваиваем указатель
    std::cout << "Объект успешно добавлен.\n";
}

void DetectedObjectRegistry::removeObject(size_t index) {
    if (index < count) {
        delete objects[index]; // Удаляем объект, на который указывает элемент массива
        for (size_t i = index; i < count - 1; ++i) {
            objects[i] = objects[i + 1]; // Сдвигаем элементы
        }
        objects[--count] = nullptr; // Обнуляем последний элемент и уменьшаем счетчик
        std::cout << "Объект по индексу " << index << " успешно удален.\n";
    }
    else {
        std::cout << "Неверный индекс объекта. Текущее количество объектов: " << count << "\n";
    }
}

void DetectedObjectRegistry::clearRegistry() {
    if (count == 0 && capacity == 0) return;

    clearInternal(); // Полная очистка
    std::cout << "Все объекты удалены из реестра, массив очищен.\n";
}

void DetectedObjectRegistry::displayAllObjects() const {
    if (count == 0) {
        std::cout << "Реестр пуст.\n";
        return;
    }
    std::cout << "\n--- Объекты в реестре (" << count << " из " << capacity << ")---\n";
    for (size_t i = 0; i < count; ++i) {
        std::cout << "Индекс: " << i << "\n";
        if (objects[i]) {
            std::cout << *objects[i] << "\n";
        }
        else {
            std::cout << "  (NULL объект)\n";
        }
        std::cout << "---------------------------------\n";
    }
}

size_t DetectedObjectRegistry::getObjectCount() const {
    return count;
}

void DetectedObjectRegistry::resize(size_t newCapacity) {
    if (newCapacity == capacity) return;

    if (newCapacity == 0) { 
        clearInternal();
        return;
    }

 
    if (newCapacity < count) {
        for (size_t i = newCapacity; i < count; ++i) {
            delete objects[i]; 
            objects[i] = nullptr;
        }
        count = newCapacity; 
    }

    DetectedObject** newObjects = new DetectedObject * [newCapacity];

   
    for (size_t i = 0; i < count; ++i) {
        newObjects[i] = objects[i];
    }

    if (objects != nullptr) {
        delete[] objects;
    }
    objects = newObjects;
    capacity = newCapacity;
    std::cout << "Реестр изменен до размера: " << capacity << "\n";
}

void inputObjectInfo(DetectedObject* obj) {
    if (obj) {
        obj->inputInfo();
        std::cout << "---------------------------------\n";
    }
    else {
        std::cout << "Объект не существует.\n";
    }
}