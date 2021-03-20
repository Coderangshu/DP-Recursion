// Problem Statement: Given two arrays one containing length of rod other containing
// price of rod according to each length. Also we have been  given a rod with a particular
// length, we need to cut the rod into smaller pieces in such a way that the resultant 
// sum of their prices is maximum.

#include<bits/stdc++.h>
using namespace std;

int topDown(int N, int val[]){
    int dp[N+1][N+1];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            if(i==0 or N==0) dp[i][j] = 0;
            else if(i>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(val[i-1]+dp[i][j-i],dp[i-1][j]);
            // cout<<dp[i][j]<<'\t';
        }
        // cout<<endl;
    }
    return dp[N][N];
}

int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int val[n];
    	for(int i=0;i<n;i++) cin>>val[i];
    	cout<<topDown(n,val);
    }
	return 0;
}
