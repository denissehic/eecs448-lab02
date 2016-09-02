/**
*	@author Denis Sehic
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
        return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
        bool isFound = false;
        Node* n = m_front;
        int temp = 0;

        while (n != NULL)
        {
            if (n->getValue() == value)
            {
                isFound = true;
            }
            n = n -> getNext();
            temp++;
        }

        if (isFound == true)
            cout<< value << " is in the list."<<endl;
        else
            cout<< value << " is NOT in the list. " << endl;

        return isFound;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
        bool isRemoved = false;
        if(m_front != NULL){
        Node* end = m_front;
        Node* prev_end;
            while(end->getNext() != NULL)
            {
                 prev_end = end;
                 end = end->getNext();
            }
            prev_end->setNext(0);
            delete end;
         isRemoved = true;
           }
        if (isRemoved == true)
        {
            m_size--;
            cout << "Removal Successful!" <<endl;
            return true;
        }
        else
            return false;
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
