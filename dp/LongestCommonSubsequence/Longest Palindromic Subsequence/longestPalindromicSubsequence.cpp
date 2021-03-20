// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int topDown(string s1, int n){
        // We take the string and its reverse and find the
        // longest common subsequence in both of them this
        // gives us the palindromic subsequence.
	    string s2 = s1;
	    reverse(s1.begin(),s1.end());
	    int dp[n+1][n+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 or j==0) dp[i][j] = 0;
	            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return dp[n][n];
	}
	
	int longestPalidromicSubsequence(string str1) 
	{ 
	    // Your code goes here
	    int m = str1.length();
	    return topDown(str1,m);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1;
        cin >> s1;

	    Solution ob;
	    cout << ob.longestPalidromicSubsequence(s1) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
