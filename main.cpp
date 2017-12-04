//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include <fstream>
#include "commands/CommandManager.h"

using namespace std;

int main() {
//    CommandManager commandManager;
//    commandManager.loadCommands();

    ofstream fileStream("test.txt");
    fileStream << "test";
    fileStream.close();

}
