#include <iostream>
#include <string>

using namespace std;

class Sales {
protected:
    float sales[3]; 
public:
    void getSales() {
        cout << "Введите продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }

    void putSales() {
        cout << "Продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите название: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore();
    }

    void putdata() {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

class Book : public Publication, public Sales {
private:
    int pages;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore();
        Sales::getSales();
    }

    void putdata() {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        Sales::putSales();
    }
};

class Type : public Publication, public Sales {
private:
    float time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore();
        Sales::getSales();
    }

    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << time << " минут" << endl;
        Sales::putSales();
    }
};

void Books() {
    Book book;
    cout << endl;
    cout << "Ввод данных для книги: " << endl << endl;
    book.getdata();
    cout << endl << "Вывод данных книги: " << endl << endl;
    book.putdata();
}

void Types() {
    Type audio;
    cout << endl;
    cout << "Ввод данных для аудиозаписи: " << endl << endl;
    audio.getdata();
    cout << endl << "Вывод данных аудиозаписи: " << endl << endl;
    audio.putdata();
}

void show() {
    Book bookExample;
    cout << "Пример книги:" << endl << endl;
    cout << "Название: Мастер и Маргарита" << endl;
    cout << "Цена: 450 руб." << endl;
    cout << "Количество страниц: 480" << endl;
    cout << "Продажи за последние 3 месяца:" << endl;
    cout << "Месяц 1: 12000 руб." << endl;
    cout << "Месяц 2: 15000 руб." << endl;
    cout << "Месяц 3: 11000 руб." << endl << endl;

    Type audioExample;
    cout << "Пример аудиозаписи:" << endl << endl;
    cout << "Название: Мастер и Маргарита" << endl;
    cout << "Цена: 299.99 руб." << endl;
    cout << "Время записи: 1020.5 минут" << endl;
    cout << "Продажи за последние 3 месяца:" << endl;
    cout << "Месяц 1: 8500.5 руб." << endl;
    cout << "Месяц 2: 9200.75 руб." << endl;
    cout << "Месяц 3: 7800.25 руб." << endl << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    cout << "Демонстрация работы" << endl << endl;
    cout << "1 - Показать пример данных" << endl;
    cout << "2 – Ввести пример данных вручную" << endl << endl;
    cout << "Выберите действие: ";
    cin >> choice;
    cin.ignore();
    cout << endl;

    switch (choice) {
    case 1:
        show();
        break;
    case 2:
        Books();
        Types();
        break;
        cout << "Неверный выбор" << endl;
    }

    return 0;
}
