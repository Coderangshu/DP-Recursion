// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Returns the maximum value that  
// can be put in a knapsack of capacity W 

int recursion(int w,int wt[], int val[], int n){
    if(w==0 or n==0) return 0;
    if(wt[n-1]>w) return recursion(w,wt,val,n-1);
    else return max(val[n-1]+recursion(w-wt[n-1],wt,val,n-1),recursion(w,wt,val,n-1));
}

int memo[1001][1001];

int memoization(int w,int wt[], int val[], int n){
    if(w==0 or n==0) return memo[w][n] = 0;
    if(memo[w][n]!=-1) return memo[w][n];
    if(wt[n-1]>w) return memo[w][n] = memoization(w,wt,val,n-1);
    else return memo[w][n] = max(val[n-1]+memoization(w-wt[n-1],wt,val,n-1),memoization(w,wt,val,n-1));
}

int topDown(int w,int wt[], int val[], int n){
    int dp[w+1][n+1];
    for(int i=0;i<w+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(wt[j-1]>i) dp[i][j] = dp[i][j-1];
            else dp[i][j] = max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
        }
    }
    return dp[w][n];
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   // Recursion
//   return recursion(W,wt,val,n);
   // Memoization
//   memset(memo,-1,sizeof(memo));
//   return memoization(W,wt,val,n);
   // BottomUp
   return topDown(W,wt,val,n);
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
