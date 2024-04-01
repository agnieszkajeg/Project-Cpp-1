#ifndef BOOKSHOP_CLASS_H
#define BOOKSHOP_CLASS_H

#include "manager.h"
#include "book.h"

class Bookshop {
public:
    Bookshop();
    Bookshop(string, Manager);
    Bookshop(const Bookshop&);

    void addBook(const Book&);
    void deleteBook(int);
    static int numOfElems();

    Bookshop& operator=(const Bookshop&);
    Book& operator[](int);
    Bookshop& operator+=(const Bookshop&);
    Bookshop& operator--();
    operator string();  
    friend ostream& operator<<(ostream&, Bookshop&);

    ~Bookshop();

private:
    string m_name = "";
    Manager m_manager;
    Book *m_books;
    int m_num_of_books = 0;
    static int num_of_objects;
};

#endif // BOOKSHOP_CLASS_H
