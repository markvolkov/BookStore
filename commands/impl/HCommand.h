//
// Created by Mark Volkov on 11/28/17.
//

#ifndef BOOKSTORE_HCOMMAND_H
#define BOOKSTORE_HCOMMAND_H

#include "../Command.h"

class HCommand : public Command {
private:
    std::string identifier;
    BookManager* bookManager;
public:
    HCommand(std::string identifier, BookManager* bookManager);

    std::string getName() override;

    int argumentCount() override;

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

};
#endif //BOOKSTORE_HCOMMAND_H
