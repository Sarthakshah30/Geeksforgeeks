#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node{
	int data;
	struct node *next;
};



void push(struct node **head,int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=(*head);
	(*head)=temp;
}

void print(struct node *head){
	cout<<"Elements are :- ";
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *add(struct node *head1, struct node *head2,int carry){
	if(head1==NULL && head2==NULL && carry==0)
	return NULL;
	
	struct node *result  = (struct node *)malloc(sizeof(struct node));
	int temp=carry;
	if(head1!=NULL){
		temp+=head1->data;
		head1=head1->next;	
	}
	if(head2!=NULL){
		temp+=head2->data;
		head2=head2->next;
	}
	result->data=temp%10;
	carry=temp/10;
	result->next=add(head1,head2,carry);
	return result;
}

int main(){
	struct node *head1=NULL;
	struct node *head2=NULL;
	srand(time(NULL));
	for(int i = 0 ; i<4 ; i++){
		push(&head1,rand()%10);
	}
	print(head1);
	for(int i = 0 ; i<6 ; i++){
		push(&head2,rand()%10);
	}
	print(head2);
	struct node *result = add(head1,head2,0);
	print(result);
}
