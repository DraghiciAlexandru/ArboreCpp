#include <iostream>
//#include "Ierarhie.h"
#include "BST.h"

using namespace std;

int main()
{
	BST bst;

	bst.root = new Node();

	bst.root->data = 8;

	bst.insert(3);
	bst.insert(10);
	bst.insert(1);
	bst.insert(6);
	bst.preorder(bst.root);
}