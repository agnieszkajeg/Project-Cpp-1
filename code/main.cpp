#include <iostream>
#include "bookshop.h"

using namespace std;

//Tworzenie obiektów globalnych
static Book b5("Lalka", 1890), b6("Anna Karenina", 1875);
static Manager m3("Jakub Wisniewski");
static Bookshop bs5("Kolorowa", m3);

int main()
{
    //Tworzenie obiektów automatyczne
    cout << endl << "Obiekty lokalne:" << endl;
    Manager m1(m3); //Konstruktor kopiujący
    Bookshop bs1, bs2("Bonito", m1);
    Book b2("Duma i uprzedzenie", 1813), b3("Hobbit", 1937), b4("Chlopi", 1902);

    //Tworzenie obiektów dynamicznych
    cout << endl <<  "Obiekty dynamiczne:" << endl;
    Manager *m2 = new Manager("Tomasz Nowak");
    Book *b1 = new Book("Maly Ksiaze", 1943);
    Book *b7 = new Book(b3); //Konstruktor kopiujący
    Book *b8 = new Book("Buszujacy w zbozu", 1951);
    Bookshop *bs3 = new Bookshop("Swiat Ksiazek", *m2);

    //Tworzenie obiektów statycznych
    cout << endl <<  "Obiekty statyczne:" << endl;
    static Book b9("Wyspa skarbow", 1883);
    static Manager m4("Wojciech Ostrowski");

    //Testuję metodę dodającą książki
    cout << endl <<  "Test metody dodajacej ksiazke:" << endl;
    bs3->addBook(b2);
    bs3->addBook(b3);
    bs3->addBook(b5);

    bs2.addBook(*b1);
    bs2.addBook(*b7);
    bs2.addBook(b6);

    bs5.addBook(b4);
    bs5.addBook(b9);
    bs5.addBook(*b8);

    //Testuję konstruktor kopiujący
    cout << endl <<  "Konstruktor kopiujacy:" << endl;
    static Bookshop bs4(bs2);

    //Testuję operator strumieniowy
    cout << endl <<  "Test operatora strumieniowego:" << endl;
    cout << *bs3;
    cout << endl << bs4;
    cout << endl << bs5;

    //Testuję operator konwersji
    cout << endl <<  "Test operatora konwersji:" << endl;
    cout << string(bs5) << endl;

    //Testuję operator jednoargumentowy - dekrementacja
    cout << endl <<  "Test operatora dekrementacji:" << endl;
    --(*bs3);
    cout << endl << *bs3;

    //Testuję operator przypisania
    cout << endl <<  "Test operatora przypisania:" << endl;
    bs1 = bs5;
    cout << endl << bs1;

    //Testuję operator indeksowy
    cout << endl <<  "Test operatora indeksowego:" << endl;
    try {
        cout << (*bs3)[1] << endl;
    }
    catch (logic_error &e) {
        cout << "Blad: " << e.what() << endl;
    }
    try {
        cout << (*bs3)[10] << endl;
    }
    catch (logic_error &e) {
        cout << "Blad: " << e.what() << endl;
    }

    //Testuję operator dwuargumentowy: +=
    cout << endl <<  "Test operatora +=:" << endl;
    bs1 += *bs3;
    cout << endl << bs1 << endl;

    //Testuję metodę usuwającą książkę z tablicy
    cout << endl <<  "Test metody usuwajacej ksiazke:" << endl;
    bs1.deleteBook(0);
    cout << endl << bs1;
    bs1.deleteBook(10);
    cout << endl << bs1;

    //Testuję statyczną metodę podającą liczbę obiektów
    cout << endl <<  "Test statycznego pola i statycznej metody:" << endl;
    cout << Bookshop::numOfElems() << endl << bs1.numOfElems() << endl;

    //Usuwanie obiektow dynamicznych
    cout << endl <<  "Usuwanie obiektow:" << endl;
    delete m2;
    delete b7;
    delete b8;
    delete b1;
    delete bs3;

    return 0;
}
