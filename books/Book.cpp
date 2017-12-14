//
// Created by Mark Volkov on 12/5/17.
//

#include "Book.h"

Book::Book(std::string title, int stockCount, int wishCount){
    this->title = title;
    this->stockCount = stockCount;
    this->wishCount = wishCount;
    this->waitlist = new LinkedQueue<Customer*>();
}


std::string Book::getTitle() { return this->title; }


int Book::getStockCount(){
    return this->stockCount;
}

int Book::getWishCount(){ return this->wishCount; }

void Book::addToStockCount(int numCopies){
    numCopies += numCopies;
}

void Book::removeFromStockCount(int numCopies){
    numCopies -= numCopies;
}

void Book::enqueueWaitlist(Customer* customer){
    enqueueWaitlist(customer);
}

Customer* Book::dequeueWaitlist(){
   return dequeueWaitlist();
}