#include "DetectedObjectRegistry.h"
#include <iostream> // ��� std::cout, std::cerr
#include <cstdlib>  // ��� exit
// #include <utility> // ��� ������� � DetectedObjectRegistry.h ��� std::swap

DetectedObjectRegistry::DetectedObjectRegistry() : objects(nullptr), capacity(0), count(0) {
    std::cout << "DetectedObjectRegistry: ����������� �� ���������.\n";
}

void DetectedObjectRegistry::clearInternal() {
    for (size_t i = 0; i < count; ++i) {
        delete objects[i]; // ����������� ������ ��� ������� �������
        objects[i] = nullptr;
    }
    if (objects != nullptr) {
        delete[] objects; // ����������� ������ ��� ������ ������� ����������
        objects = nullptr;
    }
    capacity = 0;
    count = 0;
}

DetectedObjectRegistry::~DetectedObjectRegistry() {
    std::cout << "DetectedObjectRegistry: ����������.\n";
    clearInternal(); // �������� ���������� ������� �������
}

DetectedObjectRegistry::DetectedObjectRegistry(const DetectedObjectRegistry& other)
    : objects(nullptr), capacity(0), count(0) {
    std::cout << "DetectedObjectRegistry: ����������� �����������.\n";
    if (other.count > 0) {
        resize(other.count); // �������� ������ ��� ������ ������ �� �������
        for (size_t i = 0; i < other.count; ++i) {
            if (other.objects[i]) {
                objects[i] = other.objects[i]->clone(); // ���������� ����������� �����������
            }
            else {
                objects[i] = nullptr;
            }
        }
        count = other.count;
    }
}

DetectedObjectRegistry& DetectedObjectRegistry::operator=(const DetectedObjectRegistry& other) {
    std::cout << "DetectedObjectRegistry: �������� ������������ ������������.\n";
    if (this != &other) {
        // ������ ����������� � ������ (Copy-and-Swap Idiom) ��� ������������ ����������
        // ������� ��������� �����, ��������� ����������� �����������
        DetectedObjectRegistry temp = other;
        // ������������ ������� � ��������� ��������
        std::swap(this->objects, temp.objects);
        std::swap(this->capacity, temp.capacity);
        std::swap(this->count, temp.count);
        // temp ������ �������� ������ ������ *this*, ������� ����� ���������� ��� ������ �� ������� ���������
    }
    return *this;
}

DetectedObjectRegistry::DetectedObjectRegistry(DetectedObjectRegistry&& other) noexcept
    : objects(other.objects), // ������ �������� ���������
    capacity(other.capacity),
    count(other.count) {
    other.objects = nullptr; // �������� ��������� � ���������
    other.capacity = 0;
    other.count = 0;
    std::cout << "DetectedObjectRegistry: ����������� �����������.\n";
}

DetectedObjectRegistry& DetectedObjectRegistry::operator=(DetectedObjectRegistry&& other) noexcept {
    std::cout << "DetectedObjectRegistry: �������� ������������ ������������.\n";
    if (this != &other) {
        clearInternal(); // ������� ������� �������
        objects = other.objects; // ���������� ���������
        capacity = other.capacity;
        count = other.count;
        other.objects = nullptr; // �������� ��������� � ���������
        other.capacity = 0;
        other.count = 0;
    }
    return *this;
}

DetectedObject& DetectedObjectRegistry::operator[](size_t index) {
    if (index >= count) {
        std::cerr << "������: ������ �� ��������� ��������� (" << index << " >= " << count << ")\n";
        if (count > 0) {
            // � ������ ������, ���������� ������ �� ������������ ������ (������).
            // ��� �� ��������� �������, �� ������������� ���������� ����������.
            return *objects[0];
        }
        // ���� ������ ���� � ������ �����������, ��� ����������� ������� ����������.
        exit(1); // ��������� ���������.
    }
    return *objects[index];
}

const DetectedObject& DetectedObjectRegistry::operator[](size_t index) const {
    if (index >= count) {
        std::cerr << "������ (const): ������ �� ��������� ��������� (" << index << " >= " << count << ")\n";
        if (count > 0) {
            return *objects[0];
        }
        exit(1);
    }
    return *objects[index];
}

void DetectedObjectRegistry::addObject(DetectedObject* obj) {
    if (!obj) {
        std::cout << "�� ������� �������� ������� ������.\n";
        return;
    }

    if (count == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    objects[count++] = obj; // ������ ����������� ���������
    std::cout << "������ ������� ��������.\n";
}

void DetectedObjectRegistry::removeObject(size_t index) {
    if (index < count) {
        delete objects[index]; // ������� ������, �� ������� ��������� ������� �������
        for (size_t i = index; i < count - 1; ++i) {
            objects[i] = objects[i + 1]; // �������� ��������
        }
        objects[--count] = nullptr; // �������� ��������� ������� � ��������� �������
        std::cout << "������ �� ������� " << index << " ������� ������.\n";
    }
    else {
        std::cout << "�������� ������ �������. ������� ���������� ��������: " << count << "\n";
    }
}

void DetectedObjectRegistry::clearRegistry() {
    if (count == 0 && capacity == 0) return;

    clearInternal(); // ������ �������
    std::cout << "��� ������� ������� �� �������, ������ ������.\n";
}

void DetectedObjectRegistry::displayAllObjects() const {
    if (count == 0) {
        std::cout << "������ ����.\n";
        return;
    }
    std::cout << "\n--- ������� � ������� (" << count << " �� " << capacity << ")---\n";
    for (size_t i = 0; i < count; ++i) {
        std::cout << "������: " << i << "\n";
        if (objects[i]) {
            std::cout << *objects[i] << "\n";
        }
        else {
            std::cout << "  (NULL ������)\n";
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
    std::cout << "������ ������� �� �������: " << capacity << "\n";
}

void inputObjectInfo(DetectedObject* obj) {
    if (obj) {
        obj->inputInfo();
        std::cout << "---------------------------------\n";
    }
    else {
        std::cout << "������ �� ����������.\n";
    }
}