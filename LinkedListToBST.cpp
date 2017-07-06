
int countNode(struct node *head){
	struct node *ptr=head;
	int count=0;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	return count;
}

struct bstNode* convertToBST(struct node *head){
	int n = countNode(head);
	struct bstNode * root = convertToBSTUtil(&head,n);
	return root;
}

struct bstNode * convertToBSTUtil(struct node **head,int n){
	
	if(n<=0)
	return 0;
	
	struct bstNode * root = (struct bstNode *)malloc(sizeof(struct bstNote));
	
	root->left = convertToBSTUtil(head,n/2);
	
	root->data = (*head->data);
	
	(*head)=(*head)->next;
	
	root->right = convertToBSTUtil(head,n-n/2-1);
	
	return root;
}
