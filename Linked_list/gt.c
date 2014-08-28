#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
	int data;
	struct node* next;
};
// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).

int GetNth(struct node* head, int index) {
	struct node* current = head;
	int count = 0; // the index of the node we're currently looking at
	while (current != NULL) {
		if (count == index) return(current->data);
		count++;
		current = current->next;
	}
	assert(0);
}
// if we get to this line, the caller was asking
// for a non-existent element so we assert fail.

/*int GetNth(struct node* head,int index)
{
	struct node* current;
	int i=0;
	for(current = head;  current != NULL; i++,current = current->next)
		if(i==index) break;
	assert(current);
	return current->data;
}*/
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

main()
{
	struct node* head = build123();
	printdata(head);
	printf("1 occur %d times\n",count(head,1));
	printf("3 occur %d times\n",count(head,3));
	printf("10 occur %d times\n",count(head,10));
	printf("0th element is %d \n",GetNth(head,0));
	printf("12nd element is %d \n",GetNth(head,12));
}

