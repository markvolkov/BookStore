//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_ICOMMAND_H
#define BOOKSTORE_ICOMMAND_H

#include "../Command.h"

class ICommand :public Command{
private:
    std::string identifier;
    BookManager* bookManager;
public:
    ICommand(std::string identifier, BookManager* bookManager);

    std::string toString() override;

    int argumentCount() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_ICOMMAND_H
