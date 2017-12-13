cmake_minimum_required(VERSION 3.8)
project(BookStore)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp dstrctures/list/array/ArrayList.h dstrctures/map/ArrayMap.h dstrctures/map/Item.h dstrctures/map/Map.h
        commands/CommandManager.cpp commands/CommandManager.h commands/Command.h commands/impl/HCommand.cpp
        commands/impl/HCommand.h commands/impl/ICommand.cpp commands/impl/ICommand.h commands/impl/DCommand.cpp commands/impl/DCommand.h commands/impl/QCommand.cpp commands/impl/QCommand.h
        commands/impl/ACommand.cpp commands/impl/ACommand.h commands/impl/MCommand.cpp commands/impl/LCommand.cpp commands/impl/LCommand.h commands/impl/RCommand.cpp commands/impl/RCommand.h
        commands/impl/MCommand.h commands/impl/SCommand.cpp commands/impl/SCommand.h commands/impl/OCommand.cpp commands/impl/OCommand.h
        customers/Customer.cpp customers/Customer.cpp dstrctures/list/List.h
        dstrctures/list/linked/LinkedNode.h dstrctures/list/linked/LinkedList.h dstrctures/queue/Queue.h dstrctures/queue/linked/LinkedQueue.h
        commands/impl/RCommand.cpp commands/impl/RCommand.h
        commands/impl/QCommand.cpp commands/impl/QCommand.h books/Book.cpp books/Book.h)
add_executable(BookStore ${SOURCE_FILES})