#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

struct Book {
    int udc;
    std::string author;
    std::string title;
    int year;
    int access_count;

    // Конструктор для удобного создания объектов Book
    Book(int u, std::string a, std::string t, int y, int ac)
        : udc(u), author(a), title(t), year(y), access_count(ac) {}
};

// Функция для сравнения книг по году издания (для сортировки)
bool compareByYear(const Book& a, const Book& b) {
    return a.year < b.year;
}

// Функция для вывода информации о книге
void printBook(const Book& book) {
    std::cout << "УДК: " << book.udc << ", Автор: " << book.author
        << ", Название: " << book.title << ", Год издания: "
        << book.year << ", Количество обращений: " << book.access_count
        << std::endl;
}

// Функция для вывода всей очереди
void printQueue(std::queue<Book> q) {
    while (!q.empty()) {
        printBook(q.front());
        q.pop();
    }
}

// Функция для удаления книг с количеством обращений меньше заданного
void removeBooksWithLowAccess(std::queue<Book>& q, int minAccessCount) {
    std::queue<Book> tempQueue;
    while (!q.empty()) {
        if (q.front().access_count >= minAccessCount) {
            tempQueue.push(q.front());
        }
        q.pop();
    }
    q = tempQueue;
}

int main() {
    // Вектор для начального хранения книг (для сортировки)
    std::vector<Book> books = {
        {123, "Иванов И.И.", "Программирование", 2005, 15},
        {456, "Петров П.П.", "Алгоритмы", 2010, 10},
        {789, "Сидоров С.С.", "Данные структуры", 2008, 8},
        {101, "Кузнецов К.К.", "Базы данных", 2015, 20}
    };

    // Сортировка книг по году издания
    std::sort(books.begin(), books.end(), compareByYear);

    // Очередь для хранения книг
    std::queue<Book> bookQueue;

    // Заполнение очереди отсортированными книгами
    for (const auto& book : books) {
        bookQueue.push(book);
    }

    // Вывод начальной очереди на экран
    std::cout << "Начальная очередь книг:" << std::endl;
    printQueue(bookQueue);

    // Удаление книг с количеством обращений меньше заданного
    int minAccessCount = 10;
    removeBooksWithLowAccess(bookQueue, minAccessCount);

    // Вывод очереди после удаления
    std::cout << "\nОчередь книг после удаления с количеством обращений меньше " << minAccessCount << ":" << std::endl;
    printQueue(bookQueue);

    return 0;
}