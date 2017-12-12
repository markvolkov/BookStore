
// Created by Jacquelyn Martin on 12/5/17.
//

#ifndef BOOKSTORE_LCOMMAND_H
    #define BOOKSTORE_LCOMMAND_H

#include "../Command.h"

class LCommand : public Command {
private:
    std::string identifier;
public:
    LCommand();
    LCommand(std::string identifier);

    std::string getName() override;

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

};


#endif //BOOKSTORE_LCOMMAND_H




