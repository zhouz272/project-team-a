#ifndef OBJPOSARRAYLIST_H
#define OBJPOSARRAYLIST_H

#include "objPos.h"

class objPosArrayList {
   private:
    objPos *aList;
    int sizeList;
    int sizeArray;

    void resizeArray();

   public:
    objPosArrayList();
    ~objPosArrayList();

    void insertHead(const objPos &thisPos);
    void insertTail(const objPos &thisPos);
    void removeHead();
    void removeTail();
    objPos getHeadElement() const;
    objPos getTailElement() const;
    objPos getElement(int index) const;
    int getSize() const;
};

#endif