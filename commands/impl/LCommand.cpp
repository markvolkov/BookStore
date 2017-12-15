

#include "LCommand.h"

LCommand::LCommand(std::string identifier, BookManager* bookManager){
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string LCommand::toString() {
    std::string lString = "L - Command: List Books";
    return lString;
}

//loop thru book array and print out titles in alphabetical order
void LCommand::execute(std::vector<std::string> args) {
    this->bookManager->list();

}


std::string LCommand::getName() {
    return this->identifier;
}

int LCommand::argumentCount() {
    return 0;
}