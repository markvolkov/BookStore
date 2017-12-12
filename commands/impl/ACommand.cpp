//
// Created by brien pacholec on 12/5/17.
//

#include "ACommand.h"
//Add a book to the inventory. Prompt for initial want value and have value.
//If the title already exists, inform the user and print the information for that title.

ACommand::ACommand() {

}

ACommand::ACommand(std::string identifier) {

}

std::string ACommand::toString() {
    std::cout<<"Please enter the title of the book, the count, the want, all seperated by Commas"<<std::endl;
    execute(;
}

void ACommand::execute(std::string *args) {
    std::string title;
    getline(std::cin, title);
    std::string want;
    getline(std::cin, want);
    std::string need;
    getline(std::cin,need);



}

std::string ACommand::getName() {
    return std::string();
}
