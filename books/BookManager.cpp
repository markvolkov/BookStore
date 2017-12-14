//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"
#include "../commands/CommandManager.h"

BookManager::BookManager() {


}

BookManager::~BookManager() {

}

void BookManager::addBook(std::string title, int want, int have) {
    Book* newBook = new Book(title,have,want);
    if(getBook(title)== nullptr){
        std::cout<<title<<" has already been added to the invetory!"<<std::endl;
    }
    else {
        books->put(title, newBook);
    }

}

void BookManager::readFile() {

}

void BookManager::delivery(std::string fileName) {
    //going to call read file
    //then add to books

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


}

Book *BookManager::getBook(std::string title) {
    try {
        return books->get(title);
    } catch (std::out_of_range e) {
        return nullptr;
    }
}
