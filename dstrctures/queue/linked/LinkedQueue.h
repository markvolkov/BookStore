//
// Created by Mark Volkov on 12/10/17.
//

#ifndef BOOKSTORE_LINKEDQUEUE_H
#define BOOKSTORE_LINKEDQUEUE_H

#include "../Queue.h"
#include "../../list/linked/LinkedList.h"
template<class T>
class LinkedQueue : public Queue<T> {
private:
    LinkedList<T>* list;
public:
    LinkedQueue();
    ~LinkedQueue() override;
    void enqueue(T item) override;
    T dequeue() override;
    bool isEmpty() override;

};

#include "LinkedQueue.inl"
#endif //BOOKSTORE_LINKEDQUEUE_H
