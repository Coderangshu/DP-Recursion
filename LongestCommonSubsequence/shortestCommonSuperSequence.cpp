// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n

// We use the complete lcs problem here,
// then  we subtract that from sum of the 
// largest possible supersequence, which is
// the sum of both the given strings.
int topDown(char *x, char *y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(x[i-1]==y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return m+n-dp[m][n];
}

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here
    return topDown(X,Y,m,n);
}
