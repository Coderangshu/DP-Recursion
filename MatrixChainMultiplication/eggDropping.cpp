// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */

int recursion(int e, int f){
    if(e==0 or f==0) return 0;
    if(e==1) return f;
    if(f==1) return 1;
    else{
        int ans = INT_MAX;
        for(int k=2;k<=f;k++){
            int temp = 1+max(recursion(e-1,k-1),recursion(e,f-k));
            ans = min(ans,temp);
        }
        return ans;
    }
}

int memo[11][51];
int memoization(int e, int f){
    if(e==0 or f==0) return memo[e][f] = 0;
    if(e==1) return memo[e][f] = f;
    if(f==1) return memo[e][f] = 1;
    if(memo[e][f]!=-1) return memo[e][f];
    else{
        int ans = INT_MAX;
        for(int k=2;k<=f;k++){
            int temp = 1+max(memoization(e-1,k-1),memoization(e,f-k));
            ans = min(ans,temp);
        }
        return memo[e][f] = ans;
    }
}

int tabulation(int e, int f){
    int dp[e+1][f+1];
    for(int i=0;i<=e;i++){
        for(int j=0;j<=f;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(i==1) dp[i][j] = j;
            else if(j==1) dp[i][j] = 1;
            else{
                dp[i][j] = INT_MAX;
                for(int k=2;k<=j;k++){
                    int temp = 1+max(dp[i-1][k-1],dp[i][j-k]);
                    dp[i][j] = min(dp[i][j],temp);
                }
            }
        }
    }
    
//     for(int i=0;i<=e;i++){
//         for(int j=0;j<=f;j++) cout<<dp[i][j]<<'\t';
//         cout<<endl;
//     }
    return dp[e][f];
}

int eggDrop(int n, int k) 
{
    // your code here
    // return recursion(n,k);
    // memset(memo,-1,sizeof(memo));
    // return memoization(n,k);
    return tabulation(n,k);
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
