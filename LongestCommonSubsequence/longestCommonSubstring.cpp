// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int topDown(string s1, string s2, int n, int m){
        // Commented lines inside this function are used to print the
        // complete array uncomment them to see the complete dp array.
        int dp[n+1][m+1];
        int ans = INT_MIN;
        for(int i=0;i<n+1;i++){
            // if(i!=0) cout<<s1[i-1]<<'\t';
            // if(i==0){
            //     for(int j=0;j<m+1;j++) j==0?cout<<'0'<<'\t'<<'0'<<'\t':cout<<s2[j-1]<<'\t';
            //     cout<<endl;
            // }
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = 0;
                if(dp[i][j]>ans) ans = dp[i][j];
                // cout<<dp[i][j]<<'\t';
            }
            // cout<<endl;
        }
        return ans;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        return topDown(S1,S2,n,m);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
