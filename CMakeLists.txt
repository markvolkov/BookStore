cmake_minimum_required(VERSION 3.8)
project(BookStore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp map/ArrayList.h map/ArrayMap.h map/Item.h map/Map.h
        commands/CommandManager.cpp commands/Command.h commands/impl/HCommand.cpp commands/impl/HCommand.h)
add_executable(BookStore ${SOURCE_FILES})