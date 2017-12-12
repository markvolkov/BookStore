//
// Created by Mark Volkov on 10/31/17.
//
#include <iostream>
#include "LinkedList.h"

/***
 * Store end variable to make findlast function better,
 * implement defined functions
 * test current implemented functions
 */

template<class T>
LinkedList::LinkedList() {
    top = nullptr;
    nodeCount = 0;
}

template<class T>
LinkedList::LinkedList(const LinkedList &copyLinkedList) {
    top = copyLinkedList.top;
    nodeCount = copyLinkedList.nodeCount;
}

template<class T>
LinkedList& LinkedList::operator=(const LinkedList &linkedList) {
    if (this != &linkedList) {
        top = linkedList.top;
        nodeCount = linkedList.nodeCount;
    }
    return *this;
}

template<class T>
void LinkedList::insertAtEnd(T itemToAdd) {
    insertAt(itemToAdd, nodeCount);
}

template<class T>
void LinkedList::insertAtFront(T itemToAdd) {
    insertAt(itemToAdd, 0);
}

template<class T>
void LinkedList::insertAt(T itemToAdd, int index) {
    if (index > nodeCount) {
        throw std::out_of_range("Index cannot exceed linkedlist size.");
    }
    if (top == nullptr) {
        top = new LinkedNode(itemToAdd);
        nodeCount++;
    } else {
        LinkedNode* newData = new LinkedNode(itemToAdd);
        if (index == 0) {
            newData->setNext(top);
            top = newData;
            nodeCount++;
        } else {
            LinkedNode* temp = top;
            int count = 0;
            while (count != index-1) {
                temp = temp->getNext();
                count++;
            }
            newData->setNext(temp->getNext());
            temp->setNext(newData);

            nodeCount++;
        }
    }

}

template<class T>
T LinkedList::getValueAt(int index) {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty!");
    } else if (index > itemCount()-1) {
        throw std::out_of_range("Index out of bounds.");
    } else {
        int count = 0;
        LinkedNode* temp = top;
        while(count != index) {
            temp = temp->getNext();
            count++;
        }
        return temp->getItem();
    }
}

template<class T>
T LinkedList::removeValueAt(int index) {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty!");
    } else if (index > itemCount()-1) {
        throw std::out_of_range("Index out of bounds.");
    } else {
        nodeCount--;
        if (index == 0) {
            T val = top->getItem();
            if (top->getNext() == nullptr) {
                delete top;
                top = nullptr;
                return val;
            } else {
                LinkedNode* newTop = top->getNext();
                delete top;
                top = newTop;
                return val;
            }
        } else {

            int count = 0;
            LinkedNode* temp = top;
            while (count != index-1) {
                temp = temp->getNext();
                count++;
            }
            T val = temp->getNext()->getItem();
            LinkedNode* newNext = temp->getNext()->getNext();
            delete temp->getNext();
            temp->setNext(newNext);
            return val;
        }

    }
}

template<class T>
bool LinkedList::isEmpty() {
    return itemCount() == 0;
}

template<class T>
int LinkedList::itemCount() {
    return nodeCount;
}

template<class T>
void LinkedList::clearList() {
    if (top->getNext() == nullptr) {
        delete top;
        top = nullptr;
    } else {
        LinkedNode *temp = top->getNext();
        while (temp != nullptr) {
            delete temp;
            temp = temp->getNext();
        }
        if (top != nullptr) {
            delete top;
            top = nullptr;
        }
    }
    nodeCount = 0;
}

template<class T>
std::string LinkedList::toString() {
    if (itemCount() < 1) {
        return "";
    }
    std::string value = "{";
    int count = 0;
    LinkedNode* temp = top;
    while(count < nodeCount) {
        if (count == nodeCount-1) {
            value += std::to_string(temp->getItem()) + "}";
            temp = temp->getNext();
            count++;
        } else {
            value += std::to_string(temp->getItem()) + ", ";
            temp = temp->getNext();
            count++;
        }
    }
    return value;
}
