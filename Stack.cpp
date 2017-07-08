#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

void bottomInsert(stack<int> &st,int curr){
	if(st.empty()){
		st.push(curr);
		return;
	}
	int temp = st.top();
	st.pop();
	bottomInsert(st,curr);
	st.push(temp);
}

void reverse(stack<int> &st){
	if(st.empty())
	return;
	int cur= st.top();
	st.pop();
	reverse(st);
	bottomInsert(st,cur);
}

int main(){
	stack<int> st;
	for(int i = 1 ; i<=10; i++){
		st.push(i);
	}
	for(int i = 1 ; i<= 10; i++){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	for(int i = 1 ; i<=10 ; i++){
		st.push(i);
	}
	reverse(st);
	for(int i = 1 ; i<= 10; i++){
		cout<<st.top()<<" ";
		st.pop();
	}
}

