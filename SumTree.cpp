#include<iostream>
#include<cstring>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

bool sameSum(struct node *root, int &sum){
	if(root==NULL){
		sum=0;
		return true;
	}
	
	int ls = 0;
	int rs = 0;
	
	bool res1 = sameSum(root->left,ls);
	bool res2 = sameSum(root->right,rs);
	
	sum=root->data+ls+rs;
	
	if(root->left==NULL && root->right==NULL)
	return true;
	
	if(root->data == ls+rs && res1 && res2)
	return true;
	else
	return false;
}

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
	int sum=0;
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(7);
    root->right->right = newNode(3);
    if(sameSum(root,sum))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
 
    getchar();
    return 0;
}
