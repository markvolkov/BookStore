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
    return std::string();
}

void ACommand::execute(std::string *args) {
    std::cout<<"Add a book to the system."<<std::endl;
    std::string bookTitle = std::cin>>"Enter book title";
    int bookStock = std::cin>>"Enter book stock";
    int bookNeed = std::cin>>"Enter book need";


}

std::string ACommand::getName() {
    return std::string();
}
