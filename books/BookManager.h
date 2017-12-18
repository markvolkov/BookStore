//
// Created by brien pacholec on 12/13/17.
//

#ifndef BOOKSTORE_BOOKMANAGER_H
#define BOOKSTORE_BOOKMANAGER_H

#include "Book.h"
#include "../dstrctures/map/Map.h"

class BookManager {
private:
    Map<std::string, Book*>* books;
public:
    BookManager();
    ~BookManager();
    void addBook(std::string title, int want, int have);
    void sellBook(std::string title);
    void delivery(std::string fileName);
    void placeOrder(std::string fileName);
    void returnF(std::string file);
    void list();
    void getInfo(std::string title, Book* book);
    Book* getBook(std::string title);
    void modifyStock(std::string title, int modifyStock);
    void modifyWant(std::string title, int newWant);
    void loadBooks();
    void quit();
};


#endif //BOOKSTORE_BOOKMANAGER_H
