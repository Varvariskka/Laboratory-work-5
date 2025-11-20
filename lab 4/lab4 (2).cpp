#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ProgramError {};
class MemoryAccessError : public ProgramError {};
class MathError : public ProgramError {};
class DivisionByZeroError : public MathError {};
class OverflowError : public MathError {};

template <typename T>
class PointerArray {
private:
    T** data;
    int size;

public:

    PointerArray(int n) : size(n) {
        data = new T * [size];
        for (int i = 0; i < size; i++) {
            data[i] = nullptr;
        }
    }

    ~PointerArray() {
        for (int i = 0; i < size; i++) {
            delete data[i];
        }
        delete[] data;
    }

    T*& operator[](int index) {
        if (index < 0 || index >= size) {
            throw MemoryAccessError();
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

class TestObject {
private:
    string name;
    int value;

public:
    TestObject(string n = "", int v = 0) : name(n), value(v) {}

    void input() {
        cout << "Введите название: ";
        getline(cin, name);

        cout << "Введите значение: ";
        string inputStr;
        getline(cin, inputStr);

        if (inputStr.empty()) {
            throw invalid_argument("Пустая строка не может быть преобразована в число");
        }

        for (size_t i = 0; i < inputStr.length(); i++) {
            if (i == 0 && inputStr[i] == '-') {
                continue; 
            }
            if (!isdigit(inputStr[i])) {
                throw invalid_argument("Некорректный аргумент: '" + inputStr + "' не является целым числом");
            }
        }

        try {
            value = stoi(inputStr);
        }
        catch (const out_of_range&) {
            throw invalid_argument("Число '" + inputStr + "' выходит за пределы диапазона int");
        }

        if (value < -1000 || value > 1000) {
            throw invalid_argument("Значение " + to_string(value) + " вне допустимого диапазона [-1000, 1000]");
        }
    }

    void print() const {
        cout << name << " = " << value << endl;
    }
};

void testDivision() {
    try {
        cout << "10 / 0 = ";
        int a = 10, b = 0;
        if (b == 0) throw DivisionByZeroError();
        cout << a / b << endl;
    }
    catch (const DivisionByZeroError&) {
        cout << "Деление на ноль!" << endl;
    }
}

void testOverflow() {
    try {
        cout << "MAX_INT + 1 = ";
        int a = 2147483647, b = 1;
        if (a > 0 && b > 2147483647 - a) throw OverflowError();
        cout << a + b << endl;
    }
    catch (const OverflowError&) {
        cout << "Переполнение!" << endl;
    }
}

void demonstrateArray() {

    PointerArray<TestObject> arr(3);

    arr[0] = new TestObject("Первый", 10);
    arr[1] = new TestObject("Второй", 20);
    arr[2] = new TestObject("Третий", 30);

    cout << "Содержимое массива:" << endl;
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "arr[" << i << "]: ";
        arr[i]->print();
    }

    try {
        cout << "Пробуем получить arr[5]: ";
        arr[5]->print();
    }
    catch (const MemoryAccessError&) {
        cout << "Ошибка доступа к памяти!" << endl;
    }
}

void manualInput() {

    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    cin.ignore();

    PointerArray<TestObject> arr(size);

    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Элемент " << i << ":" << endl;
        arr[i] = new TestObject();

        bool inputSuccess = false;
        while (!inputSuccess) {
            try {
                arr[i]->input();
                inputSuccess = true;
            }
            catch (const invalid_argument& e) {
                cout << "Ошибка ввода: " << e.what() << endl;
                cout << "Пожалуйста, введите данные заново:" << endl;
            }
            catch (const exception& e) {
                cout << "Неизвестная ошибка: " << e.what() << endl;
                cout << "Пожалуйста, введите данные заново:" << endl;
            }
        }
        cout << endl;
    }

    cout << "Введенные данные:" << endl;
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "arr[" << i << "]: ";
        arr[i]->print();
    }

    try {
        cout << "Проверка исключения: ";
        arr[arr.getSize() + 1]->print();
    }
    catch (const MemoryAccessError&) {
        cout << "Ошибка доступа к памяти!" << endl;
    }
}

void testInvalidArgument() {
    cout << "3. Тест invalid_argument:" << endl;

    TestObject testObj;

    cout << "Тест 1 - ввод 'abc':" << endl;
    try {
        throw invalid_argument("Некорректный аргумент: 'abc' не является целым числом");
    }
    catch (const invalid_argument& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }

    cout << "Тест 2 - ввод пустой строки:" << endl;
    try {
        throw invalid_argument("Пустая строка не может быть преобразована в число");
    }
    catch (const invalid_argument& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }

    cout << "Тест 3 - ввод значения 1500:" << endl;
    try {
        throw invalid_argument("Значение 1500 вне допустимого диапазона [-1000, 1000]");
    }
    catch (const invalid_argument& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }

    cout << endl;
}

void showExample() {
    cout << "Пример работы" << endl << endl;

    cout << "1. Тест математических ошибок:" << endl;
    testDivision();
    testOverflow();
    cout << endl;

    cout << "2. Тест массива указателей:" << endl;
    demonstrateArray();
    cout << endl;

    testInvalidArgument();
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    cout << "1 - Показать пример" << endl;
    cout << "2 - Ввести данные" << endl;
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
        cout << "Неверный выбор" << endl;
    }

    return 0;
}
