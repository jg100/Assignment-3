// Start of Program
#include "LinkedBag.h" // Pre-Defined Methods
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Adding New Node Method
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
    Node<ItemType>* newPtr = new Node<ItemType>;
    newPtr->setItem(newEntry);

    // Checks if the bag is empty or not
    if (!isEmpty()) {
        Node<ItemType>* tPtr = headPtr;
        newPtr->setNext(nullptr);

        // Keep finding until it satisfies the condition
        while (tPtr->getNext() != nullptr) {
            tPtr = tPtr->getNext();
        }

        tPtr->setNext(newPtr);
        itemCount++;
        return true;

    } else {
        add(newEntry);
    }
    return false;
}

// Removing Random Node Method
template <typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    // Method for finding deletedNode
    int deletedNode;
    srand((unsigned)time(NULL));
    deletedNode = rand() % getCurrentSize();

    Node<ItemType>* cPtr = headPtr;

    for (int i = 1; i <= deletedNode; i++) {
        cPtr = cPtr->getNext();
    }
    ItemType value = cPtr->getItem();
    remove(cPtr->getItem());
    return value;
}

// Removing 2nd Node Method
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    Node<ItemType>* nodeToRemove = headPtr->getNext();
    return remove(nodeToRemove->getItem());
}

// Size, Recursive Method
// Simple Implementation
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

    // Calling Helper Method
    return getCurrentSize340RecursiveHelper(headPtr);
} 

// Size, Recursive with Helper Method
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const {
    int count = 0;
    static Node<ItemType>* tPtr = node;

    // Checks if tPtr is equal to a null pointer
    if (tPtr == nullptr) {
        tPtr = node;
        return 0;
    } else {
       tPtr = tPtr->getNext();
       count++;
       // Calling itself
       return (count + getCurrentSize340RecursiveHelper(tPtr));
    }
}

// Size, Recursive no Helper Method
template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    int count = 0;
    static Node<ItemType>* tPtr = headPtr;

    // Checks if tPtr is equal to a null pointer
    if (tPtr == nullptr) {
        tPtr = headPtr;
        return 0;
    } else {
        tPtr = tPtr->getNext();
        count++;
        // Calling itself
        return (count + getCurrentSize340RecursiveNoHelper());
    }
}

// Size, Iterative Method
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int counter = 1;

    // Checks if the bag is empty or not
    if (!isEmpty()) {
        Node<ItemType>* tPtr = headPtr;

        // Keep finding until it satisfies the condition
        while (tPtr->getNext() != nullptr) {
            tPtr = tPtr->getNext();
            counter++;
        }
    }
    return counter;
}

// Frequency, Recursive Method
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& value) const {

    // Calling Helper Method
    return getFrequencyOf340RecursiveHelper(headPtr, value);
}

// Frequency, Helper Method
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* cPtr, const ItemType& value) const {
    static Node<ItemType>* tPtr = headPtr;
    int count = 0;

    if (tPtr == nullptr) {
        tPtr = headPtr;
        return 0;
    }

    if (tPtr->getItem() == value) {
        tPtr = tPtr->getNext();
        count++;
        return count + getFrequencyOf340RecursiveHelper(tPtr, value);
    }

    tPtr = tPtr->getNext();
    return count + getFrequencyOf340RecursiveHelper(tPtr, value);
}

// Frequency, Recursive no Helper Method
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& value) const {
    int count = 0;
    static Node<ItemType>* tPtr = headPtr;

    if (tPtr == nullptr) {
        tPtr = headPtr;
        return 0;
    }

    if (tPtr->getItem() == value) {
        tPtr = tPtr->getNext();
        count++;
        return count + getFrequencyOf340RecursiveNoHelper(value);
    }

    tPtr = tPtr->getNext();
    return count + getFrequencyOf340RecursiveNoHelper(value);
}