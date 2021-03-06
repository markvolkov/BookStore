//
// Created by brien pacholec on 12/5/17.
//

#ifndef BOOKSTORE_DCOMMAND_H
#define BOOKSTORE_DCOMMAND_H

#include "../Command.h"

class DCommand :public Command{
private:
    std::string identifier;
    BookManager* bookManager;
public:
    DCommand(std::string identifier, BookManager* bookManager);
    std::string toString() override;
    void execute(std::vector<std::string> args) override;
    std::string getName() override;
    int argumentCount() override;
};


#endif //BOOKSTORE_DCOMMAND_H
