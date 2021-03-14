// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalindrome(string s, int i, int j){
        for(int k=i;k<(j+i)/2+1;k++) if(s[k]!=s[j+i-k]) return false;
        return true;
    }
    
    int recursion(string s, int i, int j){
        if(i>=j or isPalindrome(s,i,j)) return 0;
        else{
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int temp = recursion(s,i,k)+recursion(s,k+1,j)+1;
                ans = min(temp,ans);
            }
            return ans;
        }
    }
    
    int memo[501][501];
    int memoization(string s, int i, int j){
        if(i>=j or isPalindrome(s,i,j)) return memo[i][j] = 0;
        if(memo[i][j]!=-1) return memo[i][j];
        else{
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int left = (memo[i][k]==-1)?memoization(s,i,k):memo[i][k];
                int right = (memo[k+1][j]==-1)?memoization(s,k+1,j):memo[k+1][j];
                int temp = left+right+1;
                ans = min(temp,ans);
            }
            return memo[i][j] = ans;
        }
    }
    
    int topDown(string s){
        int n = s.length();
        int dp[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i>=j) dp[i][j] = 0;
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j = i+l;
                // cout<<"Indices: "<<i<<" "<<j<<endl;
                if(isPalindrome(s,i,j)) dp[i][j] = 0;
                else{
                    int ans = INT_MAX;
                    for(int k=i;k<j;k++){
                        int temp = dp[i][k]+dp[k+1][j]+1;
                        ans = min(temp,ans);
                        // cout<<dp[i][k]<<" "<<dp[k+1][j]<<" "<<temp<<" "<<ans<<endl;
                    }
                    dp[i][j] = ans;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<'\t';
        //     cout<<endl;
        // }
        return dp[0][n-1];
    }
    
	// Top Down using dp table for finding palindromic sequences.
	// O(n^3) solution
    int topDownI(string s){
        int n = s.length();
        int dp[n][n];
        bool isPalindrome[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(i==j){
                dp[i][j] = 0;
                isPalindrome[i][j] = true;
            }
            else if(i>j){
                dp[i][j] = 0;
                isPalindrome[i][j] = false;
            }
        }
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j = i+l;
                if(s[i]==s[j]){
                    if(isPalindrome[i][j] = (l==1 or  isPalindrome[i+1][j-1])){
                        dp[i][j] = 0;
                        continue;
                    }
                }
                else isPalindrome[i][j] = false;
                int ans = INT_MAX;
                for(int k=i;k<j;k++){
                    int temp = dp[i][k]+dp[k+1][j]+1;
                    ans = min(ans,temp);
                }
                dp[i][j] = ans;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<isPalindrome[i][j]<<'\t';
            cout<<endl;
        }
        return dp[0][n-1];
    }
    
	// Top Down approach using dp table to fing palindromic sequences
	// which is solved in the beginning in O(n^2), then the dp table 
	// for number of partitions is filled which is of length n, here
	// dp[i] means number of partitions required for the string of
	// length of i. This table is filled with the help of the palindromic
	// dp table in O(n^2), thus overall time complexity being O(n^2).
    int topDownII(string str){
        string s = str;
        int n = s.length();
        int dp[n];
        bool isPalindrome[n][n];
        memset(isPalindrome,false,sizeof(isPalindrome));
        for(int l=0;l<n;l++){
            for(int i=0;i<n-l;i++){
                if(l==0) isPalindrome[i][i] = true;
                else{
                    int j = i+l;
                    if(s[i]!=s[j]) isPalindrome[i][j] = false;
                    else isPalindrome[i][j] = (j-i==1 or isPalindrome[i+1][j-1]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<isPalindrome[i][j]<<'\t';
        //     cout<<endl;
        // }
        
        // In each iteration the ending value of the sequence
        // is taken, i.e. 'j'. Then if the complete sequence
        // from 0 to j is palindromic then number of partition
        // is taken as 0 and propagate further. Else if not a
        // palindrome (from 0 to j) then i=1 to i=j we check
        // if the sequence is palindrome then we add 1 partition
        // along with the number of partitions required for the
        // sequence k=0 to k=i.
        for(int j=0;j<n;j++){
            if(isPalindrome[0][j]) dp[j] = 0;
            else{
                dp[j] = INT_MAX;
                for(int i=0;i<j;i++){
                    if(isPalindrome[i+1][j]) dp[j] = min(dp[j],1+dp[i]);
                }
            }
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[n - 1];
    }
    
    int palindromicPartition(string str)
    {
        // code here
        // return recursion(str,0,str.length()-1);
        // memset(memo,-1,sizeof(memo));
        // return memoization(str,0,str.length()-1);
        // return topDown(str);
        // return topDownI(str);
        return topDownII(str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
