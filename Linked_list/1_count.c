#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
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
}

