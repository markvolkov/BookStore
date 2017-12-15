//
// Created by Mark Volkov on 12/5/17.
//

#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H
#include "../customers/Customer.h"
#include "../dstrctures/queue/linked/LinkedQueue.h"

class Book {
private:
    std::string title;
    int stockCount;
    int wishCount;
    LinkedQueue<Customer*>* waitlist;

public:
    Book();
    Book(std::string title, int wishCount,int stockCount);
    Book(Book& toCopy);
    Book& operator=(const Book& toCopy);
    ~Book();
    std::string getTitle();
    int getStockCount();
    int getWishCount();
    void addToStockCount(int numCopies);
    void removeFromStockCount(int numCopies);
    void addToWishCount(int numCopies);
    void removeFromWishCount(int numCopies);
    void enqueueWaitlist(Customer* customer);
    Customer* dequeueWaitlist();

};


#endif //BOOKSTORE_BOOK_H
