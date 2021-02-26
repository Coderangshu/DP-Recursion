// Problem Statement: Given an array denomination of coins available.
// Also given the required amount to be formed from the given coins.
// The coins of each denominations are present in infinite quantity.
// Find the number of ways to attain the given value from the given
// array of denominations of coins.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  
    long long topDown(int S[], int m, int n){
        long long dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(S[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
                // cout<<dp[i][j]<<'\t';
            }
            // cout<<endl;
        }
        return dp[m][n];
    }
  
    long long int count( int S[], int m, int n )
    {
        //code here.
        return topDown(S,m,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
    
}
