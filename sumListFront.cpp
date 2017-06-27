#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct wrapper{
	struct node *ptr;
	int carry;
	
	wrapper() : ptr(NULL), carry(0) { }
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

struct wrapper *add(struct node *head1,struct node *head2){
	
	struct wrapper *result = (struct wrapper *)malloc(sizeof(struct wrapper));
	
	if(head1== NULL){
		return result;
	}
	
	result = add(head1->next,head2->next);
	
	int val = result->carry + head1->data + head2->data;
	
	push(&(result->ptr),val%10);
	
	result->carry = val/10;
	
	return result; 
}




struct node *addUtil(struct node **head1,int len1,struct node **head2,int len2){
	
	if(len1!=len2){
		if(len1<len2)
		while(len1<len2){
			push(head1,0);
			len1++;
		}
		else{
			while(len2<len1){
				push(head2,0);
				len2++;
			}
		}		
	}
	
	struct wrapper * result = add(*head1,*head2);
	if(result->carry==0){
		return result->ptr;
	}else{
		push(&(result->ptr),result->carry);
		return result->ptr;
	}
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
	
	struct node *result=addUtil(&head1,4,&head2,6);
	print(result);
}


