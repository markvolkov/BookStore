//
// Created by Mark Volkov on 12/10/17.
//

#include "LinkedQueue.h"

template<class T>
LinkedQueue<T>::LinkedQueue() {
    this->list = new LinkedList<T>();
}

template<class T>
LinkedQueue<T>::~LinkedQueue() {
    delete this->list;
}

template<class T>
void LinkedQueue<T>::enqueue(T item) {
    list->insertAtEnd(item);
}

template<class T>
T LinkedQueue<T>::dequeue() {
    if (!isEmpty()) {
        return list->getValueAt(0);
    } else {
        throw std::out_of_range("Queue is empty!");
    }
}

template<class T>
bool LinkedQueue<T>::isEmpty() {
    return list->isEmpty();
}
