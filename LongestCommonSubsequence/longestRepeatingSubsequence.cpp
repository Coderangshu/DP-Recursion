// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
	
	    int recursion(string str1, string str2, int n, int m){
	        if(n==0 or m ==0) return 0;
	        if(str1[n-1]==str2[m-1] and n!=m) return 1+recursion(str1,str2,n-1,m-1);
	        else return max(recursion(str1,str2,n,m-1),recursion(str1,str2,n-1,m));
	    }
	
	    int memo[501][501];
	    int memoization(string str1, string str2, int n, int m){
	        if(n==0 or m==0) return memo[n][m] = 0;
	        if(memo[n][m]!=-1) return memo[n][m];
	        if(str1[n-1]==str2[m-1] and n!=m) return memo[n][m] = 1+memoization(str1,str2,n-1,m-1);
	        else return memo[n][m] = max(memoization(str1,str2,n,m-1),memoization(str1,str2,n-1,m));
	    }
	
	    int topDown(string str1, string str2, int n, int m){
	        int dp[n+1][m+1];
	        for(int i=0;i<n+1;i++){
	            for(int j=0;j<m+1;j++){
	                if(i==0 or j==0) dp[i][j] = 0;
	                else if(str1[i-1]==str2[j-1] and i!=j) dp[i][j] = 1+dp[i-1][j-1];
	                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	            }
	        }
	        return dp[n][m];
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		  //  return recursion(str,str,n,n);
		  //  memset(memo,-1,sizeof(memo));
		  //  return memoization(str,str,n,n);
		  return topDown(str, str, n, n);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
