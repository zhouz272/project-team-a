#include "../include/objPosArrayList.h"

#include <iostream>
#include <stdexcept>  // For exceptions

// Default Constructor
objPosArrayList::objPosArrayList() : sizeList(0), sizeArray(10) {
    aList = new objPos[sizeArray];
}

// Destructor
objPosArrayList::~objPosArrayList() {
    delete[] aList;
}

// Helper function to resize the array
void objPosArrayList::resizeArray() {
    sizeArray *= 2;
    objPos* newList = new objPos[sizeArray];
    for (int i = 0; i < sizeList; ++i) {
        newList[i] = aList[i];
    }
    delete[] aList;
    aList = newList;
}

// Get the current size of the list
int objPosArrayList::getSize() const {
    return sizeList;
}

// Insert at the head
void objPosArrayList::insertHead(const objPos& thisPos) {
    if (sizeList >= sizeArray) {
        resizeArray();
    }
    for (int i = sizeList; i > 0; --i) {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    ++sizeList;
}

// Insert at the tail
void objPosArrayList::insertTail(const objPos& thisPos) {
    if (sizeList >= sizeArray) {
        resizeArray();
    }
    aList[sizeList++] = thisPos;
}

// Remove from the head
void objPosArrayList::removeHead() {
    if (sizeList == 0) {
        throw std::out_of_range("List is empty");
    }
    for (int i = 0; i < sizeList - 1; ++i) {
        aList[i] = aList[i + 1];
    }
    --sizeList;
}

// Remove from the tail
void objPosArrayList::removeTail() {
    if (sizeList == 0) {
        throw std::out_of_range("List is empty");
    }
    --sizeList;
}

// Get the head element
objPos objPosArrayList::getHeadElement() const {
    if (sizeList == 0) {
        throw std::out_of_range("List is empty");
    }
    return aList[0];
}

// Get the tail element
objPos objPosArrayList::getTailElement() const {
    if (sizeList == 0) {
        throw std::out_of_range("List is empty");
    }
    return aList[sizeList - 1];
}

// Get an element by index
objPos objPosArrayList::getElement(int index) const {
    if (index < 0 || index >= sizeList) {
        throw std::out_of_range("Index out of range");
    }
    return aList[index];
}
