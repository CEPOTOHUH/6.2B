#pragma once
#include "person.h" 

class ObjectDatabase {
private:
    Person** data;      
    size_t capacity;    
    size_t currentSize; 
    void expandCapacity();

public:
    ObjectDatabase();
    ~ObjectDatabase();
    ObjectDatabase(const ObjectDatabase& other);
    ObjectDatabase& operator=(const ObjectDatabase& other);
    ObjectDatabase(ObjectDatabase&& other) noexcept;
    ObjectDatabase& operator=(ObjectDatabase&& other) noexcept;
    void add(Person* obj);
    void remove(size_t index);
    void printAll() const;
    void clear();
    size_t getSize() const;  
    bool isEmpty() const;     
};