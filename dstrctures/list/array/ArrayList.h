//
// Created by Mark Volkov on 11/7/17.
//

#ifndef LAB9ALLFILES_ARRAYLIST_H
#define LAB9ALLFILES_ARRAYLIST_H

#include <string>
#include "../List.h"

template <class T>
class ArrayList : public List<T> {
private:
    T* array;
    int currItemCount;
    int currCapacity;
public:
    ArrayList();
    ArrayList(const ArrayList& copyArrayList);
    ArrayList& operator=(const ArrayList& arrayList);
    void insertAtEnd(T itemToAdd) override;

    void insertAtFront(T itemToAdd) override;

    void insertAt(T itemToAdd, int index) override;

    T getValueAt(int index) override;

    T removeValueAt(int index) override;

    void doubleCapacity();

    bool isEmpty() override;

    int itemCount() override;

    void clearList() override;

    ~ArrayList();


};

#include "ArrayList.inl"

#endif //LAB9ALLFILES_ARRAYLIST_H
