
//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>			ok		<===
*/
#include "LinkedBag.h"

#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

    Node<ItemType> *nodeToDelete = headPtr->getNext();
    return remove(nodeToDelete->getItem());
}



template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {


    Node<ItemType>* newNodePtr = new Node<ItemType>;
    newNodePtr->setItem(newEntry);

    if (!isEmpty()) { //accounts for a bag of size 0
        Node<ItemType>* traversePtr = headPtr;
        newNodePtr->setNext(nullptr);

        while (traversePtr->getNext() != nullptr) {
            traversePtr = traversePtr->getNext(); //Last node
        }

        traversePtr->setNext(newNodePtr);
        itemCount++;
        return true;

    } //end if statement

    else if (isEmpty()) {

        //Wold adding this work.
        add(newEntry);

        //return true;
    }
    else {
        return false;
    }

}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 1;

    if (!isEmpty()) {
        Node<ItemType>* traversePtr = headPtr;
        while (traversePtr->getNext() != nullptr) {
            traversePtr = traversePtr->getNext(); //Last node
            count++;
        }
    }

    return count;
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

    return getCurrentSize340RecursiveHelper(headPtr);


} //Heloer function defined bellow

/* Questions
 Where should we define static? Will another call to static


 */


 //Isnt this a private function? How is this file able to acess method?
 //Is it because this file is meant to define the class methods in the .h file.
 //Helper file
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* testNode) const {
    int countHelper = 0;

    //Not going to work, bc every call reset the traversalPtr

    //cool beans.
    static Node<ItemType>* traversalPointer = testNode;


    if (traversalPointer == nullptr) {
        traversalPointer = testNode;
        return 0;
    }

    else {
        traversalPointer = traversalPointer->getNext();
        countHelper++;
        return (countHelper + getCurrentSize340RecursiveHelper(traversalPointer));
    }
} //End helper function



//test 6
//No helper function
template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    int countNoHelper = 0;

    //Not going to work, bc every call reset the traversalPtr

    //cool beans.
    static Node<ItemType>* traversalPointer = headPtr;


    if (traversalPointer == nullptr) {
        traversalPointer = headPtr;
        return 0;
    }

    else {
        traversalPointer = traversalPointer->getNext();
        countNoHelper++;
        return (countNoHelper + getCurrentSize340RecursiveNoHelper());
    }

}





template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& searchedValue) const {

    return getFrequencyOf340RecursiveHelper(headPtr, searchedValue);
}


//Private
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currentPtr, const ItemType& searchedValue) const {

    //cool beans.
    static Node<ItemType>* traversalPointer = headPtr;
    int freqCount = 0;

    if (traversalPointer == nullptr) {
        traversalPointer = headPtr;
        return 0;
    }

    if (traversalPointer->getItem() == searchedValue) {
        traversalPointer = traversalPointer->getNext();
        freqCount++;
        return (freqCount + getFrequencyOf340RecursiveHelper(traversalPointer, searchedValue));
    }

    traversalPointer = traversalPointer->getNext();
    getFrequencyOf340RecursiveHelper(traversalPointer, searchedValue);
}



//test 8
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& searchedValue) const {

    //cool beans.
    static Node<ItemType>* traversalPointer = headPtr;
    int freqCount = 0;

    if (traversalPointer == nullptr) {
        traversalPointer = headPtr;
        return 0;
    }

    if (traversalPointer->getItem() == searchedValue) {
        traversalPointer = traversalPointer->getNext();
        freqCount++;
        return (freqCount + getFrequencyOf340RecursiveNoHelper(searchedValue));
    }

    traversalPointer = traversalPointer->getNext();
    getFrequencyOf340RecursiveNoHelper(searchedValue);

}



template <typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    //Little confusin... but we got it. MINECRAFT.
    srand((unsigned)time(NULL));
    int nodeToBeDeleted = rand() % getCurrentSize();


    Node<ItemType>* currPtr = headPtr;

    for (int i = 1; i <= nodeToBeDeleted; i++) {
        currPtr = currPtr->getNext();
    }
    remove(currPtr->getItem());
    return currPtr->getItem();
}


//DEFINED METHODS
/*
public:
LinkedBag();
LinkedBag(const LinkedBag<ItemType>&);
virtual ~LinkedBag();
int getCurrentSize() const;
bool isEmpty() const;
bool add(const ItemType&);
bool remove(const ItemType&);
void clear();
bool contains(const ItemType&) const;
int getFrequencyOf(const ItemType&) const;
std::vector<ItemType> toVector() const;
*/


//TO IMPLEMENT
/*
 bool removeSecondNode340();
 bool addEnd340(const ItemType&);
 int getCurrentSize340Iterative() const;
 int getCurrentSize340Recursive() const;
 int getCurrentSize340RecursiveNoHelper() const;
 int getFrequencyOf340Recursive(const ItemType&) const;
 int getFrequencyOf340RecursiveNoHelper(const ItemType&) const;
 ItemType removeRandom340();
 */



