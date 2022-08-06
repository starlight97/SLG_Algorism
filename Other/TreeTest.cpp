#include <iostream>

using namespace std;

class BTNode
{
public: 
	char data;
	BTNode* Left;
	BTNode* Right;

	BTNode(char data)
	{
		this->data = data;
		Left = nullptr;
		Right = nullptr;
	}
};

class Tree
{
public:
	BTNode *Root;

	Tree(BTNode *node)
	{
		this->Root = node;
	}

	void PreOrderTraversal(BTNode *node)
	{
		if (node == nullptr)
			return;
		cout << node->data;
		PreOrderTraversal(node->Left);
		PreOrderTraversal(node->Right);
	}

	void InorderTraverse(BTNode* node)
	{
		if (node == nullptr)
			return;
		InorderTraverse(node->Left);
		cout << node->data;
		InorderTraverse(node->Right);
	}

	void PostorderTraverse(BTNode* node)
	{
		if (node == nullptr)
			return;
		PostorderTraverse(node->Left);		
		PostorderTraverse(node->Right);
		cout << node->data;
	}
};

int main()
{
	BTNode *node1 = new BTNode('A');
	BTNode *node2 = new BTNode('B');
	BTNode *node3 = new BTNode('C');
	BTNode *node4 = new BTNode('D');
	BTNode *node5 = new BTNode('E');
	BTNode *node6 = new BTNode('F');
	BTNode *node7 = new BTNode('G');

	Tree *tree = new Tree(node1);

	node1->Left = node2;
	node1->Right = node3;

	node2->Left = node4;

	node3->Left = node5;
	node3->Right = node6;
	node6->Right = node7;

	tree->PreOrderTraversal(node1);
	cout << endl;
	tree->InorderTraverse(node1);
	cout << endl;
	tree->PostorderTraverse(node1);
	cout << endl;
}
