#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Базовый абстрактный класс
class Entity {
public:
    virtual void printInfo() const = 0;   // виртуальный метод вывода
    virtual Entity* clone() const = 0;    // виртуальный "конструктор копирования"
    virtual ~Entity() {}                 // виртуальный деструктор:contentReference[oaicite:9]{index=9}
};

// Класс Person
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
    // Конструктор копирования (глубокое копирование):contentReference[oaicite:10]{index=10}
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

// Класс Cyclist
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

// Класс Car
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

// Класс Motorcycle
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

// Класс UnattendedBag
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

// Класс динамического массива EntityArray
class EntityArray {
private:
    Entity** data;
    int size;
    int capacity;
public:
    // Конструктор без параметров
    EntityArray() : data(nullptr), size(0), capacity(0) {}

    // Конструктор копирования (глубокое копирование через clone())
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

    // Оператор копирующего присваивания (глубокое копирование)
    EntityArray& operator=(const EntityArray& other) {
        if (this != &other) {
            // Удаляем текущие объекты
            for (int i = 0; i < size; ++i) {
                delete data[i];
            }
            delete[] data;
            // Копируем данные из other
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

    // Конструктор перемещения
    EntityArray(EntityArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity)
    {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Оператор перемещающего присваивания
    EntityArray& operator=(EntityArray&& other) noexcept {
        if (this != &other) {
            // Удаляем текущие объекты
            for (int i = 0; i < size; ++i) {
                delete data[i];
            }
            delete[] data;
            // Перемещаем данные из other
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Деструктор: удаляем все объекты и массив
    ~EntityArray() {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    // Добавление объекта в массив
    void add(Entity* obj) {
        if (size == capacity) {
            // Расширяем массив (ёмкость вдвое)
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

    // Удаление последнего объекта
    void removeLast() {
        if (size > 0) {
            delete data[size - 1];
            data[size - 1] = nullptr;
            --size;
        }
    }

    // Вывод всех объектов
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
        cout << "1 - Добавить Person\n";
        cout << "2 - Добавить Cyclist\n";
        cout << "3 - Добавить Car\n";
        cout << "4 - Добавить Motorcycle\n";
        cout << "5 - Добавить UnattendedBag\n";
        cout << "6 - Вывести все объекты\n";
        cout << "7 - Удалить последний объект\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        if (choice == 1) {
            char name[100];
            int age;
            cout << "Введите имя человека: ";
            cin >> name;
            cout << "Введите возраст: ";
            cin >> age;
            Person* p = new Person(name, age);
            arr.add(p);
        }
        else if (choice == 2) {
            char name[100];
            int age;
            double speed;
            cout << "Введите имя велосипедиста: ";
            cin >> name;
            cout << "Введите возраст: ";
            cin >> age;
            cout << "Введите скорость: ";
            cin >> speed;
            Cyclist* c = new Cyclist(name, age, speed);
            arr.add(c);
        }
        else if (choice == 3) {
            char brand[100], model[100];
            int hp;
            cout << "Введите марку автомобиля: ";
            cin >> brand;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите мощность (л.с.): ";
            cin >> hp;
            Car* car = new Car(brand, model, hp);
            arr.add(car);
        }
        else if (choice == 4) {
            char brand[100];
            int cc;
            cout << "Введите марку мотоцикла: ";
            cin >> brand;
            cout << "Введите объем двигателя (см^3): ";
            cin >> cc;
            Motorcycle* m = new Motorcycle(brand, cc);
            arr.add(m);
        }
        else if (choice == 5) {
            char desc[100];
            double weight;
            cout << "Введите описание сумки: ";
            cin >> desc;
            cout << "Введите вес (кг): ";
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
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
