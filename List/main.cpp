#include <iostream>
#include "List.cpp"
#include "Collector.cpp"

int main() {
    // Call collector and create list
    Collector& thanos = Collector::getInstance();
    List list;

    // Add items to list
    list.add(1);
    list.add(2);
    list.add(5);
    list.add(15);
    list.add(20);
    list.add(123);

    // Print original list
    cout << "Original list:" << endl;
    list.display();

    // Print original collector
    cout << "Empty collector:" << endl;
    thanos.display();

    // Remove items
    cout << "Removing items..." << endl;
    list.remove(1);
    list.remove(2);
    list.remove(20);

    // Print list with removals
    cout << "List with removals:" << endl;
    list.display();

    // Print collector with removals
    cout << "Collector with removals:" << endl;
    thanos.display();

    // Add new items
    cout << "Adding new items..." << endl;
    list.add(12);
    list.add(100);
    list.add(30);

    // Print list with additions
    cout << "List with additions:" << endl;
    list.display();

    // Print collector with additions
    cout << "Collector with additions:" << endl;
    thanos.display();

    std::cout << "Goodbye, World!" << std::endl;
    return 0;
}