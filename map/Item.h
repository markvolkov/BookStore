//
// Created by Mark Volkov on 11/13/17.
//

#ifndef HASHMAP_ITEM_H
#define HASHMAP_ITEM_H

//TODO: Figure out how to delete key or value if they're on the heap
template <class K, class V>
class Item {
private:
    K k;
    V v;
public:
    Item();
    Item(K key, V value);
    Item(const Item& toCopy);
    Item& operator=(Item& toCopy);
    K getKey();
    V getValue();
};

#include "Item.inl"
#endif //HASHMAP_ITEM_H
