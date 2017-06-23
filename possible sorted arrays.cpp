#include<iostream>
#include<cstring>

using namespace std;

int A[100],B[100],m,n,C[202];
void print(int length);
void generate(int i,int j,int len,bool turn);

int main(){
	cin>>m;
	for(int i = 0 ; i<m ; i++)
	cin>>A[i];
	cin>>n;
	for(int i = 0 ; i<n ; i++)
	cin>>B[i];
	generate(0,0,0,true);
}

void generate(int i,int j,int len,bool turn){
	if(turn){
		
		if(len>0){
			print(len);
		}
		
		for(int k = i ; k<m ; k++){
			
			if(len==0){
				C[len]=A[k];
				generate(k+1,j,len+1,false);
			
			}
			else{
				if(A[k]>C[len-1]){
					C[len]=A[k];
					generate(k+1,j,len+1,false);
				}
			}
		}
	}
	else{
		for(int p = j ; p<n ; p++){
			if(B[p]>C[len-1]){
				C[len]=B[p];
				generate(i,p+1,len+1,true);
			}
		}
	}
}

void print(int length){
	for(int i = 0 ; i< length ; i++){
		cout<<C[i]<<" ";
	}
	cout<<endl;
}
