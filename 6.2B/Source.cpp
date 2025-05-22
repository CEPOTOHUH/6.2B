#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������� ����������� �����
class Entity {
public:
    virtual void printInfo() const = 0;   // ����������� ����� ������
    virtual Entity* clone() const = 0;    // ����������� "����������� �����������"
    virtual ~Entity() {}                 // ����������� ����������:contentReference[oaicite:9]{index=9}
};

// ����� Person
class Person : public Entity {
private:
    char* name;
    int age;
public:
    Person(const char* nameVal = "", int ageVal = 0)
        : age(ageVal)
    {
        name = new char[strlen(nameVal) + 1];
        strcpy(name, nameVal);
    }
    // ����������� ����������� (�������� �����������):contentReference[oaicite:10]{index=10}
    Person(const Person& other) : age(other.age) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    Person& operator=(const Person& other) {
        if (this != &other) {
            delete[] name;
            age = other.age;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }
    virtual ~Person() {
        delete[] name;
    }
    virtual Person* clone() const override {
        return new Person(*this);
    }
    virtual void printInfo() const override {
        cout << "Person(Name: " << name << ", Age: " << age << ")" << endl;
    }
};

// ����� Cyclist
class Cyclist : public Entity {
private:
    char* name;
    int age;
    double speed;
public:
    Cyclist(const char* nameVal = "", int ageVal = 0, double speedVal = 0.0)
        : age(ageVal), speed(speedVal)
    {
        name = new char[strlen(nameVal) + 1];
        strcpy(name, nameVal);
    }
    Cyclist(const Cyclist& other)
        : age(other.age), speed(other.speed)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    Cyclist& operator=(const Cyclist& other) {
        if (this != &other) {
            delete[] name;
            age = other.age;
            speed = other.speed;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }
    virtual ~Cyclist() {
        delete[] name;
    }
    virtual Cyclist* clone() const override {
        return new Cyclist(*this);
    }
    virtual void printInfo() const override {
        cout << "Cyclist(Name: " << name << ", Age: " << age << ", Speed: " << speed << ")" << endl;
    }
};

// ����� Car
class Car : public Entity {
private:
    char* brand;
    char* model;
    int horsepower;
public:
    Car(const char* brandVal = "", const char* modelVal = "", int hpVal = 0)
        : horsepower(hpVal)
    {
        brand = new char[strlen(brandVal) + 1];
        strcpy(brand, brandVal);
        model = new char[strlen(modelVal) + 1];
        strcpy(model, modelVal);
    }
    Car(const Car& other)
        : horsepower(other.horsepower)
    {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }
    Car& operator=(const Car& other) {
        if (this != &other) {
            delete[] brand;
            delete[] model;
            horsepower = other.horsepower;
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
            model = new char[strlen(other.model) + 1];
            strcpy(model, other.model);
        }
        return *this;
    }
    virtual ~Car() {
        delete[] brand;
        delete[] model;
    }
    virtual Car* clone() const override {
        return new Car(*this);
    }
    virtual void printInfo() const override {
        cout << "Car(Brand: " << brand << ", Model: " << model
            << ", HP: " << horsepower << ")" << endl;
    }
};

// ����� Motorcycle
class Motorcycle : public Entity {
private:
    char* brand;
    int engineCapacity;
public:
    Motorcycle(const char* brandVal = "", int capacityVal = 0)
        : engineCapacity(capacityVal)
    {
        brand = new char[strlen(brandVal) + 1];
        strcpy(brand, brandVal);
    }
    Motorcycle(const Motorcycle& other)
        : engineCapacity(other.engineCapacity)
    {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    }
    Motorcycle& operator=(const Motorcycle& other) {
        if (this != &other) {
            delete[] brand;
            engineCapacity = other.engineCapacity;
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        return *this;
    }
    virtual ~Motorcycle() {
        delete[] brand;
    }
    virtual Motorcycle* clone() const override {
        return new Motorcycle(*this);
    }
    virtual void printInfo() const override {
        cout << "Motorcycle(Brand: " << brand
            << ", Engine: " << engineCapacity << "cc)" << endl;
    }
};

// ����� UnattendedBag
class UnattendedBag : public Entity {
private:
    char* description;
    double weight;
public:
    UnattendedBag(const char* descVal = "", double weightVal = 0.0)
        : weight(weightVal)
    {
        description = new char[strlen(descVal) + 1];
        strcpy(description, descVal);
    }
    UnattendedBag(const UnattendedBag& other)
        : weight(other.weight)
    {
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    UnattendedBag& operator=(const UnattendedBag& other) {
        if (this != &other) {
            delete[] description;
            weight = other.weight;
            description = new char[strlen(other.description) + 1];
            strcpy(description, other.description);
        }
        return *this;
    }
    virtual ~UnattendedBag() {
        delete[] description;
    }
    virtual UnattendedBag* clone() const override {
        return new UnattendedBag(*this);
    }
    virtual void printInfo() const override {
        cout << "UnattendedBag(Description: " << description
            << ", Weight: " << weight << ")" << endl;
    }
};

// ����� ������������� ������� EntityArray
class EntityArray {
private:
    Entity** data;
    int size;
    int capacity;
public:
    // ����������� ��� ����������
    EntityArray() : data(nullptr), size(0), capacity(0) {}

    // ����������� ����������� (�������� ����������� ����� clone())
    EntityArray(const EntityArray& other) {
        size = other.size;
        capacity = other.capacity;
        if (capacity > 0) {
            data = new Entity * [capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i]->clone();
            }
            for (int i = size; i < capacity; ++i) {
                data[i] = nullptr;
            }
        }
        else {
            data = nullptr;
        }
    }

    // �������� ����������� ������������ (�������� �����������)
    EntityArray& operator=(const EntityArray& other) {
        if (this != &other) {
            // ������� ������� �������
            for (int i = 0; i < size; ++i) {
                delete data[i];
            }
            delete[] data;
            // �������� ������ �� other
            size = other.size;
            capacity = other.capacity;
            if (capacity > 0) {
                data = new Entity * [capacity];
                for (int i = 0; i < size; ++i) {
                    data[i] = other.data[i]->clone();
                }
                for (int i = size; i < capacity; ++i) {
                    data[i] = nullptr;
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    // ����������� �����������
    EntityArray(EntityArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity)
    {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // �������� ������������� ������������
    EntityArray& operator=(EntityArray&& other) noexcept {
        if (this != &other) {
            // ������� ������� �������
            for (int i = 0; i < size; ++i) {
                delete data[i];
            }
            delete[] data;
            // ���������� ������ �� other
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // ����������: ������� ��� ������� � ������
    ~EntityArray() {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    // ���������� ������� � ������
    void add(Entity* obj) {
        if (size == capacity) {
            // ��������� ������ (������� �����)
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            Entity** newData = new Entity * [newCap];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            for (int i = size; i < newCap; ++i) {
                newData[i] = nullptr;
            }
            delete[] data;
            data = newData;
            capacity = newCap;
        }
        data[size++] = obj;
    }

    // �������� ���������� �������
    void removeLast() {
        if (size > 0) {
            delete data[size - 1];
            data[size - 1] = nullptr;
            --size;
        }
    }

    // ����� ���� ��������
    void printAll() const {
        for (int i = 0; i < size; ++i) {
            if (data[i]) data[i]->printInfo();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    EntityArray arr;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1 - �������� Person\n";
        cout << "2 - �������� Cyclist\n";
        cout << "3 - �������� Car\n";
        cout << "4 - �������� Motorcycle\n";
        cout << "5 - �������� UnattendedBag\n";
        cout << "6 - ������� ��� �������\n";
        cout << "7 - ������� ��������� ������\n";
        cout << "0 - �����\n";
        cout << "�������� ��������: ";
        cin >> choice;
        if (choice == 1) {
            char name[100];
            int age;
            cout << "������� ��� ��������: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> age;
            Person* p = new Person(name, age);
            arr.add(p);
        }
        else if (choice == 2) {
            char name[100];
            int age;
            double speed;
            cout << "������� ��� �������������: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> age;
            cout << "������� ��������: ";
            cin >> speed;
            Cyclist* c = new Cyclist(name, age, speed);
            arr.add(c);
        }
        else if (choice == 3) {
            char brand[100], model[100];
            int hp;
            cout << "������� ����� ����������: ";
            cin >> brand;
            cout << "������� ������: ";
            cin >> model;
            cout << "������� �������� (�.�.): ";
            cin >> hp;
            Car* car = new Car(brand, model, hp);
            arr.add(car);
        }
        else if (choice == 4) {
            char brand[100];
            int cc;
            cout << "������� ����� ���������: ";
            cin >> brand;
            cout << "������� ����� ��������� (��^3): ";
            cin >> cc;
            Motorcycle* m = new Motorcycle(brand, cc);
            arr.add(m);
        }
        else if (choice == 5) {
            char desc[100];
            double weight;
            cout << "������� �������� �����: ";
            cin >> desc;
            cout << "������� ��� (��): ";
            cin >> weight;
            UnattendedBag* bag = new UnattendedBag(desc, weight);
            arr.add(bag);
        }
        else if (choice == 6) {
            arr.printAll();
        }
        else if (choice == 7) {
            arr.removeLast();
        }
        else if (choice != 0) {
            cout << "�������� �����, ���������� �����.\n";
        }
    } while (choice != 0);

    return 0;
}
