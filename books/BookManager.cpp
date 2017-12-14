//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"
#include "../commands/CommandManager.h"
#include <fstream>

BookManager::BookManager() {


}

BookManager::~BookManager() {

}

void BookManager::addBook(std::string title, int want, int have) {
    Book* newBook = new Book(title,have,want);
    if(getBook(title)== nullptr){
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

void BookManager::readFile() {

}

void BookManager::delivery(std::string fileName) {
    //going to call read file
    //then add to books

    std::ifstream file(fileName);
    std::string str;
    while (std::getline(file, str))
    {

    }

}

void BookManager::placeOrder(std::string fileName) {
    std::cout<<"Placing Order: Title,Want,Have"<<std::endl;
    std::cout<<"Please seperate values by commas!"<<std::endl;
    //call O-Command with a while loop running

//    string q = "1";
//    while(q=="1"){
//        //CommandManager::executeCommand(a,3);
//        std::cout<<"To continue, type 1. To quit, type 2"<<std::endl;
//        std::string line;
//        getline(std::cin, line);
//        q = line;
//    }

//    while(books){
//        if(books->get(title)->getStockCount()<1){
//            books->get(title)->addToStockCount(10);
//        }
//    }

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


