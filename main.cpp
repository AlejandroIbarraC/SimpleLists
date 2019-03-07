#include <iostream>
#include "List.cpp"
#include "Collector.cpp"

int main() {

    List a;
    a.add(1);
    a.add(2);
    a.add(5);
    a.add(15);
    a.del(a.gethead()->next);
    a.display();

    cout << a.getLength() << endl;

    Collector& thanos = Collector::getInstance();
    thanos.display();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}