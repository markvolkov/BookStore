//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"
#include "../dstrctures/map/ArrayMap.h"
#include <fstream>
#include <sstream>
#include <string>


BookManager::BookManager() {
    books = new ArrayMap<std::string, Book*>();
}
BookManager::~BookManager() {
    delete books;
}
void BookManager::addBook(std::string title, int want, int stock) {
    if (getBook(title) != nullptr) {
        std::cout << "A book with that title already exists!" << std::endl;
        std::cout<<"Updating stock count!"<<std::endl;
        modifyStock(title,stock);
        Book* book = getBook(title);
        getInfo(title,book);
        book = nullptr;
        delete book;
        return;
    }
    Book* newBook = new Book(title, want, stock);
    books->put(newBook->getTitle(), newBook);
    std::cout<<title<<" has been added to our inventory!"<<std::endl;
    return;
}
void BookManager::sellBook(std::string title) {

        if(getBook(title) == nullptr) {
            addBook(title, 0, 1);
            std::cout << title << " has been sold!" << std::endl;
        }
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
            std::cout<<title<<" has been sold!";
            books->get(title)->removeFromStockCount(1);
        }


}

void BookManager::delivery(std::string fileIN) {
    //TODO

    //creates a variable to deal with the file
    std::ifstream delieryIn(fileIN);
    //creates a string that will represent the line we are looking at
    std::string line;
    //creates a delimeter that will sperate information on line
    char delimeter = ',';


    //if the file cannot open, the program will prompt the user and the function will end
    if(delieryIn.fail()){
        std::cout<<"ERROR: There was an issues opening the file."<<std::endl;
        return;
    }
    else{
        //loop until there are no more lines
        while(std::getline(delieryIn,line)){

            //split the title and the stock by a comma
            std::stringstream oneLine(line);
            std::string word;
            //variable that will allows us to determine if it is the title or the author
            int count=0;

            //title / stock that will be collected from breaking up each individual line
            std::string title;
            std::string stockS;

            //loops through each line and seperates the words by comma
            while(std::getline(oneLine,word,delimeter)){
                if(count==0){
                    title=word;
                }
                if(count==1){
                    stockS=word;
                }
                count+=1;
            }

            //add book to the inventory
            int stock = std::stoi(stockS);
//            if(getBook(title)!= nullptr){
//                modifyStock(title,stock);
//            }
//            else {
//                addBook(title, 0, stock);
//            }
            addBook(title,0,stock);
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
void BookManager::quit(){
}

void BookManager::list() {
    for (int i = 0; i < this->books->itemSet()->itemCount(); i++) {
        Book* ref = this->books->itemSet()->getValueAt(i)->getValue();
        std::cout << "Title: "<<ref->getTitle()<<"," << " Stock: " << ref->getStockCount()<<"," << " Want: "<<ref->getWishCount()<<"," << std::endl;
    }
}
void BookManager::getInfo(std::string title, Book* toPrint) {
    if(getBook(title)== nullptr){
        std::cout<<"That book does not exist in our inventory! You can add it with the A - Command if you want!"<<std::endl;
        return;
    }
    std::cout<<"Title: "<< toPrint->getTitle()<<std::endl;
    std::cout<<"Stock: "<< toPrint->getStockCount()<<std::endl;
    std::cout<<"Want: "<<toPrint->getWishCount()<<std::endl;

}
Book* BookManager::getBook(std::string title) {
    try {
        Book* query = books->get(title);
        return query;
    }catch(std::out_of_range e) {
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
        books->get(title)->addToWishCount(newWant);
        std::cout<<newWant<<" books have been added to "<<title<<"'s want list."<<std::endl;
    }
}

