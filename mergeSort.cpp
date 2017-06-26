#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};


void push(struct node **head, int data){
	
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	temp->data=data;
	
	temp->next=(*head);
	
	*head=temp;
	
}

void print(struct node *head){
	
	cout<<"The elements of the linked list"<<endl;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void split(struct node *head, struct node **a, struct node **b){
	struct node *slow=head;
	struct node *fast=head->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	(*a)=head;
	(*b)=slow->next;
	slow->next=NULL;
}

struct node *merge(struct node *a, struct node *b){
	
	struct node *res=NULL;
	
	if(!a)
	return b;
	if(!b)
	return a;
	
	if(a->data <= b->data){
		res=a;
		res->next=merge(a->next,b);
	}
	else{
		res=b;
		res->next=merge(a,b->next);
	}
	
	return res;
}

void mergeSort(struct node **headRef){
	
	struct node *head = (*headRef);
	struct node *a=NULL;
	struct node *b=NULL;
	
	if(head==NULL || head->next==NULL)
	return;
	
	split(head,&a,&b);
	
	mergeSort(&a);
	mergeSort(&b);
	
	(*headRef)=merge(a,b);
	
}

int main(){
	
	struct node *head=NULL;
	
	push(&head, 15);
    push(&head, 10);
	push(&head, 5); 
	push(&head, 20);
	push(&head, 3);
	push(&head, 2);
	
	print(head);
	
	mergeSort(&head);
	
	print(head);
		
}


