#include <iostream>
#include <string>

using namespace std;

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

class Book : public Publication {
private:
    int pages;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore();
    }

    void putdata() {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
};

class Type : public Publication {
private:
    float time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore();
    }

    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << time << " минут" << endl;
    }
};

void Books() {
    Book book;
    cout << "Ввод данных для книги " << endl << endl;
    book.getdata();
    cout << "Вывод данных книги" << endl << endl;
    book.putdata();
}

void Types() {
    Type audio;
    cout << "Ввод данных для аудиозаписи" << endl << endl;
    audio.getdata();
    cout << "Вывод данных аудиозаписи" << endl << endl;
    audio.putdata();
}

void show() {
    Book bookExample;
    cout << "Пример книги:" << endl << endl;
    cout << "Название: Мастер и Маргарита" << endl;
    cout << "Цена: 450 руб." << endl;
    cout << "Количество страниц: 480" << endl << endl;

    Type audioExample;
    cout << "Пример аудиозаписи:" << endl << endl;
    cout << "Название: Мастер и Маргарита" << endl;
    cout << "Цена: 299.99 руб." << endl;
    cout << "Время записи: 1020.5 минут" << endl << endl;
}

int main() {

    setlocale(LC_ALL, "RU");
    int choice;

    cout << "Демонстрация работы" << endl << endl;
    cout << "1 - Показать пример данных" << endl;
    cout << "2 - Ввести пример данных вручную" << endl;
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
    default:
        cout << "Неверный выбор" << endl;
    }

    return 0;
}
