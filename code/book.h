#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    Book();
    Book(string, int);
    Book(const Book&);

    Book& operator=(const Book&);
    bool operator==(const Book&);
    friend ostream& operator<<(ostream&, Book&);

    ~Book();

private:
    string m_title = "";
    int m_release_year = 0;
    static int num_of_objects;
};

#endif // BOOK_H
