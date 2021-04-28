#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool recursion(string a, string b) {
        int n = a.length();
        if(n!=b.length()) return 0;
        if(a.compare(b)==0) return 1;
        if(n<=1) return 0;
        else{
            for(int k=1;k<n;k++){
                int swapped = (recursion(a.substr(0,k),b.substr(n-k,k)) and recursion(a.substr(k,n-k),b.substr(0,n-k)));
                int not_swapped = (recursion(a.substr(0,k),b.substr(0,k)) and recursion(a.substr(k,n-k),b.substr(k,n-k)));
                if(swapped or not_swapped) return 1;
            }
            return 0;
        }
    }
    
    unordered_map<string,bool> mp;
    bool memoization(string a, string b){
        int n = a.length();
        if(n!=b.length()) return mp[a+b] = 0;
        if(a.compare(b)==0) return mp[a+b] = 1;
        if(n<=1) return mp[a+b] = 0;
        if(mp.find(a+b)!=mp.end()) return mp[a+b];
        else{
            for(int k=1;k<n;k++){
                // int sf = (mp.find(a.substr(0,k)+b.substr(n-k,k))!=mp.end())?mp[a.substr(0,k)+b.substr(n-k,k)]:memoization(a.substr(0,k),b.substr(n-k,k));
                // int ss = (mp.find(a.substr(k,n-k)+b.substr(0,n-k))!=mp.end())?mp[a.substr(k,n-k)+b.substr(0,n-k)]:memoization(a.substr(k,n-k),b.substr(0,n-k));
                int swapped = (memoization(a.substr(0,k),b.substr(n-k,k)) and memoization(a.substr(k,n-k),b.substr(0,n-k)));
                
                // int nsf = (mp.find(a.substr(0,k)+b.substr(0,k))!=mp.end())?mp[a.substr(0,k)+b.substr(0,k)]:memoization(a.substr(0,k),b.substr(0,k));
                // int nss = (mp.find(a.substr(k,n-k)+b.substr(k,n-k))!=mp.end())?mp[a.substr(k,n-k)+b.substr(k,n-k)]:memoization(a.substr(k,n-k),b.substr(k,n-k));
                int not_swapped = (memoization(a.substr(0,k),b.substr(0,k)) and memoization(a.substr(k,n-k),b.substr(k,n-k)));
                if(swapped or not_swapped) return mp[a+b] = 1;
            }
            return mp[a+b] = 0;
        }
    }
};

int main(){
    Solution obj = Solution();
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<obj.recursion(a,b)<<endl;
        cout<<obj.memoization(a,b)<<endl;
    }
}
