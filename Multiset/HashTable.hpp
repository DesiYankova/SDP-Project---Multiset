template <typename K, typename V>
HashTable<K,V>::HashTable()
{
    this -> sizeOfHashTable =  256;
    this->hashTable = new vector<LinkedList<K,V>>();
    LinkedList<K,V> temp;
    for (size_t i = 0; i < this->sizeOfHashTable ; i++)
    {
        this->hashTable->push_back(temp);
    }
}


template <typename K, typename V>
HashTable<K,V>::~HashTable()
{
    delete hashTable;
}


template <typename K, typename V>
void HashTable<K,V>::add(const Pair<K,V>& element)
{
    size_t hashOfKey = hashOfString(element.getKey());
    if(hashOfKey > sizeOfHashTable)
    {
        resize();
    }
    hashTable->at(hashOfKey).push_front(element);
    numberOfElements++;
}


template <typename K, typename V>
void HashTable<K,V>::remove(const Pair<K,V>& element)
{
    size_t hashOfKey = hashOfString(element.getKey());
    if(hashTable->at(hashOfKey).isEmpty() == true)
    {
        cout << "Wrong key" << endl;
    }
    else
    {
        hashTable->at(hashOfKey).removeElem(element);
        numberOfElements--;
    }
}


template <typename K, typename V>
void HashTable<K,V>::removeAll(const K& key)
{
    size_t hashOfKey = hashOfString(key);
    if(hashTable->at(hashOfKey).isEmpty() == true)
    {
        cout << "Wrong key" << endl;
    }
    else
    {
        numberOfElements -= hashTable->at(hashOfKey).getSize();
        hashTable->at(hashOfKey).Destroy();
    }
}


template <typename K, typename V>
void HashTable<K,V>::count()
{
    LinkedList<K,V> temp;
    for(int i = 0; i < sizeOfHashTable; i++)
    {
        if(hashTable->at(i).isEmpty() == false)
        {
            Node<K,V>* node = hashTable->at(i).getFirst();
            while (node != NULL)
            {
                temp.push_front(node -> data);
                node = node -> next;
            }
        }
    }
    temp.removeDuplicates(temp.getFirst());
    cout << temp.getSize();
}


template <typename K, typename V>
void HashTable<K,V>::count(const K& key)
{
    size_t hashOfKey = hashOfString(key);
    if(hashTable->at(hashOfKey).isEmpty() == true)
    {
        cout << "Wrong key" << endl;
    }
    else
    {
        cout << hashTable->at(hashOfKey).getSize() << endl;
    }
}


template <typename K, typename V>
void HashTable<K,V>::Print()const
{
    for(int i = 0; i < sizeOfHashTable; i++)
    {
        if(hashTable->at(i).isEmpty() == true)
        {
            continue;
        }
        else
        {
            hashTable->at(i).Print();
        }
    }
}


template <typename K, typename V>
size_t HashTable<K,V>::getSize()const
{
    return this -> sizeOfHashTable;
}


template <typename K, typename V>
LinkedList<K,V>& HashTable<K,V>::operator[](size_t index)
{
	return hashTable -> at(index);
}


template <typename K, typename V>
const LinkedList<K,V>& HashTable<K,V>::operator[](size_t index) const
{
    return hashTable -> at(index);
}


template <typename K, typename V>
void HashTable<K,V>::resize()
{
    size_t newSize = sizeOfHashTable * 2;
    vector<LinkedList<K,V>>* newTable = new vector<LinkedList<K,V>>;
    LinkedList<K,V> temp;
    for (size_t i = 0; i < newSize ; i++)
    {
        this->hashTable->push_back(temp);
    }

    for (size_t i = 0; i < newSize; i++)
    {
        if (hashTable->at(i).isEmpty() == false)
        {
            size_t index = hashOfString(hashTable->at(i).PeekFront().getKey());
            newTable[index] = hashTable[i];
        }
    }
    delete hashTable;
    hashTable = newTable;
}


template <typename K, typename V>
size_t HashTable<K,V>::hashOfString(string key)
{
    size_t hash = 0;
    size_t index = 0;

    for (int i = 0; i < key.length (); i++)
    {
        hash = hash + ((int) key[i]) * 5;
    }
    index = hash % sizeOfHashTable;
    return index;
}
