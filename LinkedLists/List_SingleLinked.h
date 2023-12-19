#pragma once

template<typename T>
class List_SingleLinked
{
	template<typename T>
	struct Node
	{
		Node(const T& data = T(), Node<T>* next = nullptr)
			:m_data{ data }, m_next(next) {}

		T m_data;
		Node<T>* m_next;
	};

	Node<T>* m_first;
	int m_size;

	Node<T>* getAtIndex(const int index)
	{
		Node<T>* current(m_first);
		int count(0);
		while (count < index)
		{
			current = current->m_next;
			++count;
		}

		return current;
	}

public:

	List_SingleLinked();
	~List_SingleLinked();

	T& operator[](const int index);

	void pushBack(const T& data);
	int getSize() { return m_size; }
	void popFront();
	void clear();
	void pushFront(const T& data);
	void insert(const T& data, const int index);
	void removeAt(const int index);
	void popBack();
};

//////////////////////////////////////////////////////////////////////////////////// Public
//////////////////////////////////////////////////////////////// Ctor

template<typename T>
List_SingleLinked<T>::List_SingleLinked()
	:m_first(nullptr), m_size(0) {}

//////////////////////////////////////////////////////////////// Dtor

template<typename T>
List_SingleLinked<T>::~List_SingleLinked()
{
	clear();
}

//////////////////////////////////////////////////////////////// Operator

template<typename T>
T& List_SingleLinked<T>::operator[](const int index)
{
	return getAtIndex(index)->m_data;
}

//////////////////////////////////////////////////////////////// Func

template<typename T>
void List_SingleLinked<T>::pushBack(const T& data)
{
	if (!m_first)
	{
		m_first = new Node<T>(data);
	}
	else
	{
		Node<T>* current{ getAtIndex(m_size - 1) };
		current->m_next = new Node<T>(data);
	}

	++m_size;
}

template<typename T>
inline void List_SingleLinked<T>::popFront()
{
	Node<T>* temp = m_first;
	m_first = m_first->m_next;
	--m_size;
	delete temp;
}

template<typename T>
inline void List_SingleLinked<T>::clear()
{
	while (m_first)
		popFront();
}

template<typename T>
inline void List_SingleLinked<T>::pushFront(const T& data)
{
	Node<T>* temp = new Node<T>(data,m_first);
	m_first = temp;
	++m_size;
}

template<typename T>
inline void List_SingleLinked<T>::insert(const T& data, const int index)
{
	if (!index)
		pushFront(data);
	else
	{
		Node<T>* previous = getAtIndex(index - 1);
		previous->m_next = new Node<T>(data, previous->m_next);
		++m_size;
	}
}

template<typename T>
inline void List_SingleLinked<T>::removeAt(const int index)
{
	if (!index)
		popFront();
	else
	{
		Node<T>* previous(getAtIndex(index - 1));
		Node<T>* deleted(previous->m_next);
		previous->m_next = deleted->m_next;
		delete deleted;
		--m_size;
	}
}

template<typename T>
inline void List_SingleLinked<T>::popBack()
{
	removeAt(m_size - 1);
}
