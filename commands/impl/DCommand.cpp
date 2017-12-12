//
// Created by brien pacholec on 12/5/17.
//

#include "DCommand.h"
//Take information from a file listing the delivery shipment of books.
//The file will contain the title and the count of each book included in the shipment.

DCommand::DCommand() {

}

DCommand::DCommand(std::string identifier) {

}

std::string DCommand::toString() {
    std::string dString = "D - Command: Delivery Of Books";
    return dString;
}

void DCommand::execute(std::string *args) {

}

std::string DCommand::getName() {
    return std::string();
}
