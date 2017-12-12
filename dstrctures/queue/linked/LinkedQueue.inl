//
// Created by Mark Volkov on 12/10/17.
//

#include "LinkedQueue.h"

template<class T>
LinkedQueue::LinkedQueue() {
    this->list = new LinkedList();
}

template<class T>
~LinkedQueue::LinkedQueue() {
    delete this->list;
}

template<class T>
void LinkedQueue::enqueue(T item) {
    list->insertAtEnd(item);
}

template<class T>
T LinkedQueue::dequeue() {
    if (!isEmpty()) {
        return list->getValueAt(0);
    } else {
        throw std::out_of_range("Queue is empty!");
    }
}

template<class T>
bool LinkedQueue::isEmpty() {
    return list->isEmpty();
}
