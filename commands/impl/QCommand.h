//
// Created by brien pacholec on 12/12/17.
//

#ifndef BOOKSTORE_QCOMMAND_H
#define BOOKSTORE_QCOMMAND_H


#include "../Command.h"
class QCommand :public Command{
private:
    std::string identifier;
public:
    QCommand();
    QCommand(std::string identifier);

    std::string toString() override;

    void execute(std::vector<std::string> args) override;

    std::string getName() override;
};


#endif //BOOKSTORE_QCOMMAND_H
