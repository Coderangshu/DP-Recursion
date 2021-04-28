#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int e){
	if(s.size()==0 or s.top()<e) s.push(e);
	else{
		int temp = s.top();
		s.pop();
		insert(s,e);
		insert(s,temp);
	}
}

void sort(stack<int> &s){
	if(s.size()==1) return;
	else{
		int temp = s.top();
		s.pop();
		sort(s);
		insert(s,temp);
	}
}

int main(){
	stack<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		s.push(e);
	}
	sort(s);
	while(s.size()!=0){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
