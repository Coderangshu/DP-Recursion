#include <bits/stdc++.h>
using namespace std;

void prntRec(int n){
	if(n==1) cout<<1<<" ";
	else{
		prntRec(n-1);
		cout<<n<<" ";
	}
}

int main(){
	int n;
	cin>>n;
	prntRec(n);
	return 0;
}
