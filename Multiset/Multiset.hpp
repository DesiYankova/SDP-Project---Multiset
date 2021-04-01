template <typename K, typename V>
void Multiset<K,V>::add(const Pair<K,V>& element)
{
    multiset.add(element);

}


template <typename K, typename V>
void Multiset<K,V>::remove(const Pair<K,V>& element)
{
    multiset.remove(element);
}


template <typename K, typename V>
void Multiset<K,V>::removeAll(const K& key)
{
    multiset.removeAll(key);
}


template <typename K, typename V>
size_t Multiset<K,V>::count()
{
    multiset.count();
}


template <typename K, typename V>
size_t Multiset<K,V>::count(const K& key)
{
    multiset.count(key);
}


template <typename K, typename V>
bool Multiset<K,V>::isSubSet(Multiset<K,V>& first, Multiset<K,V>& second)
{
    int counter = 0;

    LinkedList<K,V> temp1;
    for(int i = 0; i < first.getSize(); i++)
    {
        if(first[i].isEmpty() == false)
        {
            Node<K,V>* node1 = first[i].getFirst();
            while (node1 != NULL)
            {
                temp1.push_front(node1 -> data);
                node1 = node1 -> next;
            }
        }
        else
        {
            continue;
        }
    }

    LinkedList<K,V> temp2;
    for(int i = 0; i < second.getSize(); i++)
    {
        if(second[i].isEmpty() == false)
        {
            Node<K,V>* node2 = second[i].getFirst();
            while (node2 != NULL)
            {
                temp2.push_front(node2 -> data);
                node2 = node2 -> next;
            }
        }
        else
        {
            continue;
        }
    }

    Node<K,V>* node1 = temp1.getFirst();
    Node<K,V>* node2 = temp2.getFirst();


    for(int i = 0; i < temp1.getSize() && node1 != NULL; i++)
    {
        for(int j = 0; j < temp2.getSize() && node2 != NULL; j++)
        {
            if(node1->data != node2->data)
            {
                node2 = node2 -> next;
            }
            else
            {
                node1 = node1 -> next;
                node2 = temp2.getFirst();
                counter++;
                break;
            }
        }
    }

    if(counter == temp1.getSize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename K, typename V>
size_t Multiset<K,V>::getSize()const
{
    return multiset.getSize();
}


template <typename K, typename V>
void Multiset<K,V>::Print()const
{
    multiset.Print();
}


template <typename K, typename V>
void Multiset<K,V>::merge(Multiset<K,V>& multiset1, Multiset<K,V>& multiset2)
{
    LinkedList<K,V> temp1;
    for(int i = 0; i < multiset1.getSize(); i++)
    {
        if(multiset1[i].isEmpty() == false)
        {
            Node<K,V>* node1 = multiset1[i].getFirst();
            while (node1 != NULL)
            {
                temp1.push_front(node1 -> data);
                node1 = node1 -> next;
            }
        }
        else
        {
            continue;
        }
    }

    LinkedList<K,V> temp2;
    for(int i = 0; i < multiset2.getSize(); i++)
    {
        if(multiset2[i].isEmpty() == false)
        {
            Node<K,V>* node2 = multiset2[i].getFirst();
            while (node2 != NULL)
            {
                temp2.push_front(node2 -> data);
                node2 = node2 -> next;
            }
        }
        else
        {
            continue;
        }
    }

    size_t size = temp2.getSize();
    for(int i = 0; i < size; i++)
    {
        Node<K,V>* tempNode = temp2.getFirst();
        temp1.push_front(temp2.pop_front());
    }

    Pair<K,V> newPair;
    Multiset<K,V> newMulti;
    Node<K,V>* tempNode = temp1.getFirst();
    for(int i = 0; i < temp1.getSize(); i++)
    {
        newPair.setKey(tempNode->data.getKey());
        newPair.setValue(tempNode->data.getValue());
        newMulti.add(newPair);
        tempNode = tempNode -> next;
    }
    newMulti.Print();
}


template <typename K, typename V>
void Multiset<K,V>::backup(string name)const
{
    LinkedList<K,V> temp1;
    for(int i = 0; i < multiset.getSize(); i++)
    {
        if(multiset[i].isEmpty() == false)
        {
            Node<K,V>* node1 = multiset[i].getFirst();
            while (node1 != NULL)
            {
                temp1.push_front(node1 -> data);
                node1 = node1 -> next;
            }
        }
        else
        {
            continue;
        }
    }
    ofstream myfile(name);
    Node<K,V>* tmp = temp1.getFirst();
    for(int i = 0; i < temp1.getSize(); i++)
    {
        myfile << tmp -> data.getKey();
        myfile << ",";
        myfile << tmp -> data.getValue();
        myfile << "\n";
        tmp = tmp -> next;
    }
    myfile.close();
}


template <typename K, typename V>
LinkedList<K,V>& Multiset<K,V>::operator[](size_t index)
{
	return multiset[index];
}


template <typename K, typename V>
const LinkedList<K,V>& Multiset<K,V>::operator[](size_t index) const
{
    return multiset[index];
}
