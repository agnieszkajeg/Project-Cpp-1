#include "book.h"
#include <iostream>

using namespace std;

int Book::num_of_objects = 0;

Book::Book() {
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor domyslny klasy Book, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Book::Book(string title, int release_year) {
    m_title = title;
    m_release_year = release_year;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor klasy Book, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif

}

Book::Book(const Book &b) {
    m_title = b.m_title;
    m_release_year = b.m_release_year;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor kopiujacy klasy Book, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Book::~Book() {
    num_of_objects--;

    #ifdef _DEBUG
    cout << "Wywolano destruktor klasy Book, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Book& Book::operator=(const Book &b) {
    if (this == &b) {
        return *this;
    }

    m_title = b.m_title;
    m_release_year = b.m_release_year;

    return *this;
}

bool Book::operator==(const Book &b) {
    if (this == &b)
        return true;

    if (m_title == b.m_title && m_release_year == b.m_release_year)
        return true;

    return false;
}

ostream& operator<<(ostream &s, Book &b) {
    return s << "Tytul: " << b.m_title << endl << "Rok wydania: " << b.m_release_year;
}

