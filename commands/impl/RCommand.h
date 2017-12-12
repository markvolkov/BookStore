//
// Created by brien pacholec on 12/12/17.
//

#ifndef BOOKSTORE_RCOMMAND_H
#define BOOKSTORE_RCOMMAND_H

#include "../Command.h"
class RCommand : public Command {
private:
    std::string identifier;
public:
    RCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_RCOMMAND_H
