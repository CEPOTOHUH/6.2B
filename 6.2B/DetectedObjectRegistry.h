#pragma once
#include "DetectedObject.h" 
#include <cstddef> 
#include <utility> 

// ���������� ��������������� ������� (��� std::unique_ptr)
void inputObjectInfo(DetectedObject* obj);

class DetectedObjectRegistry {
private:
    DetectedObject** objects; // ������ ���������� �� DetectedObject
    size_t capacity;
    size_t count;

    void resize(size_t newCapacity);
    void clearInternal(); // ��������������� ������� ��� ������� ��������

public:
    DetectedObjectRegistry();
    ~DetectedObjectRegistry();

    // ����������� �����������
    DetectedObjectRegistry(const DetectedObjectRegistry& other);
    // �������� ������������ ������������
    DetectedObjectRegistry& operator=(const DetectedObjectRegistry& other);

    // ����������� �����������
    DetectedObjectRegistry(DetectedObjectRegistry&& other) noexcept;
    // �������� ������������ ������������
    DetectedObjectRegistry& operator=(DetectedObjectRegistry&& other) noexcept;

    // �������� ������� �� ������� (�������������)
    DetectedObject& operator[](size_t index);
    // �������� ������� �� ������� (�����������)
    const DetectedObject& operator[](size_t index) const;

    void addObject(DetectedObject* obj); // ��������� ����� ���������
    void removeObject(size_t index);
    void clearRegistry();
    void displayAllObjects() const;
    size_t getObjectCount() const;
};