#include <iostream>
#include "Ierarhie.h"

using namespace std;

int main()
{
	Ierarhie ierarhie;

	ierarhie.root = new Node();

	ierarhie.root->data = 8;

	ierarhie.insert(8, 3);

	cout << ierarhie.root->data << endl;
	cout << ierarhie.root->left->data;

}