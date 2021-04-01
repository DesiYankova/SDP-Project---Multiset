#pragma once
#include <iostream>
#include "LinkedList.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

template <typename K, typename V>
class HashTable
{
public:
    HashTable();
    ~HashTable();

    //add
    void add(const Pair<K,V>& element);

    //remove - �������� ��������� �������.
    void remove(const Pair<K,V>& element);

    //removeAll - �������� ������ �������� � ������� ����
    void removeAll(const K& key);

    //count() - ��� �������� - ����� ���� �� ������ �������� � ���������.
    void count();

    //count(//) - � �������� - ����� ���� �� ���������� �� �������� � ��������� ����.
    void count(const K& key);

    void Print()const;
    size_t getSize()const;

    LinkedList<K,V>& operator[](size_t index);
	const LinkedList<K,V>& operator[](size_t index) const;

private:
    vector<LinkedList<K,V>>* hashTable;
    size_t sizeOfHashTable;
    size_t numberOfElements;

    void resize();
    size_t hashOfString(string);
};

#include "HashTable.hpp"
