#include "object_database.h"
#include <iostream>
#include <utility> 
const size_t INITIAL_CAPACITY = 4; 

void ObjectDatabase::expandCapacity() {
    size_t newCapacity = capacity == 0 ? INITIAL_CAPACITY : capacity * 2;
    DetectedObject** newData = new DetectedObject * [newCapacity];

    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

ObjectDatabase::ObjectDatabase() : data(nullptr), capacity(0), currentSize(0) {}

ObjectDatabase::~ObjectDatabase() {
    clear();
}

ObjectDatabase::ObjectDatabase(const ObjectDatabase& other)
    : data(nullptr), capacity(0), currentSize(0) {
    if (other.currentSize > 0) {
        capacity = other.currentSize; 
        data = new DetectedObject * [capacity];

        currentSize = 0;
        for (size_t i = 0; i < other.currentSize; ++i) {
            add(other.data[i]);
        }
    }
}

ObjectDatabase& ObjectDatabase::operator=(const ObjectDatabase& other) {
    if (this != &other) {
        ObjectDatabase temp(other);

        std::swap(data, temp.data);
        std::swap(capacity, temp.capacity);
        std::swap(currentSize, temp.currentSize);
    }
    return *this;
}

ObjectDatabase::ObjectDatabase(ObjectDatabase&& other) noexcept
    : data(other.data),
    capacity(other.capacity),
    currentSize(other.currentSize)
{
    other.data = nullptr;
    other.capacity = 0;
    other.currentSize = 0;
}

ObjectDatabase& ObjectDatabase::operator=(ObjectDatabase&& other) noexcept {
    if (this != &other) {
        clear();

        data = other.data; other.data = nullptr;
        capacity = other.capacity; other.capacity = 0;
        currentSize = other.currentSize; other.currentSize = 0;
    }
    return *this;
}

void ObjectDatabase::add(DetectedObject* obj) {
    if (obj == nullptr) {
        std::cerr << "Ошибка: Попытка добавить NULL объект в базу данных.\n";
        return;
    }
    if (currentSize >= capacity) {
        expandCapacity();
    }
    data[currentSize] = obj->clone();
    currentSize++;
}

void ObjectDatabase::remove(size_t index) {
    if (index >= currentSize) {
        std::cerr << "Ошибка: Индекс выходит за пределы базы данных при удалении.\n";
        return;
    }

    delete data[index];

    for (size_t i = index; i < currentSize - 1; ++i) {
        data[i] = data[i + 1];
    }
    data[currentSize - 1] = nullptr;
    currentSize--;
}

void ObjectDatabase::printAll() const {
    if (isEmpty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    std::cout << "\n--- Содержимое Базы Данных (" << currentSize << " элементов) ---\n";
    for (size_t i = 0; i < currentSize; ++i) {
        std::cout << "Элемент " << i + 1 << ":\n";
        data[i]->print(std::cout);
        std::cout << "--------------------\n";
    }
}

void ObjectDatabase::clear() {
    for (size_t i = 0; i < currentSize; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    capacity = 0;
    currentSize = 0;
}

size_t ObjectDatabase::getSize() const {
    return currentSize;
}

bool ObjectDatabase::isEmpty() const {
    return currentSize == 0;
}