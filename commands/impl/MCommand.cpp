//
// Created by brien pacholec on 12/5/17.
//

#include "MCommand.h"

MCommand::MCommand(std::string identifier) {
    this->identifier = identifier;
}

std::string MCommand::toString() {
    std::string mString = "M - Command: Modify Want Value";
    return mString;}

void MCommand::execute(std::vector<std::string> args) {

}

std::string MCommand::getName() {
    return std::string();
}

int MCommand::argumentCount() {
    return 0;
}
