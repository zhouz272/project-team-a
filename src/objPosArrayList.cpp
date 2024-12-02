#include "../include/objPosArrayList.h"

#include <stdexcept>  // support std::out_of_range

objPosArrayList::objPosArrayList() : sizeList(0), sizeArray(10) {
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList() {
    delete[] aList;
}

void objPosArrayList::insertHead(const objPos &thisPos) {
    if (sizeList >= sizeArray) resizeArray();
    for (int i = sizeList; i > 0; --i) {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    ++sizeList;
}

void objPosArrayList::insertTail(const objPos &thisPos) {
    if (sizeList >= sizeArray) resizeArray();
    aList[sizeList++] = thisPos;
}

void objPosArrayList::removeHead() {
    if (sizeList == 0) {
        throw std::out_of_range("List is empty");
    }
    for (int i = 0; i < sizeList - 1; ++i) {
        aList[i] = aList[i + 1];
    }
    --sizeList;
}

void objPosArrayList::removeTail() {
    if (sizeList > 0) --sizeList;
}

objPos objPosArrayList::getHeadElement() const {
    return aList[0];
}

objPos objPosArrayList::getTailElement() const {
    return aList[sizeList - 1];
}

objPos objPosArrayList::getElement(int index) const {
    if (index < 0 || index >= sizeList) {
        throw std::out_of_range("Index out of range");
    }
    return aList[index];
}

int objPosArrayList::getSize() const {
    return sizeList;
}

void objPosArrayList::resizeArray() {
    sizeArray *= 2;
    objPos *newList = new objPos[sizeArray];
    for (int i = 0; i < sizeList; ++i) {
        newList[i] = aList[i];
    }
    delete[] aList;
    aList = newList;
}
