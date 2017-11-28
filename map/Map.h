//
// Created by Mark Volkov on 11/15/17.
//
#include "ArrayList.h"
#include "Item.h"
template <class K, class V>
class Map {

public:
    virtual V put(K key, V value)=0;
    virtual V get(K key)=0;
    virtual ArrayList<Item<K,V>*>* itemSet()=0;

};
