cmake_minimum_required(VERSION 3.8)
project(BookStore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp map/ArrayList.h map/ArrayMap.h map/Item.h map/Map.h
        commands/CommandManager.cpp commands/Command.h commands/impl/HCommand.cpp
        commands/impl/HCommand.h commands/impl/ICommand.cpp commands/impl/ICommand.h
        commands/impl/ACommand.cpp commands/impl/ACommand.h commands/impl/MCommand.cpp
        commands/impl/MCommand.h commands/impl/SCommand.cpp commands/impl/SCommand.h
        customers/Customer.cpp customers/Customer.cpp)
add_executable(BookStore ${SOURCE_FILES})