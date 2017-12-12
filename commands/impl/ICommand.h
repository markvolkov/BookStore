//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_ICOMMAND_H
#define BOOKSTORE_ICOMMAND_H

#include "../Command.h"

class ICommand :public Command{
private:
    std::string identifier;
public:
    ICommand();
    ICommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_ICOMMAND_H
