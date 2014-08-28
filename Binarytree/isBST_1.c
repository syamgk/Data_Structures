#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
/*1.build123() 
  a: by calling newNode() three times, and using three pointer variables
  b: by calling newNode() three times, and using only one pointer variable
  c: by calling insert() three times passing it the root pointer to build up the tree */
struct node* build123c(void);

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
/* For each node in a binary search tree, create a new duplicate node,
   and insert the duplicate as the left child of the original node. 
   The resulting tree should still be a binary search tree. */
void doubleTree(struct node* root)
{
	if( root == NULL)
		return;
	else {
		doubleTree(root->left);
		doubleTree(root->right);
		struct node* new = NewNode(root->data);
		new->left = root->left;
		root->left = new;
	}
}
/* Given two trees, return true if they are
   structurally identical. */
int sameTree(struct node* a, struct node* b)
{
	if( a == NULL&& b== NULL)
		return 1;
	else if(a->data == b->data)
		return (sameTree(a->left,b->left) && sameTree(a->right, b->right));
	else return 0;
}
/* For the key values 1...numKeys, how many structurally unique
   binary search trees are possible that store those keys.
   Strategy: consider that each value could be the root.
   Recursively find the size of the left and right subtrees. */
int countTrees(int numKeys)
{
	if (numKeys <= 1)
		return 1;
	else {
		int sum =0;
		int left, right, root;
		for(root=1; root<=numKeys; root++) {
			left = countTrees(root -1);
			right = countTrees(numKeys -root);
			sum += left*right;
		}
		return sum;
	}
}
/* Given a non-empty binary search tree(ordered)
   returns the minimum data value found on tree */
int minValue(struct node* root)
{
	if(root->left == 0)
		return root->data;
	else 
		return minValue(root->left);
}
/* Given a non-empty binary search tree(ordered)
   returns the maximum data value found on tree */
int maxValue(struct node* root)
{
	if(root->right == 0)
		return root->data;
	else 
		return maxValue(root->right);
}
/* Returns true if a binary tree is a binary search tree. */
int isBST(struct node* node) {
	if (node==NULL) return(true);
	// false if the min of the left is > than us
	if (node->left!=NULL && minValue(node->left) > node->data)
		return(false);
	// false if the max of the right is <= than us
	if (node->right!=NULL && maxValue(node->right) <= node->data)
		return(false);
	// false if, recursively, the left or right is not a BST
	if (!isBST(node->left) || !isBST(node->right))
		return(false);
	// passing all that, it's a BST
	return(true);
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
/* Change a tree so that the roles of the
left and right pointers are swapped at every node. */
void mirror(struct node* root)
{
	if(root->left == 0 && root->right == 0)
		return;
	else {
		struct node* temp = root->left;
		root->left = root->right;
		root->right = temp;
		mirror(root->left);
		mirror(root->right);
	}
}	
void print(int *path, int len)
{
	int i;
	printf("Path : ");
	for(i=0 ;i<=len; i++)
		printf("%d ",*(path+i));
	printf("\n");
}
/* print path if reached leaf node */
void printTrack( struct node* root, int *path, int len)
{
	*(path+len) = root->data;
	if (root->left == 0 && root->right == 0) {
		print(path, len);
		return;
	}
	else {
		len++;
		if ( root->left !=0)
			printTrack(root->left, path, len);
		if ( root->right != 0)
			printTrack(root->right, path, len);
	}
}
/* Given a binary tree, print out all of its root-to-leaf paths, one per line. */
void printPaths(struct node* root)
{
	int paths[1000];
	printTrack(root, paths, 0);
}
// a: by calling newNode() three times, and using three pointer variables
struct node* build12345()
{
	struct node* root = NewNode(4);
	struct node* left = NewNode(2);
	struct node* right = NewNode(5);
	root->left = left;
	root->right = right;
	root->left->left = NewNode(1);
	root->left->right = NewNode(3);
	return root; // <<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>
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
/* returns the number of nodes along the longest path 
   from root node down to farthest leaf node. */
  int maxDepth(struct node* root)
{
	if (root == 0)
		return 0;
	else {
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + (left > right ? left: right);
	}
}
/* Given a non-empty binary search tree(ordered)
   iterate over the nodes to print them in postorder */
void printPostorder(struct node* root)
{
	if(root->left == 0)
		printf("%d\n",root->data);
	else {
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d\n",root->data);
	}
}
/* Given a tree and a sum, return true if there is a path from the root
   down to a leaf, such that adding up all the values along the path
   equals the given sum. */
int hasPathSum(struct node* root, int sum)
{
	if(root == 0)
		return sum ==0;
	else {
		int newsum = sum - root->data;
		return (hasPathSum(root->left,newsum) || hasPathSum(root->right,newsum));
	}
}
/* Compute the number of nodes in a tree. */
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
	struct node* r1 = build12345();
	root =  build12345();
	printf("no of nodes %d\n",size(root));
	printf(">>%d<<\n",isBST(root));
	return 0;
}

