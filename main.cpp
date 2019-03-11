#include <iostream>
#include "List/List.cpp"
#include "List/Collector.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(Listtests, ListStartsEmpty)
{
    List list;
    EXPECT_EQ(0, list.getLength());
}

TEST(ListTests, createList)
{
    List list;
    Collector& thanos = Collector::getInstance();
    // Add items to list
    list.add(1);
    list.add(2);
    list.add(5);
    list.add(15);
    list.add(20);
    list.add(123);
    EXPECT_EQ(6, list.getLength());
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
    EXPECT_EQ(3, list.getLength());
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
    EXPECT_EQ(6, list.getLength());
    // Print list with additions
    cout << "List with additions:" << endl;
    list.display();
    // Print collector with additions
    cout << "Collector with additions:" << endl;
    thanos.display();
}





int main(int argc, char* argv[]) {



    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}