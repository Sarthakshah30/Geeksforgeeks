#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};

int getIntersectionPoint(struct node *head1,struct node *head2,int d);

int main(){
	struct node *head1,*head2;
	head1=head2=NULL;
	
	head1=(struct node *)malloc(sizeof(struct node));
	head1->data=3;
	
	head1->next=(struct node *)malloc(sizeof(struct node));
	head1->next->data=6;
	
	head1->next->next=(struct node *)malloc(sizeof(struct node));
	head1->next->next->data=9;
	
	head1->next->next->next=(struct node *)malloc(sizeof(struct node));
	head1->next->next->next->data=15;
	
	head1->next->next->next->next=(struct node *)malloc(sizeof(struct node));
	head1->next->next->next->next->data=30;	
	head1->next->next->next->next->next=NULL;		
	
	head2=(struct node *)malloc(sizeof(struct node));
	head2->data=10;
	
	head2->next=head1->next->next->next;
	
	cout<<"Linked List 1 and 2 meet at "<<getIntersectionPoint(head1,head2,2)<<endl;
}

int getIntersectionPoint(struct node *head1,struct node *head2,int d){
	
	for(int i = 0 ;i<d ; i++){
		if(head1==NULL)
		return -1;
		head1=head1->next;
	}
	
	while(head1 && head2){
		if(head1==head2)
		return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
	
	return -1;
}
