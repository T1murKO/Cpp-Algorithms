#pragma once
#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Queue
{
public:
	Queue();
	Queue(const size_t);
	~Queue();

	bool add(T);
	T peek();
	T poll();
	bool isEmpty();
	bool remove(size_t);
	size_t getSize();

private:
	T* queue;
	size_t length;
	size_t capacity;

	void grow(size_t);
};

template <typename T>
Queue<T>::Queue()
{
	queue = nullptr;
	length = 0;
	capacity = 0;
}

template <typename T>
Queue<T>::Queue(const size_t allocateCapacity)
{
	queue = new T[allocateCapacity];
	capacity = allocateCapacity;
	length = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	if (queue != nullptr)
		delete queue;
}

template <typename T>
bool Queue<T>::add(T object)
{
	try
	{
		if (length >= capacity)
			this->grow(capacity + 1);

		queue[length] = object;
		length++;
		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in add method   parametr: add = " << object << endl;
		return false;
	}

}

template <typename T>
void Queue<T>::grow(size_t minCapacity)
{
	try
	{
		size_t newCapacity = minCapacity < 64 ? minCapacity + 2 : minCapacity * 2;
		T* newQueue = new T[newCapacity];
		for (size_t i = 0; i < minCapacity - 1; ++i)
		{
			newQueue[i] = queue[i];
		}
		delete queue;
		capacity = newCapacity;
		queue = newQueue;

	}
	catch (exception& e)
	{
		cerr << e.what() << " in grow method\n";
	}

}

template <typename T>
size_t Queue<T>::getSize()
{
	return length;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	return (length == 0) ? true : false;
}

template <typename T>
T Queue<T>::peek()
{
	return queue[0];
}

template <typename T>
T Queue<T>::poll()
{
	T dataToReturn = queue[0];
	for (size_t i = 0; i < length - 1; ++i)
	{
		queue[i] = queue[i + 1];
	}

	return dataToReturn;
}

#endif _QUEUE_