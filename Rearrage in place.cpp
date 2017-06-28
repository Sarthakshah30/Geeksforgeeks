#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node{
	int data;
	struct node *next;
};


void push(struct node **head,int data){
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(*head!=NULL){
		temp->next=(*head);
	}
	*head=temp;
}

void reverse(struct node **head){
	struct node *prev;
	struct node *curr;
	struct node *next;
	curr=(*head);
	prev=next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	(*head)=prev;
}

void rearrange(struct node **head){
	struct node *fast = (*head);
	struct node *slow = (*head);
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	struct node *second = slow->next;
	struct node *first = (*head);
	slow->next=NULL;
	
	reverse(&second);
	while(second!=NULL){
		struct node *next = first->next;
		first->next=second;
		second=second->next;
		first->next->next=next;
		first=first->next->next;
	}
}

void print(struct node *head){
	cout<<"Elements are : ";
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	struct node *head=NULL;
	srand(time(NULL));
	for(int i = 0 ; i<8 ; i++){
		push(&head,rand()%20);
	}
	print(head);
	rearrange(&head);
	print(head);
}
