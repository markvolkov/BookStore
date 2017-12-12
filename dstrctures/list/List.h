//
// Created by Mark Volkov on 12/8/17.
//

#ifndef BOOKSTORE_LIST_H
#define BOOKSTORE_LIST_H

#include <string>

template<class T>
class List {
public:
    virtual void insertAtEnd(T itemToAdd)=0;

    virtual void insertAtFront(T itemToAdd)=0;

    virtual void insertAt(T itemToAdd, int index)=0;

    virtual T getValueAt(int index)=0;

    virtual T removeValueAt(int index)=0;

    virtual void doubleCapacity()=0;

    virtual bool isEmpty()=0;

    virtual int itemCount()=0;

    virtual void clearList()=0;

};
#endif //BOOKSTORE_LIST_H
