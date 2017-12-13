//
// Created by Mark Volkov on 11/28/17.
//
#include "HCommand.h"
#include "ACommand.h"

HCommand::HCommand(std::string identifier){
    this->identifier = identifier;
}

std::string HCommand::toString() {
    std::string hString = "H - Command: Help";
    return hString;
}

void HCommand::execute(std::vector<std::string> args) {
    std::cout << toString() << std::endl;
    std::cout << "A - Command: Add Book" << std::endl;
    std::cout << "D - Command: Delivery Of Books" << std::endl;
    std::cout << "I - Command: Inquire Information" << std::endl;
    std::cout << "L - Command: List Books" << std::endl;
    std::cout << "M - Command: Modify Want Value" << std::endl;
    std::cout << "O - Command: Order Books" << std::endl;
    std::cout << "Q - Command: Quit" << std::endl;
    std::cout << "R - Command: Return" << std::endl;
    std::cout << "S - Command: Sell Book" << std::endl;

}


std::string HCommand::getName() {
    return this->identifier;
}

int HCommand::argumentCount() {
    return 0;
}

