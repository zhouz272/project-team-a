#include <iostream>

#include "../include/objPosArrayList.h"

void testObjPosArrayList() {
    objPosArrayList list;

    // Test inserting at the tail
    list.insertTail(objPos(1, 1, 'A'));
    list.insertTail(objPos(2, 2, 'B'));
    list.insertTail(objPos(3, 3, 'C'));

    // Print the list
    std::cout << "After inserting at the tail:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        list.getElement(i).print();
    }

    // Test inserting at the head
    list.insertHead(objPos(0, 0, 'Z'));
    std::cout << "After inserting at the head:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        list.getElement(i).print();
    }

    // Test removing from the head
    list.removeHead();
    std::cout << "After removing the head:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        list.getElement(i).print();
    }

    // Test removing from the tail
    list.removeTail();
    std::cout << "After removing the tail:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        list.getElement(i).print();
    }
}

int main() {
    testObjPosArrayList();
    return 0;
}
