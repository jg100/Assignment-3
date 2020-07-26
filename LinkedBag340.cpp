//
//  LinkedBag340.cpp
//  ASMT3
//
//  Created by Ernesto Diaz on 7/24/20.
//  Copyright © 2020 Ernesto Diaz. All rights reserved.
//

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
    return 0;
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
    static int counter = 0;

    if (isEmpty()) {
        return 0;
    }

    if (testNode->getNext() == nullptr) {
        //End of the node chain.
        int size = counter;
        counter = 0;
        return size;
    }

    getCurrentSize340RecursiveHelper(testNode->getNext());
    counter++;
    return 0;
} //End helper function




//No helper function
template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static int countNoHelper = 0;

    //Not going to work, bc every call reset the traversalPtr

    //cool beans.
    static Node<ItemType>* traversalPointer = headPtr;


    if (traversalPointer->getNext() == nullptr) {
        int size = countNoHelper;
        countNoHelper = 0;
        return size;
    }

    traversalPointer = traversalPointer->getNext();
    countNoHelper++;
    getCurrentSize340RecursiveNoHelper();
    return 0;
}





template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& searchedValue) const {

    return getFrequencyOf340RecursiveHelper(headPtr, searchedValue);
}


//Private
template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currentPtr, const ItemType& searchedValue) const {

    static int freq = 0;

    if (isEmpty()) {
        return 0;
    }

    if (currentPtr->getNext() == nullptr) {
        //End of the node chain.

        int returnedFreq = freq;
        freq = 0;
        return returnedFreq;
    }

    if (currentPtr->getItem() == searchedValue) {
        freq++;
        getFrequencyOf340RecursiveHelper(currentPtr->getNext(), searchedValue);

    }
    return 0;
}




template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& searchedValue) const {
    static int freqCount = 0;

    //cool beans.
    static Node<ItemType>* traversalPointer = headPtr;


    if (traversalPointer->getNext() == nullptr) {
        int searched = freqCount;
        freqCount = 0;
        return searched;
    }

    if (traversalPointer->getItem() == searchedValue) {
        freqCount++;
        getFrequencyOf340Recursive(searchedValue);
    }
    return 0;
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

