#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Detail {
protected:
    string name;
    double weight;

    Detail(string n, double w) : name(n), weight(w) {}
    Detail() {}

public:
    virtual ~Detail() = default;

    virtual void input() {
        cout << "Введите название: ";
        getline(cin, name);
        cout << "Введите вес: ";
        cin >> weight;
        cin.ignore();
    }

    virtual void print() const {
        cout << "Название: " << name << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }

    static Detail* makeDetail() {
        return new Detail();
    }

    static Detail* makeDetail(string name, double weight) {
        return new Detail(name, weight);
    }
};

class Assembly : public Detail {
private:
    int partsCount;

protected:
    Assembly(string n, double w, int count) : Detail(n, w), partsCount(count) {}
    Assembly() : Detail(), partsCount(0) {}

public:
    void input() override {
        Detail::input();
        cout << "Введите количество деталей: ";
        cin >> partsCount;
        cin.ignore();
    }

    void print() const override {
        Detail::print();
        cout << "Количество деталей: " << partsCount << endl;
    }

    static Assembly* makeAssembly() {
        return new Assembly();
    }

    static Assembly* makeAssembly(string name, double weight, int count) {
        return new Assembly(name, weight, count);
    }
};

void manualInput() {

    cout << "Создание детали:" << endl;
    Detail* detail = Detail::makeDetail();
    detail->input();
    cout << endl;

    cout << "Создание сборки:" << endl;
    Assembly* assembly = Assembly::makeAssembly();
    assembly->input();
    cout << endl;

    cout << "Результат:" << endl;
    cout << "Деталь:" << endl;
    detail->print();
    cout << endl << "Сборка:" << endl;
    assembly->print();

    delete detail;
    delete assembly;
}

void showExample() {
    cout << "Пример данных" << endl << endl;

    vector<Detail*> items;

    items.push_back(Detail::makeDetail("Болт", 0.1));
    items.push_back(Detail::makeDetail("Гайка", 0.05));
    items.push_back(Assembly::makeAssembly("Двигатель", 150.0, 50));
    items.push_back(Assembly::makeAssembly("Коробка передач", 80.0, 25));

    cout << "Содержимое хранилища:" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << "Объект " << i + 1 << ":" << endl;
        items[i]->print();
        cout << endl;
    }

    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    cout << "1 - Показать пример" << endl;
    cout << "2 - Ввести данные" << endl << endl;
    cout << "Выберите: ";
    cin >> choice;
    cin.ignore();
    cout << endl;

    switch (choice) {
    case 1:
        showExample();
        break;
    case 2:
        manualInput();
        break;
    default:
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}
