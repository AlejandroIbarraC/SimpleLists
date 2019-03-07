#include <iostream>
#include "list.cpp"

int main() {

    list a;
    a.add(1);
    a.add(2);
    a.front(3);
    a.add(5);
    a.add(15);
    a.after(a.gethead()->next->next->next, 10);
    a.del(a.gethead()->next);
    a.display();

    cout << a.getLength() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}