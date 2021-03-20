// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int recursion(int x, int y, string s1, string s2){
    if(x==0 or y==0) return 0;
    if(s1[x-1]==s2[y-1]) return 1 + recursion(x-1,y-1,s1,s2);
    else return max(recursion(x,y-1,s1,s2),recursion(x-1,y,s1,s2));
}

int memo[101][101];
int memoization(int x, int y, string s1, string s2){
    if(x==0 or y==0) return memo[x][y] = 0;
    if(memo[x][y]!= -1) return memo[x][y];
    if(s1[x-1]==s2[y-1]) return memo[x][y] = 1+memoization(x-1,y-1,s1,s2);
    return memo[x][y] = max(memoization(x,y-1,s1,s2),memoization(x-1,y,s1,s2));
}

int topDown(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    // return recursion(x,y,s1,s2);
    // memset(memo,-1,sizeof(memo));
    // return memoization(x,y,s1,s2);
    return topDown(x,y,s1,s2);
}
