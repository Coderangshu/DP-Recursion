#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int e){
	if(v.size()==0 or e>v[v.size()-1]) v.push_back(e);
	else{
		int temp = v[v.size()-1];
		v.pop_back();
		insert(v,e);
		insert(v,temp);
	}
}

void sort(vector<int> &v){
	if(v.size()==1) return;
	else{
		int temp = v[v.size()-1];
		v.pop_back();
		sort(v);
		insert(v,temp);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		v.push_back(e);
	}
	sort(v);
	for(auto e:v) cout<<e<<" ";
	return 0;
}
