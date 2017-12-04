//
// Created by Mark Volkov on 11/28/17.
//
#ifndef BOOKSTORE_COMMAND_H
#define BOOKSTORE_COMMAND_H

#include <iostream>

class Command {

public:
    std::string identifier;
    Command();
    Command(std::string identifier);
    virtual std::string toString()=0;
    virtual void execute()=0;
};

#endif //BOOKSTORE_COMMAND_H
