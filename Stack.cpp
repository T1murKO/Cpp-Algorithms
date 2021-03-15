#pragma once
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack() : top(nullptr), size(0) {}
	~Stack();
	struct Node
	{
		Node(T el) : data(el), previous(nullptr) {}
		Node(T el, Node* pr) : data(el), previous(pr) {}
		/*~Node()
		{
			delete this;
		}*/
		Node* previous;
		T data;
	};

	bool push(const T&);
	T pop();
	T peek();
	bool remove(const size_t);
	size_t getSize();
	bool isEmpty();

private:
	T prev();
	Node* top;
	int size;
	Node* getNodeByIndex(size_t index)
	{
		Node* currentNode = top;
		size_t iter = 0;
		while (iter != index)
		{
			currentNode = currentNode->previous;
			iter++;
		}
		return currentNode;
	}
};

template <typename T>
bool Stack<T>::push(const T& el)
{
	try
	{
		if (top != nullptr)
		{
			Node* temp = new Node(el, top);
			top = temp;
		}
		else
		{
			top = new Node(el);
		}
		size++;
		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in push method  parametr: el = " << el << endl;
		return false;
	}
}

template <typename T>
bool Stack<T>::remove(const size_t index)
{
	try
	{
		Node* nodeToDelete = getNodeByIndex(index);
		if (index == 0)
		{
			top = nodeToDelete->previous;
		}
		else
		{
			Node* nodeBeforeDeleted = getNodeByIndex(index - 1);
			if (index != size - 1)
				nodeBeforeDeleted->previous = nodeToDelete->previous;
			else
				nodeBeforeDeleted->previous = nullptr;
		}
		size--;
		nodeToDelete->~Node();

		return true;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in remove method   parametr: index =  " << index << endl;
		return false;
	}
}

template <typename T>
T Stack<T>::pop()
{
	try
	{
		if (top == nullptr)
			throw out_of_range("Error: Out of range\n");
		Node* temp = top;
		top = top->previous;
		size--;
		T dataToReturn = temp->data;
		delete temp;
		return dataToReturn;
	}
	catch (exception& e) {
		cerr << e.what() << " in pop method\n";
	}

}

template <typename T>
T Stack<T>::peek() {
	try
	{
		if (top == nullptr)
			throw out_of_range("Erorr: Stack is empty\n");

		return top->data;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in peek method\n";
	}
}

template <typename T>
T Stack<T>::prev()
{
	try
	{
		if (top == nullptr)
			throw("Erorr: Stack is empty\n");
		return top->previous->data;
	}
	catch (exception& e)
	{
		cerr << e.what() << " in prev method\n";
	}
}
template <typename T>
size_t Stack<T>::getSize()
{
	return size;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return (size == 0) ? false : true;
}

template <typename T>
Stack<T>::~Stack<T>()
{
	if (top != nullptr)
	{
		Node* nodeToDelete = top;
		while (nodeToDelete->previous != nullptr)
		{
			Node* tmp = nodeToDelete;
			nodeToDelete = nodeToDelete->previous;
			delete tmp;
		}
		delete nodeToDelete;
	}
}
