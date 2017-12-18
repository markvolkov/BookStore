//
// Created by Mark Volkov on 11/28/17.
//
#include "HCommand.h"
#include "ACommand.h"

HCommand::HCommand(std::string identifier, BookManager* bookManager){
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string HCommand::toString() {
    std::string hString = "H - Command: Help";
    return hString;
}

void HCommand::execute(std::vector<std::string> args) {
    std::cout << toString() << std::endl;
    std::cout << "A - Command: Add Book (TITLE, WANT, STOCK)" << std::endl;
    std::cout << "D - Command: Delivery Of Books (DELIVERY.TXT)" << std::endl;
    std::cout << "I - Command: Inquire Information (TITLE)" << std::endl;
    std::cout << "L - Command: List Books" << std::endl;
    std::cout << "M - Command: Modify Want Value (TITLE)" << std::endl;
    std::cout << "O - Command: Order Books (ORDER.TXT)" << std::endl;
    std::cout << "Q - Command: Quit" << std::endl;
    std::cout << "R - Command: Return (RETURN.TXT)" << std::endl;
    std::cout << "S - Command: Sell Book (TITLE)" << std::endl;

}


std::string HCommand::getName() {
    return this->identifier;
}

int HCommand::argumentCount() {
    return 0;
}

