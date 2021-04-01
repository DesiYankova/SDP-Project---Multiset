#pragma once
#include <iostream>
using namespace std;

template <typename K, typename V>
class Pair
{
public:
    Pair();
    Pair(K key, V value);
    Pair(const Pair<K,V>& other);
    Pair<K,V>& operator= (const Pair<K,V>& other);

    bool operator==(const Pair<K,V>& rhs);
    bool operator!=(const Pair<K,V>& rhs);
    bool operator>(const Pair<K,V>& rhs);
    bool operator<(const Pair<K,V>& rhs);


    K getKey()const;
    void setKey(const K& newKey);

    V getValue()const;
    void setValue(const V& newValue);

    void PrintPair()const;

private:
    K key;
    V value;
};

#include "Pair.hpp"
