// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recursion(string s, int i, int j, int t){
        if(i>j) return 0;
        if(i==j){
            if(t) return s[i]=='T'?1:0;
            else return s[i]=='T'?0:1;
        }
        else{
            int ans = 0;
            for(int k=i+1;k<j;k+=2){
                int lt = recursion(s,i,k-1,1);
                int lf = recursion(s,i,k-1,0);
                int rt = recursion(s,k+1,j,1);
                int rf = recursion(s,k+1,j,0);
                if(s[k]=='&'){
                    if(t) ans+=lt*rt;
                    else ans+=lf*rt+rf*lt+lf*rf;
                }
                else if(s[k]=='|'){
                    if(t) ans+=lt*rt+lf*rt+rf*lt;
                    else ans+=lf*rf;
                }
                else{
                    if(t) ans+=lf*rt+rf*lt;
                    else ans+=lt*rt+lf*rf;
                }
            }
            return ans%1003;
        }
    }

    unordered_map<string,int> mp;
    int memoization(string s, int i, int j, int t){
        string partial_key = to_string(i)+to_string(j);
        if(i>j) return mp[partial_key+to_string(0)]=mp[partial_key+to_string(1)]=0;
        if(i==j){
            if(t) return mp[partial_key+to_string(1)] = (s[i]=='T')?1:0;
            else return mp[partial_key+to_string(0)] = (s[i]=='T')?0:1;
        }
        string key = partial_key+to_string(t);
        if(mp.find(key)!=mp.end()) return mp[key];
        else{
            int ans = 0;
            for(int k=i+1;k<j;k+=2){
                int lt = (mp.find(to_string(i)+to_string(k-1)+to_string(1))!=mp.end())?mp[to_string(i)+to_string(k-1)+to_string(1)]:memoization(s,i,k-1,1);
                int lf = (mp.find(to_string(i)+to_string(k-1)+to_string(0))!=mp.end())?mp[to_string(i)+to_string(k-1)+to_string(0)]:memoization(s,i,k-1,0);
                int rt = (mp.find(to_string(k+1)+to_string(j)+to_string(1))!=mp.end())?mp[to_string(k+1)+to_string(j)+to_string(1)]:memoization(s,k+1,j,1);
                int rf = (mp.find(to_string(k+1)+to_string(j)+to_string(0))!=mp.end())?mp[to_string(k+1)+to_string(j)+to_string(0)]:memoization(s,k+1,j,0);
                if(s[k]=='&'){
                    if(t) ans+=lt*rt;
                    else ans+=lf*rt+rf*lt+lf*rf;
                }
                else if(s[k]=='|'){
                    if(t) ans+=lt*rt+lf*rt+rf*lt;
                    else ans+=lf*rf;
                }
                else{
                    if(t) ans+=lf*rt+rf*lt;
                    else ans+=lt*rt+lf*rf;
                }
            }
            return mp[key] = ans%1003;
        }
    }

    int memo[201][201][2];
    int memoizationI(string s, int i, int j, int t){
        if(i>j) return memo[i][j][0] = memo[i][j][1] = 0;
        if(i==j){
            if(t) return memo[i][j][1] = (s[i]=='T')?1:0;
            else return memo[i][j][0] = (s[i]=='T')?0:1;
        }
        if(memo[i][j][t]!=-1) return memo[i][j][t];
        else{
            int ans = 0;
            for(int k=i+1;k<j;k+=2){
                int lt = (memo[i][k-1][1]!=-1)?memo[i][k-1][1]:memoizationI(s,i,k-1,1);
                int lf = (memo[i][k-1][0]!=-1)?memo[i][k-1][0]:memoizationI(s,i,k-1,0);
                int rt = (memo[k+1][j][1]!=-1)?memo[k+1][j][1]:memoizationI(s,k+1,j,1);
                int rf = (memo[k+1][j][0]!=-1)?memo[k+1][j][0]:memoizationI(s,k+1,j,0);
                if(s[k]=='&'){
                    if(t) ans+=lt*rt;
                    else ans+=lf*rt+rf*lt+lf*rf;
                }
                else if(s[k]=='|'){
                    if(t) ans+=lt*rt+lf*rt+rf*lt;
                    else ans+=lf*rf;
                }
                else{
                    if(t) ans+=lf*rt+rf*lt;
                    else ans+=lt*rt+lf*rf;
                }
            }
            return memo[i][j][t] = ans%1003;
        }
    }

    int topDown(string s, int n){
        int dp[n][n][2];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(i==j){
                if(s[i]=='T'){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 1;
                }
                else{
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 0;
                }
            }
            else if(i>j){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        for(int l=3;l<=n;l+=2){
            for(int i=0;i<=n-l;i+=2){
                int j = i+l-1;
                dp[i][j][1] = 0;
                dp[i][j][0] = 0;
                for(int k=i+1;k<j;k+=2){
                    int lt = dp[i][k-1][1];
                    int lf = dp[i][k-1][0];
                    int rt = dp[k+1][j][1];
                    int rf = dp[k+1][j][0];
                    if(s[k]=='&'){
                        dp[i][j][1]+=(lt*rt)%1003;
                        dp[i][j][0]+=(lf*rt+rf*lt+lf*rf)%1003;
                    }
                    else if(s[k]=='|'){
                        dp[i][j][1]+=(lt*rt+lf*rt+rf*lt)%1003;
                        dp[i][j][0]+=(lf*rf)%1003;
                    }
                    else{
                        dp[i][j][1]+=(lf*rt+rf*lt)%1003;
                        dp[i][j][0]+=(lt*rt+lf*rf)%1003;
                    }
                }
            }
        }
        return dp[0][n-1][1]%1003;
    }

    int countWays(int N, string S){
        // code here
//         return recursion(S,0,N-1,1);
//         mp.clear();
//         return memoization(S,0,N-1,1);
        memset(memo,-1,sizeof(memo));
        return memoizationI(S,0,N-1,1);
        return topDown(S,N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
