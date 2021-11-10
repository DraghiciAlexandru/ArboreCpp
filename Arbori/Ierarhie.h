#include <iostream>
#include "TreeNode.h"
#include <algorithm>
#include <queue>

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

	int height(Node* node)
	{
		if (node == NULL)
			return -1;
		return 1 + max(height(node->left), height(node->right));
	}

	bool simetric(Node* node1, Node* node2)
	{
		queue<Node*> queue1;
		queue<Node*> queue2;

		if (node1 != NULL)
			queue1.push(node1);
		if (node2 != NULL)
			queue2.push(node2);

		while (queue1.size() > 0 && queue2.size() > 0)
		{
			if (queue1.front()->left != NULL && queue2.front()->right != NULL)
			{
				queue1.push(queue1.front()->left);
				queue2.push(queue2.front()->right);
			}
			else if ((queue1.front()->left != NULL && queue2.front()->right == NULL)||(queue1.front()->left == NULL && queue2.front()->right != NULL))
				return false;

			if (queue1.front()->right != NULL && queue2.front()->left != NULL)
			{
				queue1.push(queue1.front()->right);
				queue2.push(queue2.front()->left);
			}
			else if ((queue1.front()->right != NULL && queue2.front()->left == NULL) || (queue1.front()->right == NULL && queue2.front()->left != NULL))
				return false;

			queue1.pop();
			queue2.pop();
		}

		if (queue1.size() == 0 && queue2.size() == 0)
			return true;
		return false;
	}
};