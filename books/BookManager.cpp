//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"
#include "../dstrctures/map/ArrayMap.h"
#include <fstream>
#include <sstream>

BookManager::BookManager() {
    books = new ArrayMap<std::string, Book*>();
}

BookManager::~BookManager() {
    delete books;
}

void BookManager::addBook(std::string title, int want, int stock) {
    if (getBook(title) == nullptr) {
        Book* newBook = new Book(title,want,stock);
        books->put(title, newBook);
    } else {
        std::cout << title << " has already been added to the inventory!" << std::endl;
    }

}

void BookManager::sellBook(std::string title) {

    try{
        if(getBook(title) == nullptr) {
            addBook(title, 0, 1);
            std::cout << title << " has been sold!" << std::endl;
        }
    } catch(std::out_of_range e)
    {
        if (books->get(title)->getStockCount() < 1) {
            std::cout << "We currently do not have this book in stock! You will be added to the wait list" << std::endl;
            std::cout << "Please enter your Name: " << std::endl;
            std::string name;
            getline(std::cin, name);
            std::cout << "Please enter your phone number - following this format (18002004444): " << std::endl;
            std::string number;
            getline(std::cin, number);
            std::cout << "Please enter your email address: " << std::endl;
            std::string email;
            getline(std::cin, email);
            std::cout << "Please enter your contact preference - 'email' or 'phone': " << std::endl;
            std::string pref;
            getline(std::cin, pref);

            Customer *newCustomer = new Customer(name, number, email, pref);
            books->get(title)->enqueueWaitlist(newCustomer);

        } else {
            books->get(title)->removeFromStockCount(1);
        }
    }

}

void BookManager::delivery(std::string fileIN) {
    //TODO
    std::ifstream infile("delivery.txt");
    if (infile.fail()) {
        std::cout << "ERROR";
    }
    else {

        std::string line;
        std::string title;
        std::string stockS;

        while (getline(infile, line)) {

            std::stringstream splitter(line);

            if (splitter) {
                getline(splitter, title, '|');

                while (splitter) {

                    getline(splitter, stockS);


                    int stock = std::stoi(stockS);

                    if (getBook(title) == nullptr) {
                        addBook(title, 0, stock);
                    } else {
                        modifyStock(title, stock);
                    }

                    std::cout<<title + ":" + stockS<<std::endl;

                }
            }

        }

    }

}

void BookManager::placeOrder(std::string fileName) {
    std::cout << "Placing Order..." << std::endl;
    for (int i = 0; i < books->itemSet()->itemCount(); ++i) {
        Book *newBook = books->itemSet()->getValueAt(i)->getValue();
        int want = newBook->getWishCount();
        int stock = newBook->getStockCount();
        std::string title = newBook->getTitle();
        if (want > stock) {
            int orderAmount = want - stock;

            std::string bookOrder = title + "|" + std::to_string(orderAmount);
            std::ofstream fout(fileName);
            if (fout) {
                std::stringstream parts(bookOrder);
                while (parts) {
                    std::string part;
                    getline(parts, part);
                    fout << part << std::endl;
                }

                fout.close();
            } else {
                std::cout << "Error in opening file";
            }
        }
    }


}

void BookManager::returnF(std::string fileName) {
    for (int i = 0; i < books->itemSet()->itemCount(); ++i) {
        Book *newBook = books->itemSet()->getValueAt(i)->getValue();
        int want = newBook->getWishCount();
        int have = newBook->getStockCount();
        std::string title = newBook->getTitle();
        if (have > want) {
            int returnAmount = have - want;
            modifyStock(title, -returnAmount);
            std::string bookOrder = title + "|" + std::to_string(returnAmount);
            std::ofstream fout(fileName);
            if (fout) {
                std::stringstream parts(bookOrder);
                while (parts) {
                    std::string part;
                    getline(parts, part);
                    fout << part << std::endl;
                }

                fout.close();
            } else {
                std::cout << "Error in opening file";
            }
        }

    }
}

void BookManager::list() {
    std::cout << "Books being listed" << "Size: "<< books->itemSet()->itemCount() << std::endl;
    for (int i = 0; i < this->books->itemSet()->itemCount(); i++) {
        Book* ref = this->books->itemSet()->getValueAt(i)->getValue();
        std::cout << ref->getTitle() << ref->getStockCount() << ref->getWishCount() << std::endl;
    }
}

void BookManager::getInfo(std::string title, Book* toPrint) {
    std::cout << toPrint->getTitle()<<" "<< toPrint->getWishCount() << " "<<toPrint->getStockCount()<<std::endl;

}

Book* BookManager::getBook(std::string title) {
    if (books->itemSet()->isEmpty()) {
        return nullptr;
    }
    try {
        return books->get(title);
    }catch (std::out_of_range e) {
        return nullptr;
    }

}


void BookManager::modifyStock(std::string title, int newStock) {
    if (getBook(title) == nullptr) {
        std::cout << title << "That book does not exist in our inventory!" << std::endl;
    } else {
        books->get(title)->addToStockCount(newStock);
    }

}

void BookManager::modifyWant(std::string title, int newWant) {
    if (getBook(title) == nullptr) {
        std::cout << title << " That book does not exist in our inventory!" << std::endl;
    } else {
        books->get(title)->addToStockCount(newWant);
    }
}
