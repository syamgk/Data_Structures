struct node *append(struct node *h, struct node *n)
{
 if(h==0) return n;
 if(h->data < n->data)
	h->left = append(h->left , n);
 else
	h->right = append( h->right,n);
 return h;
}
