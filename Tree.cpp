#include <iostream>

using namespace std;

template <typename T>
class Tree
{
	struct Node;
	Node* root;
	int _size;
public:
	enum crossroad { right, left };
	struct Node
	{
		Node* right;
		Node* left;
		T data;
		Node(T el) : Node(el, nullptr, nullptr) {}
		Node(T el, Node* newBranch, crossroad side) {
			if (!side)Node(el, newBranch, nullptr);
			else Node(el, nullptr, newBranch);
		}
		Node(T el, Node* addRight, Node* addLeft) : data(el), right(addRight), left(addLeft) {}
	};
	Tree();
	void insert();



};
template <typename T>
Tree<T>::Tree() : root(nullptr), _size(0) {}



int main()
{
	Tree<int> tr;
}