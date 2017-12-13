//
// Created by Mark Volkov on 12/5/17.
//

#include "Book.h"

Book::Book(std::string title, std::string author, int stockCount, int wishCount){
    this->title = title;
    this->author = author;
    this->stockCount = stockCount;
    this->wishCount = wishCount;
    this->waitlist = new LinkedQueue<Customer*>();
}


std::string Book::getTitle() { return this->title; }

std::string Book::getAuthor() { return this->author; }

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