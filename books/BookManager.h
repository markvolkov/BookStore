//
// Created by brien pacholec on 12/13/17.
//

#ifndef BOOKSTORE_BOOKMANAGER_H
#define BOOKSTORE_BOOKMANAGER_H

#include "Book.h"
#include "../dstrctures/map/ArrayMap.h"

class BookManager {
private:
     static ArrayMap<std::string,Book*> *books;
public:
    BookManager();
    ~BookManager();
    static void addBook(std::string title, int want, int have);
    static void sellBook(std::string title);
    static void delivery(std::string fileName);
    static void placeOrder(std::string fileName);
    static void returnF(std::string file);
    static void list();
    static void getInfo(std::string title);
    static Book* getBook(std::string title);
    static void modifyHave(std::string title, int newHave);
    static void modifyWant(std::string title, int newWant);
};


#endif //BOOKSTORE_BOOKMANAGER_H
