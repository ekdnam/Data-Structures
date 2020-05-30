#include <iostream>
using namespace std;
/*
operations to be performed:
1) search
2) minimum
3) maximum
4) predecessor
5) sucessor
6) insert
7) delete
*/

/*
most operations performed in O(lg n) time
*/

class BST;
/*
The Node class has the fields:
1) val
2) left
3) right
*/
class Node {
	friend class BST;
	int key;
	Node *right;
	Node *left;
	Node *parent;
public:
	Node() {
		key = -999;
		right = NULL;
		left = NULL;
	}
	Node(int x) {
		key = x;
		right = NULL;
		left = NULL;
	}
};
class BST {
	Node *root;
public:
	BST() {
		root = NULL;
	}
	void inorder_tree_walk(Node*);
	void postorder_tree_walk(Node*);
	void preorder_tree_walk(Node*);
	void call_inorder();
	void call_postorder();
	void call_preorder();
	Node* search(Node* x, int k);
	void call_search();
	Node* iterative_search(Node *x, int key);
	void call_max();
	void call_min();
	Node* tree_minimum(Node *x);
	Node* tree_maximum(Node *x);
	void tree_insert(Node *z);
	void call_insert();
	void call_iterative_search();
};

void BST::tree_insert(Node *z) {
	Node *y = NULL;
	Node *x = root;
	while (x) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL) {
		root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}

void BST::call_insert() {
	int x;
	cout << "Value to be inserted: ";
	cin >> x;
	Node *z = new Node(x);
	tree_insert(z);

}

Node* BST::tree_maximum(Node *x) {
	while (x->left) {
		x = x->left;
	}
	return x;
}

Node* BST::tree_minimum(Node *x) {
	while (x->right) {
		x = x->right;
	}
	return x;
}

void BST::call_max() {
	cout << "\nThe max value in the BST is: " << tree_maximum(root)->key;
	cout << endl;
}

void BST::call_min() {
	cout << "\nThe min value in the BST is: " << tree_minimum(root)->key;
	cout << endl;
}

Node* BST::iterative_search(Node *x, int key) {
	while (x != NULL && key != x->key) {
		if (key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

Node* BST::search(Node *x, int key) {
	if (x == NULL || key == x->key) {
		return x;
	}
	if (key < x->key) {
		return search(x->left, key);
	}
	else {
		return search(x->right, key);
	}
}

void BST::call_search() {
	cout << "Value to be searched: ";
	int x;
	cin >> x;
	Node *res = search(root, x);
	if (res == NULL) {
		cout << "\nValue not found." << endl;
	}
	else {
		cout << "\nValue found." << endl;
	}
}

void BST::call_iterative_search() {
	cout << "Value to be searched: ";
	int x;
	cin >> x;
	Node *res = iterative_search(root, x);
	if (res == NULL) {
		cout << "\nValue not found." << endl;
	}
	else {
		cout << "\nValue found." << endl;
	}
}

void BST::inorder_tree_walk(Node *x) {
	if (x) {
		inorder_tree_walk(x->left);
		cout << x->key << " ";
		inorder_tree_walk(x->right);
	}
}

void BST::preorder_tree_walk(Node *x) {
	if (x) {
		cout << x->key << " ";
		inorder_tree_walk(x->left);
		inorder_tree_walk(x->right);
	}
}

void BST::postorder_tree_walk(Node *x) {
	if (x) {
		inorder_tree_walk(x->left);
		inorder_tree_walk(x->right);
		cout << x->key << " ";
	}
}

void BST::call_inorder() {
	cout << "Inorder traversal of the tree is: " << endl;
	inorder_tree_walk(root);
 }

void BST::call_postorder() {
	cout << "Postorder traversal of the tree is: " << endl;
	postorder_tree_walk(root);
}

void BST::call_preorder() {
	cout << "Preoder traversal of the tree is: " << endl;
	preorder_tree_walk(root);
}

int main()
{
	BST tree;
	int op = 1;
	while (op != 9) {
		cout << "To insert value: 1\n";
		cout << "To search value (recursively): 2\n";
		cout << "To search value (non recursively): 3\n";
		cout << "For preorder traversal: 4\n";
		cout << "For inorder traversal: 5\n";
		cout << "For postorder traversal: 6\n";
		cout << "For maximum value: 7\n";
		cout << "For minimum value: 8\n";
		cout << "To exit: 9\n";
		cout << "Your choice? :";
		cin >> op;

		cout << "\n\n\n";
		switch (op) {
		case 1:
			tree.call_insert();
			cout << endl; cout << endl;
			break;
		case 2: 
			tree.call_search();
			cout << endl; cout << endl;
			break;
		case 3:
			tree.call_iterative_search();
			cout << endl; cout << endl;
			break;
		case 4:
			tree.call_preorder();
			cout << endl; cout << endl;
			break;
		case 5:
			tree.call_inorder();
			cout << endl; cout << endl;
			break;
		case 6:
			tree.call_postorder();
			cout << endl; cout << endl;
			break;
		case 7:
			tree.call_max();
			cout << endl; cout << endl;
			break;
		case 8: 
			tree.call_min();
			cout << endl; cout << endl;
			break;
		case 9:
			break;
		default:
			cout << "Please enter valid value..." << endl;
		}
	}
}
