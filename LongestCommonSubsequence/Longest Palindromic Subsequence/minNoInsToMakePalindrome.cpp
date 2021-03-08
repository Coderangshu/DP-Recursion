// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countMin(string str);

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << countMin(str) << endl;
    }
return 0;
}

// } Driver Code Ends

// This is same as minimum no. of deletions to make
// palindromic sequence, for deletion we remove the
// matching characters, but in here we insert the 
// extra needed characters to make the non matching
// characters pair.
int topDown(string s, int n){
    string s1 = s;
    reverse(s.begin(),s.end());
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            else if(s[i-1]==s1[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];
}

int countMin(string str){
    //complete the function here
    return topDown(str,str.length());
}
