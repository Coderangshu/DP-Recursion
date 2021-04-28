// Question link
// https://www.hackerrank.com/challenges/sam-and-substrings/problem

#include <bits/stdc++.h>
#define llint long long int
#define MOD 1000000007
using namespace std;

llint memo[200001];

llint recursion(string s,llint ans){
	llint n = stoi(s);
	if(memo[n]!=-1) return 0;
	if(s.length()==1){
		memo[n] = n;
		return (ans+n)%MOD;
	}
	else{
	    memo[n] = n;
		return (ans+n+recursion(s.substr(0,s.length()-1),ans)+recursion(s.substr(1,s.length()),ans)%MOD);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	memset(memo,-1,sizeof(memo));
    llint ans = recursion(s,0);
	cout<<ans<<endl;
	return 0;
}
