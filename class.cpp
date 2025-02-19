#include <iostream>
#include "class.h"

using namespace std;
Person::Person(const string& ln, const string& fn, const string& pn) {
    lastName = ln;
    firstName = fn;
    patronymic = pn;
}


void Person::Show() {
    cout << "Name and Last_name: "<< lastName << " " << firstName << endl;
}
void Person::ShowFormal() {
    cout <<"FIO: " << lastName << " " << firstName << " " << patronymic << endl;
}