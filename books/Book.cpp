//
// Created by Mark Volkov on 12/5/17.
//

#include "Book.h"
#include "Customer.h"
#include "LinkedQueue.h"

Book::Book(std::string title, std::string author, int stockCount, int wishCount){
    this->title = title;
    this->author = author;
    this->stockCount = stockCount;
    this->wishCount = wishCount;
    LinkedQueue* waitlist = new LinkedQueue;
}


std::string Book::getTitle() { return this->title; }

std::string Book::getAuthor() { return this->author; }

int getStockCount(){ return this->stockCount; }

int getWishCount(){ return this->wishCount; }

void addToStockCount(int numCopies){
    numCopies += numCopies;
}

void removeFromStockCount(int numCopies){
    numCopies -= numCopies;
}

void enqueueWaitlist(Customer* customer){
    enqueueWaitlist(customer);
}

Customer* dequeueWaitlist(){
   return dequeueWaitlist();
}