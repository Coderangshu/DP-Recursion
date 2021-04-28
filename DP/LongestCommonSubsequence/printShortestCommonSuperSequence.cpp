//Follow https://youtu.be/VDhRg-ZJTuc to know the logic

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printShortestCommonSupersequence(char* , char*, int, int );

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
	cout << printShortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
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
string topDown(char *x, char *y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(x[i-1]==y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=m,j=n;
    string ans = "";
    while(i>0 and j>0){
        if(x[i-1]==y[j-1]){
            ans += x[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans += x[i-1];
                i--;
            }else{
                ans += y[j-1];
                j--;
            }
        }
    }
    while(i>0){
        ans += x[i-1];
        i--;
    }
    while(j>0){
        ans += y[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string printShortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here
    return topDown(X,Y,m,n);
}
