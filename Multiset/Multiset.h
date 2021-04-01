#pragma once
#include <iostream>
#include "HashTable.h"

template <typename K, typename V>
class Multiset
{
public:
    Multiset() = default;
    ~Multiset() = default;

    //add
    void add(const Pair<K,V>& element);

    //remove - Премахва конкретен елемент.
    void remove(const Pair<K,V>& element);

    //removeAll - Премахва всички елементи с подаден ключ
    void removeAll(const K& key);

    //count() - без аргумент - Връща броя на всички елементи в мултисета.
    size_t count();

    //count(//) - с аргумент - Връща броя на срещанията на елементи с подадения ключ.
    size_t count(const K& key);

    //isSubSet- Проверява дали даден мултисет е подмножество на друг мултисет.
    bool isSubSet(Multiset<K,V>&, Multiset<K,V>&);

    //merge - Слива две мултимножества в ново мултимножество.
    void merge(Multiset<K,V>&, Multiset<K,V>&);

    void Print()const;
    size_t getSize()const;

    void backup(string name)const;

    LinkedList<K,V>& operator[](size_t index);
	const LinkedList<K,V>& operator[](size_t index) const;

private:
    HashTable<K,V> multiset;
};

#include "Multiset.hpp"
