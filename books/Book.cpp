//
// Created by Mark Volkov on 12/5/17.
//

#include "Book.h"
Book::Book() {

}

Book::Book(std::string title, int wishCount, int stockCount){
    this->title = title;
    this->stockCount = stockCount;
    this->wishCount = wishCount;
    this->waitlist = new LinkedQueue<Customer*>();
}


Book::Book(Book &toCopy) {
    this->title = toCopy.title;
    this->stockCount = toCopy.stockCount;
    this->wishCount = toCopy.wishCount;
    this->waitlist = toCopy.waitlist;
}

Book::~Book() {

}


std::string Book::getTitle() {
    return this->title;
}

int Book::getStockCount(){
    return this->stockCount;
}



int Book::getWishCount(){ return this->wishCount; }

void Book::addToStockCount(int numCopies){
    stockCount += numCopies;
}

void Book::removeFromStockCount(int numCopies){
    stockCount -= numCopies;
}

void Book::addToWishCount(int numCopies) {
    wishCount+=numCopies;

}

void Book::removeFromWishCount(int numCopies) {
    wishCount-=numCopies;
}

void Book::enqueueWaitlist(Customer* customer){
    enqueueWaitlist(customer);
}

Customer* Book::dequeueWaitlist(){
   return dequeueWaitlist();
}
