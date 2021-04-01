#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "Pair.h"
#include "Node.h"
using namespace std;


template <typename K, typename V>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<K,V>&);
    LinkedList& operator=(const LinkedList<K,V>&);
    ~LinkedList();


    Pair<K,V> pop_front();
    Pair<K,V> pop_back();

    void push_front(const Pair<K,V>& data);
    void push_back(const Pair<K,V>& data);

    Pair<K,V>& PeekFront();
	const Pair<K,V>& PeekFront() const;
	Pair<K,V>& PeekBack();
	const Pair<K,V>& PeekBack() const;

	void Destroy();
    bool isEmpty() const;
    size_t getSize() const;
	Node<K,V>* getFirst() const;
    Pair<K,V> removeAt(size_t index);
    Pair<K,V> removeElem(const Pair<K,V>& dataToDelete);
	void removeDuplicates(Node<K,V> *start);

    Pair<K,V>& operator[](size_t index);
	const Pair<K,V>& operator[](size_t index) const;

	void Print()const;

private:
    Node<K,V>* firstElem;
    Node<K,V>* lastElem;
    size_t sizeOfList;

    void copyList(const LinkedList&);
    void Empty();
    void Init();
    Node<K,V>* elemAtPosition(size_t index) const;
};

#include "LinkedList.hpp"
