#include <bits/stdc++.h>
using namespace std;

void prntRec(int n){
	if(n==1) cout<<1<<" ";
	else{
		cout<<n<<" ";
		prntRec(n-1);
	}
}

int main(){
	int n;
	cin>>n;
	prntRec(n);
	return 0;
}
