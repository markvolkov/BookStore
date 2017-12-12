//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_OCOMMAND_H
#define BOOKSTORE_OCOMMAND_H

#include "../Command.h"
class OCommand :public Command{
private:
    std::string identifier;
public:
    OCommand();
    OCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};



#endif //BOOKSTORE_OCOMMAND_H
