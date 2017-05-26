#include<bits/stdc++.h>

using namespace std;

int *array1;
int *array2;
int n;

int findMedian(int start1,int end1,int start2,int end2);

int main(){
	cout<<"Enter the number of elements of the array"<<endl;
	cin>>n;
	array1 = new int[n];
	array2 = new int[n];
	cout<<"Enter the elements of the array1 one by one"<<endl;
	for(int i = 0 ; i < n ; i++)
	cin>>array1[i];
	cout<<"Enter the elements of the array2 one by one"<<endl;
	for(int i = 0 ; i< n ; i++)
	cin>>array2[i];
	sort(array1,array1+n);
	sort(array2,array2+n);
	cout<<findMedian(0,n-1,0,n-1)<<endl;
}

int findMedian(int start1,int end1,int start2,int end2){
	
	if(start1==end1)
	return (array1[start1]+array2[start2])/2;
	if(start1+1==end1)
	return (max(array1[start1],array2[start2])+min(array1[end1],array2[end2]))/2;
	
	int m1 = (end1-start1+1)%2==0 ? (array1[(end1+start1)/2]+array1[(end1+start1+1)/2])/2 : array1[(end1+start1)/2]/2;
	int m2 = (end2-start2+1)%2==0 ? (array2[(end2+start2)/2]+array2[(end2+start2+1)/2])/2 : array2[(end2+start2)/2]/2;
		
	if(m1==m2)
	return m1;
	
	if(m1 > m2){
		if((end1-start1+1)%2==0)
		return findMedian(start1,(end1+start1+1)/2,(end2+start2)/2,end2);
		return findMedian(start1,(end1+start1)/2,(end2+start2)/2,end2);
	}
	
	if((end1-start1+1)%2==0)
	return findMedian((end1+start1)/2,end1,start2,(end2+start2+1)/2);
	return findMedian((end1+start1)/2,end1,start2,(end2+start2)/2);
	
}
