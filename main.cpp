#include "class.h"

int main() {
    Person person0("Param", "Dan", "Uzbekobvich");
    Person person1("Gasparyan", "Artem", "Artem");
    person0.Show();
    person0.ShowFormal();

    person1.Show();
    person1.ShowFormal();

    return 0;
};
