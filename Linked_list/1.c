int count(struct node* head,int searchFor ) {
	struct node* p = head;
	int count = 0;
	while (p!= NULL){
		count++;
		p=p->pointer;
	}
	return count;
}

		
