#ifndef MANAGER_H
#define MANAGER_H

#include <string>
using namespace std;

class Manager {
public:
    Manager();
    Manager(string);
    Manager(const Manager&);

    Manager& operator=(const Manager&);

    string managersName();

    ~Manager();

private:
    string m_name = "";
    static int num_of_objects;
};

#endif // MANAGER_H
