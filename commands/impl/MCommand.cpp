//
// Created by brien pacholec on 12/5/17.
//

#include "MCommand.h"

MCommand::MCommand() {

}

MCommand::MCommand(std::string identifier) {

}

std::string MCommand::toString() {
    std::string mString = "M - Command: Modify Want Value";
    return mString;}

void MCommand::execute(std::string *args) {

}

std::string MCommand::getName() {
    return std::string();
}
