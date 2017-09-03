#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
} *root = NULL;

Node *createNode(int key) {
	Node *t = (Node *)malloc(sizeof(Node));
	t->data = key;
	t->left = NULL;
	t->right = NULL;
	return t;
}

//----------- TREE PRINTING -----------//
// all are O(n) functions.

void preOrder(Node *r) {
	if (r != NULL) {
		cout << r->data << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void postOrder(Node *r) {
	if (r != NULL) {
		postOrder(r->left);
		postOrder(r->right);
		cout << r->data << " ";
	}
}

void inOrder(Node *r) {
	if (r != NULL) {
		inOrder(r->left);
		cout << r->data << " ";
		inOrder(r->right);
	}
}

//--------------------------------------//

//---------- TREE INSERTION ------------//

//iterative insert
void insertNode(Node *z) {
	Node *trav = root;
	Node *p = NULL;
	while (trav != NULL) {
		p = trav;
		if (z->data < trav->data)
			trav = trav->left;
		else
			trav = trav->right;
	}
	if (z->data < p->data)
		p->left = z;
	else
		p->right = z;
}

//recursive insert
Node *insertNode(Node *val, Node *r) {
	if (r == NULL)
		return val;
	else if (val->data < r->data)
		r->left = insertNode(val, r->left);
	else
		r->right = insertNode(val, r->right);
	return r;
}

//-------------------------------------//

int height_recur(Node *r) {
	if (r == NULL)
		return 0;
	int lheight = height_recur(r->left);
	int rheight = height_recur(r->right);
	return (lheight > rheight ? lheight + 1 : rheight + 1);
}

int height_iter(Node *r) {
	if (r == NULL)
		return 0;
	queue<Node *> q;
	q.push(r);
	int h = 0;
	while (true) {
		int count = q.size();
		if (count == 0)
			return h;
		h++;
		while (count > 0) {
			Node *n = q.front();
			q.pop();
			if (n->left != NULL)
				q.push(n->left);
			if (n->right != NULL)
				q.push(n->right);
			count--;
		}
	}
}

void calcRight(Node *r) {
	cout << r->data << " ";
	if (r->right != NULL)
		calcRight(r->right);
}

void calcLeft(Node *r) {
	if (r->left != NULL)
		calcLeft(r->left);
	cout << r->data << " ";
}

void topView(Node *r) {
	if (r->left != NULL)
		calcLeft(r->left);
	cout << r->data << " ";
	if (r->right != NULL)
		calcRight(r->right);
}

void levelOrder(Node *r) {
	queue<Node *> q;
	q.push(r);
	while (true) {
		int count = q.size();
		if (count == 0)
			break;
		while (count > 0) {
			Node *n = q.front();
			q.pop();
			cout << n->data << " ";
			if (n->left != NULL)
				q.push(n->left);
			if (n->right != NULL)
				q.push(n->right);
			count--;
		}
	}
}

int main() {
	int x = 1;
	cout << "Enter values for the tree (-1 to end) :- " << endl;
	while (x >= 0) {
		cin >> x;
		if (x == -1)
			break;
		if (root == NULL)
			root = createNode(x);
		else
			insertNode(createNode(x));
	}
	levelOrder(root);
	cout << endl;	
	return 0;
}