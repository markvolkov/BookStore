//
// Created by brien pacholec on 12/13/17.
//

#ifndef BOOKSTORE_BOOKMANAGER_H
#define BOOKSTORE_BOOKMANAGER_H

#include "Book.h"
#include "../dstrctures/Map/ArrayMap.h"

class BookManager {
private:
    ArrayMap<std::string,Book*> *books;
public:
    BookManager();
    ~BookManager();
    void addBook(std::string title, int want, int have );
    void readFile();
    void delivery(std::string fileName);
    void placeOrder(std::string fileName);
    Book* getBook(std::string title);
    Book* modifyHave(std::string title, int newHave);
    Book* modifyWant(std::string title, int newWant);









};


#endif //BOOKSTORE_BOOKMANAGER_H
