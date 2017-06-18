#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

struct psum{
	int a,b,sum;
}; 

bool comp(struct psum p1,struct psum p2){
	return p1.sum < p2.sum;
}

int main(){
	int array[50],n,size,k=0,i=0,j=0,X;
	cin>>n>>X;
	for(int i = 0 ; i < n ; i++)
	cin>>array[i];
	size = (n*(n-1))/2;
	struct psum aux[size];
	for(i = 0 ; i< n ; i++){
		for(j = i+1 ; j< n ; j++){
			aux[k].a=i;
			aux[k].b=j;
			aux[k].sum=(array[i]+array[j]);
			k++;
		}
	}
	i=0;
	j=size-1;
	sort(aux,aux+size,comp);
	while(i<size && j>=0){
		if(aux[i].sum+aux[j].sum==X && !(aux[i].a==aux[j].a || aux[i].a==aux[j].b || aux[i].b==aux[j].a ||aux[i].b==aux[j].b)){
			cout<<aux[i].a<<" "<<aux[i].b<<" "<<aux[j].a<<" "<<aux[j].b<<endl;
			i++;
			j--;
		}
		else if(aux[i].sum +aux[j].sum > X)
		j--;
		else
		i++;
	}
}
