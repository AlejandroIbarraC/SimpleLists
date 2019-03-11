#include <iostream>
#include "List/List.cpp"
#include "List/Collector.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


int main(int argc, char* argv[]) {

    Collector& thanos = Collector::getInstance();

    List a;
    a.add(1);
    a.add(2);
    a.add(5);
    a.add(15);
    a.add(20);
    a.add(123);
    a.del(a.gethead()->next);
    a.del(a.gethead());
    a.display();

    cout << a.getLength() << endl;

    thanos.display();

    std::cout << "Hello, World!" << std::endl;
    return RUN_ALL_TESTS();
}