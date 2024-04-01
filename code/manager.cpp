#include "manager.h"
#include <iostream>

using namespace std;

int Manager::num_of_objects = 0;

Manager::Manager() {
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor domyslny klasy Manager, aktualna liczba obiektow tej klasy: " << num_of_objects  << endl;
    #endif
}

Manager::Manager(string name) {
    m_name = name;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor klasy Manager, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif 
}

Manager::Manager(const Manager &m) {
    m_name = m.m_name;
    num_of_objects++;

    #ifdef _DEBUG
    cout << "Wywolano konstruktor kopiujacy klasy Manager, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

Manager::~Manager() {
    num_of_objects--;

    #ifdef _DEBUG
    cout << "Wywolano destruktor klasy Manager, aktualna liczba obiektow tej klasy: " << num_of_objects << endl;
    #endif
}

string Manager::managersName() {
    return m_name;
}

Manager& Manager::operator=(const Manager &m) {
    if (this == &m) {
        return *this;
    }

    m_name = m.m_name;

    return *this;
}
