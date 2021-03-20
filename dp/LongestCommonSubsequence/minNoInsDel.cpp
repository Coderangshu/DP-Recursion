// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int topDown(string s1, string s2, int m, int n){
	    int dp[m+1][n+1];
	    for(int i=0;i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 or j==0) dp[i][j] = 0;
	            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    // Here we find the lcs of both the strings, we know that the
	    // lcs will be present in the final output without any change,
	    // now we delete the number of characters excess in the first
	    // string from the lcs string this gives us the deletion chars
	    // then we subtract final output and lcs this gives us the difference
	    // how many elements have to be inserted.
	    //       To delete    To insert
	    return (m-dp[m][n])+(n-dp[m][n]);
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.length();
	    int n = str2.length();
	    return topDown(str1,str2,m,n);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
