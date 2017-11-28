//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include "map/ArrayMap.h"
using namespace std;

int main() {
    Map<string, string>* strings = new ArrayMap<string, string>();
    strings->put("Hello", "World");
    cout << "Hello " << strings->get("Hello") << endl;
}