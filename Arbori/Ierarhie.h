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

	void preorder(Node* node)
	{
		if (node == NULL)
			return;

		cout << node->data << endl;

		preorder(node->left);
		preorder(node->right);
	}

	void inorder(Node* node)
	{
		if (node == NULL)
			return;

		inorder(node->left);
		cout << node->data << endl;
		inorder(node->right);
	}

	void postorder(Node* node)
	{
		if (node == NULL)
			return;
		postorder(node->left);
		postorder(node->right);
		cout << node->data << endl;
	}

	int nivel(Node* node, int data) 
	{
		if (node == NULL)
			return 0;
		if (node->data == data)
		{
			return nivel(NULL, data);
		}
		else if (find(node->left, data) != NULL)
			return 1 + nivel(node->left, data);
		else if (find(node->right, data) != NULL)
			return 1 + nivel(node->right, data);
		return -1;
	}
};