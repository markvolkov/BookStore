//
// Created by brien pacholec on 12/13/17.
//

#include "BookManager.h"

BookManager::BookManager() {

}

BookManager::~BookManager() {

}

void BookManager::addBook(std::string title, int want, int have) {
    if()

}

void BookManager::readFile() {

}

void BookManager::delivery(std::string fileName) {

}

void BookManager::placeOrder(std::string fileName) {

}

Book *BookManager::getBook(std::string title) {
    try {
        return books->get(title);
    } catch (std::out_of_range e) {
        return nullptr;
    }
}
