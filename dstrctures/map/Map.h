//
// Created by Mark Volkov on 11/15/17.
//

#ifndef MAP_MAP_M
#define MAP_MAP_M

#include "Item.h"
#include "../list/array/ArrayList.h"

template <class K, class V>
class Map {

public:
    virtual ~Map(){};
    virtual V put(K key, V value)=0;
    virtual V get(K key)=0;
    virtual ArrayList<Item<K,V>*>* itemSet()=0;

};
#endif //MAP_MAP_M
