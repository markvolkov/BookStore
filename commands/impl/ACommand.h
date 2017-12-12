//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_ACOMMAND_H
#define BOOKSTORE_ACOMMAND_H

#include "../Command.h"
class ACommand : public Command{
private:
    std::string identifier;
public:
    ACommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_ACOMMAND_H
