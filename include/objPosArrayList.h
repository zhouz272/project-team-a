#ifndef OBJPOSARRAYLIST_H
#define OBJPOSARRAYLIST_H

#include "objPos.h"

class objPosArrayList {
   private:
    objPos* aList;  // Dynamic array to store objPos objects
    int sizeList;   // Number of elements in the list
    int sizeArray;  // Capacity of the array

    // Helper function to resize the array
    void resizeArray();

   public:
    // Constructors and Destructor
    objPosArrayList();   // Default constructor
    ~objPosArrayList();  // Destructor

    // Basic List Operations
    int getSize() const;                     // Get the current size of the list
    void insertHead(const objPos& thisPos);  // Insert at the head
    void insertTail(const objPos& thisPos);  // Insert at the tail
    void removeHead();                       // Remove from the head
    void removeTail();                       // Remove from the tail
    objPos getHeadElement() const;           // Get the head element
    objPos getTailElement() const;           // Get the tail element
    objPos getElement(int index) const;      // Get an element by index
};

#endif  // OBJPOSARRAYLIST_H
