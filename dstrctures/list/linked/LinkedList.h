//
// Created by Mark Volkov on 10/31/17.
//

#ifndef LAB8ALLFILES_LinkedList_H
#define LAB8ALLFILES_LinkedList_H
#include "../List.h"
#include "LinkedNode.h"

template<class T>
class LinkedList : public List<T> {
private:
    LinkedNode<T>* top;
    int nodeCount;
public:
    LinkedList();
    LinkedList(const LinkedList& copyLinkedList);
    LinkedList& operator=(const LinkedList& linkedList);
    ~LinkedList();
    void insertAtEnd(T itemToAdd) override;

    void insertAtFront(T itemToAdd) override;

    void insertAt(T itemToAdd, int index) override;

    T getValueAt(int index) override;

    T removeValueAt(int index) override;

    bool isEmpty() override;

    int itemCount() override;

    void clearList() override;

};

#include "./LinkedList.inl"
#endif //LAB8ALLFILES_LinkedList_H
