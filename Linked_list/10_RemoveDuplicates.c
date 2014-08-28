#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node {
	int data;
	struct node* next;
};
void testfun(void);
void SortedInsert(struct node** headRef, struct node* newNode);
void Push(struct node** headRef, int data);
/*	Remove duplicates from a sorted list. */
void RemoveDuplicates(struct node* head) {
	struct node* current = head;
	if (current == NULL) return;
	while(current->next != NULL) {
		if(current->data == current->next->data) {
			struct node* newNext = current->next;
			current->next = current->next->next;
		}
		else 
			current = current->next;
	}
}
/*	Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list. */
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) 
{
	assert( source != NULL);
	struct node* slow = source;
	struct node* fast = source->next;
	while( fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
//  Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append( struct node** aRef, struct node** bRef)
{
	struct node dummy;
	struct node *current = &dummy;
	dummy.next = *aRef;
	while(current->next != NULL)
		current = current->next;
	current->next = *bRef;
	*bRef = NULL;
	*aRef = dummy.next;
}
// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort( struct node** headRef)
{
	struct node* current = *headRef;
	struct node* result = NULL;
	struct node* next;
	
	while(current != NULL) {
		next = current->next;
		SortedInsert(&result, current);
		current = next;
	}
	*headRef = result;
}

//
void SortedInsert(struct node** headRef, struct node* newNode) 
{
	struct node dummy;
	struct node *current = &dummy;
	dummy.next = *headRef;
	while(current->next != NULL && newNode->data > current->next->data ) 
		current = current->next;
	newNode->next = current->next;
	current->next = newNode;
	*headRef = dummy.next;
}
/* A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index. */
void InsertNth(struct node** headRef, int index, int data)
{
	if(index == 0) 
		Push(headRef, data);
	else {
		int i=0;
		struct node *current = *headRef;
		while(i < index-1) { // tracing the previous node of required node
			assert(current != NULL);
			current = current->next;
			i++;
		}
		assert(current != NULL);
		Push(&(current->next), data); // need to modify the pointer on linked list 
										// not the local variable "current"
	}
}
/* The opposite of Push(). Takes a non-empty list
and removes the front node, and returns the data
which was in that node. */
int pop(struct node** head)
{
	struct node* previous = *head;
	assert(*head != NULL);
	int node_data = (*head)->data;	// copying data before deleting
	*head = (*head)->next; // moving curser to next node
	free(previous); // free the head node
	return node_data;
}
//Deallocates all of its memory and sets its
//head pointer to NULL
void DeleteList(struct node** headRef)
{
	struct node* current = *headRef;
	struct node* next;
	while( current != NULL) {
		next = current->next;
		free(current);
		current = next;
	} 
	printf("List was deleted !!!!\n");
}
// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head,int index)
{
	struct node* current;
	int i=0;
	for(current = head;  current != NULL; i++,current = current->next)
		if(i==index) break;
	assert(current);
	return current->data;
}
/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int count(struct node* head,int searchFor)
{
	int count = 0;
	struct node* current = head;
	while(current != NULL){
		if(current->data == searchFor)
			count++;
		current = current->next;
	}
	return count;
}
//puts data at begining
void Push(struct node** headRef, int data) 
{
	struct node* newNode =(struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}


struct node* build123()
{
	struct node* head;
	head = malloc(sizeof(struct node));
	head->data = 1;
	head->next = malloc(sizeof(struct node));
	head->next->data = 2;
	head->next->next = malloc(sizeof(struct node));
	head->next->next->data = 3;
	head->next->next->next = NULL;
	return head;
}
void printdata(struct node* head)
{
	printf("{");
	while(head != NULL) {
		printf("%d",head->data);
		head = head->next;
		if(head != NULL)
			printf(",");
			
	}
	printf("}\n");
}

int main()
{
	testfun();
	return 1;
}
void testfun()
{
	struct node* a = build123();
//	Push(&a,2);
	Push(&a,1);
	Push(&a,3);
	InsertSort(&a);
	printdata(a); // before
	RemoveDuplicates(a);
	printdata(a); //after
}
