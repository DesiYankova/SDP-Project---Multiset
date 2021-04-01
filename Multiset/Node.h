#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

template <typename K, typename V>
struct Node
{
	Node(const Pair<K,V>& data, Node<K,V>* next = NULL)
	{
	    this -> data = data;
	    this -> next = next;
	    this -> prev = prev;
	}

	Pair<K,V> data;
    Node<K,V>* next;
    Node<K,V>* prev;


	bool operator==(const Node& rhs) const
	{
	    return data == rhs.data;
	}
	bool operator!=(Node& rhs)const
	{
	    return !(*this == rhs);
	}
};
