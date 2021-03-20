// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recursion(int N, int W, int val[], int wt[]){
        if(W==0 or N==0) return 0;
        if(wt[N-1]>W) return recursion(N-1,W,val,wt);
        else return max(val[N-1]+recursion(N,W-wt[N-1],val,wt),recursion(N-1,W,val,wt));
    }
    
    int memo[1001][1001];
    int memoization(int N, int W, int val[], int wt[]){
        if(W==0 or N==0) return memo[W][N] = 0;
        if(memo[W][N]!=-1) return memo[W][N];
        if(wt[N-1]>W) return memo[W][N] = memoization(N-1,W,val,wt);
        else return memo[W][N] = max(memoization(N,W-wt[N-1],val,wt)+val[N-1],memoization(N-1,W,val,wt));
    }
    
    int topDown(int N, int W, int val[], int wt[]){
        int dp[W+1][N+1];
        for(int i=0;i<W+1;i++){
            for(int j=0;j<N+1;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(wt[j-1]>i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = max(val[j-1]+dp[i-wt[j-1]][j],dp[i][j-1]);
            }
        }
        return dp[W][N];
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // return recursion(N,W,val,wt);
        // memset(memo,-1,sizeof(memo));
        // return memoization(N,W,val,wt);
        return topDown(N,W,val,wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
