#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

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
}

