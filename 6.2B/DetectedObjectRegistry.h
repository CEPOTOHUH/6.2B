#pragma once
#include "DetectedObject.h" 
#include <cstddef> 
#include <utility> 

// Объявление вспомогательной функции (без std::unique_ptr)
void inputObjectInfo(DetectedObject* obj);

class DetectedObjectRegistry {
private:
    DetectedObject** objects; // Массив указателей на DetectedObject
    size_t capacity;
    size_t count;

    void resize(size_t newCapacity);
    void clearInternal(); // Вспомогательная функция для очистки объектов

public:
    DetectedObjectRegistry();
    ~DetectedObjectRegistry();

    // Конструктор копирования
    DetectedObjectRegistry(const DetectedObjectRegistry& other);
    // Оператор присваивания копированием
    DetectedObjectRegistry& operator=(const DetectedObjectRegistry& other);

    // Конструктор перемещения
    DetectedObjectRegistry(DetectedObjectRegistry&& other) noexcept;
    // Оператор присваивания перемещением
    DetectedObjectRegistry& operator=(DetectedObjectRegistry&& other) noexcept;

    // Оператор доступа по индексу (неконстантный)
    DetectedObject& operator[](size_t index);
    // Оператор доступа по индексу (константный)
    const DetectedObject& operator[](size_t index) const;

    void addObject(DetectedObject* obj); // Принимает сырой указатель
    void removeObject(size_t index);
    void clearRegistry();
    void displayAllObjects() const;
    size_t getObjectCount() const;
};