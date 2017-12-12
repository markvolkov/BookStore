//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_MCOMMAND_H
#define BOOKSTORE_MCOMMAND_H

#include "../Command.h"
class MCommand :public Command{
private:
    std::string identifier;
public:
    MCommand();
    MCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_MCOMMAND_H
