#include <iostream>
#include<cstdlib>
using namespace std;

//declaring definition of node
typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
}Node;

Node* root; //root of binary search tree

Node* Search(Node* root, int value)               //search a value in bst
{
	Node* p = root;
	while (p != NULL && p->key != value)
	{
		if(value < p->key)
		p = p->left;
		else
		p = p->right;	
	}
	return p;
}

Node* Tree_Min(Node* t)                          //finding minimum function
{
	Node* p = t;
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
}

Node* Tree_Max(Node* t)                          //finding maximum function
{
	Node* p = t;
	while (p->right != NULL)
	{
		p = p->right;
	}
	return p;
}

Node* Successor(Node * t)                       //finding successor of node
{
	Node* p = t;
	if (p->right != NULL)
		return Tree_Min(p->right);
	Node* y = p->parent;
	while (y != NULL && p == y->right)
	{
		p = y;
		y = y->parent;
	}
	return y;
}
Node* Insert(Node* root, int value)              //inserting node
{
	Node* z = (Node*)malloc(sizeof(Node));
	

	z->key = value;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	
	Node* y = NULL;
	Node* x = root;
	
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		root = z;                        // when tree is empty
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
		
	return root;
}

void Transplant(Node* root, Node* u, Node* v)          //transplanting  subtrees
{
	if (u->parent == NULL)
		root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
		
	if (v != NULL)
		v->parent = u->parent;
}

void Tree_Delete(Node* root, int value)                   //deleting a node
{
	Node* z = Search(root,value);
	if (z == NULL)
	{
		cout<<"Value is not present in Binary Search Tree"<<endl;
		return;
	}
	if(z->left == NULL)
		Transplant(root, z, z->right);
	else if(z->right == NULL)
		Transplant(root, z, z->left);
	else
	{
		Node* y = Successor(z->right);
		if (y != z->right)
		{
			Transplant(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	delete z;
}

void Inorder(Node* root)                             //Inorder tree walk
{
	Node* p = root;
	if(p != NULL)
	{
		Inorder(p->left);
		cout<<p->key<<" ";
		Inorder(p->right);
	}
}
int main()
{
	int value, n;
	Node* tmp;
	root = NULL;
	cout<<"Enter the number of values you want to enter in Binary Search Tree"<<endl;
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cin>>value;
		root = Insert(root,value);
	}
	cout<<"Search the value"<<endl;
	cin>>value;
	tmp = Search(root, value);
	if(tmp == NULL)
		cout<<"NOT FOUND"<<endl;
	else
		cout<<"FOUND"<<endl;
		
	tmp = Tree_Min(root);
	cout<<tmp->key<<endl;
	
	tmp = Tree_Max(root);
	cout<<tmp->key<<endl;
	
	Inorder(root);
	
	cout<<"Enter the value you want to delete"<<endl;
	cin>>value;
	Tree_Delete(root,value);
	
	Inorder(root);
}




