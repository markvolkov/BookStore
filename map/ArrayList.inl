//
// Created by Mark Volkov on 11/7/17.
//

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList() {
    currCapacity = 5;
    currItemCount = 0;
    array = new T[currCapacity];
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList &copyArrayList) {
    currCapacity = copyArrayList.currCapacity;
    currItemCount = copyArrayList.currItemCount;
    array = new T[currCapacity];
    if (currItemCount > 0) {
        for (int i = 0; i <= currItemCount; i++) {
            array[i] = copyArrayList.array[i];
        }
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete[] array;
    array = nullptr;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &arrayList) {
    if (this != &arrayList) {
        delete[] array;
        array = nullptr;
        currCapacity = arrayList.currCapacity;
        currItemCount = arrayList.currItemCount;
        array = new T[currCapacity];
        if (currItemCount > 0) {
            for (int i = 0; i <= currItemCount; i++) {
                array[i] = arrayList.array[i];
            }
        }
    }
    return *this;
}

template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
    insertAt(itemToAdd, currItemCount);
}

template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd) {
    insertAt(itemToAdd, 0);
}

template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index) {
    if (index > currItemCount || index < 0) {
        throw std::out_of_range("Index out of range.");
    }
    if (currItemCount >= currCapacity) {
        doubleCapacity();
    }
    currItemCount++;
    T temp = array[index];
    for (int i = index; i < currItemCount; i++) {
        if (i == index) {
            array[index] = itemToAdd;
        } else {
            T next = array[i];
            array[i] = temp;
            temp = next;
        }
    }
}

template <class T>
T ArrayList<T>::getValueAt(int index) {
    if (index < currItemCount && index >= 0) {
        return array[index];
    } else {
        throw std::out_of_range("Index out of range.");
    }
}

template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if (index > currItemCount-1 || index < 0) {
        throw std::out_of_range("Index out of range.");
    }
    T copyVal = array[index];
    for (int i = index; i < currItemCount; i++) {
        for (int j = i+1; j < currItemCount;) {
            T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            break;
        }
    }
    currItemCount--;
    return copyVal;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return currItemCount = 0;
}

template <class T>
int ArrayList<T>::itemCount() {
    return currItemCount;
}

template <class T>
void ArrayList<T>::clearList() {
    delete[] array;
    array = new T[currCapacity];
    currItemCount = 0;
}

template <class T>
void ArrayList<T>::doubleCapacity() {
    T* newArray = new T[currCapacity*2];
    for (int i = 0; i < currCapacity; i++) {
        newArray[i] = array[i];
    }
    currCapacity*=2;
    delete[] array;
    array = newArray;
    //I might need this line not sure though
    newArray = nullptr;
}

std::string toStringR(const int *const arrayPtr, const int size, int index, std::string value);
std::string toStringStub(const int *const arrayPtr, const int size);

template <class T>
std::string toStringR(const int *const arrayPtr, const int size, int index, std::string value) {
    if (index > (size - 1)) {
        return value + "}";
    } else if (index == 0) {
        return toStringR(arrayPtr, size, index+1, value + std::to_string(arrayPtr[index]));
    } else {
        return toStringR(arrayPtr, size, index+1, value + ", " + std::to_string(arrayPtr[index]));
    }
}

template <class T>
std::string toString(const int *const arrayPtr, const int size) {
    return toStringR(arrayPtr, size, 0, "{");
}

template <class T>
std::string ArrayList<T>::toString() {
    return toStringStub(array, currItemCount);
}


