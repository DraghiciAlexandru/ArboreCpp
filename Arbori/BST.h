#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

struct BST {

	Node* root = NULL;

	void insert(Node* node, int data)
	{
		if (node->data > data)
		{
			if (node->left == NULL)
			{
				node->left = new Node();
				node->left->data = data;
			}
			else
			{
				insert(node->left, data);
			}
		}
		else
		{
			if (node->right == NULL)
			{
				node->right = new Node();
				node->right->data = data;
			}
			else
			{
				insert(node->right, data);
			}
		}
	}

	void insert(int data)
	{
		if (root == NULL)
		{
			root = new Node();
			root->data = data;
		}
		else
		{
			insert(root, data);
		}
	}

	string ToString()
	{
		string text = "";

		queue<Node*> queue;

		if (root != NULL)
			queue.push(root);

		while (queue.size() > 0)
		{
			if (queue.front()->left != NULL)
			{
				queue.push(queue.front()->left);
			}
			if (queue.front()->right != NULL)
			{
				queue.push(queue.front()->right);
			}

			text += queue.front()->data;
			queue.pop();
		}

		return text;
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

	Node* find(Node* node, int data)
	{
		if (node == NULL)
			return NULL;
		else if(node->data==data)
		{
			return node;
		}
		else if (node->data > data)
		{
			return find(node->left, data);
		}
		else
		{
			return find(node->right, data);
		}
	}

	int nivel(Node* node, int data)
	{
		if (node == NULL)
			return 0;
		else if (node->data == data)
		{
			return nivel(NULL, data);
		}
		else if (node->data > data)
		{
			return 1 + nivel(node->left, data);
		}
		else {
			return 1 + nivel(node->right, data);
		}
	}

	int minim(Node* node)
	{
		if (node == NULL)
			return NULL;

		while (node->left != NULL)
			node = node->left;

		return node->data;
	}

	int maxim(Node* node)
	{
		if (node == NULL)
			return NULL;

		while (node->right != NULL)
			node = node->right;

		return node->data;
	}

	Node* succesor(Node* node)
	{
		Node* current = node->right;

		while (current != NULL && current->left != NULL)
		{
			current = current->left;
		}

		return current;
	}

	Node* remove(Node* node, int data)
	{
		if (node == NULL)
		{
			return NULL;
		}
		if (node->data > data)
		{
			node->left = remove(node->left, data);
		}
		else if (node->data < data)
		{
			node->right = remove(node->right, data);
		}
		else {
			if (node->left == NULL)
			{
				Node* tmp = node->right;
				node = NULL;
				return tmp;
			}
			if (node->right == NULL)
			{
				Node* tmp = node->left;
				node = NULL;
				return tmp;
			}

			Node* succ = succesor(node);
			node->data = succ->data;
			node->right = remove(node->right, succ->data);
		}
		return node;
	}
};