#pragma once
#include <exception>
#include <iostream>
#include <List>
using namespace std;

template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList() :head(new Node()), tail(head), size(0) {}
	~DoubleLinkedList();
	class Node
	{
	public:
		T data;
		Node* prevNode;
		Node* nextNode;
		Node() :prevNode(nullptr), nextNode(nullptr) {}
		Node(const T& data, Node* tail)
		{
			tail->nextNode = this;
			this->data = data;
			this->prevNode = tail;
			this->nextNode = nullptr;
		}
	};
	bool add(const T& value);
	bool remove(const size_t index);
	bool insert(const size_t index, const T& value);
	T get(const size_t);
	size_t getSize();
	bool isEmpty();
	T operator [] (const size_t index);
private:
	Node* head;
	Node* tail;
	size_t size;
	Node* getNodeByIndex(size_t index)
	{
		if (index < 0 || index >= size)
			throw out_of_range("Error: Out of range\n");
		Node* currentNode;
		if (index < size / 2)
		{
			currentNode = head;
			size_t currentIndex = 0;
			while (currentIndex != index)
			{
				currentNode = currentNode->nextNode;
				currentIndex++;
			}
		}
		else
		{
			currentNode = tail;
			size_t currentIndex = size - 1;
			while (currentIndex != index)
			{
				currentNode = currentNode->prevNode;
				currentIndex--;
			}
		}
		return currentNode;
	}
};

template <typename T>
size_t DoubleLinkedList<T>::getSize()
{
	return size;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return (size == 0) ? true : false;
}

template <typename T>
bool DoubleLinkedList<T>::insert(const size_t index, const T& value)
{
	try
	{
		if (index == size)
		{
			add(value);
			return true;
		}


		Node* nodeToInsert = new Node();
		nodeToInsert->data = value;
		Node* nodeToShift = getNodeByIndex(index);

		if (nodeToShift->prevNode == nullptr)
		{

			head = nodeToInsert;
		}
		else
		{
			nodeToInsert->prevNode = nodeToShift->prevNode;
			nodeToShift->prevNode->nextNode = nodeToInsert;
			tail = nodeToShift;
		}
		nodeToShift->prevNode = nodeToInsert;
		nodeToInsert->nextNode = nodeToShift;
		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in insert method\n";
		return false;
	}
}

template <typename T>
bool DoubleLinkedList<T>::add(const T& value)
{
	try
	{
		if (isEmpty())
		{
			head->data = value;
			size++;
		}
		else
		{
			tail = new Node(value, tail);
			size++;

		}
		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in add method\n";
		return false;
	}
}

template <typename T>
T DoubleLinkedList<T>::get(const size_t index)
{
	try
	{
		if (index < 0 || index >= size)
			throw out_of_range("Error: Out of range\n");
		Node* currentNode;
		if (index < size / 2)
		{
			currentNode = head;
			size_t currentIndex = 0;
			while (currentIndex != index)
			{
				currentNode = currentNode->nextNode;
				currentIndex++;
			}
		}
		else
		{
			currentNode = tail;
			size_t currentIndex = size - 1;
			while (currentIndex != index)
			{
				currentNode = currentNode->prevNode;
				currentIndex--;
			}
		}
		return currentNode->data;
	}
	catch (exception& e)
	{
		cerr << e.what() << "in get method\n";
		system("pause");
		exit(0);
	}
}


template <typename T>
T DoubleLinkedList<T>::operator [] (const size_t index)
{
	try
	{
		return this->getNodeByIndex(index)->data;
	}
	catch (exception& e)
	{
		cerr << e.what() << "in get method\n";
		system("pause");
	}
}

template <typename T>
bool DoubleLinkedList<T>::remove(const size_t index)
{
	try
	{
		Node* currentNode = getNodeByIndex(index);
		if (currentNode->prevNode == nullptr)
			head = currentNode->nextNode;
		else if (currentNode->nextNode == nullptr)
			tail = currentNode->prevNode;
		else
		{
			currentNode->prevNode->nextNode = currentNode->nextNode;
			currentNode->nextNode->prevNode = currentNode->prevNode;
		}
		size--;
		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << "in remove method\n";
		return false;
	}
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node* nodeToDelete = head;
	while (nodeToDelete->nextNode != nullptr)
	{
		Node* tmp = nodeToDelete;
		nodeToDelete = nodeToDelete->nextNode;
		delete tmp;
	}
	delete nodeToDelete;
}