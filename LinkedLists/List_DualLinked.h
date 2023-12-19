#pragma once

template<typename T>
class List_DualLinked
{
	template<typename T>
	struct Node
	{
		Node<T>* m_next, *m_previous;
		T m_data;
		Node(const T& data = T(), Node<T>* next = nullptr, Node<T>* previous = nullptr)
			:m_data{ data }, m_next(next), m_previous(previous) {}
	};

	Node<T>* getAtIndex(const int index)
	{
		bool isInFirstHalf(index <= m_size / 2);
		Node<T>* current(m_first);
		int count(0);

		if (isInFirstHalf)
		{
			while (count < index)
			{
				current = current->m_next;
				++count;
			}
		}
		else
		{
			current = m_last;
			count = m_size - 1;

			while (count > index)
			{
				current = current->m_previous;
				--count;
			}
		}

		return current;
	}

	void initFirst(const T& data)
	{
		m_first = new Node<T>(data);
		m_last = m_first;
	}

	Node<T>* m_first, *m_last;
	int m_size;

public:
	List_DualLinked();
	~List_DualLinked();

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
inline List_DualLinked<T>::List_DualLinked()
	:m_first(nullptr), m_last(nullptr), m_size(0) {}

//////////////////////////////////////////////////////////////// Dtor

template<typename T>
inline List_DualLinked<T>::~List_DualLinked()
{
	clear();
}

//////////////////////////////////////////////////////////////// Operator

template<typename T>
inline T& List_DualLinked<T>::operator[](const int index)
{
	return getAtIndex(index)->m_data;
}

//////////////////////////////////////////////////////////////// Func

template<typename T>
inline void List_DualLinked<T>::pushBack(const T& data)
{
	if (!m_size)
		initFirst(data);
	else
	{
		m_last->m_next = new Node<T>(data, nullptr, m_last);
		m_last = m_last->m_next;
	}
	++m_size;
}

template<typename T>
inline void List_DualLinked<T>::popFront()
{
	Node<T>* temp(m_first);
	m_first = m_first->m_next;
	delete temp;
	--m_size;
}

template<typename T>
inline void List_DualLinked<T>::clear()
{
	while (m_first)
		popFront();
}

template<typename T>
inline void List_DualLinked<T>::pushFront(const T& data)
{
	if (!m_size)
		initFirst(data);
	else
	{
		m_first->m_previous = new Node<T>(data, m_first);
		m_first = m_first->m_previous;
	}
	++m_size;
}

template<typename T>
inline void List_DualLinked<T>::insert(const T& data, const int index)
{
	Node<T>* previous(getAtIndex(index - 1));
	previous->m_next = new Node<T>(data, previous->m_next, previous);
	previous->m_next->m_next->m_previous = previous->m_next;
	++m_size;
}

template<typename T>
inline void List_DualLinked<T>::removeAt(const int index)
{
	if (!index)
		popFront();
	else if (index == m_size - 1)
		popBack();
	else
	{
		Node<T>* current(getAtIndex(index));
		current->m_previous->m_next = current->m_next;
		current->m_next->m_previous = current->m_previous;
		delete current;
		--m_size;
	}
}

template<typename T>
inline void List_DualLinked<T>::popBack()
{
	m_last = m_last->m_previous;
	delete m_last->m_next;
	m_last->m_next = nullptr;
	--m_size;
}
