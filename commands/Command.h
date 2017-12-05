//
// Created by Mark Volkov on 11/28/17.
//
#ifndef BOOKSTORE_COMMAND_H
#define BOOKSTORE_COMMAND_H

#include <iostream>

class Command {

private:
    std::string identifier;

public:
    virtual std::string toString()=0;
    virtual void execute(std::string args[])=0;
    virtual std::string getName()=0;
};

#endif //BOOKSTORE_COMMAND_H
