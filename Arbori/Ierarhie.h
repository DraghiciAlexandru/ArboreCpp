#include <iostream>
#include "TreeNode.h"

using namespace std;

struct Ierarhie {

	Node* root = NULL;

	Node* find(Node* node, int data)
	{
		if (node == NULL)
			return NULL;

		if (node->data == data)
			return node;

		Node* left;

		left = find(node->left, data);

		if (left != NULL)
			return left;

		return find(node->right, data);
	}

	bool insert(int manager, int subordonat)
	{
		Node* node = find(root, manager);

		if (node->left != NULL && node->right != NULL)
		{
			return false;
		}

		if (node->left == NULL)
		{
			node->left = new Node();
			node->left->data = subordonat;
			return true;
		}

		if (node->right == NULL)
		{
			node->right = new Node();
			node->right->data = subordonat;
			return true;
		}

		return false;
	}


};