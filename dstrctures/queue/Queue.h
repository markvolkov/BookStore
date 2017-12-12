//
// Created by Mark Volkov on 12/10/17.
//

#ifndef BOOKSTORE_QUEUE_H
#define BOOKSTORE_QUEUE_H
template <class T>
class Queue {
public:

    virtual ~Queue(){};

    virtual void enqueue(T item)=0;

    virtual T dequeue()=0;

    virtual bool isEmpty()=0;

};
#endif //BOOKSTORE_QUEUE_H
