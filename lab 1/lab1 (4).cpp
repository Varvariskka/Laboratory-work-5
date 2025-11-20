#include <iostream>
#include <string>
using namespace std;

const int FICTION = 0;
const int TECHNICAL = 1;
const int MAX_BOOKS = 100;

struct Book
{
    string author;
    string name;
    int genre; 
};

void addBook(Book library[], int& count, string author, string name, int genre)
{
    if (count >= MAX_BOOKS) {
        cout << "Библиотека переполнена!" << endl;
        return;
    }

    if (author.empty()) {
        cout << "У книги нет автора." << endl;
        return;
    }

    if (name.empty()) {
        cout << "У книги нет названия." << endl;
        return;
    }

    library[count].author = author;
    library[count].name = name;
    library[count].genre = genre;

    count++;
}

string getGenreName(int genre)
{
    if (genre == FICTION) {
        return "Художественная";
    }
    else if (genre == TECHNICAL) {
        return "Техническая";
    }
    else {
        return "Неизвестный жанр";
    }
}

void countWithSwitch(Book library[], int count)
{
    int fictionCount = 0;
    int technicalCount = 0;

    for (int i = 0; i < count; i++) {
        switch (library[i].genre) {
        case FICTION:
            fictionCount++;
            break;
        case TECHNICAL:
            technicalCount++;
            break;
        default: 
            break;
        }
    }

    cout << "С помощью оператора switch:" << endl;
    cout << "Количество художественной литературы: " << fictionCount << endl;
    cout << "Количество технической литературы: " << technicalCount << endl;
}

void countWithIfElse(Book library[], int count)
{
    int fictionCount = 0;
    int technicalCount = 0;

    for (int i = 0; i < count; i++) {
        if (library[i].genre == FICTION) {
            fictionCount = fictionCount + 1;
        }
        else if (library[i].genre == TECHNICAL) {
            technicalCount = technicalCount + 1;
        }
    }

    cout << "С помощью конструкции if/else:" << endl;
    cout << "Количество художественной литературы: " << fictionCount << endl;
    cout << "Количество технической литературы: " << technicalCount << endl;
}

void printLibrary(Book library[], int count)
{
    cout << "Список книг в библиотеке:" << endl;

    if (count == 0) {
        cout << "Библиотека пуста." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". Автор: " << library[i].author;
        cout << ", Название: " << library[i].name;
        cout << ", Жанр: " << getGenreName(library[i].genre) << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    Book library[MAX_BOOKS];

    int bookCount = 0;

    addBook(library, bookCount, "Ф.М. Достоевский", "Преступление и наказание", FICTION);
    addBook(library, bookCount, "", "Горе от ума", FICTION); 
    addBook(library, bookCount, "М.А. Булгаков", "", FICTION); 
    addBook(library, bookCount, "В.В. Захаров", "Тестирование программного обеспечения. Основы", TECHNICAL);
    addBook(library, bookCount, "Л.Н. Толстой", "Война и мир", FICTION);
    addBook(library, bookCount, "А.А. Ладенко", "Основы строительства нефтяных и газовых скважин", TECHNICAL);

    cout << endl;

    printLibrary(library, bookCount);

    cout << endl;

    countWithSwitch(library, bookCount);
    cout << endl;
    countWithIfElse(library, bookCount);
    cout << endl;

    cout << "Всего книг в библиотеке: " << bookCount << endl;

    return 0; 
}
