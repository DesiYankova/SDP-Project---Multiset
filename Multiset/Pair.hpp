template <typename K, typename V>
Pair<K,V>::Pair()
    :key(), value()
{

}


template <typename K, typename V>
Pair<K,V>::Pair(K key, V value)
{
    this -> key = key;
    this -> value = value;
}


template <typename K, typename V>
Pair<K,V>::Pair(const Pair<K,V>& other)
{
    this -> setKey(other.getKey());
    this -> setValue(other.getValue());
}


template <typename K, typename V>
Pair<K,V>& Pair<K,V>::operator= (const Pair<K,V>& other)
{
    this -> setKey(other.getKey());
    this -> setValue(other.getValue());
}


template <typename K, typename V>
bool Pair<K,V>::operator==(const Pair<K,V>& rhs)
{
    return key == rhs.key && value == rhs.value;
}


template <typename K, typename V>
bool Pair<K,V>::operator!=(const Pair<K,V>& rhs)
{
    return !(*this == rhs);
}


template <typename K, typename V>
bool Pair<K,V>::operator>(const Pair<K,V>& rhs)
{
    return key > rhs.key && value > rhs.value;
}


template <typename K, typename V>
bool Pair<K,V>::operator<(const Pair<K,V>& rhs)
{
    return key < rhs.key && value < rhs.value;
}


template <typename K, typename V>
K Pair<K,V>::getKey()const
{
    return key;
}


template <typename K, typename V>
void Pair<K,V>::setKey(const K& newKey)
{
    key = newKey;
}


template <typename K, typename V>
V Pair<K,V>::getValue()const
{
    return value;
}


template <typename K, typename V>
void Pair<K,V>::setValue(const V& newValue)
{
    value = newValue;
}


template <typename K, typename V>
void Pair<K,V>::PrintPair()const
{
    cout << "Key: " << getKey() << ", Value: " << getValue() << endl;
}
