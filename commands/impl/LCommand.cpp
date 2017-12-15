

#include "LCommand.h"

LCommand::LCommand(std::string identifier){
    this->identifier = identifier;
}

std::string LCommand::toString() {
    std::string lString = "L - Command: List Books";
    return lString;
}

//loop thru book array and print out titles in alphabetical order
void LCommand::execute(std::vector<std::string> args) {
    BookManager::list();

}


std::string LCommand::getName() {
    return this->identifier;
}

int LCommand::argumentCount() {
    return 0;
}