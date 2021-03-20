// Problem Statement: Given array of coin denominations each of
// them are available infinte in number, also given a sum to make
// using the coins of the given denominations. Find the minimum
// number of coins to get the sum.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int recursion(int coins[], int M, int V){
	    if(M==0) return INT_MAX-1;
	    // here INT_MAX-1 is used s.t. after addition of 1 to it,
	    // it still remains in the limit of int. If not subtracted
	    // after adding it would exceed int limit and become negative
	    // thus producing faulty results.
	    if(V==0) return 0;
	    if(coins[M-1]>V) return recursion(coins, M-1, V);
	    return min(recursion(coins,M,V-coins[M-1])+1,recursion(coins,M-1,V));
	}
	
	int memo[1001][1001];
	int memoization(int coins[], int M, int V){
	    if(M==0) return memo[M][V] = INT_MAX - 1;
	    if(V==0) return memo[M][V] = 0;
	    if(memo[M][V]!=-1) return memo[M][V];
	    if(coins[M-1]>V) return memo[M][V] = memoization(coins,M-1,V);
	    return memo[M][V] = min(memoization(coins,M,V-coins[M-1])+1,memoization(coins,M-1,V));
	}
	
	int topDown(int coins[], int M, int V){
	    int dp[M+1][V+1];
	    for(int i=0;i<M+1;i++){
	        for(int j=0;j<V+1;j++){
	            if(i==0) dp[i][j] = INT_MAX - 1;
	            else if(j==0) dp[i][j] = 0;
	            else if(coins[i-1]>j) dp[i][j] = dp[i-1][j];
	            else dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
	        }
	    }
	    return dp[M][V];
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   // return (recursion(coins,M,V)==INT_MAX-1)?-1:recursion(coins,M,V);
	   // memset(memo,-1,sizeof(memo));
	   // return (memoization(coins,M,V)==INT_MAX-1)?-1:memoization(coins,M,V);
	   return (topDown(coins,M,V)==INT_MAX-1)?-1:topDown(coins,M,V);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
