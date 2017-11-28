//
// Created by Mark Volkov on 11/13/17.
//

#include "Item.h"
template <class K, class V>
Item<K, V>::Item() {
    this->k = nullptr;
    this->v = nullptr;
}
template <class K, class V>
Item<K, V>::Item(K key, V value) {
    this->k = key;
    this->v = value;
}
template <class K, class V>
Item<K, V>::Item(const Item& toCopy){
    this->k = toCopy.key;
    this->v = toCopy.value;
}
template <class K, class V>
Item<K, V>& Item<K, V>::operator=(Item<K, V>& toCopy) {
    this->k = toCopy.key;
    this->v = toCopy.value;
}
template <class K, class V>
K Item<K, V>::getKey() {
    return k;
}
template <class K, class V>
V Item<K, V>::getValue() {
    return v;
}
