//
// Created by Mark Volkov on 11/7/17.
//

#ifndef LAB9ALLFILES_ARRAYLIST_H
#define LAB9ALLFILES_ARRAYLIST_H

#include <string>

template <class T>
class ArrayList {
private:
    T* array;
    int currItemCount;
    int currCapacity;
public:
    ArrayList();
    ArrayList(const ArrayList& copyArrayList);
    ArrayList& operator=(const ArrayList& arrayList);
    void insertAtEnd(T itemToAdd);

    void insertAtFront(T itemToAdd);

    void insertAt(T itemToAdd, int index);

    T getValueAt(int index);

    T removeValueAt(int index);

    void doubleCapacity();

    bool isEmpty();

    int itemCount();

    void clearList();

    std::string toString();

    ~ArrayList();


};

#include "ArrayList.inl"

#endif //LAB9ALLFILES_ARRAYLIST_H
