//
// Created by Mark Volkov on 11/28/17.
//

#ifndef BOOKSTORE_HCOMMAND_H
#define BOOKSTORE_HCOMMAND_H

#include "../Command.h"

class HCommand : public Command {
private:
    std::string identifier;
public:
    HCommand(std::string identifier);

    std::string getName() override;

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

};
#endif //BOOKSTORE_HCOMMAND_H
