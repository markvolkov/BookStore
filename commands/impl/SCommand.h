//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_SCOMMAND_H
#define BOOKSTORE_SCOMMAND_H

#include "../Command.h"
class SCommand : public Command {
private:
    std::string identifier;
public:
    SCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;

    int argumentCount() override;
};



#endif //BOOKSTORE_SCOMMAND_H
