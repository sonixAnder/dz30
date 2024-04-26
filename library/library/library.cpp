#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Book
{
    string title;
    string author;
    string publisher;
    string genre;
};

// Функции для сортировки (используя sort и лямбда-выражения)
bool compareByTitle(const Book& a, const Book& b)
{
    return a.title < b.title;
}

bool compareByAuthor(const Book& a, const Book& b)
{
    return a.author < b.author;
}

bool compareByPublisher(const Book& a, const Book& b)
{
    return a.publisher < b.publisher;
}

// Функция для печати информации о книге
void printBook(const Book& book)
{
    cout << "Название: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << "------------------------" << endl;
}

//редактирование книг
void editBook(Book& book)
{
    cout << "Введите новое название: ";
    getline(cin >> ws, book.title); // ws для удаления пробелов

    cout << "Введите нового автора: ";
    getline(cin, book.author);

    cout << "Введите новое издательство: ";
    getline(cin, book.publisher);

    cout << "Введите новый жанр: ";
    getline(cin, book.genre);
}

//поиск книги по автору
vector<Book> searchByAuthor(const vector<Book>& books, const string& author)
{
    vector<Book> foundBooks;
    for (const Book& book : books)
    {
        if (book.author == author)
        {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

//поиск книги по названию 
vector<Book> searchByTitle(const vector<Book>& books, const string& title)
{
    vector<Book> foundBooks;
    for (const Book& book : books)
    {
        if (book.title == title)
        {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

//печать всех книг
void printBooks(const vector<Book>& books)
{
    if (books.empty())
    {
        cout << "Библиотека пуста.\n";
    }
    else
    {
        for (const Book& book : books)
        {
            printBook(book);
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    vector<Book> books(10);
    books[0] = { "Атака титанов", "Хадзимэ Исаяма", "Азбука", "Роман" };
    books[1] = { "Клинок рассекающий демонов", "Коёхару, Готогэ", "Истари Комикс", "Боевые исскуства" };
    books[2] = { "Магическая битва.", "Акутами Гэгэ", "Азбука", "Сёнен" };
    books[3] = { "Берсерк", "Миура Кэнтаро", "XL Media", "Сэйнен, ужасы" };
    books[4] = { "Поднятие уровня в одиночку", "Чан Соннак", "АСТ", "Сверхъестественное,Боевик" };
    books[5] = { "Человек-Бензопила", "Фудзимото Тацуки", "Азбука", "Сёнэн,Сверхъестественное" };
    books[6] = { "Преступление и наказание", "Ооба Цугуми", "Азбука", "Психологическое" };
    books[7] = { "Токийский гуль", "Исида Суи", "Азбука", "Сэйнэн,Ужасы" };
    books[8] = { "Твоё имя", "Синкай Макото", "Истари Комикс", "Сэйнэн,Сверхъестественное" };
    books[9] = { "Созданный в бездне", "Цукуси Акихито", "АСТ", "Сэйнэн,Фэнтези" };

    while (true)
    {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Редактировать книгу\n";
        cout << "3. Печать всех книг\n";
        cout << "4. Поиск книг по автору\n";
        cout << "5. Поиск книги по названию\n";
        cout << "6. Сортировка по названию\n";
        cout << "7. Сортировка по автору\n";
        cout << "8. Сортировка по издательству\n";
        cout << "9. Выход\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        { // Добавить книгу
            if (books.size() == 10)
            {
                cout << "Библиотека полна. Нельзя добавить больше книг.\n";
            }
            else
            {
                Book newBook;
                cout << "Введите название: ";
                getline(cin >> ws, newBook.title);
                cout << "Введите автора: ";
                getline(cin, newBook.author);
                cout << "Введите издательство: ";
                getline(cin, newBook.publisher);
                cout << "Введите жанр: ";
                getline(cin, newBook.genre);
                books.push_back(newBook);
                cout << "Книга добавлена!\n";
            }
            break;
        }
        case 2: // Редактировать книгу
        {  
            cout << "Введите номер книги для редактирования (1-10): ";
            int index;
            cin >> index;
            if (index >= 1 && index <= books.size())
            {
                editBook(books[index - 1]);
                cout << "Книга отредактирована!\n";
            }
            else
            {
                cout << "Неверный номер книги.\n";
            }
            break;
        }
        case 3: // Печать всех книг 
        {
            printBooks(books);
            break;
        }
        case 4:
        { // Поиск книг по автору 
            string author;
            cout << "Введите автора для поиска: ";
            getline(cin >> ws, author);
            vector<Book> foundBooks = searchByAuthor(books, author);
            printBooks(foundBooks);
            break;
        }
        case 5: // Поиск книги по названию
        {
            string title;
            cout << "Введите название для поиска: ";
            getline(cin >> ws, title);
            vector<Book> foundBooks = searchByTitle(books, title);
            printBooks(foundBooks);
            break;
        }
        case 6: // Сортировка по названию 
        {
            sort(books.begin(), books.end(), compareByTitle);
            cout << "Книги отсортированы по названию.\n";
            break;
        }
        case 7: // Сортировка по автору
        {
            sort(books.begin(), books.end(), compareByAuthor);
            cout << "Книги отсортированы по автору.\n";
            break;
            
        }
            
        case 8: // Сортировка по издательству
        {
            sort(books.begin(), books.end(), compareByPublisher);
            cout << "Книги отсортированы по издательству.\n";
            break;
        }
        case 9: // Выход
            return 0;
        default:
            cout << "Неверный выбор.\n";
        }
    }
}

