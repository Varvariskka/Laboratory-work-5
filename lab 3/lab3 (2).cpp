#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Base {
protected:
    string name;
    int number;

    Base(string n, int num) : name(n), number(num) {}
    Base() {}

public:
    virtual ~Base() {}

    virtual void show() {
        cout << "Базовый класс: " << name << ", число: " << number << endl;
    }

    virtual void calculate() {
        cout << "Результат: " << number * 2 << endl;
    }

    static Base* create() {
        return new Base("Базовый", 10);
    }

    static Base* create(string name, int number) {
        return new Base(name, number);
    }
};

class Derived : public Base {
private:
    double factor;

protected:
    Derived(string n, int num, double f) : Base(n, num), factor(f) {}
    Derived() : Base(), factor(1.5) {}

public:
    void show() override {
        cout << "Производный класс: " << name << ", число: " << number << ", множитель: " << factor << endl;
    }

    void calculate() override {
        double result = number * factor;
        cout << "Результат: " << result << endl;
    }

    static Derived* create() {
        return new Derived("Производный", 20, 2.5);
    }

    static Derived* create(string name, int number, double factor) {
        return new Derived(name, number, factor);
    }
};

vector<Base*> objects;

void add(Base* obj) {
    objects.push_back(obj);
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    cout << "Создание объектов" << endl;
    
    for (int i = 0; i < 5; i++) {
        if (rand() % 2 == 0) {
            Base* obj = Base::create("Базовый объект", (i + 1) * 5);
            add(obj);
            
        } else {
            Derived* obj = Derived::create("Производный объект", (i + 1) * 8, 1.5 + i * 0.5);
            add(obj);
        }
    }

    cout << endl << "Демонстрация поведения" << endl;
    for (int i = 0; i < objects.size(); i++) {
        cout << "Объект " << i + 1 << ": ";
        objects[i]->show();
        cout << "Расчет: ";
        objects[i]->calculate();
        cout << endl;
    }

    cout << "Очистка памяти" << endl;
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i];
        cout << "Объект " << i + 1 << " удален" << endl;
    }
    objects.clear();

    return 0;
}
