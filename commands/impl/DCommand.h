//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_DCOMMAND_H
#define BOOKSTORE_DCOMMAND_H

#include "../Command.h"

class DCommand :public Command{
private:
    std::string identifier;
public:
    DCommand();
    DCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_DCOMMAND_H
