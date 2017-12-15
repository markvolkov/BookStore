
// Created by Jacquelyn Martin on 12/5/17.
//

#ifndef BOOKSTORE_LCOMMAND_H
    #define BOOKSTORE_LCOMMAND_H

#include "../Command.h"

class LCommand : public Command {
private:
    std::string identifier;
    BookManager* bookManager;
public:

    LCommand(std::string identifier, BookManager* bookManager);
    std::string getName() override;
    std::string toString() override;
    void execute(std::vector<std::string> args) override;
    int argumentCount() override;


};


#endif //BOOKSTORE_LCOMMAND_H




