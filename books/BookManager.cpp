//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"
#include "../commands/CommandManager.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

BookManager::BookManager() {


}
BookManager::~BookManager() {

}

void BookManager::addBook(std::string title, int want, int have) {
    Book* newBook = new Book(title,have,want);
    if(this->getBook(title)== nullptr){
        books->put(title, newBook);
    }
    else {
        std::cout<<title<<" has already been added to the invetory!"<<std::endl;
    }

}

void BookManager::sellBook(std::string title) {
    if (books->get(title) == nullptr){
//        ACommand::execute(title);
    }
    else{
        if(books->get(title)->getStockCount()<1){
            std::cout<<"We currently do not have this book in stock! You will be added to the wait list"<<std::endl;
            std::cout<<"Please enter your Name: "<<std::endl;
            std::string name;
            getline(std::cin, name);
            std::cout<<"Please enter your phone number - following this format (18002004444): "<<std::endl;
            std::string number;
            getline(std::cin, number);
            std::cout<<"Please enter your email address: "<<std::endl;
            std::string email;
            getline(std::cin, email);
            std::cout<<"Please enter your contact preference - 'email' or 'phone': "<<std::endl;
            std::string pref;
            getline(std::cin, pref);

            Customer* newCustomer = new Customer(name,number,email,pref);
            books->get(title)->enqueueWaitlist(newCustomer);

        }
        else{
            books->get(title)->removeFromStockCount(1);
        }
    }

}

void BookManager::delivery(std::string fileIN) {
    //going to call read file
    //then add to books
    std::ifstream infile(fileIN);
    std::string line;
    std::string title;
    std::string stockS;

    if(infile.fail()) std::cout<< "ERROR";
    else{

        while(getline(infile, line)){

            std::stringstream splitter(line);

            if (splitter) {
                getline(splitter, title, '|');
                while (splitter) {
                    getline(splitter, stockS, '|');
                    std::cout << title + ":" + stockS<< std::endl;

                    int stock = std::stoi(stockS);
                    if (getBook(title)== nullptr){
                        addBook(title,0,stock);
                    }
                    else{
                        modifyHave(title,stock);
                    }

                }
            }
        }

    }

}

void BookManager::placeOrder(std::string fileName) {
    std::cout<<"Placing Order..."<<std::endl;
    for (int i = 0; i < this->books->itemSet()->itemCount(); ++i) {
        Book* newBook = books->itemSet()->getValueAt(i)->getValue();
        int want = newBook->getWishCount();
        int stock = newBook->getStockCount();
        std::string title = newBook->getTitle();
        if (want>stock){
            int orderAmount = want-stock;

            std::string bookOrder = title + "|" + std::to_string(orderAmount);
            std::ofstream fout (fileName);
            if (fout) {
                std::stringstream parts(bookOrder);
                while(parts){
                    std::string part;
                    getline(parts, part);
                    fout << part << std::endl;
                    }

                fout.close();
            }
            else {
                std::cout << "Error in opening file";
            }
        }
    }


}

void BookManager::returnF(std::string fileName) {
    for (int i = 0; i < this->books->itemSet()->itemCount() ; ++i) {
        Book* newBook = books->itemSet()->getValueAt(i)->getValue();
        int want = newBook->getWishCount();
        int have = newBook->getStockCount();
        std::string title = newBook->getTitle();
        if(have>want){
            int returnAmount = have-want;
            modifyHave(title,-returnAmount);
            std::string bookOrder = title + "|" + std::to_string(returnAmount);
            std::ofstream fout (fileName);
            if (fout) {
                std::stringstream parts(bookOrder);
                while(parts){
                    std::string part;
                    getline(parts, part);
                    fout << part << std::endl;
                }

                fout.close();
            }
            else {
                std::cout << "Error in opening file";
            }
        }

    }
}

void BookManager::list() {
    for (int i = 0; i < this->books->itemSet()->itemCount() ; ++i) {
        Book *newBook = books->itemSet()->getValueAt(i)->getValue();
        getInfo(newBook->getTitle());
    }
}

Book *BookManager::getInfo(std::string title) {

    std::cout<<books->get(title)->getTitle()<<std::endl;
    std::cout<<books->get(title)->getWishCount()<<std::endl;
    std::cout<<books->get(title)->getStockCount()<<std::endl;
}

Book *BookManager::getBook(std::string title) {
    try {
        return books->get(title);
    } catch (std::out_of_range e) {
        return nullptr;
    }
}

Book *BookManager::modifyHave(std::string title, int newHave) {
    if(getBook(title)== nullptr){
        std::cout<<title<<"That book does not exist in our inventory!"<<std::endl;
    }
    else {
        books->get(title)->addToStockCount(newHave);
    }

}

Book *BookManager::modifyWant(std::string title, int newWant) {
    if(getBook(title)== nullptr)
    {
        std::cout<<title<<"That book does not exist in our inventory!"<<std::endl;
    }
    else {
        books->get(title)->addToStockCount(newWant);
    }
}



