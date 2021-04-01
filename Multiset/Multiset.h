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

    //remove - �������� ��������� �������.
    void remove(const Pair<K,V>& element);

    //removeAll - �������� ������ �������� � ������� ����
    void removeAll(const K& key);

    //count() - ��� �������� - ����� ���� �� ������ �������� � ���������.
    size_t count();

    //count(//) - � �������� - ����� ���� �� ���������� �� �������� � ��������� ����.
    size_t count(const K& key);

    //isSubSet- ��������� ���� ����� �������� � ������������ �� ���� ��������.
    bool isSubSet(Multiset<K,V>&, Multiset<K,V>&);

    //merge - ����� ��� �������������� � ���� ��������������.
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
