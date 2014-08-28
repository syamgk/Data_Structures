#include<stdio.h>
#include<stdlib.h>

/*1.build123() 
  a: by calling newNode() three times, and using three pointer variables
  b: by calling newNode() three times, and using only one pointer variable
  c: by calling insert() three times passing it the root pointer to build up the tree */

struct node {
	int data;
	struct node* left;
	struct node* right;
};
/*	Helper function that allocates a new node
	with the given data and NULL left and right
	pointers. */
struct node* NewNode(int data) 
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
/* Give a binary search tree and a number, inserts a new node
   with the given number in the correct place in the tree.
   Returns the new root pointer which the caller should
   then use (the standard trick to avoid using reference
   parameters). */
struct node* insert(struct node* node, int data) 
{
	// 1. If the tree is empty, return a new, single node
	if (node == NULL) {
		return(NewNode(data));
	}
	else {
	// 2. Otherwise, recur down the tree
		if (data <= node->data) node->left = insert(node->left, data);
		else node->right = insert(node->right, data);
		return(node); // return the (unchanged) node pointer
	}
}
// a: by calling newNode() three times, and using three pointer variables
struct node* build123a()
{
	struct node* root = NewNode(2);
	struct node* left = NewNode(1);
	struct node* right = NewNode(3);
	root->left = left;
	root->right = right;
	return root; // <<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>
}
// b: by calling newNode() three times, and using only one pointer variable
struct node* build123b()
{
	struct node* root = NewNode(2);
	root->left = NewNode(1);
	root->right = NewNode(3);
	return root;
}
// c: by calling insert() three times passing it the root pointer to build up the tree 
struct node* build123c()
{
	struct node* root = NULL ;
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,3);
	return root;
}

int size(struct node* root)
{
	if(root == NULL)
		return 0;
	else 
		return ( 1+ size(root->left)+ size(root->right));
}
int main()
{
	struct node* root = NULL;
	root =  build123a();
	printf("no of nodes %d\n",size(root));
	return 0;
}

