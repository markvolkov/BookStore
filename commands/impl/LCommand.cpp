

#include "LCommand.h"

LCommand::LCommand() {
    this->identifier = "error";
}
LCommand::LCommand(std::string identifier){
    this->identifier = identifier;
}

std::string LCommand::toString() {
    std::string lString = "L - Command: List Books";
    return lString;
}

//loop thru book array and print out titles in alphabetical order
void LCommand::execute(std::string args[]) {
    std::cout << toString() << std::endl;
}


std::string LCommand::getName() {
    return this->identifier;
}
