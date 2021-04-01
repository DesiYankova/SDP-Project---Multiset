template <typename K, typename V>
LinkedList<K,V>::LinkedList()
{
    this -> firstElem = NULL;
    this -> lastElem = NULL;
    this -> sizeOfList = 0;
}


template <typename K, typename V>
LinkedList<K,V>::LinkedList(const LinkedList<K,V>& linkedList)
{
    this -> Init();
    this -> copyList(linkedList);
}


template <typename K, typename V>
LinkedList<K,V>& LinkedList<K,V>::operator= (const LinkedList<K,V>& linkedList)
{
    if(this != &linkedList)
    {
        this -> Empty();
        this -> Init();
        this -> copyList(linkedList);
    }
    return *this;
}


template <typename K, typename V>
LinkedList<K,V>::~LinkedList()
{
    this -> Empty();
    this -> Init();
}


template <typename K, typename V>
Pair<K,V> LinkedList<K,V>::pop_front()
{
    //assert(firstElem != NULL);
	Node<K,V>* elemToDelete = firstElem;
	Pair<K,V> data = elemToDelete -> data;
	if (elemToDelete -> next == NULL)
	{
		firstElem = lastElem = NULL;
	}
	else
	{
		firstElem -> next -> prev = NULL;
		firstElem = firstElem -> next;
	}
    delete elemToDelete;
	sizeOfList--;
	return data;
}


template <typename K, typename V>
Pair<K,V> LinkedList<K,V>::pop_back()
{
    assert(firstElem != NULL);
	Node<K,V>* elemToDelete = lastElem;
	Pair<K,V> data = elemToDelete -> data;
	if (elemToDelete -> prev == NULL)
	{
		firstElem = lastElem = NULL;
	}
	else
	{
		lastElem -> prev -> next = NULL;
		lastElem = lastElem -> prev;
	}
	delete elemToDelete;
	sizeOfList--;
	return data;
}


template <typename K, typename V>
void LinkedList<K,V>::push_front(const Pair<K,V>& data)
{
    Node<K,V>* newNode = new Node<K,V>(data, this -> firstElem);
    if(newNode)
    {
        if(isEmpty() == true)
        {
            firstElem = lastElem = newNode;
        }
        else
        {
            newNode -> next = firstElem;
            firstElem -> prev = newNode;
            firstElem = newNode;
        }
        sizeOfList++;
    }
}


template <typename K, typename V>
void LinkedList<K,V>::push_back(const Pair<K,V>& data)
{
    Node<K,V>* newNode = new Node<K,V>(data, NULL);
    if(newNode)
    {
        if(isEmpty() == true)
        {
            firstElem = lastElem = newNode;
        }
        else
        {
            newNode -> prev = lastElem;
            lastElem -> next = newNode;
            lastElem = newNode;
        }
        sizeOfList++;
    }
}


template <typename K, typename V>
Pair<K,V>& LinkedList<K,V>::PeekFront()
{
    assert(firstElem != NULL);
	return firstElem -> data;
}


template <typename K, typename V>
const Pair<K,V>& LinkedList<K,V>::PeekFront() const
{
    assert(firstElem != NULL);
	return firstElem -> data;
}


template <typename K, typename V>
Pair<K,V>& LinkedList<K,V>::PeekBack()
{
    assert(lastElem != NULL);
	return lastElem -> data;
}


template <typename K, typename V>
const Pair<K,V>& LinkedList<K,V>::PeekBack() const
{
    assert(lastElem != NULL);
	return lastElem -> data;
}


template <typename K, typename V>
void LinkedList<K,V>::Destroy()
{
    while(isEmpty() == false)
    {
        this -> pop_front();
    }
}


template <typename K, typename V>
Pair<K,V> LinkedList<K,V>::removeElem(const Pair<K,V>& dataToDelete)
{
    if(isEmpty() == true)
    {
        cout << "empty" << endl;
    }
    else
    {
        if(this -> firstElem -> data == dataToDelete)
        {
            return this -> pop_front();
        }
        else if(this -> lastElem -> data == dataToDelete)
        {
            return this -> pop_back();
        }
        else
        {
            Node<K,V>* temp = firstElem -> next;
            for(size_t i = 0; i < getSize() - 1; i++)
            {
                if(temp -> data == dataToDelete)
                {
                    Node<K,V>* nodeToDelete = temp;
                    Pair<K,V> deletedData = nodeToDelete -> data;
                    nodeToDelete -> prev -> next = nodeToDelete -> next;
                    nodeToDelete -> next -> prev = nodeToDelete -> prev;
                    delete nodeToDelete;
                    sizeOfList--;
                    return deletedData;
                }
            }
        }
    }
}


template <typename K, typename V>
bool LinkedList<K,V>::isEmpty() const
{
    return sizeOfList == 0;
}


template <typename K, typename V>
size_t LinkedList<K,V>::getSize() const
{
    return this -> sizeOfList;
}


template <typename K, typename V>
Pair<K,V>& LinkedList<K,V>::operator[](size_t index)
{
    Node<K,V>* node = elemAtPosition(index);
	assert(node != NULL);
	return node -> data;
}


template <typename K, typename V>
const Pair<K,V>& LinkedList<K,V>::operator[](size_t index) const
{
    Node<K,V>* node = elemAtPosition(index);
	assert(node != NULL);
	return node -> data;
}


template <typename K, typename V>
void LinkedList<K,V>::Print()const
{
    Node<K,V>* current;
    current = firstElem;
    while(current != nullptr)
    {
        current -> data.PrintPair();
        current = current -> next;
    }
}


template <typename K, typename V>
void LinkedList<K,V>::removeDuplicates(Node<K,V> *start)
{
    Node<K,V> *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data.getValue() == ptr2->next->data.getValue())
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dup;
                sizeOfList--;
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


template <typename K, typename V>
void LinkedList<K,V>::copyList(const LinkedList<K,V>& linkedList)
{
    Node<K,V>* node = linkedList.getFirst();
    for(int i = 0; i < linkedList.getSize(); i++)
    {
        this->push_back(node->data);
        node = node->next;
    }
}

template <typename K, typename V>
Node<K,V>* LinkedList<K,V>::getFirst() const
{
    if(this->isEmpty()) return NULL;
    return this->firstElem;
}


template <typename K, typename V>
void LinkedList<K,V>::Empty()
{

    for(size_t i = 0; i < this -> sizeOfList; i++)
    {
        this -> pop_front();
    }

     this -> Init();

}


template <typename K, typename V>
void LinkedList<K,V>::Init()
{
    this-> firstElem = NULL;
    this-> lastElem = NULL;
    this-> sizeOfList = 0;
}


template <typename K, typename V>
Node<K,V>* LinkedList<K,V>::elemAtPosition(size_t index)const
{
    Node<K,V>* node = firstElem;
	size_t Size = 0;
	while (node != NULL && index > Size)
	{
		node = node -> next;
		Size++;
	}
	return node;
}
