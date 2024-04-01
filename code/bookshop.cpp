#include "bookshop.h"
#include <iostream>

using namespace std;

int Bookshop::num_of_objects = 0;

Bookshop::Bookshop() {
    m_books = nullptr;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor domyslny klasy Bookshop, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Bookshop::Bookshop(string name, Manager manager) {
    m_name = name;
    m_manager = manager;
    num_of_objects++;
    m_books = nullptr;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor klasy Bookshop, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif

}

Bookshop::Bookshop(const Bookshop &bs) {
    m_name = bs.m_name;
    m_manager = bs.m_manager;
    m_num_of_books = bs.m_num_of_books;

    if (bs.m_books) {
        m_books = new Book[m_num_of_books];
        for (int i = 0; i < m_num_of_books; i++) {
            m_books[i] = bs.m_books[i];
        }
    }
    else
        m_books = nullptr;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor kopiujacy klasy Bookshop, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Bookshop& Bookshop::operator=(const Bookshop &bs) {
    if (this == &bs) {
        return *this;
    }

    m_name = bs.m_name;
    m_manager = bs.m_manager;
    m_num_of_books = bs.m_num_of_books;

    if (m_books) {
        delete[] m_books;
    }

    if (bs.m_books) {
        m_books = new Book[m_num_of_books];
        for (int i = 0; i < m_num_of_books; i++) {
            m_books[i] = bs.m_books[i];
        }
    }
    else
        m_books = nullptr;

    return *this;
}

Bookshop::~Bookshop() {
    if (m_books != nullptr) {
        delete[] m_books;
    }

    num_of_objects--;

    #ifdef _DEBUG
    cout << "Wywolano destruktor klasy Bookshop, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

int Bookshop::numOfElems() {
    return num_of_objects;
}

ostream& operator<<(ostream &s, Bookshop &bs) {
    s << "Nazwa ksiegarni: " << bs.m_name << endl << "Imie managera: " << bs.m_manager.managersName() << endl
      << "Liczba ksiazek: " << bs.m_num_of_books << endl;

    if (bs.m_books)
        for (int i = 0; i < bs.m_num_of_books; i++) {
            s << "Ksiazka nr " << i << ": " << endl << bs.m_books[i] << endl;
        }

    return s;
}

Book& Bookshop::operator[](int i) {
    if (i < 0 || i >= m_num_of_books) {
        throw logic_error( "Nie ma ksiazki o takim indeksie" );
    }
    else
        return m_books[i];
}

Bookshop& Bookshop::operator+=(const Bookshop &bs) {
    int size = m_num_of_books + bs.m_num_of_books;
    Book *tmp_array = new Book[size];
    int a = m_num_of_books;

    for (int i = 0; i < m_num_of_books; i++) {
        tmp_array[i] = m_books[i];
    }

    for (int i = 0; i < bs.m_num_of_books; i++) {
        for (int j = 0; j < m_num_of_books; j++) {
            if (m_books[j] == bs.m_books[i]) {
                size--;
                break;
            }
            if (j == m_num_of_books - 1) {
                tmp_array[a] = bs.m_books[i];
                a++;
            }
        }
    }

    if (m_books)
        delete[] m_books;

    m_num_of_books = size;
    m_books = new Book[size];

    for (int i = 0; i < size; i++) {
        m_books[i] = tmp_array[i];
    }

    delete[] tmp_array;
    return *this;
}

Bookshop::operator string() {
    return (string)"Ksiegarnia: " + m_name + (string)", Manager: " + m_manager.managersName()
           + (string)", Liczba ksiazek: " + to_string(m_num_of_books);
}

Bookshop& Bookshop::operator--() {
    if (!m_books)
        return *this;

    m_num_of_books--;
    Book *tmp = new Book[m_num_of_books];

    for (int i = 0; i < m_num_of_books; i++) {
        tmp[i] = m_books[i];
    }

    delete[] m_books;
    m_books = tmp;
    return *this;
}

void Bookshop::addBook(const Book &b) {
    for (int i = 0; i < m_num_of_books; i++) {
        if (m_books[i] == b)
            return;
    }

    Book *new_m_books = new Book[m_num_of_books + 1];
    for (int i = 0; i < m_num_of_books; i++) {
        new_m_books[i] = m_books[i];
    }

    new_m_books[m_num_of_books] = b;
    m_num_of_books++;

    if (m_books)
        delete[] m_books;
    m_books = new_m_books;
}

void Bookshop::deleteBook(int idx) {
    if (idx < 0 || idx > m_num_of_books - 1)
        return;

    Book *new_m_books = new Book[m_num_of_books - 1];

    for (int i = 0; i < idx; i++) {
        new_m_books[i] = m_books[i];
    }

    for (int i = idx + 1; i < m_num_of_books; i++) {
        new_m_books[i - 1] = m_books[i];
    }

    m_num_of_books--;
    delete[] m_books;
    m_books = new_m_books;
}

