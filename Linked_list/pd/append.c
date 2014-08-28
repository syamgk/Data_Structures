struct node *
struct node *append(struct node *h, struct node *n)
{
	if(h == 0) return n;

	h->next = append(h->next,n);

	return h;
}
